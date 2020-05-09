#include<stdio.h>
#include <locale.h>
#define N 20

float MinMata (float a[N][N], int str, int stlb)
{
    float min = a[0][0];
    for (int i=0; i<=str; i++)
        for (int j=0; j<=stlb; j++)
            if (a[i][j] < min)
                min = a[i][j];
    return min;
}

int main (void)
{
    int str,stlb,n;
    float a[N][N],b[N][N];
    setlocale(LC_ALL, "RUS");
    
    printf("Введите размер квадратной матрицы:");
    if(scanf("%d",&n)==0)
    {
        printf("Вы ввели не число");
        return 0;
    }
    
    printf("Введите элементы матрицы:\n");
    for (str=0; str<n; str++)
        for (stlb=0; stlb<n; stlb++)
            if(scanf("%f",&a[str][stlb])==0)
            {
                printf("Вы ввели не число");
                return 0;
            }
    
    for (str=0; str<n; str++)
        for (stlb=0; stlb<n; stlb++)
            b[str][stlb] = MinMata(a, str, stlb);
    
    printf("Исходная матрица:\n");
   for (str=0; str<n; str++)    
    {
        for (stlb=0; stlb<n; stlb++)
            printf("%5g",a[str][stlb]);
        printf("\n");
    }
    
    printf("Конечная матрица:\n");
    for (str=0; str<n; str++)
    {
        for (stlb=0; stlb<n; stlb++)
            printf("%5g",b[str][stlb]);
        printf("\n");
    }
}
