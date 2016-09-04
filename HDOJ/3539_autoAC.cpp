#include <map>
#include <set>
#include <list>
#include <queue>
#include <cmath>
#include <stack>
#include <bitset>
#include <cstdio>
#include <cctype>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define lowbit(x) (x&(-x))
#define ff first 
#define ss second 
#define all(c) c.begin(),c.end()
#define PB push_back
#define MP make_pair
#define SZ(a) ((int)a.size())
#define CC(a,b) memset(a,b,sizeof(a))
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define repe(i,a,b) for(int i=(a);i<=(b);i++)
#define reps(i,s) for(int i=0;s[i];i++)
#define repi(it,c) for(typeof(c.begin()) it=c.begin();it!=c.end();it++)
#define inf 0x7f7f7f7f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long 
#define ULL unsigned long long
#define L(x) (x<<1)
#define R(x) (x<<1|1) 
#define maxn 15
#define maxm 505
#define mod 1000000007
#define SQ(x) ((x)*(x))
const double eps=1e-6;
const double pi=acos(-1.0);
template<class Z>inline bool checkmax(Z &a,Z b){if(a==-1||a<b){a=b;return true;}return false;}
template<class Z>inline bool checkmin(Z &a,Z b){if(a==-1||a>b){a=b;return true;}return false;}
template<class Z>inline bool mymax(Z &a,Z b){if(a<b){a=b;return true;}return false;}
template<class Z>inline bool mymin(Z &a,Z b){if(a>b){a=b;return true;}return false;}
int cas=1; void printcase(){printf("Case #%d: ",cas++);}
int pre[maxn][maxn];
int dp[1<<maxn][maxn];
string str[maxn],a[maxn];
int n;
map<string,bool>has;
void init() {
    CC(pre,0);
    CC(dp,-1);
    has.clear();
}
void input() {
    int idx=0,m=0;
    rep(i,0,n) {
        string b;
        cin>>b;
        if(!has[b]) {
            has[b]=true;
            a[idx++]=b;
        }
    }
    n=idx;
    rep(i,0,n) {
        int flag=0;
        rep(j,0,n) {
            if(i==j) continue;
            if(a[j].find(a[i])!=a[j].npos) {
                flag=1; break;
            }
        }
        if(!flag) str[m++]=a[i];
    }
    n=m;
    sort(str,str+n);
}
void initpre() {
    rep(i,0,n) {
        rep(j,0,n) {
            if(i==j) continue;
            rep(k,0,SZ(str[i])) {
                int ii,jj;
                for(ii=k,jj=0;ii<SZ(str[i]);ii++,jj++) {
                    if(str[i][ii]!=str[j][jj]) break;
                }
                if(ii==SZ(str[i])) {
                    pre[i][j]=SZ(str[i])-k;
                    break;
                }
            }
        }
    }
}
void solve() {
    int tol=(1<<n);
    rep(i,0,n) {
        dp[1<<i][i]=str[i].size();
    }
    rep(sta,0,tol) {
        rep(i,0,n) {
            if(dp[sta][i]==-1) continue;
            rep(j,0,n) {
                if(sta&(1<<j)) continue;
                checkmin(dp[sta|(1<<j)][j],dp[sta][i]+SZ(str[j])-pre[j][i]);
            }
        }
    }
    int mini=-1;
    rep(i,0,n) {
        if(dp[tol-1][i]==-1) continue;
        checkmin(mini,dp[tol-1][i]);
    }
    string ans="";
    string temp="";
    int sta=tol-1;
    int p=13;
    while(sta) {
        string a=temp;
        int idx=-1;
        rep(i,0,n) {
            if(dp[sta][i]+temp.size()-pre[p][i]==mini) {
                if(idx==-1) {
                    idx=i;
                    a=a.substr(0,a.size()-pre[p][i])+str[i];
                }
                else {
                    string b=temp;
                    b=b.substr(0,b.size()-pre[p][i])+str[i];    
                    if(a>b) {
                        a=b;
                        idx=i;
                    }
                }
            }
        } 
        temp=a;
        ans+=str[idx];
        p=idx;
        sta^=(1<<idx);
    }
    printcase();
    cout<<temp<<endl;
}
int main() {
    while(~scanf("%d",&n)) {
        init();
        input(); 
        initpre();    
        solve();
    }
}
