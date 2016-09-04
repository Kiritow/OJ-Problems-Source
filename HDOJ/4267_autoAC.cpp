#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 50010;
int cnt[N][11][11];
int num[N];
int inline lowbit(int x){
    return x & (-x);
}
void inline update(int x,int k,int mod,int add){
    while(x > 0){
      cnt[x][k][mod] += add;
      x -= lowbit(x);
    }
}
int inline sum(int x,int a){
    int s = 0;
    while(x < N){
        for(int i = 1; i <= 10; ++i){
           s += cnt[x][i][a%i];
        }
        x += lowbit(x);
    }
    return s;
}
int main(){
    int n;
    while(scanf("%d",&n) != EOF){
       for(int i = 1; i <= n; ++i)
           scanf("%d",&num[i]);
       memset(cnt,0,sizeof(cnt));
       int m;
       scanf("%d",&m);
       while(m--){
          int op,a,b,k,add;
          scanf("%d",&op);
          if(op == 1){
             scanf("%d%d%d%d",&a,&b,&k,&add);
             update(b,k,a%k,add);
             update(a-1,k,a%k,-add);
          }
          else{
            scanf("%d",&a);
            int ans = sum(a,a);
            printf("%d\n",ans + num[a]);
          }
       }
    }
    return 0;
}
