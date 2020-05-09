#include<stdio.h>
#include <locale.h>
#define n 100
#define m 100

void main()
{
    int a[n][m],i,j,N,M,found=0,t;
    setlocale(LC_ALL, "RUS");
    printf("Введите кол-во строк:");
    if(scanf("%d",&N)==0)
    {
        printf("Вы ввели не число");
        return;
    }
    
    printf("Введите кол-во столбцов:");
    if(scanf("%d",&M)==0)
    {
        printf("Вы ввели не число");
        return;
    }
    printf("Введите элементы матрицы:\n");
    for(i=0;i<N;i++) //N - строки
        for(j=0;j<M;j++) //M - столбцы
            if(scanf("%d",&a[i][j])==0)
            {
                printf("Вы ввели не число");
                return;
            }
    
    
    for(i=0;i<N && !found;i++) //N - строки
        for(j=0;j<M && !found;j++) //M - столбцы
        {
            found=1;
            for(t=0; t<N && found; t++)
                if (a[i][j]>a[t][j])
                    found=0;
            for(t=0; t<M && found; t++)
                if (a[i][j]<a[t][j])
                    found=0;
        }
    if(found)
        printf("found %d %d",i,j);
    else
        printf("не найдено");

    
    
    
}
