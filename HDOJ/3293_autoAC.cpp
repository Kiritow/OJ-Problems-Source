#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
struct NODE
{
    char name[30];
    char lv[30];
    char ori[30];
} girl[505];
int cmp(NODE x,NODE y)
{
    if(strcmp(x.ori,y.ori))
        return strcmp(x.ori,y.ori)<0;
    if(strcmp(x.lv,y.lv))
    {
        if(!strcmp(x.lv,"wonderful"))
            return 1;
        if(!strcmp(y.lv,"wonderful"))
            return 0;
        if(!strcmp(y.lv,"so-so"))
            return 1;
        if(!strcmp(x.lv,"so-so"))
            return 0;
    }
    return strcmp(x.name,y.name)<0;
}
int main()
{
    int n,i,cas = 1;
    while(~scanf("%d",&n))
    {
        for(i = 0; i<n; i++)
            scanf("%s%s%s",girl[i].name,girl[i].ori,girl[i].lv);
        printf("Case %d\n",cas++);
        sort(girl,girl+n,cmp);
        char s[30];
        strcpy(s,girl[0].ori);
        int flag = 1;
        for(i = 0; i<n; i++)
        {
            if(flag)
            {
                printf("%s:\n",s);
                flag = 0;
            }
            printf("          %s %s\n",girl[i].name,girl[i].lv);
            if(strcmp(s,girl[i+1].ori))
            {
                strcpy(s,girl[i+1].ori);
                flag = 1;
            }
        }
    }
    return 0;
}
