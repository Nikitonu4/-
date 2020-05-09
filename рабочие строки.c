 
int i = 0,j = 0;
char ident[35][21];

int charInfo(){
    for(int i = 0; i!='\0';i++)
        ident
}

int digit(int i)
{
    int flg = 1;
    for(j=0;j<strlen(ident[i]);j++)
        if (isdigit(ident[i][j]))
            flg = 0;
    if(flg)
        return 1;
    else
            return 0;
}

int main()
{
    
    char ch;
    ch=0;
    printf("Введите идентефикаторы, закончите запятой: \n");
    while (ch!=',' && i<21)
    {
        ch=getchar();
        if(ch!=' ')
        {
            if (j<36)
            {
                ident[i][j]=ch;
                j+=1;
            }
            else
            {
                printf("Длина последовательности >35!");
                break;
            }
        }
        else
        {
            if (digit(i))
                printf("%s\n",ident[i]);
                i++;
                j=0;
        }
    }
    if(ch==',')
    {
        ident[i][j-1]='\0';
        if (digit(i))
            printf("%s\n",ident[i]);
    }
    
if (i>35)
    printf("Больше 35 идентефикаторов!");
}
