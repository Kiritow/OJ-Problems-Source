#include<stdio.h>
__int64 T,n,tag;
__int64 ans,mod[11]={0,1},dig[11];
__int64 i,j,k,t;
struct node
{
    __int64 id,val;
}que[100000001];
__int64 wei(__int64 x)
{
    __int64 z=1;
    if(!x) return 0;
    while(x/=10) z++;
    return z;
}
__int64 cmp(__int64 a, __int64 b, __int64 k)
{
    while(k--)
    {
        if(a%10!=b%10) return 0;
        a/=10;b/=10;
    }
    return 1;
}
__int64 bfs(__int64 x)
{
    __int64 t=0,pop=0,push=1,i,j,bl,ans,sw,k=0;
    que[0].id=que[0].val=0;ans=sw=0x7fffffff;
    while(pop<push)
    {
        t=que[pop].val;
        k=que[pop++].id+1;
        if(cmp(t*t,x,wei(x))) 
        {
            ans=t<ans?t:ans;
            sw=wei(ans);
        }
        if(wei(t)>=wei(x)) return 0;
        if(k>sw) continue;
        for(i=0;i<10;i++)
        {
            if(cmp((i*mod[k]+t)*(i*mod[k]+t),x%mod[k+1],k))
            {
                if(cmp((i*mod[k]+t)*(i*mod[k]+t),x,wei(x)))
                {
                    ans=(i*mod[k]+t)<ans?(i*mod[k]+t):ans;
                    sw=wei(ans);
                    continue;
                }
                if(k>=sw) continue;
                que[push].val=i*mod[k]+t;
                que[push++].id=k;
            }
        }
    }
    if(ans==0x7fffffff) return 0;
    return ans;
}
int main()
{
    scanf("%I64d",&T);
    for(i=2;i<=10;i++) mod[i]=mod[i-1]*10;
    while(T--)
    {
        scanf("%I64d",&tag);
        ans=bfs(tag);
        if(ans) printf("%I64d\n",ans);
        else printf("None\n");
    }
    return 0;
}
