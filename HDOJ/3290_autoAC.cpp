#include<iostream>
#include<algorithm>
#include<vector>
#define MAXN 20000+10
using namespace std;
vector<int> g[MAXN];
int n,v[MAXN],in[MAXN],out[MAXN];
int dfs(int cnt)
{
    if(out[cnt]==0)
        return cnt;
    vector<int> ss;
    for(int i=0;i<out[cnt];i++)
        ss.push_back(dfs(g[cnt][i]));
    sort(ss.begin(),ss.end());
    return ss[(out[cnt]+1)/2-1];
}
int main()
{
    int a;
    while(scanf("%d",&n)==1)
    {
        for(int i=1;i<=n;i++)
            g[i].clear();
        memset(in,0,sizeof(in));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&out[i]);
            for(int j=0;j<out[i];j++)
            {
                scanf("%d",&a);
                g[i].push_back(a);
                in[a]++;
            }
        }
        int root;
        for(int i=1;i<=n;i++)
            if(in[i]==0)
            {
                root=i;
                break;
            }
        printf("%d\n",dfs(root));
    }
    return 0;
}
