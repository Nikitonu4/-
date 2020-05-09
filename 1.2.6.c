#include<stdio.h>
#include <locale.h>
#define n 100
void main()
{
    setlocale(LC_ALL, "RUS");
    int number, i=0, star1=-1, star2=-1; //number - кол-во чисел в массиве, star1 и star2 - первая пара звездочек
    char a[n];
    printf("введите количество чисел в массиве(не должно превышать 100):");
    scanf("%d", &number);
    if (number>100 || number<=1)
    {
        printf("\n Вы ввели недопустимое число. Пожалуйста введите кол-во меньше 100 и больше 1."); //защита от пользователя
        return;
    }
    printf("Введите элементы массива:\n");
    
    for (i=2;i<number+2;i++)
        scanf("%c",&a[i]);
    
    for (i=1;i<number+2;i++)
    {
        if(a[i]=='*')
            star1=i;
        if(star1!=-1)
            break;
    }
    
    for (i=i+1;i<number+2;i++)
    {
        if(a[i]=='*')
            star2=i;
        if(star2!=-1)
            break;
    }
    
    
    if (star1==-1 || star2==-1) //проверка условия наличия обоих звездочек
        printf("Две звездочки в заданной последовательности из %d символов не обнаружены, повторите ввод. Вам необходимо ввести как минимум две звездочки.\n",number);
    else
        printf("Кол-во символов между звездочками = %d",(star2-star1)-1);
}
