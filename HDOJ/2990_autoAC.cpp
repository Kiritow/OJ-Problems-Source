#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int ans;
int n, a, b, y[1005];
void cal(int x){
    int ret1 = 0, ret2 = 0;
    for(int i = 1; i <= n; i++)
    {
        ret1 += y[i] / x;
        if(y[i] % x){
            ret1++;
            ret2 += x - y[i] % x;
        }
    }
    if(b * ret1 * 6 + a * ret2 < ans){
        ans = b * ret1 * 6 + a * ret2;
    }
}
int main()
{
    while(scanf("%d", &n) != EOF &&n){
        scanf("%d%d", &a, &b);
        int Max = -1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &y[i]);
            y[i] = y[i] * 6;
            if(Max < y[i]){
                Max = y[i];
            }
        }
        Max = Max / 3;
        ans = 0x7fffffff;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= 3; j++)
                if(y[i] / j >= Max) {
                    cal(y[i] / j);
                }
        int tmp = 6;
        if(ans % 2 == 0)
            ans /= 2, tmp /= 2;
        if(ans % 3 == 0)
            ans /= 3, tmp /= 3;
        printf("%d", ans);
        if(tmp != 1)
            printf(" / %d", tmp);
        cout << endl;
    }
    return 0;
}
