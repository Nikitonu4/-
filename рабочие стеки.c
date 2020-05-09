#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <ctype.h>
#include <string.h>
#define N 100

char stack[N],el;
int top1 = -1,top2 = -1, n,i=1;

void push()
{
    printf("\nВведите элемент стека — букву латинского алфавита: \n");
    scanf("%s",&el);
    if (isalpha(el))
    {
        top1++;
        top2++;
        stack[top1] = el;
    }
    else
    {
        i=0;
        printf("Вы ввели не символ латинского алфавита!\n");
    }
    return;
}

int pop()
{
    top2--;
    return stack[top2 + 1];
}

void top()
{
    printf("Вершина стека: %c\n", stack[top2]);
    return;
}

void print()
{
    printf("\nВывод элементов стека: ");
    if(top1 == -1)
        printf("Стек пуст(\n");
    else
        while (top2 > -1)
            printf("%c ", pop());
    printf("\n");
    top2=top1;
}

void size()
{
    printf("Размер стека: %d\n", top1+1);
}

void clearr()
{
    while(top1!=-1)
    {
        top1--;
        stack[top1]='\0';
    }
    
    top1 = -1;
    printf("Стек очищен!\n");
    return;
}

void main()
{
    int com=0;
    setlocale(LC_ALL, "Russian");
    top1 = -1; // стек пуст
    
    printf("Введите размер стека: ");
    if(scanf("%d", &n)==0)
    {
        printf("Недопустимое значение!\n");
        return;
    }
    
    
    for(;;)
    {
        printf("Введите команду:\n");
        printf("1 - push\n2 - pop\n3 - top\n4 - print\n5 - size\n6 - clear\n7 - exit\n\n");
        if(scanf("%d",&com)==0)
        {
            printf("Недопустимое команда!\n");
            return;
        }
        
        if (com == 1)
        {
            push();
            
            if (top1 > n-1)
            {
                printf("Переполнение стека!\n");
                return;
            }
            
            if (i==0)
                return;
            
            continue;
        }
        
        if (com == 2)
        {
            pop();
            continue;
        }
        
        
        if (com == 3)
        {
            top();
            continue;
        }
        
        if (com == 4)
        {
            print();
            continue;
        }
        
        if (com == 5)
        {
            size();
            continue;
        }
        
        if (com == 6)
        {
            clearr();
            continue;
        }
        
        if (com == 7)
        {
            printf("Выход из программы. \n");
            return;
        }
    }
}
