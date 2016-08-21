#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#define maxn 1005
#define MAXN 100005
#define mod 1000000000
#define INF 0x3f3f3f3f
#define pi acos(-1.0)
#define eps 1e-6
typedef long long ll;
using namespace std;
int n,m,ans,cnt,tot,flag;
char s[maxn],res[10005][105];
string S,cur,now;
struct Node
{
    int len,id;
    char endc;
    string s;
} tt;
vector<Node> vn[26];
int vis[1005];
bool isok(int pos,int i)
{
    int j,t=S[pos]-'a',len=vn[t][i].len;
    if(len==-1) return 1;
    if(pos+len+1>=tot) return 0;
    if(vn[t][i].endc!=S[pos+len+1]) return 0;
    string ss=S.substr(pos+1,len);
    sort(ss.begin(),ss.end());
    if(ss==vn[t][i].s) return 1;
    return 0;
}
void solve()
{
    int i,j,t;
    vector<int>vs[1005];
    memset(vis,0,sizeof(vis));
    vis[0]=1;
    for(i=0; i<tot; i++)
    {
        if(!vis[i]) continue ; 
        t=S[i]-'a';
        for(j=0; j<vn[t].size(); j++) 
        {
            if(isok(i,j))
            {
                int next=i+vn[t][j].len+2;
                if(vis[next]==0)
                {
                    if(vis[i]==1)
                    {
                        vis[next]=1;
                        vs[next]=vs[i];
                        vs[next].push_back(vn[t][j].id);
                    }
                    else vis[next]=2;
                }
                else vis[next]=2;
            }
        }
    }
    if(vis[tot]==0) printf("impossible\n");
    else if(vis[tot]==2) printf("ambiguous\n");
    else
    {
        for(i=0; i<vs[tot].size()-1; i++)
        {
            printf("%s ",res[vs[tot][i]]);
        }
        printf("%s\n",res[vs[tot][i]]);
    }
}
int main()
{
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        for(i=0; i<26; i++) vn[i].clear();
        scanf("%s",s);
        S=s;
        tot=S.length();
        scanf("%d",&cnt);
        for(i=1; i<=cnt; i++)
        {
            scanf("%s",res[i]);
            cur=res[i];
            int len=cur.length();
            tt.id=i;
            if(len==1)
            {
                tt.len=-1;
                tt.s="";
                tt.endc=res[i][0];
                vn[res[i][0]-'a'].push_back(tt);
            }
            else
            {
                tt.len=len-2;
                tt.s=cur.substr(1,len-2);
                tt.endc=res[i][len-1];
                sort(tt.s.begin(),tt.s.end());
                vn[res[i][0]-'a'].push_back(tt);
            }
        }
        solve();
    }
    return 0;
}
