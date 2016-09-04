#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
#define N 100010
char s[N];
int nextval[N];
int len;
void getnext(const char *s)
{
    int i = 0, j = -1;
    nextval[0] = -1;
    while(i != len)
    {
        if(j == -1 || s[i] == s[j])
            nextval[++i] = ++j;
        else
            j = nextval[j];
    }
}
int main()
{
    int ncase;
    int length, add;
    scanf("%d", &ncase);
    while(ncase--)
    {
        scanf("%s", s);
        len = strlen(s);
        getnext(s);
        length = len - nextval[len]; 
        if(len != length && len % length == 0) 
            printf("0\n");
        else
        {
            add = length - nextval[len] % length; 
            printf("%d\n",add);
        }
    }
    return 0;
}
