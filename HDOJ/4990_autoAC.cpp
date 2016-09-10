#include <iostream>     
#include <stdio.h>     
#include <cmath>     
#include <algorithm>     
#include <iomanip>     
#include <cstdlib>     
#include <string>     
#include <memory.h>     
#include <vector>     
#include <queue>     
#include <stack>     
#include <map>   
#include <set>   
#include <ctype.h>     
#include <sstream> 
#define INF 1000000000 
#define ll long long 
#define min3(a,b,c) min(a,min(b,c)) 
#define max3(a,b,c) max(a,max(b,c)) 
#define MAXN 100010 
using namespace std;   
ll a,b,c,d;
ll n,m;
ll fun(ll a,ll b,ll c,ll d,ll n){
    ll ta=1;
    ll tb=0;
    ll tc=0;
    ll td=1;
    while(n){
        ll aa,bb,cc,dd;
        if(n&1){
            aa=a*ta+b*tc;
            bb=a*tb+b*td;
            cc=c*ta+d*tc;
            dd=c*tb+d*td;
            ta=aa; tb=bb; tc=cc; td=dd;
            ta%=m; tb%=m; tc%=m; td%=m;
        }
        aa=a*a+b*c;
        bb=a*b+b*d;
        cc=c*a+d*c;
        dd=c*b+d*d;
        a=aa; b=bb; c=cc; d=dd;
        a%=m; b%=m; c%=m; d%=m;
        n>>=1;
    }
    return tb;
}
int main(){
    while(~scanf("%I64d%I64d",&n,&m)){
        ll nn=(n+1)/2;
        ll ans=fun(4,1,0,1,nn);
        if(n%2==0)ans*=2;
        ans%=m;
        printf("%I64d\n",ans);
    }
    return 0;
}
