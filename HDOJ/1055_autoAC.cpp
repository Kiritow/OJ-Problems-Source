#include "stdio.h"
#include "string"
#define maxn 1001
struct H{
    int val;
    int cost;
    int time;
    void clear() {
        val = cost = time = 0;
    }
}hh[maxn];
int father[maxn];
int main() {
    int n,r,i;
    while(scanf("%d%d",&n,&r),n+r) {
        for(i =1 ; i <= n ; i ++) {
            scanf("%d",&hh[i].cost);
            hh[i].val = hh[i].cost;
            hh[i].time = 1;
        }
        for(i = 1; i < n ; i ++) {
            int a,b;
            scanf("%d%d",&a,&b);
            father[b] = a;
        }
        while(true) {
            int idx = 0;
            for(i = 1 ; i <= n ; i ++) {
                if(i != r && hh[i].time && (idx == 0 || hh[idx].val * hh[i].time < hh[i].val * hh[idx].time)) {
                    idx = i;
                }
            }
            if(idx == 0)    break;
            int f = father[idx];
            hh[f].cost += hh[idx].cost + hh[idx].val * hh[f].time;
            hh[f].val += hh[idx].val;
            hh[f].time += hh[idx].time;
            hh[idx].clear();
        }
        printf("%d\n",hh[r].cost);
    }
    return 0;
}
