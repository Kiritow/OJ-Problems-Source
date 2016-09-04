#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,m,k;
int wi[60];
int cnt;
void dfs(int id,int num,int weight)
{
    cnt=max(cnt,weight);
    if(id==k) return ;
    dfs(id+1,num,weight);
    if(weight+wi[id]<=m&&num+1<=n) dfs(id+1,num+1,weight+wi[id]);
}
int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        scanf("%d",&k);
        int tsum;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&wi[i]);
        }
        sort(wi,wi+k);
        tsum=0;
        for(int i=k-1;i>=k-n;i--) tsum+=wi[i];
        if(wi[0]>m) tsum=0;
        if(tsum<=m)
        {
            printf("%d\n",tsum);
            continue;
        }
        cnt=0;
        dfs(0,0,0);
        printf("%d\n",cnt);
    }
    return 0;
}
