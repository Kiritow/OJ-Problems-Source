#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
const int MAXN = 100000;
int prime[MAXN+1];
void getPrime(){
    memset(prime,0,sizeof(prime));
    for(int i = 2;i <= MAXN;i++){
        if(!prime[i])prime[++prime[0]] = i;
        for(int j = 1;j <= prime[0] && prime[j] <= MAXN/i;j++){
            prime[prime[j]*i] = 1;
            if(i%prime[j] == 0)break;
        }
    }
}
int factor[100][2];
int fatCnt;
inline int getFactor(int x){
    fatCnt = 0;
    for(int i = 1;prime[i] <= x/prime[i];i++)
        if(x%prime[i] == 0){
            factor[fatCnt][0] = prime[i];
            factor[fatCnt][1] = 0;
            while(x%prime[i] == 0){
                factor[fatCnt][1]++;
                x /= prime[i];
            }
            fatCnt++;
        }
    if(x != 1){
        factor[fatCnt][0] = x;
        factor[fatCnt++][1] = 1;
    }
    return fatCnt;
}
int a[100010];
int num[100010];
int two[20];
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    two[0] = 1;
    for(int i = 1;i < 20;i++)
        two[i] = two[i-1]<<1;
    getPrime();
    while(T--){
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            getFactor(a[i]);
            for(int j = 0;j < two[fatCnt];j++){
                int tmp = 1;
                for(int k = 0;k < fatCnt;k++)
                    if(j&two[k]){
                        tmp *= factor[k][0];
                    }
                num[tmp]++;
            }
        }
        long long ret = 0;
        for(int i = 0;i < n;i++){
            getFactor(a[i]);
            int cc = 0;
            for(int j = 0;j < two[fatCnt];j++){
                int tmp = 1;
                int cnt = 0;
                for(int k = 0;k < fatCnt;k++)
                    if(j&two[k]){
                        cnt++;
                        tmp *= factor[k][0];
                    }
                if(cnt&1)cc -= num[tmp];
                else cc += num[tmp];
            }
            if(a[i] == 1)cc--;
            ret += (long long)cc*(n-1-cc);
        }
        long long tot = (long long)n*(n-1)*(n-2)/6;
        printf("%I64d\n",tot-ret/2);
    }
    return 0;
}
