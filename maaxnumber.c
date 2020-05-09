#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int maxDigit(int number, int max)
{
    if (!number)
        return max;
    int tmp = number % 10;
    if(max<tmp)
        max=tmp;
    return maxDigit(number/10, max);
}
int main(void)
{
    int number;
    printf("Введите число: ");
    scanf("%d",&number);
    int max = number % 10;
    max = maxDigit(number, max);
    printf("max = %d\n", max);
}
