#include<stdio.h>
__int64 prime[16]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
__int64 n,cnter,ans;
void dfs(__int64 cur,__int64 cnt,__int64 power,__int64 sub)
{
    __int64 i;
    if(cur>n)
        return;
    if(cnt==cnter&&cur<ans)
        ans=cur;
    if(cnt>cnter)
    {
        ans=cur;
        cnter=cnt;
    }
    __int64 p=prime[sub];
    for(i=1;i<=power;i++)
    {
        if(cur*p>n)
            break;
        dfs(cur*p,cnt*(i+1),i,sub+1);
        p=p*prime[sub];
    }
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        scanf("%I64d",&n);
        cnter=0,ans=0;
        dfs(1,1,50,0);
        printf("Case #%d: %I64d\n",t,ans);
    }
    return 0;
}
