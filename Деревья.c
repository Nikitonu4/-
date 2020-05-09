//22
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
struct tree
{
    int inf;
    struct tree *L;
    struct tree *R;
    struct tree *parent;
};

void createTree(struct tree *N)
{
    struct tree *T;
    int a;
    printf("Ввести левого сына для %d 1/0? ",N->inf);
    scanf("%d",&a);
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        T ->parent = NULL;
        printf("Введите значение: ");
        scanf("%d",&T->inf);
        if((T->inf)>(N->inf))
        {
            printf("Вы вводите не дерево поиска:(\n");
            return;
        }
        N->L = T;
        T->parent = N;                                      //предок элемента
        createTree(T);
    }
    
    printf("Ввести правого сына для %d 1/0? ",N->inf);
    scanf("%d",&a);
    if(a)
    {
        T = (struct tree*)malloc(sizeof(struct tree));
        T ->L = NULL;
        T ->R = NULL;
        T ->parent = NULL;
        printf("Введите значение: ");
        scanf("%d",&T->inf);
        if((T->inf)<(N->inf))
        {
            printf("Вы вводите не дерево поиска");
            return;
        }
        N->R = T;
        T->parent = N;                                      //предок элемента
        createTree(T);
        
    }
    return;
}

struct tree* minimum(struct tree* x)
{
    if ((x->L) == NULL)
        return x;
    return minimum(x->L);
}


struct tree* next(struct tree* x)                   //поиск следующего элемента после x
{
    struct tree* y;
    
    if ((x->R) != NULL)
        return minimum(x->R);

    
    y = x->parent;
    while ((y != NULL) && (x == y->R))
    {
        x = y;
        y = y->parent;
    }
    return y;
}

void delete(struct tree* v)                  // v - удаляемый элемент
{
    struct tree* nextv;
    nextv = NULL;
    struct tree* p;
    p = (v -> parent);                                // предок удаляемого элемента
    if ((v->L == NULL) && (v->R == NULL))             // удаляемый элемент не имеет потомков
    {
        if ((p->L) == v)
            p->L = NULL;
        if ((p->R) == v)
            p->R = NULL;
        return;
    }
    
    else if ((v->L == NULL) || (v->R == NULL))         // удаляемый элемент имеет одного потомка
        if (v->L == NULL)
        {
            if (p->L == v)
                p->L = v->R;
            else
                p->R = v->R;
            (v->R)->parent = p;
            return;
        }
        else
        {
            if (p->L == v)
                p->L = v->L;
            else
                p->R = v->L;
            (v->L)->parent = p;
            return;
        }
    
    else                                             // удаляемый элемент имеет двух потомков
    {
        nextv = next(v);                            //нахожу следующий за элементом
        v->inf=nextv->inf;
        
        if (((nextv->parent)->L) == nextv)
        {
            (nextv->parent)->L = nextv->R;
            if ((nextv->R) != NULL)
                (nextv->R)->parent = nextv->parent;
        }
        else
            {
                (nextv->parent)->R = nextv->L;
                if ((nextv->L) != NULL)
                    (nextv->R)->parent = nextv->parent;
            }
        }
    return;
}


void searchel(struct tree *root, int key)   //key - искомый элемент
{

    if(key == root->inf)
    {
        delete(root);                       //вызов функции удаления
        return;
    }
    if(key < (root->inf))
    {
        if(root->L)
            searchel(root->L, key);
    }
    else
    {
        if(root->R)
            searchel(root->R, key);
    }
}

void printTree(struct tree *N)          //прямой обход
{
    printf("%d ",N->inf);
    if(N->L)
        printTree(N->L);
    if(N->R)
        printTree(N->R);
}


int count(struct tree *N)
{
    if(N->L)
        printTree(N->L);
        else
            count++;
    if(N->R)
        printTree(N->R);
    else
        count++;
    if((N->L)==NULL&&(N->R)==NULL)
        return count;
}



void cleanTree(struct tree *N)                  //очистка памяти
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
    int a,k;
    setlocale(LC_ALL, "Russian");
    printf("Введите корень -> ");
    scanf("%d", &a);
    if(!(Root = (struct tree*)malloc(sizeof(struct tree))))
    {
        printf("Не удалось выделить память");
        return 0;
    }
    Root -> inf = a;
    Root -> L = NULL;
    Root -> R = NULL;
    createTree(Root);
    printf("Введите узел для удаления: ");
    
    if(!(scanf("%d",&k)))
    {
        printf("Вы ввели не число");
        return 0;
    }
    searchel(Root,k);
    printf("Введено дерево ->");
    printTree(Root);
    
    count(Root);
    printf("count =", count);
    
}
