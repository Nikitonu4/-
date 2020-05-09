#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define BUFSIZE 80
//...........................//
//              для do until ..... loop             //
FILE *fp;
char buf[BUFSIZE]; //буфер
int d = 0; //для числового представления константы
int j = 0; // номер строки в таблице, где находится лексема, найденная функцией look
int bufcount = 0; //счетчик кол-ва символов в buf
int TNUMcount = 0, TIDcount = 0; //счетчики символов в TNUM и TID
int flagEr = 0;
char TW[7][BUFSIZE] = {"", "until", "loop", "not", "and", "or", "do"}; //служебные слова
char TD[18][BUFSIZE] = {"",":=","!=","=","[", "]", "'", ":", ";", "<", ">", "*", "+", "-", "/", "(", ")","&"}; //ограничители
char TID[BUFSIZE][BUFSIZE]; //идентефикаторы
int TNUM[BUFSIZE]; //константы
char c = '\0', tmp = '\0'; // c - очередной символ, tmp - символ для :=
typedef struct lex
{
    int clas;          //номер таблицы
    int value;         //номер в таблице
}lex;
lex curr_lex;
lex getlex();

lex returnvoid(){
    lex r;
    r.clas = 0;
    r.value = 0;
    return r;
}

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

lex makelex(int k, int i)           // k - таблица i - номер в таблице
{
    {
        switch(k){
            case 1:
                printf("(TW,%d) ", i);
                break;
            case 2:
                printf("(TD,%d) ", i);
                break;
            case 3:
                printf("(TID,%d) ", i);
                break;
            case 4:
                printf("(TNUM,%d) ", i);
                break;
        }
    }
    lex l;
    l.clas = k; l.value = i;
    return l;
}

int id()
{
    if (curr_lex.clas == 3)
        return 1;
    return 0;
}

int num()                       //если константа
{
    if (curr_lex.clas == 4)
        return 1;
    return 0;
}

int eq( char *s)                //срвнение строки из буфера и s
{
    int i=0;
    for(i=0;i<strlen(s);i++)
        if (buf[i]!=s[i])
            return 0;
    if (bufcount - i != 0)
        return 0;
    return 1;
}

void error() {
    printf("\nТип ошибочки: ");
    switch (flagEr)
    {
        case 1:
            printf("Синтаксическая ошибка\n");
            break;
        case 2:
            printf("Не найден do\n");
            exit(0);
        case 3:
            printf("Не найден until\n");
            exit(0);
        case 4:
            printf("Не найден loop\n");
            exit(0);
        case 5:
            printf("Не корректный операнд\n");
            break;
        case 6:
            printf("Не найдена закрывающая скобка\n");
            break;
        case 7:
            printf("Ожидалось :=");
            break;
    }
}

void operand() {
    if (!id()) {
        if (!num()){
            flagEr = 5;
            error();
        }
    }
    curr_lex = getlex();
}

void comparasionEx() {
    operand();
    if(eq("<")||eq(">")||eq("=")||eq("!="))
    {
        curr_lex = getlex();
        operand();
    }
    else
        return;
}
void logicalEx() {
    if (eq("not")) {
        curr_lex = getlex();
        comparasionEx();
    }
    else
        comparasionEx();
    if (!eq("and"))
        if (!eq("or"))
            return;
    curr_lex = getlex();
    logicalEx();
}

void arifmEx() {
    if (eq("(")) {
        curr_lex = getlex();
        arifmEx();
        if (!eq(")")){
            flagEr = 6;
            error();
        }
        curr_lex = getlex();
    }
    else {
        operand();
        if(eq("+")||eq("-")||eq("/")||eq("*"))
        {
            //        if (!eq("+"))
            //            if (!eq("-"))
            //                if (!eq("/"))
            //                    if (!eq("*"))
            //                        return;
            curr_lex = getlex();
            arifmEx();
        }
        else return;
    }
}
void identeficator() {
    if (!id()){
        flagEr = 1;
        error();
    }
}
void operator() {
    identeficator();
    curr_lex = getlex();
    if (!eq(":=")){
        flagEr = 7;
        error();
    }
    curr_lex = getlex();
    arifmEx();
    if (eq(";")) {
        curr_lex = getlex();
        operator();
    }
}

void Program() {
    if (eq("do")) {
        curr_lex = getlex();
    }
    else{
        flagEr = 2;
        error();
    }
    
    if (!eq("until")){
        flagEr = 3;
        error();
    }
    
    curr_lex = getlex();
    logicalEx();
    operator();
    
    if (!eq("loop")){
        flagEr = 4;
        error();
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

lex getlex()
{
    enum state
    {
        H,ID,NUM,COM,ASS,DLM,ER,FIN
    };
    enum state TC;
    lex E;
    E.clas = 0; E.value = 0;
    TC = H;
    fseek(fp, -1, SEEK_CUR);
    c = fgetc(fp);
    while(c!=EOF)
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
                        clearr();
                        add(c);
                        tmp = c;
                        c = fgetc(fp);
                        TC = ASS;
                    }
            
            
                    else if (c =='&') //типа ограничитель
                    {
                        return makelex(2, 17);
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
                if ((j = look(TW)) != 0)
                    return makelex(1, j);
                else
                {
                    if (j = look(TID))
                    {
                        return makelex(3, j);
                    }
                    else
                    {
                        TIDcount++;
                        j = putl(TID);
                        return makelex(3, j);
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
                return makelex(4, putnum());
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
                add(c);
                c = fgetc(fp);
                if (tmp == '!')
                    return makelex(2, 2);
                if (tmp == ':')
                    return makelex(2, 1);
                TC = H;
                
            }
            else TC = ER;
            break;
        case FIN:
            return makelex(2, 1 );
            break;
        case DLM:
            clearr();
            add(c);
            if (j = look(TD))
            {
                c = fgetc(fp);
                return makelex(2, j);
                TC = H;
            }
            else
                TC = ER;
            break;
        case ER:
            break;
            
    }
    if (TC == ER && c!= EOF )
    {
        printf("Error\n");
        return returnvoid();
    }
    return returnvoid();
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "RUS");
    if ((fp = fopen(argv[1], "rt")) == NULL)
    {
        printf("Файл не считан");
        return 0;
    }
    
    TID[0][0]=0;
    TW[0][0]=7;
    TD[0][0]=18;
    TNUM[0] = 0;
    curr_lex = getlex();
    Program();
    printtable();
}
