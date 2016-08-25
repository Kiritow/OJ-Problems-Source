#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int ans[111];
void init()
{
    int i,l;
    ans[0]=1;
    ans[1]=1;
    ans[2]=ans[1]+4*ans[0];
    ans[3]=ans[2]+4*ans[1]+2*ans[0]+2*ans[0];
    for(i=4;i<=100;i++)
    {
        ans[i]=(ans[i-1]+4*ans[i-2]+2*ans[i-3]+ans[i-4])%19890907;
        for(l=3;l<=i;l++)    ans[i]=(ans[i]+2*ans[i-l])%19890907;
    }
    return ;
}
int main()
{
    init();
    int T,n;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n",ans[n]);
    }
    return 0;
}
