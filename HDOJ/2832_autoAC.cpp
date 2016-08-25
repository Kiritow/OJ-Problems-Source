#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define N 111
int ans[N];
void init()
{
    ans[5]=272400600;
    ans[6]=9717617;
    ans[7]=898515;
    int k,q;
    double t,temp;
    for(k=8;k<=100;k++)
    {
        t=0;
        temp=1;
        q=0;
        while(t<100)
        {
            t+=k/temp;
            temp++;
            q++;
        }
        ans[k]=q;
    }
}
int main()
{
    init();
    int k;
    while(scanf("%d",&k)!=-1)
        printf("%d\n",ans[k]);
    return 0;
}
