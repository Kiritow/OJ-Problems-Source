#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
typedef int ll;
const int MAX_N = 10005;
const ll MOD = 123456789;
ll C[105][MAX_N];
ll A[MAX_N],B[MAX_N];
int len;
int lowbit(int x){
  return x&(-x);
}
void add(int x,ll value, int floor){
     while(x<=len){
        C[floor][x]=(C[floor][x]+value)%MOD;
        x+=lowbit(x);
     }
}
ll sum(int x, int floor){
    ll ans=0;
    while(x>0){
         ans=(ans+C[floor][x])%MOD;
         x-=lowbit(x);
    }
    return ans;
 }
int main()
{
     int n,m;
    while(scanf("%d%d",&n,&m)==2){
         for(int i=0; i<n; ++i){
             scanf("%d",&A[i]);
             B[i] = A[i];
         }
         sort( B , B + n );
         len = unique(B,B+n)-B;
         memset(C,0,sizeof(C));
         for(int i =0; i<n; ++i){
             int loc = lower_bound(B,B+len,A[i])-B+1;
             add(loc,1,1);
             for(int j = 2; j<=m ; ++j ){
                ll num = sum(loc-1,j-1);
                add(loc,num,j);
             }
         }
         ll ans = sum(len,m);
         printf("%d\n",ans);
     }
     return 0;
}
