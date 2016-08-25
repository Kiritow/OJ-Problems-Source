#include <stdio.h>
#include <string.h>
char s[81];
int l;
int Dig(char c)
{
    if (c >= '0' && c <= '9')
    {
        return 1;
    }
    return 0;
}
int Upper(char c)
{
    if (c >= 'A' && c <= 'Z')
    {
        return 1;
    }
    return 0;
}
int Lower(char c)
{
    if (c >= 'a' && c <= 'z')
    {
        return 1;
    }
    return 0;
}
int Char(char c)
{
    if (Upper(c) || Lower(c))
    {
        return 1;
    }
    return 0;
}
int Punc(char c)
{
    if (Dig(c) || Char(c) || c == ' ')
    {
        return 0;
    }
    return 1;
}
int Iso(char c)
{
    if (c == 'A' || c == 'a' || c == 'I')
    {
        return 1;
    }
    return 0;
}
int check1()
{
    int i;
    for (i = 0; i < l - 1; i++)
    {
        if(Upper(s[i]) && Upper(s[i + 1]))
            return 0;
    }
    return 1;
}
int check2()
{
    int i;
    for (i = 0; i < l - 1; i++)
    {
        if ((Char(s[i]) && Dig(s[i + 1])) || (Char(s[i + 1]) && Dig(s[i])))
            return 0;
    }
    return 1;
}
int check3()
{
    int i;
    if (l == 1)
    {
        if (Iso(s[0]))
        {
            return 1;
        }
        return 0;
    }
    if (s[1] == ' '&& Iso(s[0]) == 0 && s[0] != ' ')
        return 0;
    if (s[l - 2] == ' ' && Iso(s[l - 1]) == 0 && s[l - 1] != ' ')
        return 0;
    for (i = 1; i < l - 1; i++)
    {
        if(s[i] != ' ' && s[i - 1] == ' ' && s[i + 1] == ' ' && Iso(s[i]) == 0)
            return 0;
    }
    return 1;
}
int check4()
{
    int i;
    for (i = 0; i < l - 1; i++)
    {
        if(Punc(s[i]) && Punc(s[i + 1]) && s[i] != '\"' && s[i + 1] != '\"')
        return 0;
    }
    return 1;
}
int check()
{
    if (check1() == 0)
    {
        return 0;
    }
    if (check2() == 0)
    {
        return 0;
    }
    if (check3() == 0)
    {
        return 0;
    }
    if (check4() == 0)
    {
        return 0;
    }
    return 1;    
}
int main()
{
    while (1)
    {
        gets(s);
        if (strcmp(s, "#") == 0)
        {
            break;
        }
        l = strlen(s);
        if (check())
        {
            printf("OK\n");
        }
        else
        {
            printf("suspicious\n");
        }
    }    
}
