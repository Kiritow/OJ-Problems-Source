#include<iostream>
#include<algorithm>
#include<string.h>
#include<stdio.h>
using namespace std;
typedef struct shop
{
    int price;
    char name[35];
}shop;
shop a[10005];
shop M;
bool cmp(shop b,shop c)
{
     return strcmp(b.name,c.name)>0;
}
int erfen(int n,char s[])
{
    int low=1,high=n,t;
    while(low<=high)
    {
        t=(low+high)/2;
        if(strcmp(s,a[t].name)==0)
            break;
        else if(strcmp(s,a[t].name)>0)
            high=t-1;
        else
            low=t+1;
    }
    return t;
}
int main()
{
    int n,m,count;
    int i,j;
    char s[35];
    int price,tem;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            scanf("%s",a[i].name);
            a[i].price=0;
        }
        M.price=0;
        scanf("%d",&m);
        sort(a+1,a+n+1,cmp);
        for(i=1;i<=m;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%d%s",&price,s);
                if(strcmp(s,"memory")==0)
                {
                    M.price+=price;
                }
                tem=erfen(n,s);
                a[tem].price+=price;
            }
            count=0;
            for(j=1;j<=n;j++)
            {
                if(a[j].price>M.price)
                    count++;
            }
            printf("%d\n",count+1);
        }
    }
}
