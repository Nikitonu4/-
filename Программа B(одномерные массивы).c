#include<stdio.h>
#include <locale.h>
#define an 100
#define bn 100
void main()
{
    int i,number,j = 0,k,z,x,y,f,q = 0;
    int a[an], b[bn];
    setlocale(LC_ALL, "RUS");
    printf("Введите кол-во элементов массива:");
    if(scanf("%d",&number)==0) //проверка на букву
    {
        printf("Некорректное значение\n");
        return;
    }
    printf("Введите элементы массива:");
    for(i=0;i<number;i++)
    {
        if(scanf("%d",&a[i])==0) ///проверка на букву
        {
            printf("Некорректно\n");
            return;
        }
    }
    for(i=0;i<number;i++)
        b[i]=a[i]; //создаю 2 массив, чтобы не изменять первый a[i]
    
    for(i=0;i<number;i++) //проверка на четырехзначность
    {
        while (b[i]>0)
        {
            b[i]=b[i]/10;
            j++;
        }
        if(j!=4)
        {
            printf("Вы ввели не четырехзначное число.");
            return;
        }
        if (b[i]<=0)
            j=0;
    }
    printf("Введите k от 0 до 9 = ");
    if(scanf("%d",&k)==0)
    {
       printf("Некорректное значение. Введите пожалуйста число от 0 до 9.");
       return;
    }
    if (k<0 || k>9)
    {
       printf("Некорректное значение. Введите пожалуйста число от 0 до 9.");
       return;
    }
    
    printf("Подпоследовательность, состоящая из чисел, оканчивающихся на k: ");
    for(i=0;i<number;i++)
        if ((a[i]%10)==k)
        {
            printf("%d ",a[i]);
            q++;
        }
    if (q==0)
        printf("Не найдено");
    q=0;
    
    for(i=0;i<number;i++)
        b[i]=a[i];
    
    printf("\nПоследовательность, состоящая из чисел, у которых сумма первых двух цифр равна сумме последних двух: ");
    for (i=0;i<number;i++)
    {
        z=b[i]%10;b[i]=b[i]/10;
        x=b[i]%10;b[i]=b[i]/10;
        y=b[i]%10;b[i]=b[i]/10;
        f=b[i]%10;
        if ((y+f)==(x+z))
        {
            printf("%d ",a[i]);
            q++;
        }
        z=0;
        x=0;
        y=0;
        f=0;
    }
    if (q==0)
        printf("Не найдено");
}
