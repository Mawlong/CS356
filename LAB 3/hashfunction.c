/*

    To implement open addressing using Double Hashing

*/


#include<stdio.h>

#define tableSize 10


struct hash
{
    int key;
    int value;
};

struct hash hashTable[tableSize];

void populateInitial()
{
    int i = 0;

    // We use  the value -1 to indicate a value of NIL at the key position

    for(i;i<tableSize;i++)
        hashTable[i].key = -1;
}

int auxilaryHash1(int value)
{

    // here 7 is a Prime number less than table size

    return (value % 7);
}

int auxilaryHash2(int value)
{
    return (value % 8);
}

int doubleHash(int value, int control)
{
    if(control == tableSize)
        return -1;
    else
    {
        return (auxilaryHash1(value) + (control * auxilaryHash2(value) ) %7 );
    }
    
}

int searchHash(int value)
{
    int i = 0;
    int findKey;
    while(i<tableSize)
    {
        findKey = doubleHash(value,i);

        if(hashTable[findKey].value == value)
            return findKey;
        
        i++;
    }
    return -1;
}

void display()
{
    int i = 0;
    printf("\nValue\tKey\n");
    for(i;i<tableSize;i++)
    {
        if(hashTable[i].key == -1)
            continue;
        else
        {
            printf("\n%d\t%d",hashTable[i].value,hashTable[i].key);
        }
        
    }
}
void insert(int store, int key)
{
    hashTable[key].key = key;
    hashTable[key].value = store;
}

void delete(int value)
{
    int key;
    key = searchHash(value);
    if(key == -1)
    {    
        printf("\nValue does not exist.");
    }
    else
    {
        hashTable[key].key = -1;
    }   

}

int main()
{
    int count = 0;

    int temp;

    int choice;
    int searched;

    populateInitial();

    while(1)
    {
        printf("\nPlease Enter your choice:\n1.Insert\n2.Search\n3.Delete\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                printf("\nEnter the value to be inserted: ");
                scanf("%d", &temp);
                if(count >= tableSize)
                {
                    printf("\nTable Full! ABORT!");
                    break;
                }
                insert(temp, doubleHash(temp,count));
                count++;
                display();
                break;
            
            case 2:
                
                printf("\nEnter the value to be searched: ");
                scanf("%d", &temp);
                searched = searchHash(temp);
                if(searched == -1)
                    printf("\nValue not found");
                else
                {
                    printf("\nValue available at key value %d",hashTable[searched].key);
                }
                
                break;

            case 3:
                printf("\nEnter an Element to be deleted: ");
                scanf("%d", &temp);
                delete(temp);
                display();
                break;
            
            default:
                printf("\nWrong Choice!");
        }
        printf("\nWant to continue? press 1\n");
        scanf("%d", &choice);
        if(choice != 1)
            break;
    }
}