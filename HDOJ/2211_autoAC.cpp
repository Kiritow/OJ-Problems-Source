#include<stdio.h>
int main()
{
    int dfs(int n,int k);
    int t;
    int n,k;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&k);
        printf("%d\n",dfs(n,k));
    }
    return 0;
}
int dfs(int n,int k)
{
    int num;
    if(n==k)
    {
        return k;
    }
    num=dfs(n-n/k,k);
    return ((num-1)/(k-1)+num);
}
