#include<iostream>
#include<stdio.h>
#include<algorithm>
const int N=3000;
const int inf=1e9;
using namespace std;
struct node
{
    int a,b;
    void read(){ scanf("%d%d",&a,&b); }
    bool operator <(const node tmp)const { return a+b<tmp.a+tmp.b; }
}no[N];
int opt[N][N],n,h;
int solve()
{
    int sum=0;
    for(int i=1;i<=n;i++) sum+=no[i].a;
    for(int j=1;j<=n;j++) opt[0][j]=inf;
    opt[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        opt[i][0]=0;
        for(int j=1;j<=n;j++){
            opt[i][j]=opt[i-1][j];
            if(sum-opt[i-1][j-1]+no[i].b>=h)
                opt[i][j]=min(opt[i][j],opt[i-1][j-1]+no[i].a);
        }
    }
    for(int j=n;j>=0;j--)
        if(opt[n][j]!=inf)
            return j;
}
int main()
{
    while(scanf("%d",&n)!=-1)
    {
        for(int i=1;i<=n;i++)
            no[i].read();
        scanf("%d",&h);
        sort(no+1,no+n+1);
        cout<<solve()<<endl;
    }
    return 0;
}
