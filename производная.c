#include<stdio.h>
#include <locale.h>
#include <ctype.h>
#include <math.h>
#define n 200


//int j,i,count=0,N,M,K,found=0,k;      //k - коэф-т точности вычисления производной в точке
//char a[n];
//
//
//void process()
//{
//    if(isdigit(a[i-1]))       //предпоследняя, 2 и 3 цифры до значка степени, соответственно M, N и K
//        a[i-1]=M;
//    if(isdigit(a[i-2]))
//        a[i-2]=N;
//    if(isdigit(a[i-3]))
//        a[i-3]=K;
//}
//
//void main()
//{
//    setlocale(LC_ALL, "RUS");
//    printf("Введите многочлен, начиная со старшей степени, закончите ввод запятой сразу после последнего символа:");            //придумать как сделать до свободного члена
//    while(1)
//    {
//        a[i]=getchar();
//        if (a[i]=='^')
//            process();
//
//
//
//
//         i++;

    

    
//    printf("Введите элементы матрицы:\n");
//    for(i=0;i<N;i++) //N - строки
//        for(j=0;j<M;j++) //M - столбцы
//            if(scanf("%d",&a[i][j])==0)
//            {
//                printf("Вы ввели не число");
//                return;
//            }
//
//
//    for(i=0;i<N && !found;i++) //N - строки
//        for(j=0;j<M && !found;j++) //M - столбцы
//        {
//            found=1;
//            for(t=0; t<N && found; t++)
//                if (a[i][j]>a[t][j])
//                    found=0;
//            for(t=0; t<M && found; t++)
//                if (a[i][j]<a[t][j])
//                    found=0;
//        }
//    if(found)
//        printf("found %d %d",i,j);
//    else
//        printf("не найдено");
//

double f(double x)
{
    return (10 * pow(x,5));
}


void main()
{
        double x, h, fc;
        int z;
        
        x = 2; // точка, в которой вычисляем производную
        h = 0.0000001; // шаг, с которым вычисляем производную

    z=fc;
        fc = (f(x + h) - f(x - h)) / (2 * h);
    printf("%f\n",fc);
    }
    
    

