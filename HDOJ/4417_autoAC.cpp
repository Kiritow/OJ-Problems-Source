#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 100010;
struct dit{
    int num,id;
}dd[N];
struct ask{
    int lp,rp,value,id;
}aa[N];
int cnt[N];
bool cmp1(dit a,dit b){
    return a.num < b.num;
}
bool cmp2(ask a,ask b){
    return a.value < b.value;
}
int inline lowbit(int x){
    return x & (-x);
}
void inline update(int x){
    while(x < N){
       cnt[x]++;
       x += lowbit(x);
    }
}
int inline sum(int x){
    int s = 0;
    while(x > 0){
      s += cnt[x];
      x -= lowbit(x);
    }
    return s;
}
int main(){
    int numcase;
    scanf("%d",&numcase);
    for(int ca = 1; ca <= numcase; ++ca){
       int n,m;
       memset(cnt,0,sizeof(cnt));
       scanf("%d%d",&n,&m);
       for(int i = 0; i < n; ++i){
          scanf("%d",&dd[i].num);
          dd[i].id = i + 1;
       }
       int x,y;
       for(int i = 0; i < m; ++i){
          scanf("%d%d%d",&x,&y,&aa[i].value);
          aa[i].lp = x + 1;
          aa[i].rp = y + 1;
          aa[i].id = i + 1;
       }
       sort(dd,dd+n,cmp1);
       sort(aa,aa+m,cmp2);
       int ans[N] = {0};
       for(int aski = 0,ditj = 0; aski < m; ++aski){
           while(ditj < n && aa[aski].value >= dd[ditj].num){
              update(dd[ditj].id);
              ditj++;
           }
           ans[aa[aski].id] = sum(aa[aski].rp) - sum(aa[aski].lp - 1);
       }
       printf("Case %d:\n",ca);
       for(int i = 1; i <= m; ++i){
          printf("%d\n",ans[i]);
       }
    }
    return 0;
}
