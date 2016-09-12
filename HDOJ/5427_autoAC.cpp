#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;
struct node
{
    char s[110];
    int a;
}p[1000],t;
int T,n;
int main()
{
    while(~scanf("%d",&T))
    {
        while(T--)
        {
            scanf("%d",&n);
            getchar();
            for(int i=0;i<n;i++)
            {
                gets(p[i].s);
            }
            for(int i=0;i<n;i++)
            {
                int sum=0;
                int len=strlen(p[i].s);
                for(int j=len-4;j<len;j++)
                {
                    sum*=10;
                    sum+=p[i].s[j]-'0';
                }
                p[i].s[len-5]='\0';   
                p[i].a=sum;
            }
            for(int i=0;i<n-1;i++)
            {
                for(int j=0;j<n-1-i;j++)
                {
                    if(p[j].a<p[j+1].a)
                    {
                        t=p[j];
                        p[j]=p[j+1];
                        p[j+1]=t;
                    }
                }
            }
            for(int i=0;i<n;i++)
            printf("%s\n",p[i].s);
        }
    }
}
