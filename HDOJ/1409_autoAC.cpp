#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
char s[200];
int pz(int x,int y)
{
    int ys=0,i;
    for(i=x;i<=y;i++)
    {
        if(i==x)
        {
            if(s[i]=='+'||s[i]=='-')
                continue;
            else if(s[i]>='0'&&s[i]<='9')
                ys++;
            else
                return 0;
        }
        else
        {
            if(s[i]>='0'&&s[i]<='9')
                ys++;
            else
            {
                return 0;
            }
        }
    }
    if(ys>0)
        return 1;
    else
        return 0;
}
int pd(int x,int y)
{
    int ys=0,i;
    for(i=x;i<=y;i++)
    {
        if(i==x)
        {
            if((s[i]=='+'||s[i]=='-')||(s[i]>='0'&&s[i]<='9'))
                continue;
            else if(s[i]=='.')
                ys++;
            else
                return 0;
        }
        else
        {
            if(s[i]>='0'&&s[i]<='9')
                continue;
            else if(s[i]=='.')
                ys++;
            else
                return 0;
        }
    }
    if(ys==1)
        return 1;
    else
        return 0;
}
int main()
{
    int t,i,ye,e,T;
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        ye=0;
        gets(s);
        t=strlen(s);
        for(i=0;i<t;i++)
        {
            if(s[i]=='E')
            {
                ye=1;
                e=i;
            }
        }
        if(ye==1)
        {
            if((pz(0,e-1)||pd(0,e-1))&&pz(e+1,t-1))
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(pz(0,t-1)||pd(0,t-1))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
