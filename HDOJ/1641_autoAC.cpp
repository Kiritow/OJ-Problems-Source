#include<stdio.h>
#include<string.h>
int H,K,ans[15],res;
int judge(int target,int cur,int num,int tot,int *A,int end)
{
    int i,j;
    if(tot==target)
        return 1;
    else if(cur==end||num==H)
        return 0;
    if(judge(target,cur+1,num,tot,A,end))
        return 1;
    if(judge(target,cur,num+1,tot+A[cur],A,end))
        return 1;
    return 0;
}
void dfs(int cur,int *A,int end)
{
    int i,j;
    if(judge(cur,0,0,0,A,end))
        dfs(cur+1,A,end);
    if(end<K)
    {
        A[end]=cur;
        end++;
        dfs(cur+1,A,end);
        end--;
        A[end]=-1;
    }
    if(cur-1>res)
    {
        res=cur-1;
        memcpy(ans,A,sizeof(ans));
    }
}
int main()
{
    int i,j,k,A[15];
    while(1)
    {
        scanf("%d%d",&H,&K);
        if(H==0)
            break;
        memset(A,-1,sizeof(A));
        res=0;
        dfs(1,A,0);
        for(i=0;i<K;i++)
            printf("%3d",ans[i]);
        printf(" ->");
        printf("%3d\n",res);
    }
    return 0;    
}
