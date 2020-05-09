#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int A[2][2], B[2][2];
void powma(int n)
{
    int i, j, k, sum;
    int C[n][n];

    for (i = 0; i<n; i++) {
        for (k = 0; k<n; k++) {
            sum = 0;
            for (j = 0; j<n; j++) {
                sum +=  A[i][j] * A[j][k];
            }
            C[i][k] += sum;
        }
    }


    int flag = 0;
    for (i = 0; i < n; i++)
     for (j = 0; j < n; j++)
         if(C[i][j]!=B[i][j]){
             flag = 1;
             break;
         }

             if(flag ==1)
                 printf("Не является\n");
             else
                 printf("Является\n");


    printf("Матрица квадрата А:\n");
    for (i = 0; i < n; i++)
       {
        for (j = 0; j < n; j++)
            printf("%d ",C[i][j]);
            printf("\n");
       }
    printf("\n");


    printf("Матрица А:\n");
    for (i = 0; i < n; i++)
       {
        for (j = 0; j < n; j++)
            printf("%d ",A[i][j]);
            printf("\n");
       }
    
    printf("Матрица B:\n");
       for (i = 0; i < n; i++)
          {
           for (j = 0; j < n; j++)
               printf("%d ",B[i][j]);
               printf("\n");
          }

    return;
}
int main(void)
{
    int  i, j;

    printf("Матрица А:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &A[i][j]);
        }
    
    printf("Матрица B:\n");
    for (i = 0; i < 2; i++)
        for (j = 0; j < 2; j++)
        {
            scanf("%d", &B[i][j]);
        }
    powma(2);
}
