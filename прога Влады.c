//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//int i,j,z=0;
//char ident[35][21];
//char ma[1500];
//
//void chet(char ident[i][j])
//
//{
//    int p=0;
//    for(int k = 0; k<j;k++)
//        for(int zup=0;zup<=9;zup++)
//            if(ident[i][k]==zup) //прибавляю 1 к p если нашлась цифра
//        {
//            p++; //если p = 0 записываю в отдельный массив, который потом вывожу
//        }
//
//    if(p==0)
//    {
//        ma[z]=ident[i][j];
//        z++;
//    }
//    return;
//}
//
//int main(void)
//{
//
//    char ch;
//
//    ch=0;
//    i=0;
//    j=0;
//
//    printf("Введите последовательность идентефикаторов через пробел(закончите запятой): \n");
//    while (ch!=',' && i<35)
//    {
//        ch=getchar();
//
//        if (ch!=' ' && ch!=',')
//        {
//            if (j<21)
//            {
//                ident[i][j]=ch;
//                j++;
//            }
//            else
//            {
//                printf("Выход за пределы");
//                break;
//            }
//        }
//        else
//        {
//            if(ch==',')
//                ident[i][j]='\0';
//            chet(ident);
//
//                i++;
//                j=0;
//        }
//    }
//    for(int h=0;h<z;h++)
//        printf("%c ",ma[h]);
//
//    if ((i==35) && (ch!= ','))
//        printf("Вы ввели больше 35 идентефикаторов");
//
//    }
//
//
//
