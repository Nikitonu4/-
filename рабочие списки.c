#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct List
{
    int info;
    struct List* next;
} List;

List *First, *Last, *el, *tmp;
int k=0;

void push(int inf, int max)
{
    struct List* el;
    
    el = (struct List*)malloc(sizeof(struct List));
    if(k==0)
        max=inf;
    if (el == NULL)
    {
        printf("Не удалось выделить память под элемент списка.\n");
        return;
    }
    
    el->info = inf;
    el->next = NULL;
    
    if (First == NULL)
        First = Last = el;
    else
    {
        Last->next = el;
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
    for (el = First; el != Last; el = el->next)
        if (el->info > max)
            max= el->info;
    
    el = First;
    while (el != NULL)
    {
        tmp = First;
        if (el->info == max)
        {
            if (el == First)
            {
                First = el->next;
                el = el->next;
            }
            else
            {
                while (tmp->next != el)
                    tmp = tmp->next;
                tmp->next = el->next;
                el=el->next;
            }
        }
        else
            el = el->next;
        }
    
    printf("\n");
    
    for (el = First; el != NULL; el = el->next)
    {
        printf("%d ", el->info);
    }
    
    for (el = First; el != NULL;)
    {
        tmp = el;
        el = el->next;
        free(tmp);
    }
    return 0;
}


