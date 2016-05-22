#include <stdio.h> 
#include <string.h> 
#define MAX 110000 
#define INF (1<<29) 
#define min(a,b) ((a)<(b)?(a):(b)) 
 
 
struct product { 
     
    int code,st,num,price; 
}arr[MAX],special[MAX]; 
int dp[MAX],hash[1000],n,m,nn,ans; 
int ST[10] = {1,6,36,216,1296,7776,46656,279936}; 
 
 
void Initial() { 
 
    ans = nn = 0; 
    memset(hash,-1,sizeof(hash)); 
    for (int i = 0; i < ST[6]; ++i) 
        dp[i] = INF; 
} 
void Solve_DP() { 
 
    int i,j,k; 
    dp[0] = 0; 
    for (i = 0; i <= nn; ++i) 
        for (j = 0; j < n + m; ++j) 
            dp[i+arr[j].st] = min(dp[i+arr[j].st],dp[i]+arr[j].price); 
    ans = min(ans,dp[nn]); 
} 
 
 
int main() 
{ 
    int i,j,k,tp,num,code; 
 
 
    while (scanf("%d",&n) != EOF) { 
 
        Initial(); 
        for (i = 0; i < n; ++i) { 
 
            scanf("%d%d%d",&arr[i].code,&arr[i].num,&arr[i].price); 
            arr[i].st = ST[i]; 
            hash[arr[i].code] = i; 
            nn += arr[i].num * arr[i].st; 
            ans += arr[i].num * arr[i].price; 
        } 
        scanf("%d",&m); 
        for (i = 0; i < m; ++i) { 
 
            scanf("%d",&k); 
            arr[i+n].st = 0; 
            for (j = 0; j < k; ++j) { 
 
                scanf("%d%d",&code,&num); 
                if (hash[code] == -1) continue; 
                arr[i+n].st += arr[hash[code]].st * num; 
            } 
            scanf("%d",&arr[i+n].price); 
        } 
 
 
        Solve_DP(); 
        printf("%d\n",ans); 
    } 
} 
