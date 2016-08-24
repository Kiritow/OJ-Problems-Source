# include <stdio.h>
# include <string.h>
char str[110] ;
char tab[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZ',-.?" ;
int cnt, label[1100] ;
void gao()
{
    int i, sp = 0 ;
    for (i = 0 ; str[i] ; i++)
    {
        if (str[i] != ' ' && sp != 0)
            label[cnt++] = ((sp&1)?0:1), 
            sp = 0 ;
        else if (str[i] == ' ') sp++ ;
    }
}
void Print()
{
    int i, j, buff ;
    for (i = 0 ; i < cnt ; i+= 5)
    {
        buff = 0 ;
        for (j = 0 ;j < 5 ; j++)
        {
            if (i+j>=cnt) label[i+j] = 0 ;
            buff = buff * 2 + label[i+j] ;
        }
        putchar (tab[buff]) ;
    }
    printf("\n") ;
}
int main ()
{
    gets (str) ;
    while (1)
    {
        cnt = 0 ;
        if (strcmp(str, "#") == 0) break ;
        while (1)
        {
            if (strcmp(str, "*") == 0) break ;
            gao() ;
            gets (str) ;
        }
        Print() ;
        gets (str) ;
    }
    return 0 ;
}
