#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <set>
#include <queue>
#include <string.h>
using namespace std;
#define ll __int64
ll n, m, k;
char s[40], t[40];
void go(ll x, char *S){
    ll top = 1;
    while(x){ S[top++] = ('0'+(x&1));    x>>=1;    }
    S[top] = 0;
}
ll z, o;//n涓0 1涓
ll Zero(ll x){ll ans = 0; while(x){ans += !(x&1);x>>=1;}return ans;}
ll One(ll x){ll ans = 0; while(x){ans += (x&1);x>>=1;}return ans;}
ll work(char *c){
    ll ans = 0, er = 1;
    for(ll i = strlen(c)-1; i>=0; i--, er<<=1)if(c[i]=='1')ans += er;
    return ans;
}
bool ok(ll x){
    if(Zero(x)<z || One(x)<o)return false;
    go(x, t);
    ll len = 0;
    for(ll i = 1, j = 1; s[i] && t[j]; j++)
        if(s[i] == t[j])len++, i++;
    return len == (z+o);
}
int main()
{
    ll i, j, k;
    while(~scanf("%s",s))
    {
        n = work(s);
        scanf("%I64d",&m); 
        if(n==0){puts("0");continue;}
        z = Zero(n), o = One(n);
        go(n, s);
        for(i = 1;;i++)if(ok(i*m))break;
        go(i*m, s);
        for(i=strlen(s+1); i; i--)printf("%c",s[i]);puts("");
    }
    return 0;
}
