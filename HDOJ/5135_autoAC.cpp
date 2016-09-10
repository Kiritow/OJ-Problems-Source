#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int n, a[12];
double dp[1<<12];
double cal(int a, int b, int c){
    if(a+b<=c)    return 0.0;
    double p = (a+b+c)*0.5;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}
vector<int> V;
int main(){
    while(~scanf("%d", &n) && n){
        memset(dp, 0, sizeof(dp));
        for(int i=0; i<n; i++)    scanf("%d", a+i);
        sort(a, a+n);
        V.clear();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    int st = (1<<i)|(1<<j)|(1<<k);
                    dp[st] = cal(a[i], a[j], a[k]);
                    if(a[i]+a[j]>a[k])    V.push_back(st);
                }
            }
        }
        for(int i=0; i<(1<<n); i++){
            for(int j=0; j<V.size(); j++){
                if(i&V[j])    continue;
                dp[i|V[j]] = max(dp[i|V[j]], dp[i]+dp[V[j]]);
            }
        }
        printf("%.2f\n", dp[(1<<n)-1]);
    }
    return 0;
}
