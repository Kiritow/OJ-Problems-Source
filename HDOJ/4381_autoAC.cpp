#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int maxn = 2005;
struct node{
    int aa,cor;
    node(){}
    node(int _aa,int _cor){
       aa = _aa;   cor = _cor;
    }
}x1[maxn],x2[maxn];
int n,m;
int dp1[maxn],dp2[maxn];
int sumx1,sumx2;
bool cmp(const node &p,const node &q){
    return p.aa < q.aa;
}
int min(int a,int b)
{
    return a<b?a:b;
}
int main()
{
    int cas,ta=1;
    scanf("%d",&cas);
    while(cas--){
         int i,j;
         scanf("%d%d",&n,&m);
         sumx1 = sumx2 = 1;
         for(i=0; i<m; i++){
             int key,yy,z;
             scanf("%d%d%d",&key,&yy,&z);
             if(key == 1){
                x1[sumx1++] = node(yy,z);
             }else{
                x2[sumx2++] = node(n+1-yy,z);
             }
         }
         sort(x1+1,x1+sumx1,cmp);
         sort(x2+1,x2+sumx2,cmp);
         memset(dp1,0x3f,sizeof(dp1));
         memset(dp2,0x3f,sizeof(dp2));
         dp1[0] = dp2[0] = 0;
         for(i=1; i<sumx1; i++){
             for(j=x1[i].aa; j>=x1[i].cor; j--){
                dp1[j] = min(dp1[j],dp1[j-x1[i].cor]+1);
             }
         }
         for(i=1; i<sumx2; i++){
             for(j=x2[i].aa; j>=x2[i].cor; j--){
                dp2[j] = min(dp2[j],dp2[j-x2[i].cor]+1);
             }
         }
         int ans = 0,anssum = 0,tmp;
         for(i=1; i<=n; i++){
            for(j=0; j<=i; j++){
               tmp = dp1[j] + dp2[i-j];
               if(tmp <= m){
                  if(ans != i){
                    ans = i;   anssum = tmp;
                  }else if(tmp < anssum){
                      anssum = tmp;
                  }
               }
            }
         }
         printf("Case %d: %d %d\n",ta++,ans,anssum);
    }
    return 0;
}
