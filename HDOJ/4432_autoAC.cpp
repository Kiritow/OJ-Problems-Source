#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
int bit[100];
int cnt;
void change(int n,int base)
{
    cnt=0;
    while(n)
    {
        bit[cnt++]=n%base;
        n/=base;
    }
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        int sum=0;
        int t=(int)sqrt(n*1.0);
        for(int i=1;i<=t;i++)
        {
            if(n%i==0)
            {
                int tmp=i;
                while(tmp)
                {
                    sum+=((tmp%m)*(tmp%m));
                    tmp/=m;
                }
                tmp=n/i;
                if(tmp==i)continue;
                while(tmp)
                {
                    sum+=((tmp%m)*(tmp%m));
                    tmp/=m;
                }
            }
        }
        change(sum,m);
        for(int i=cnt-1;i>=0;i--)
        {
            if(bit[i]>9)printf("%c",bit[i]-10+'A');
            else printf("%d",bit[i]);
        }
        printf("\n");
    }
    return 0;
}
