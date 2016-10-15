#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#pragma comment(linker,"/STACK:102400000,102400000")

using namespace std;
#define   MAX           200010
#define   MAXN          1000005
#define   maxnode       5
#define   sigma_size    30
#define   lson          l,m,rt<<1
#define   rson          m+1,r,rt<<1|1
#define   lrt           rt<<1
#define   rrt           rt<<1|1
#define   middle        int m=(r+l)>>1
#define   LL            long long
#define   ull           unsigned long long
#define   mem(x,v)      memset(x,v,sizeof(x))
#define   lowbit(x)     (x&-x)
#define   pii           pair<int,int>
#define   bits(a)       __builtin_popcount(a)
#define   mk            make_pair
#define   limit         10000

//const int    prime = 999983;
const int    INF   = 0x3f3f3f3f;
const LL     INFF  = 0x3f3f;
//const double PI    = acos(-1.0);
const double inf   = 1e18;
const double eps   = 1e-6;
const LL     mod   = 1e9+7;
const ull    mx    = 133333331;

/*****************************************************/
inline void RI(int &x) {
      char c;
      while((c=getchar())<'0' || c>'9');
      x=c-'0';
      while((c=getchar())>='0' && c<='9') x=(x<<3)+(x<<1)+c-'0';
 }
/*****************************************************/

int mat[55][55];
LL fact[55];
int n,m;
LL ans;
void init(){
    fact[0]=1;
    for(int i=1;i<=50;i++) fact[i]=fact[i-1]*i%mod;
}
LL qpow(LL a,LL n){
    LL ans=1;
    while(n){
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}

LL C(int n,int m){
    return fact[n]*qpow(fact[m],mod-2)%mod*qpow(fact[n-m],mod-2)%mod;
}

int main(){
    //freopen("in.txt","r",stdin);
    int t,kase=0;
    cin>>t;
    init();
    while(t--){
        kase++;
        cin>>n>>m;
        mem(mat,0);
        for(int i=0;i<m;i++){
            int a,b;
            scanf("%d%d",&a,&b);
            mat[a][b]=mat[b][a]=1;
        }
        ans=0;
        if(n>=6){
            for(int i=6;i<=n;i++){
                ans+=C(n,i);
                if(ans>=mod) ans-=mod;
            }
        }
        if(n>=3){
            vector<int> v;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        v.clear();
                        v.push_back(i);
                        v.push_back(j);
                        v.push_back(k);
                        int flag=0;
                        for(int ii=0;ii<v.size();ii++){
                            for(int jj=ii+1;jj<v.size();jj++){
                                for(int kk=jj+1;kk<v.size();kk++){
                                    int a=v[ii];
                                    int b=v[jj];
                                    int c=v[kk];
                                    if(mat[a][b]&&mat[a][c]&&mat[b][c]){
                                        flag=1;

                                    }
                                    if(!mat[a][b]&&!mat[a][c]&&!mat[b][c]){
                                        flag=1;
                                    }
                                    if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        ans+=flag;
                    }
                }
            }
        }
        if(n>=4){
            vector<int> v;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int h=k+1;h<=n;h++){
                            v.clear();
                            v.push_back(i);
                            v.push_back(j);
                            v.push_back(k);
                            v.push_back(h);
                            int flag=0;
                        for(int ii=0;ii<v.size();ii++){
                            for(int jj=ii+1;jj<v.size();jj++){
                                for(int kk=jj+1;kk<v.size();kk++){
                                    int a=v[ii];
                                    int b=v[jj];
                                    int c=v[kk];
                                    if(mat[a][b]&&mat[a][c]&&mat[b][c]){
                                        flag=1;

                                    }
                                    if(!mat[a][b]&&!mat[a][c]&&!mat[b][c]){
                                        flag=1;
                                    }
                                    if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        ans+=flag;
                        }
                    }
                }
            }
        }
        if(n>=5){
            vector<int> v;
            for(int i=1;i<=n;i++){
                for(int j=i+1;j<=n;j++){
                    for(int k=j+1;k<=n;k++){
                        for(int h=k+1;h<=n;h++){
                            for(int hh=h+1;hh<=n;hh++){
                                v.clear();
                                v.push_back(i);
                                v.push_back(j);
                                v.push_back(k);
                                v.push_back(h);
                                v.push_back(hh);
                                int flag=0;
                        for(int ii=0;ii<v.size();ii++){
                            for(int jj=ii+1;jj<v.size();jj++){
                                for(int kk=jj+1;kk<v.size();kk++){
                                    int a=v[ii];
                                    int b=v[jj];
                                    int c=v[kk];
                                    if(mat[a][b]&&mat[a][c]&&mat[b][c]){
                                        flag=1;

                                    }
                                    if(!mat[a][b]&&!mat[a][c]&&!mat[b][c]){
                                        flag=1;
                                    }
                                    if(flag) break;
                                }
                                if(flag) break;
                            }
                            if(flag) break;
                        }
                        ans+=flag;
                            }
                        }
                    }
                }
            }
        }
        ans%=mod;
        printf("Case #%d: ",kase);
        cout<<ans<<endl;
    }
    return 0;
}
