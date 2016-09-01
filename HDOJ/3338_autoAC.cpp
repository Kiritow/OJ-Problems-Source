#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
#define Del(a,b) memset(a,b,sizeof(a))
const int N = 20500;
const int inf = 0x3f3f3f3f;
int n,m;
struct Node
{
    int from,to,cap,flow;
};
vector<int> v[N];
vector<Node> e;
int vis[N];  
int cur[N];
void add_Node(int from,int to,int cap)
{
    e.push_back((Node){from,to,cap,0});
    e.push_back((Node){to,from,0,0});
    int tmp=e.size();
    v[from].push_back(tmp-2);
    v[to].push_back(tmp-1);
}
bool bfs(int s,int t)
{
    Del(vis,-1);
    queue<int> q;
    q.push(s);
    vis[s] = 0;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0;i<v[x].size();i++)
        {
            Node tmp = e[v[x][i]];
            if(vis[tmp.to]<0 && tmp.cap>tmp.flow)  
            {
                vis[tmp.to]=vis[x]+1;
                q.push(tmp.to);
            }
        }
    }
    if(vis[t]>0)
        return true;
    return false;
}
int dfs(int o,int f,int t)
{
    if(o==t || f==0)  
        return f;
    int a = 0,ans=0;
    for(int &i=cur[o];i<v[o].size();i++) 
    {
        Node &tmp = e[v[o][i]];
        if(vis[tmp.to]==(vis[o]+1) && (a = dfs(tmp.to,min(f,tmp.cap-tmp.flow),t))>0)
        {
            tmp.flow+=a;
            e[v[o][i]^1].flow-=a; 
            ans+=a;
            f-=a;
            if(f==0)  
                break;
        }
    }
    return ans;  
}
int dinci(int s,int t)
{
    int ans=0;
    while(bfs(s,t))
    {
        Del(cur,0);
        int tm=dfs(s,inf,t);
        ans+=tm;
    }
    return ans;
}
int mp[250][250];
struct Node1
{
    int x,y,z;
};
Node1 raw[N],col[N];
int solve(int raw_cnt,int id,int s)
{
    int cnt = 0,pos = id+raw_cnt;
    return e[v[pos][1]].flow+1;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        memset(mp,-1,sizeof(mp));
        memset(col,0,sizeof(col));
        memset(raw,0,sizeof(raw));
        int cnt=0,raw_cnt=0,col_cnt=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                string str;
                cin>>str;
                 if(str[0] == '.'){
                    mp[i][j] = ++cnt;
                }else{
                    mp[i][j] = -1;
                    if(str[0] != 'X'){
                        int tmp = (str[0]-'0')*100 + (str[1]-'0')*10 + str[2]-'0';
                        col[++col_cnt].x = i;
                        col[col_cnt].y = j;
                        col[col_cnt].z = tmp;
                    }
                    if(str[4] != 'X'){
                        int tmp = (str[4]-'0')*100 + (str[5]-'0')*10 + str[6]-'0';
                        raw[++raw_cnt].x = i;
                        raw[raw_cnt].y = j;
                        raw[raw_cnt].z = tmp;
                    }
                }
            }
        }
        int start=0,t=col_cnt+cnt+raw_cnt+2;
        for(int i = 1;i <= raw_cnt;i++){
            int x = raw[i].x;
            int y = raw[i].y;
            int cnt_len = 0;
            for(y = y+1;y <= m;y++){
                if(mp[x][y] != -1){
                    cnt_len++;
                    add_Node(i,raw_cnt+mp[x][y],8);
                }
                else   break;
            }
            add_Node(start,i,raw[i].z-cnt_len);
        }
        for(int i = 1;i <= col_cnt;i++){
            int x = col[i].x;
            int y = col[i].y;
            int cnt_len = 0;
            for(x = x+1;x <= n;x++){
                if(mp[x][y] != -1){
                    cnt_len++;
                    add_Node(raw_cnt+mp[x][y],raw_cnt+cnt+i,8);
                }
                else    break;
            }
            add_Node(raw_cnt+cnt+i,t,col[i].z-cnt_len);
        }
        int ans=dinci(start,t);
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j]==-1)
                    printf("_");
                else
                    printf("%d",solve(raw_cnt,mp[i][j],cnt));
                printf("%c",j==m?'\n':' ');
            }
        }
        for(int i=0;i<=t;i++)
            v[i].clear();
        e.clear();
    }
    return 0;
}
