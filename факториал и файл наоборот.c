#include <stdio.h>
int factorial(int n)
{
    if (n==1)
        return 1;
    return n*factorial(n-1);
}

void main()
{
    printf("%d\n",factorial(6));
}



#include <stdio.h>
void inv(FILE *FA)
{
    char ch;
    ch = getc(FA);
    if(!feof(FA))
        inv(FA);
    printf("%c",ch);
}
void main()
{
    FILE *FA;
    FA = fopen("FA.txt","r");
    inv(FA);
}

