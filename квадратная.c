#include<stdio.h>
#include <locale.h>
#define n 20

void main()
{
    int i,j,N,found = 0,t;
    float a[n][n];
    setlocale(LC_ALL, "RUS");
    printf("Введите размер квадратной матрицы:");
    if(scanf("%d",&N)==0)
    {
        printf("Вы ввели не число");
        return;
    }
    
    printf("Введите элементы матрицы:\n");
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            if(scanf("%f",&a[i][j])==0)
            {
                printf("Вы ввели не число");
                return;
            }
    
    for(i=0;i<N;i++){
        for(j=0;j<N;j++)
            printf("%4g",a[i][j]);
        printf("\n");
    }
}
