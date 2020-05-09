#include<stdio.h>
#include <locale.h>
#define n 100
void main()
{
    int i,number,amount=0;
    float a[n];
    setlocale(LC_ALL, "RUS");
    printf("Введите кол-во элементов массива:");
    if(scanf("%d",&number)==0) //проверка на букву
    {
        printf("Неккоректное значение\n");
        return;
    }
    printf("Введите элементы массива:");
    for(i=0;i<number;i++)
    {
            if(scanf("%f",&a[i])==0) ///проверка на букву
            {
                printf("Неккоректно\n");
                return;
            }
    }
    
    for (i=0;i<number-1;i++)
        if((a[i]/a[i+1])<=0)
            amount++;
    printf("Знак меняется %d раз(а), на позициях: ",amount);
    
    for (i=0;i<number-1;i++)
        if((a[i]/a[i+1])<=0)
            printf("%d ",i+1);
}
