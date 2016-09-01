#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int f[55][1005];
void init(){
    for(int i = 1; i < 1001; i ++)
        f[1][i] = i;
    for(int i = 2; i < 51; i ++){
        f[i][1] = 1;
        for(int j = 2; j < 1001; j ++){
            f[i][j] = f[i][j - 1] + 1;;
            for(int k = 2; k < j; k ++){
                f[i][j] = min(f[i][j], max(f[i - 1][k - 1], f[i][j - k]) + 1);
            }
        }
    }
}
int main(){
    int t, T, n, m;
    init();
    scanf("%d", &T);
    while(T --){
        scanf("%d%d%d", &t, &n, &m);
        cout<<t<<" "<<f[n][m]<<endl;
    }
}
