//22
//узел задается пользователем
//дерево хранится в файле в скобочной форме

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct tree
{
    int inf;
    struct tree *L;
    struct tree *R;
};

void createTree(struct tree *N)
{
    struct tree *T;
    int a;
    printf("Ввести левого сына для %d 1/0?",N->inf);
    scanf("%d",&a);
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        printf("Введите значение");
        scanf("%d",&T->inf);
        N->L = T;
        createTree(T);
    }
    printf("Ввести правого сына для %d 1/0?",N->inf);
    scanf("%d",&a);
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        printf("Введите значение");
        scanf("%d",&T->inf);
        N->R = T;
        createTree(T);
    }
    return;
}

void printTree(struct tree *N)          //прямой обход
{
    printf("%d ",N->inf);
    if(N->L)
        printTree(N->L);
    if(N->R)
        printTree(N->R);
}

//void printTree(struct tree *N)          //обратный обход
//{
//
//    if(N->L)
//        printTree(N->L);
//    if(N->R)
//        printTree(N->R);
//    printf("%d ",N->inf);
//}

//void printTree(struct tree *N)          //симметричный обход
//{
//
//    if(N->L)
//        printTree(N->L);
//printf("%d ",N->inf);
//    if(N->R)
//        printTree(N->R);
//}

void cleanTree(struct tree *N)
{
        if(N->L)
            printTree(N->L);
        if(N->R)
            printTree(N->R);
    free(N);
}


int main()
{
    struct tree *Root;
    int a;
    setlocale(LC_ALL, "Russian");
    printf("Введите корень -> ");
    scanf("%d", &a);
    Root = (struct tree*)malloc(sizeof(struct tree));    //проверить на выделение
    Root -> inf = a;
    Root -> L = NULL;
    Root -> R = NULL;
    createTree(Root);
    printf("Введено дерево ->");
    printTree(Root);
}


//обязательно написать функцию для очистки памяти от бинарного дерева



//22
//узел задается пользователем
//дерево хранится в файле в скобочной форме

#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct tree
{
    int inf;
    struct tree *L;
    struct tree *R;
};



void createTree(struct tree *N, pointer)
{
    struct tree *T;
    int a;
    printf("Ввести левого сына для %d 1/0?",N->inf);
    scanf("%d",&a);
    
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        printf("Введите значение");
        scanf("%d",&T->inf);
        
        if((T->inf)>=(N->inf))
        {
            printf("Вы вводите не дерево поиска");
            return;
        }
        
        
        N->L = T;
        createTree(T,pointer);
    }
    printf("Ввести правого сына для %d 1/0?",N->inf);
    scanf("%d",&a);
    
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        printf("Введите значение");
        scanf("%d",&T->inf);
        if((T->inf)<(N->inf))
        {
            printf("Вы вводите не дерево поиска");
            return;
        }
        N->R = T;
        createTree(T, pointer);
    }
    return;
}

void printTree(struct tree *N)          //прямой обход
{
    printf("%d ",N->inf);
    if(N->L)
        printTree(N->L);
    if(N->R)
        printTree(N->R);
}

//void printTree(struct tree *N)          //обратный обход
//{
//
//    if(N->L)
//        printTree(N->L);
//    if(N->R)
//        printTree(N->R);
//    printf("%d ",N->inf);
//}

//void printTree(struct tree *N)          //симметричный обход
//{
//
//    if(N->L)
//        printTree(N->L);
//printf("%d ",N->inf);
//    if(N->R)
//        printTree(N->R);
//}

void cleanTree(struct tree *N)
{
    if(N->L)
        printTree(N->L);
    if(N->R)
        printTree(N->R);
    free(N);
}


int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "Russian");
    FILE *FA;
    char c = '\0';
    int *pointer = NULL, n = 0, h = 0, i = 0;
    if (!(FA = fopen(argv[1], "rt")))
    {
        printf("Error with opening file\n");
        fclose(FA);
        return 0;
    }
    int j = 0;
    int q = 0;
    char p = '-';
    while (c != EOF)
    {
        c = fgetc(FA);
        n++;
        
        if(c == '(' )
            i++;
        if(c == ')' )
            i--;
        if(c == ',')
            j++;
        if(isdigit(c))
            if(!isdigit(p))
                q++;
        p = c;
        
        //        if((j==1)&&(i==1))                                                      //сделать проверку на запятые
        //        {
        //            printf("Неверная поставлены запятые. Проверьте скобки");
        //            return 0;
        //        }
        
        
        //        if(i<0)
        //        {
        //            printf("Неверная скобочная форма. Проверьте скобки\n");
        //            return 0;
        //        }
        //
        //    }
        //
        //    if (i!=0)
        //    {
        //        printf("Неверная скобочная форма. Проверьте скобки\n");
        //        return 0;
        //    }
        //
        //    pointer = (int*)malloc(n * sizeof(int));
        //
        //    rewind(FA);
        //
        //    int string[n+1];
        //
        //    int x;
        //
        //    for(int i=0;i<n;i++)
        //    {
        //        fscanf(FA,"%d",&x);
        //        string[i] = x;
        //        fseek(FA,ftell(FA)+1,0);
        //    }
        //   while(string[p]!=NULL)
        
        // for(int i = 0; i<q+1; i++)
        //    {
        //        x = string[i];
        //        printf("%d ", x);
        //   //     p++;
        //    }
        
        
        
        struct tree *Root;
        Root = (struct tree*)malloc(sizeof(struct tree));   //проверить на выделение
        Root->inf = *pointer;
        
        
        Root->L = NULL;
        Root->R = NULL;
        
        
        
        //    createTree(Root,*pointer);
        
        //    printf("Введено дерево ->");
        //    printTree(Root);
        //    cleanTree(Root);
    }
    
    
    //обязательно написать функцию для очистки памяти от бинарного дерева
    //проверить стек на переполнение
    
    
    
