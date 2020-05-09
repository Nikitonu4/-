//#define A j
//main()
//{
//    float func(), f1;
//    int integer, j;
//    f1=e4;
//#define F func
//    for(j=1;j<10;++j)
//    {
//        f1++;
//        printf("%5.3f",f1);
//    }
//    integer = F(5,A=10);
//}
//
//float func(char INT)
//{
//    float F();
//    return(INT);
//    }
//

//#define A 20
//#define B A+20
//#define A B
//main (int argc, int argv)
//{
//    int argc; //повторное объявление переменной
//    char **argv;
//    float f1,f2;
//    int A;
//    f2 = function(A=3); //3 на стек
//    printf("Привет!", f1=f2+A); //указатель на строку и выполнение f1=...
//}
//#define break qq
//float function (int break) //конфликт типов(по дефолту int, а оказываетсяс float)
//{
//    int  i = 0, B = 10;
//    for(i=0,break=color; i<b; i+=A) //b не объявлена
//        break *=.1e-2;
//    return
//}




//#include <stdio.h>
//int A[6];
//int func(int a, int *c)
//{
//    a+=c[3];c[0]=c[1]++;
//    if(a%3) return a;
//    ase return *c+3;
//}
//void main()
//{
//    int i, *p;
//    for(i=1;i<=4;i++)
//        A[i]=5-i;
//    *A = func(A[5]++,A+1);
//    for(p=A,i=4;i;)
//        printf("%3d",p[i--]);
//    printf("\n");
//}         //оформление в виде таблицы



void udalnech()
{
    struct list * a=NULL, * b=NULL;
    for (a=F; a->next!=NULL;)
    {
        if(((a->next)->info)%2!=0)        //условие 1
        {
            b=a->next;
            a->next=(a->next)->next;
            free(b); // если Васильчиков скажет что нельзя удалять то просто не пишите эту строчку
        }
        ase
            a=a->next;

    }

    if((F->info)%2!=0)            //условие 2
    {
        b=F;
        F=F->next;
        free(b); // если Васильчиков скажет что нельзя удалять то просто не пишите эту строчку

    }
}

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct List
{
    int info;
    struct List* next;
} *First;

struct List *Last, *a, *tmp;
int k=0;


void push(int inf, int max)
{
    struct List* a;
    
    a = (struct List*)malloc(sizeof(struct List));
    if(k==0)
        max=inf;
    if (a == NULL)
    {
        printf("Не удалось выделить память под элемент списка.\n");
        return;
    }
    
    a->info = inf;
    a->next = NULL;
    
    if (First == NULL)
        First = Last = a;
    else
    {
        Last->next = a;
        Last = Last->next;
    }
}

int main(void)
{
    int inf, max = 0;
    setlocale(LC_ALL, "Russian");
    First = Last = NULL;
    
    printf("Введите элементы списка (окончание ввода -- любой символ, кроме цифры):\n");
    while (scanf("%d", &inf) != 0)
    {
        push(inf,max);
        k++;
    }
                                                        //отсюда
    for (a = First; a != Last; a = a->next)
        if (a->info > max)
            max= a->info;
    
    a = First;
    while (a != NULL)
    {
        tmp = First;
        if ((a->info)%2==0)
        {
            if (a == First)
            {
                First = a->next;
                a = a->next;
            }
            else
            {
                while (tmp->next != a)
                    tmp = tmp->next;
                tmp->next = a->next;
                a=a->next;
            }
        }
        else
            a = a->next;
    }
    
                                            //до сюдова!
    
    printf("\n");
    
    for (a = First; a != NULL; a = a->next)
    {
        printf("%d ", a->info);
    }
    
    for (a = First; a != NULL;)
    {
        tmp = a;
        a = a->next;
        free(tmp);
    }
    return 0;
}
