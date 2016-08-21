#include <stdio.h>
#include <string.h>
int A[10][10],B[10][10];
int vary[10];
bool flag[10];
int small1,small2,min;
void action(int n)
{
    int i,j,val=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[vary[i]][vary[j]]==B[i][j])    continue;
            if(A[vary[i]][vary[j]])
                val+=small2;
            else
                val+=small1;
        }
    }
    if(val<min)    min=val;
}
void DFS(int pos,int n)
{
    int i;
    if(pos==n)    {action(n);    return ; }
    for(i=0;i<n;i++)
    {
        if(flag[i])
        {
            vary[pos]=i;
            flag[i]=false;
            DFS(pos+1,n); 
            flag[i]=true;
        }
    }
}
void solve()
{
    int n,Ma,Mb,Ia,Ib,Da,Db;
    int i,a,b,cas=0;
    while(scanf("%d %d %d",&n,&Ma,&Mb) && n)
    {
        scanf("%d %d %d %d",&Ia,&Ib,&Da,&Db);
        small1=(Ia<Db?Ia:Db);
        small2=(Ib<Da?Ib:Da);
        min=0xfffffff;
        memset(A,0,sizeof(A));
        memset(B,0,sizeof(B));
        for(i=0;i<Ma;i++)
        {
            scanf("%d %d",&a,&b);
            A[a][b]=A[b][a]=1;
        }
        for(i=0;i<Mb;i++)
        {
            scanf("%d %d",&a,&b);
            B[a][b]=B[b][a]=1;
        }
        for(i=0;i<n;i++)    flag[i]=true;
        DFS(0,n);
        printf("Case #%d: %d\n",++cas,min/2);
    }
}
int main()
{
    solve();
    return 0;
}
