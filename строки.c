//идентефикатор не больше 20 символом(21 для \0)
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <stdio.h>
#define n 21
#define l 100
char str[n],cmpl[l];
int a[n],j,k,z =0 ;     //identefication - вводимый идентефикатор, a - массив, в котором чередуются 0 и 1(см. конец программы)

void func1(char str)
{
    for(int i=0;i<strlen(str);i++)
        if (isalpha(str)==0)
            a[i]=0;
        else
            a[i]=1;
    func2(a);
}


int func2(int a[n])
{
    for(int i = 0; i<strlen(str);i++)                   //отладить и перепроверить для последнего элемента
        if(a[i]!=a[i+1])
            j++;
    if(j==strlen(str))
    {                                                   // цикл для проверки массива а на чередование 0 и 1
        cmpl[z]=str;
        z++;
        func3(z);
        
    }
   
    return 0;
}



void func3(char cmpl,int z)
{
    for(int i;i<z;i++)
        printf("Удовлетворюяющие идентефикаторы: %d ",cmpl[i]);
    return;
}

int main(void)
{
    setlocale(LC_ALL, "RUS");
    printf("Введите:\n");
    scanf("%s",&str);
    func1(str);
//    for(;;)
//
//    {
//        if(gets(str)==' ')
//
//

//    }
}

//использование  gets(str);
//strlen(a) - длины строки до пробела
//если цифра - 1, если буква - 0;
