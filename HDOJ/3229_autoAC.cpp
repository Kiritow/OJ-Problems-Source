#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <string.h>
const int MAXN = 1000 + 10;
const int INF = 1<<29;
int N, Track[7][MAXN],conflict[128];     
int total[MAXN];                        
int max(int x, int y){
    if (x>y) return x;
    else return y;
}
void Build_Confliction(){
    int K;
    memset(conflict,0,sizeof(int)*128);
    scanf("%d",&K);
    while (K--){
        int t,i,conf = 0;
        scanf("%d",&t);
        for (i=1; i<=64; i*=2){
            conf += (t%10)*i;            
            t = t/10;                       
        }
        for (i=0; i<=127; i++){
            conflict[conf|i] = 1;
        }
    }
    return ;
}
void Build_Cut(){
    int t,k;
    memset(total, 0, sizeof(int)*MAXN);
    for (t=1; t<=N; t++){
        for (k=0; k<=6; k++)
            if (Track[k][t]>0)  
                total[t] |= (1<<(6-k));
    }
}
void init(){
    scanf("%d", &N);
    memset(Track, 0, sizeof(int)*7*MAXN);
    for (int i=0; i<=6; i++){
        int C;
        scanf("%d", &C);
        while (C--){
            int t1,t2;
            char t3;
            scanf("%d%c", &t1, &t3);
            if (t3=='-'){
                scanf("%d", &t2);
                Track[i][t1] = 3; Track[i][t2] = 4;
                for (int j=t1+1; j<t2; j++)
                    Track[i][j] = 2;
            }
            else
                Track[i][t1] = 1;
        }
    }
    Build_Confliction();
    Build_Cut();
    return ;
}
int solve()
{
    int f[MAXN][128],j,k,t,ans = 0;;
    for (t=0; t<=N; t++)
        for (j=0; j<=127; j++)
            f[t][j] = -INF;
    f[0][0] = 0;
    for (t=1; t<=N; t++){
        for (j=0; j<=127; j++)
            if ((j&total[t])==j){    
                int i, add_t = 0, pre = 0, now = 0, j_temp = j;
                for (i=0; i<=6; i++){
                    if (Track[i][t] == 1 && ((1<<(6-i))&j) != 0)
                        add_t++;               
                    if (Track[i][t] == 3 && ((1<<(6-i))&j) != 0){
                        ++add_t;                    
                        now += (1<<(6-i));
                    }
                    if (Track[i][t] == 2 && ((1<<(6-i))&j) != 0){
                        now += (1<<(6-i));           
                        pre += (1<<(6-i));
                    }
                    if (Track[i][t] == 4 && ((1<<(6-i))&j) != 0){
                        ++add_t;                    
                        pre += (1<<(6-i));
                        j_temp -= (1<<(6-i));       
                    }
                }
                if (!conflict[j_temp]){ 
                    for (k=0; k<=127; k++)
                        if (!conflict[k] && ((pre&k)==pre) && f[t-1][k] != -INF)
                            f[t][now] = max(add_t + f[t-1][k], f[t][now]);
                }
            }
    }
    for (j=0; j<=127; j++)
        if (f[N][j]>ans) ans = f[N][j];
    return ans;
}
int main(){
    int T,Cases;
    scanf("%d", &T);
    for (Cases = 1; Cases <= T; Cases++){
        init();
        printf("Case #%d: %d\n", Cases, solve());
    }
    return 0;
}
