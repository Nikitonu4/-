#define A j
main()
{
    float func(), f1;
    int integer, j;
    f1=e4;
#define F func
    for(j=1;j<10;++j)
    {
        f1++;
        printf("%5.3f",f1);
    }
    integer = F(5,A=10);
}

float func(char INT)
{
    float F();
    return(INT);
    }


#define B 20
#define B color
#define A B
main (int argc, int argv)
{
    int argc; //повторное объявление переменной
    char **argv;
    float f1,f2;
    int A;
    f2 = function(A=3); //3 на стек
    printf("Привет!", f1=f2+A); //указатель на строку и выполнение f1=...
}
#define break qq
float function (int break) //конфликт типов(по дефолту int, а оказываетсяс float)
{
    int  i = 0, B = 10;
    for(i=0,break=color; i<b; i+=A) //b не объявлена
        break *=.1e-2;
    return
}



#include <stdio.h>
int A[6];
int func(int a, int *c)
{
    a+=c[3];c[0]=c[1]++;
    if(a%3) return a;
    else return *c+3;
}
void main()
{
    int i, *p;
    for(i=1;i<=4;i++)
        A[i]=5-i;
    *A = func(A[5]++,A+1);
    for(p=A,i=4;i;)
        printf("%3d",p[i--]);
    printf("\n");
}         //оформление в виде таблицы

//#include <stdio.h>
//#include <string.h>
//#include <locale.h>
//#include <stdlib.h>
//#define n 100
//int k = 0, col = 0, j, m, b[n]; //col - кол-во символов
//char a[n];
//
//int charl(char a)
//{
//    for (int i = 0; i < 26; i++)
//    {
//        if ((a == ('a' + i)) || (a == ('A' + i)))
//        {
//            return 1;
//        }
//    }
//    return 0;
//}
//
//int digital(char a)
//{
//    for (int i = 0; i < 10; i++)
//    {
//        if (a == ('1' + i))
//        {
//            return 1;
//
//        }
//    }
//    return 0;
//}
//
//void print()
//{
//    for (int i = b[m]; i < b[m + 1]; i++)
//    {
//        printf("%c", a[i]);
//    }
//    printf(" ");
//    return;
//}
//
//void main()
//{
//    setlocale(LC_ALL, "RUS");
//    int i=0, pr = 0, fk = 0;          //pr - число или буква(если буква - 1, если число - 0)
//
//    printf("Введите последовательность идентефикаторов: ");
//
//    for (i;;i++)
//    {
//        a[i] = getchar();
//
//        if ((digital(a[i])) && (charl(a[i])) && (!' ') && (!'#'))
//        {
//            printf("Вы ввели некорректную запись");
//            return;
//        }
//
//        if (i == 0)
//        {
//            if ((digital(a[i]) == 1) || (charl(a[i]) == 1))
//            {
//                b[k] = i;
//                k++;
//            }
//        }
//
//        if (a[i] == ' ')
//        {
//            if ((digital(a[i - 1]) == 1) || (charl(a[i - 1]) == 1))
//            {
//                b[k] = i;
//                k++;
//            }
//        }
//
//        if ((digital(a[i]) == 1) || (charl(a[i]) == 1))          //номер следующего идентефикатора
//        {
//            if (a[i - 1] == ' ')
//            {
//                b[k] = i;
//                k++;
//            }
//        }
//
//        if ((a[i] == '#') && (a[i - 1] == '#') && (a[i - 2] == '#'))
//        {
//            b[k] = i - 2;
//            k++;
//            break;
//        }
//    }
//
//    printf("\nИдентефикаторы удовлетворяющие условию:");
//    for (m = 0; m < k; m = m + 2)        //+2 потому что m - номера начала и конца идентефикатора,
//    {
//        for (j = b[m]; j < b[m + 1]; j++)
//        {
//            if (j == b[m])
//            {
//                if (digital(a[j]))
//                {
//                    pr = 0;
//                    col++;
//                }
//                else
//                {
//                    pr = 1;
//                    col++;
//                }
//            }
//            else                        //если не первая буква в идентефикаторе
//            {
//                if ((digital(a[j])) && (pr == 1))
//                {
//                    pr = 0;
//                    col++;
//                }
//                else
//                    if ((charl(a[j])) && (pr == 0))
//                    {
//                        pr = 1;
//                        col++;
//                    }
//                    else
//                    {
//                        fk = 1;
//                        break;
//                    }
//            }
//        }
//
//        if (col > 22)               //проверка на >22 col - кол-во символов в идентефикторе
//        {
//            printf("Вы ввели индификатор больше 22 символов");
//            return;
//        }
//
//        if (fk != 1)
//            print();
//        col = 0;
//        fk = 0;
//    }
//    printf("\n");
//
//}



