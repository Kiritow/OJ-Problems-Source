#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <deque>
using namespace std;
const int INF = 0x7fffffff;
int N,M,K,hap[102][10020],len[102][10020],f[102][10020],sum[10300];
struct node{
    int hap,dis;
    node() {}
    node(int h,int d):hap(h),dis(d) {}
};
int main(){
    while (scanf("%d%d%d",&N,&M,&K) != EOF && N+M+K){
        ++N;
        memset(f,0,sizeof(f));
        memset(len,0,sizeof(len));
        memset(hap,0,sizeof(hap));
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d",&hap[i][j]);
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                scanf("%d",&len[i][j]);
        for (int i = 1; i <= N; i++){
            deque<node> deq;
            int dis = 0;
            for (int j = 1; j <= M; j++)
                sum[j] = sum[j-1]+hap[i][j];
            for (int j = 0; j <= M; j++){
                dis += len[i][j];
                while (!deq.empty() && deq.front().hap <= f[i-1][j]-sum[j])
                    deq.pop_front();
                deq.push_front(node(f[i-1][j]-sum[j],dis));
                while (!deq.empty() && deq.front().dis-deq.back().dis > K)
                    deq.pop_back();
                f[i][j] = deq.back().hap + sum[j];
            }
            deq.clear();
            dis = 0;
            len[i][M+1] = 0;
            for (int j = M; j >= 0; j--){
                dis += len[i][j+1];
                while (!deq.empty() && deq.front().hap <= f[i-1][j]+sum[j])
                    deq.pop_front();
                deq.push_front(node(f[i-1][j]+sum[j],dis));
                while (!deq.empty() && deq.front().dis - deq.back().dis > K)
                    deq.pop_back();
                f[i][j] = max(f[i][j],deq.back().hap - sum[j]);
            }
        }
        int ans = 0;
        for (int j = 0; j <= M; j++)
            ans = max(ans,f[N][j]);
        printf("%d\n",ans);
    }
    return 0;
}
