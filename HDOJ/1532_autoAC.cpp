#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXM=203;
int capacity[MAXM][MAXM];
int flow[MAXM];
int pre[MAXM];
int n,m;
int bfs()
{
    memset(pre,0,sizeof(pre));
    flow[1]=11000000;
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int s=q.front();
        q.pop();
        for(int i=2;i<=m;++i)
            if(capacity[s][i]>0&&pre[i]==0)
            {
                flow[i]=min(flow[s],capacity[s][i]);
                pre[i]=s;
                if(i==m)
                    return flow[m];
                q.push(i);
            }
    }
    return 0;
}
int maxFlow()
{
    int increase;
    int sumflow=0;
    while(increase=bfs())
    {
        sumflow+=increase;
        for(int i=m;i;i=pre[i])
        {
            capacity[pre[i]][i]-=increase;
            capacity[i][pre[i]]+=increase;
        }
    }
    return sumflow;
}
void show()
{
    for(int i=1;i<=m;++i)
    {
        for(int j=1;j<=m;++j)
            cout<<capacity[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int a,b,c;
    while(cin>>n>>m)
    {
        memset(capacity,0,sizeof(capacity));
        for(int i=1;i<=n;++i)
        {
            cin>>a>>b>>c;
            capacity[a][b]+=c;
        }
        cout<<maxFlow()<<endl;
    }
    return 0;
}
