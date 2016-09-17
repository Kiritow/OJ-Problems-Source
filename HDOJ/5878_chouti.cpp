#include<map>
#include<stack>
#include<queue>
#include<cstdio>
#include<string>
#include<vector>
#include<cstring>
#include<complex>
#include<iostream>
#include<assert.h>
#include<algorithm>
using namespace std;
#define inf 1001001001
#define infll 1001001001001001001LL
#define ll long long
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl
#define gmax(a,b) (a)=max((a),(b))
#define gmin(a,b) (a)=min((a),(b))
#define Ri register int
#define gc getchar()
#define il inline
#include<set>
il int read(){
    bool f=true;Ri x=0;char ch;while(!isdigit(ch=gc))if(ch=='-')f=false;while(isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=gc;}return f?x:-x;
}
#define gi read()
ll p[10000],_p;
set<ll>q;
int main(){
    q.insert(1);
    int cnt=0;
    while(!q.empty()){
        p[++_p]=*q.begin();
        q.erase(p[_p]); 
        ll t=p[_p];
        if(t>1000000000){break;}
        if(2*t<=1000000000)q.insert(2*t);
        if(3*t<=1000000000)q.insert(5*t);
        if(5*t<=1000000000)q.insert(3*t);
        if(7*t<=1000000000)q.insert(7*t);
    }
    int T=gi;
    while(T--){
        int n=gi;
        int pos = lower_bound(p+1, p+_p+1, n) - p;
        printf("%I64d\n", p[pos]);
    }
}
