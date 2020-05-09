#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define BUFSIZE 80
//...........................//
//              для do until ..... loop             //
char buf[BUFSIZE];
int d = 0;
int j = 0; // номер строки в таблице, где находится лексема, найденная функцией look
int bufcount = 0;
int TNUMcount = 0, TIDcount = 0;
char TW[7][BUFSIZE] = {"", "until", "loop", "not", "and", "or", "do"}; //служебные слова
char TD[18][BUFSIZE] = {"",":=","!=","=","[", "]", "'", ":", ";", "<", ">", "*", "+", "-", "/", "(", ")","&"}; //ограничители
char TID[BUFSIZE][BUFSIZE]; //идентефикаторы
int TNUM[BUFSIZE]; //константы

void clearr()   // очистка буфера buf
{
    for(int i = 0; i<bufcount; i++)
        buf[i] = '\0';
    bufcount = 0;
}

void add(char c) // добавление символа с в конец буфера buf
{
    buf[bufcount]=c;
    bufcount++;
}

int look(char T[][BUFSIZE]) // поиск в таблице лексемы из buf; результат: номер строки таблицы либо 0
{
    int temp = T[0][0];
    for(int i = 1; i<=temp; i++)
    {
        if(strcmp(buf,T[i])==0)
            return i;
    }
    return 0;
}

int putl(char T[][BUFSIZE]) // запись в таблицу лексемы из buf,если ее там не было; Результат : номер строки таблицы
{
    T[0][0]++;
    int temp = T[0][0];
    for(int i = 0; i<BUFSIZE; i++)
        T[temp][i] = buf[i];
    return temp;
}

int putnum() // запись в TNUM константы из d, если ее там не было; результат: номер строки таблицы TNUM(если была - возвратит номер строки где была)
{
    
    for(int j = 0; j<=TNUMcount; j++)
        if(d==TNUM[j] && d!=0)
            return  j+1;
    
    TNUM[TNUMcount] = d;
    d = 0;
    TNUMcount++;
    return  TNUMcount;
}

void makelex(int a ,int b)
{
    switch(a){
        case 1:
            printf("(TW,%d) ", b);
            break;
        case 2:
            printf("(TD,%d) ", b);
            break;
        case 3:
            printf("(TID,%d) ", b);
            break;
        case 4:
            printf("(TNUM,%d) ", b);
            break;
    }
}

void printtable()
{
    printf("\nTW: \n");
    for(int i = 1; i<7; i++)
    {
        printf("%d. ",i);
        puts(TW[i]);
    }
    
    printf("\nTD: \n");
    for(int i = 1; i<18; i++)
    {
        printf("%d. ",i);
        puts(TD[i]);
    }
    
    printf("\nTID: \n");
    for(int i = 1; i<TID[0][0]+1; i++)
    {
        printf("%d. ",i);
        puts(TID[i]);
    }
    
    printf("\nTNUM: \n");
    for(int i = 1; i<TNUMcount+1; i++)
    {
        printf("%d. %d\n",i,TNUM[i-1]);
    }
}

void main (int argc, char *argv[])
{
    FILE *fp;
    enum state
    {
        H,ID,NUM,COM,ASS,DLM,ER,FIN
    };
    enum state TC;
    char c = '\0', tmp = '\0';
    TC = H;
    TID[0][0]=0;
    TW[0][0]=7;
    TD[0][0]=18;
    TNUM[0] = 0;
    fp = fopen(argv[1],"rt");
    c = fgetc(fp);
    do{
        switch (TC)
        {
            case H:
                if (c == ' ')
                    c = fgetc(fp);
                else
                    if (c == '\n')
                    {
                        printf("\n");
                        c = fgetc(fp);
                    }
                    else
                        if (isalpha(c))
                        {
                            clearr();
                            add(c);
                            c = fgetc(fp);
                            TC = ID;
                        }
                        else if (isdigit(c))
                        {
                            d = c - '0';
                            c = fgetc(fp);
                            TC = NUM;
                        }
                        else if (c == '{')
                        {
                            c = fgetc(fp);
                            TC = COM;
                        }
                        else if ((c == ':') || (c == '!'))
                        {
                            tmp = c;
                            c = fgetc(fp);
                            TC = ASS;
                        }
                
                
                        else if (c =='&') //типа ограничитель
                        {
                            makelex(2, 17);
                            TC = FIN;
                        }
                        else TC = DLM;
                break;
                
            case ID:
                if (isalpha(c) || isdigit(c))
                {
                    add(c);
                    c = fgetc(fp);
                }
                else
                {
                    if (j = look(TW))
                        makelex(1, j);
                    else
                    {
                        if (j = look(TID))
                        {
                            makelex(3, j);
                        }
                        else
                        {
                            TIDcount++;
                            j = putl(TID);
                            makelex(3, j);
                        }
                    };
                    TC = H;
                };
                break;
                
            case NUM:
                if (isdigit(c))
                {
                    d = d*10+(c-'0');
                    c = fgetc(fp);
                }
                else
                {
                    makelex(4, putnum());
                    TC = H;
                }
                break;
                
            case COM:
                if (c == '}')
                    TC = H;
                else
                    if (c == '&')
                        TC = ER;
                    else
                        c = fgetc(fp);
                break;
                
            case ASS:
                if (c == '=')
                {
                    if (tmp == '!')
                        makelex(2, 2);
                    if (tmp == ':')
                        makelex(2, 1);
                    TC = H;
                    c = fgetc(fp);
                }
                else TC = ER;
                break;
                
            case FIN:
                makelex(2, 1 );
                break;
            case DLM:
                clearr();
                add(c);
                if (j = look(TD))
                {
                    makelex(2, j);
                    c = fgetc(fp);
                    TC = H;
                }
                else
                    TC = ER;
                break;
            case ER:
                break;
                
        }
    }
    while (TC != FIN && TC != ER);
    if (TC == ER && c!= EOF )
    {
        printf("Error\n");
        return;
    }
    printtable();
}
