#include<iostream>
#include<string.h> 
using namespace std;
int n,m;
int cnt=0;
typedef struct e{
    int data;
    e *next;
}e;
e edge[401];
int v[401];
int a[402],b[402];
int dp[402][402];
void dfs(int s){
    v[s]=1;
    if(s<=n)
        a[cnt]++;
    else
        b[cnt]++;
    e *p=edge[s].next;
    while(p){
        if(!v[p->data])
            dfs(p->data);
        p=p->next;
    }
}
void solve(){
    int i,j,k;
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(k=1;k<=cnt;k++)
        for(i=n/2;i>=a[k];i--)
            for(j=n/2;j>=b[k];j--)
                dp[i][j]=dp[i][j]||dp[i-a[k]][j-b[k]];
    for(i=n/2;i>=0;i--)
        if(dp[i][i])
            break;
    cout<<i<<endl;
}
void bfs(){
    int i,j,k;
    cnt=0;
    memset(v,0,sizeof(v));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(i=1;i<=2*n;i++)
        if(v[i]==0)
        {
            cnt++;
            dfs(i);
        }
}
void read(){
    int i,j,k,s,t;
    int K;
    cin>>K;
    while(K--)
    {
        cin>>n>>m;
        for(i=1;i<=2*n;i++)
        {
            edge[i].data=i;
            edge[i].next=0;
        }
        for(i=1;i<=m;i++)
        {
            cin>>j>>k;
            e *p=new e;
            p->data=k+n;
            p->next=edge[j].next;
            edge[j].next=p;
            e *q=new e;
            q->data=j;
            q->next=edge[k+n].next;
            edge[k+n].next=q;
        }
        bfs();
        solve();
    }
}
int main(){
    read();
    return 0;
}
