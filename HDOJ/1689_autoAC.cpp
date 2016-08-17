#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define maxn 10000+1
using namespace std;
vector<int>mapp[maxn];
int n,m;
int visit[maxn][2];
struct stu
{
    int pre;
    int now;
    int deep;
};
int bfs(int p)
{
    queue<stu>root;
    stu x,y;
    x.pre=-1;
    x.now=p;
    x.deep=0;
    root.push(x);
    while(root.size())
    {
        x=root.front();
        root.pop();
        if(x.now==p&&x.deep>=3&&x.deep%2) return x.deep;
        else if(x.now==p&&x.deep!=0) continue; 
        for(int i=0;i<mapp[x.now].size();i++)
        {
            if(mapp[x.now][i]!=x.pre&&!visit[mapp[x.now][i]][(x.deep+1)%2])
            {
                y.pre=x.now;
                y.now=mapp[x.now][i];
                y.deep=x.deep+1;
                visit[y.now][y.deep%2]=1;
                root.push(y);
            }  
        }
    }
    return 1<<30;
}
int main()
{
    cin.sync_with_stdio(false);
    int t;
    cin>>t;
    int casee=1;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)  mapp[i].clear();
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            mapp[x].push_back(y);
            mapp[y].push_back(x);
        }
        int ans=1<<30;
        for(int i=1;i<=n;i++)
        {
            memset(visit,0,sizeof(visit));
            ans=min(ans,bfs(i));
        }
        cout<<"Case "<<casee++<<": ";
        if(ans!=1<<30) cout<<"JYY has to use "<<ans<<" balls."<<endl;
        else cout<<"Poor JYY."<<endl;
    }
    return 0;
}
