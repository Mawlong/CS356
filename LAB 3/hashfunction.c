/*

    To implement open addressing using Double Hashing for strings

*/

#include<stdio.h>
#include<math.h>
#include<string.h>
 
struct data
{
	int key;
	char value[10];
};
 
struct hashtable_item 
{
 
	int flag;
	/*
	 * flag = 0 : data not present
	 * flag = 1 : some data already present
	 * flag = 2 : data was present,but deleted
	*/
	struct data *item;
 
};
 
struct hashtable_item *array;
int max = 7;
int size = 0;
int prime = 3;
 
int hashcode1(int key)
{
	return (key % max);
}
 
int hashcode2(int key)
{
	return (prime - (key % prime));
}
 
void insert(int key, char value[])
{
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
 
	int index = hash1;
 
	/* create new data to insert */
	struct data *new_item = (struct data*) malloc(sizeof(struct data));
	new_item->key = key;
	strcpy(new_item->value, value);
 
	if (size == max) 
        {
		printf("\n Hash Table is full, cannot insert more items \n");
		return;
	}
 
	/* probing through other array elements */
	while (array[index].flag == 1) {
		if (array[index].item->key == key)
                {
			printf("\n Key already present, hence updating its value \n");
			strcpy(array[index].item->value, value);
			return;
		}
		index = (index + hash2) % max; 
		if (index == hash1)
                {
			printf("\n Add is failed \n");
			return;
		}
		printf("\n probing \n");
 
	}
 
	array[index].item = new_item;
	array[index].flag = 1;
	size++;
	printf("\n Key (%d) has been inserted \n", key);
 
}
 
/* to remove an element from the array */
void remove_element(int key)
{
	int hash1 = hashcode1(key);
	int hash2 = hashcode2(key);
	int index = hash1;
 
	if (size == 0)
        {
		printf("\n Hash Table is empty \n");
		return;
	}
 
	/* probing through other elements */
	while (array[index].flag != 0)
        {
		if (array[index].flag == 1  &&  array[index].item->key == key)
                {
			array[index].item = NULL;
			array[index].flag = 2;
			size--;
			printf("\n Key (%d) has been removed \n", key);
			return;
		}
		index = (index + hash2) % max;
		if (index == hash1)
                {
			break;
		}
	}
 
	printf("\n Key (%d) does not exist \n", key);
 
}
 
int size_of_hashtable()
{
	return size;
}
 
/* displays all elements of array */
void display()
{
    printf("\nIndex\tKey\t\tValue");
	int i;
	for (i = 0; i < max; i++)
        {
		if (array[i].flag != 1)
                {
			printf("\n%d  \t - \t\t -  ", i);
		}
		else
                {
			printf("\n%d  \t %d \t\t %s", i, array[i].item->key, array[i].item->value);
		}
	}
}
 
/* returns largest prime number less than size of array */
int get_prime()
{
	int i,j;
	for (i = max - 1; i >= 1; i--)
        {
		int flag = 0;
		for (j = 2; j <= (int)sqrt(i); j++)
                {
			if (i % j == 0)
                        {
				flag++;
			}
		}
		if (flag == 0)
                {
			return i;
		}
	}
	return 3;
 
}

/* initializes array */
void init_array()
{
	int i;
	for(i = 0; i < max; i++)
        {
		array[i].item = NULL;
		array[i].flag = 0;
	}
	prime = get_prime();
}
 
int main()
{
<<<<<<< HEAD
	int choice, key, n, c;
    char value[10];
	printf("\nEnter the size of the hash table: ");
    scanf("%d", &max);
 
	array = (struct hashtable_item*) malloc(max * sizeof(struct hashtable_item));
	init_array();
 
	do {
		printf("Implementation of Hash Table in C with Double Hashing.\n\n");
		printf("MENU-: \n1.Inserting item in the Hash Table" 
                              "\n2.Removing item from the Hash Table" 
                              "\n3.Display Hash Table"
		       "\n\n Please enter your choice-:");
 
		scanf("%d", &choice);
 
		switch(choice) 
                {
 
		case 1:
 
		      printf("Inserting element in Hash Table\n");
		      printf("Enter key and value-:\t");
		      scanf("%d %s", &key, value);
		      insert(key, value);
 
		      break;
 
   		case 2:
 
		      printf("Deleting in Hash Table \n Enter the key to delete-:");
		      scanf("%d", &key);
		      remove_element(key);
 
		      break;
 
		case 3:
 
		      display();
 
		      break;
 
		default:
 
		       printf("Wrong Input\n");
 
		}
 
		printf("\n Do you want to continue-:(press 1 for yes)\t");
		scanf("%d", &c);
 
	}while(c == 1); 
=======
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
>>>>>>> 5ec6f2388570888986af2bcd5aec137c89e0b93f
}