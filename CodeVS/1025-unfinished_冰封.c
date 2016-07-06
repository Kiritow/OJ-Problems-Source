/*
作者:千里冰封
题目:p1025 选菜
*/

#include<stdio.h>
const int size = 101;
int k, n, d[size], c[size], m[size], dp[size];
double x, v[size];
int isin(int idx){
    int i;
    for(i= 0; i < k; i++)
        if(idx == i) return 1;
    return 0;
}
int main(){
    scanf("%d%d%lf", &n, &k, &x);
    int i;
    for(i = 0; i < n; i++)
        scanf("%d", &d[i]);
    for(i = 0; i < n; i++)
        scanf("%lf", &v[i]);
    for(i = 0; i < n; i++)
        scanf("%d", &c[i]);
    for(i = 0; i < k; i++)
        scanf("%d", &m[i]);
    for(i = 0; i < n; i++){
        int j;
        for(j = n - 1; j >= v[i]; j++){
            
        }
    }
    for(;;);
    return 0;
}
