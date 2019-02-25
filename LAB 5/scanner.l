%option noyywrap
if{#include "toke.h"%}

if %
[a-z,A-Z][a-z,A-Z,0-9]*
                {return id;}

"+" return "+"
"*" return "*"
"(" return "("
")" return ")"

%%