#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
const int N = 1010;
const int lim = 24*60;
int T, n, t, k, m;
int cnt[N], last[N];
void print(int time){
    if(time>=lim)   time%=lim;
    printf("%02d:%02d\n", time/60, time%60);
}
int main(){
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d %d", &n, &t, &k, &m);
        memset(cnt,0,sizeof(cnt));
        int hh, mm, a, b;
        int cur = 0;
        for(int i=0; i<m; i++){
            scanf("%d:%d %d %d", &hh, &mm, &a, &b);
            hh = hh*60+mm;
            if(cnt[a]>=b && last[a]>=hh){
                cnt[a]-=b;
                print(last[a]+t);
                continue;
            }
            if(cnt[a] && last[a]>=hh){
                b-=cnt[a];
            }
            int x = (b-1)/k + 1;
            cur = max(cur, hh) + t*x;
            print(cur);
            cnt[a] = x * k - b;
            last[a] = cur - t;
        }
        if(T)   puts("");
    }
    return 0;
}
