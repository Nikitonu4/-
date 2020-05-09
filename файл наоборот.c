#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    FILE *FA, *FB;
    char c = '\0';
    int *a, n = 0, h = 0;
    if (!(FA = fopen(argv[1], "rt")))
    {
        printf("Error with opening file 1\n");
        return 0;
    }
    
    if ((FB = fopen(argv[2], "rt")))
    {
        printf("Out file exist, rewriting?(1-yes,2-no)\n");
        scanf("%d",&h);
        if(h==2)
        {
            printf("Program end.\n");
            fclose(FA);
            fclose(FB);
            return 0;
        }
        else
            FB = fopen(argv[2], "wt");
    }
    else
        FB = fopen(argv[2], "wt");
    
    while (c != EOF)
    {
        c = fgetc(FA);
        n++;
    }
    a = (int*)malloc(n * sizeof(int));
    
    rewind(FA);
    
    for(int i=1;i<n;i++)
    {
        *(a+i) = fgetc(FA);
    }
    for (n--; n != 0; n--)
    {
        putc(*(a + n), FB);
    }
    
    fclose(FA);
    fclose(FB);
}
