#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <stack>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
#define lp (p << 1)
#define rp (p << 1|1)
#define getmid(l,r) (l + (r - l) / 2)
#define MP(a,b) make_pair(a,b)
typedef long long ll;
const int INF = 1 << 30;
const int maxn = 1010;
int n,m,cnt;
int din[maxn],dout[maxn],reb[maxn];
int vis[maxn],first[maxn],nex[maxn * maxn],ver[maxn * maxn],ecnt;
string s,id1,id2;
char name[1500];
map< string,int > mp;
queue<int> q1,q2;
void Add_edge(int u,int v){
    nex[++ecnt] = first[u];
    ver[ecnt] = v;
    first[u] = ecnt;
}
void Init(){
    memset(reb,0,sizeof(reb));
    memset(vis,0,sizeof(vis));
    memset(din,0,sizeof(din));
    memset(dout,0,sizeof(dout));
    memset(first,-1,sizeof(first));
    while(!q1.empty()) q1.pop();
    while(!q2.empty()) q2.pop();
    ecnt = cnt = 0;
    mp.clear();
}
int Topo_count(){
    for(int i = 1; i <= cnt; ++i) if(din[i] == 0){
        if(reb[i] == 0) q1.push(i);
        else q2.push(i);
    }
    int res = 0;
    while(!q1.empty() || !q2.empty()){
        if(q1.empty() && !q2.empty()){
            ++res;
            while(!q2.empty()){
                int x = q2.front(); q2.pop();
                q1.push(x);
            }
        }
        while(!q1.empty()){
            int x = q1.front(); q1.pop();
            vis[x] = 1;
            for(int i = first[x]; i != -1; i = nex[i]){
                int v = ver[i];
                din[v]--;
                if(din[v] == 0){
                    if(!reb[v]) q1.push(v);
                    else q2.push(v);
                }
            }
        }
    }
    return res;
}
int main(){
    int a,b,len,flag;
    scanf("%d",&n);
    getchar();
    getchar();
    for(int Case = 1; Case <= n; ++Case){
        Init();
        while(getline(cin,s) != NULL){
             if(s[0] == '\0')
                 break;
             istringstream sin(s);
             sin >> name;
             flag = 0;
             int len = strlen(name);
             for(int i = 0; i < len; ++i)
                 if(name[i] == '*') flag = 1;
             name[len - 1 - flag] = '\0';
             id1 = name;
             if(mp.find(id1) == mp.end())
                mp[id1]= ++cnt;
             reb[mp[id1]] = flag;
             while(sin >> id2){
                 if(mp.find(id2) == mp.end())
                     mp[id2] = ++cnt;
                 Add_edge(mp[id2],mp[id1]);
                 dout[mp[id2]]++;
                 din[mp[id1]]++;
             }
        }
           printf("Case %d: %d\n",Case,Topo_count());
    }
    return 0;
}
