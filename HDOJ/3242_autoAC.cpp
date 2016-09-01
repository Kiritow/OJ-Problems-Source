#include <iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 10005;
char str[N];
struct node
{
    char s[81];
    int len;
    int flag;
}list1[N],list2[N];
int n1,n2;
int op;
void solve()
{
    int len = strlen(str);
    memset(list1,0,sizeof(list1));
    memset(list2,0,sizeof(list2));
    n1 = n2 = 0;
    int i,j;
    for(i = 1;i < len;)
    {
        while(str[i] != ',' && str[i] != ']')
            list1[n1].s[list1[n1].len ++] = str[i ++];
        list1[n1].s[list1[n1].len] = '\0';
        n1 ++;
        if(str[i] == ']')
            break;
        i ++;
    }
    i +=2;
    if(str[i] == '+')
        op = 1;
    else
        op = 0;
    i += 4;
    for(;i < len - 1;)
    {
        while(str[i] != ',' && str[i] != ']')
            list2[n2].s[list2[n2].len ++] = str[i ++];
        list2[n2].s[list2[n2].len] = '\0';
        n2 ++;
        i ++;
    }
    if(op == 1)
    {
        printf("[%s",list1[0].s);
        for(i = 1;i < n1;i ++)
            printf(",%s",list1[i].s);
        for(i = 0;i < n2;i ++)
            printf(",%s",list2[i].s);
        printf("]\n");
        return;
    }
    for(i = 0;i < n2;i ++)
    {
        for(j = 0;j < n1;j ++)
        {
            if(list1[j].flag)
                continue;
            if(strcmp(list1[j].s,list2[i].s) == 0)
            {
                list1[j].flag = 1;
                break;
            }
        }
    }
    printf("[");
    for(j = n1 - 1;j >= 0;j --)
        if(list1[j].flag == 0)
            break;
    for(i = 0;i < j;i ++)
    {
        if(list1[i].flag == 0)
            printf("%s,",list1[i].s);
    }
    printf("%s]\n",list1[j].s);
}
int main()
{
    while(gets(str))
    {
        if(str[0] == '.')
            break;
        solve();
    }
    return 0;
}
