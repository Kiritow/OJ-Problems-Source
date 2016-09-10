#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
const int N = 35;
int n;
int map1[N][N], map2[N][N];
int a1[N][N], a2[N][N], a3[N][N];
void Init() {
    memset(map1, 0, sizeof(map1));
    memset(map2, 0, sizeof(map2));
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &map1[i][j]);
    for(int i = 0; i < n ; i++)
        for(int j = 0; j < n; j++)
            scanf("%d", &map2[i][j]);
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a1[i][j] = map2[j][n-i-1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a2[i][j] = a1[j][n-i-1];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            a3[i][j] = a2[j][n-i-1];
}
int main() {
    while(scanf("%d", &n), n) {
        Init() ;
        int pwd1 = 0, pwd2 = 0, pwd3 = 0, pwd4 = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++) {
                if(map1[i][j] == map2[i][j]) pwd1++;
                if(map1[i][j] == a1[i][j])   pwd2++;
                if(map1[i][j] == a2[i][j])   pwd3++;
                if(map1[i][j] == a3[i][j])   pwd4++;
            }
        int sum = 0;
        if(pwd1 > sum) sum = pwd1;
        if(pwd2 > sum) sum = pwd2;
        if(pwd3 > sum) sum = pwd3;
        if(pwd4 > sum) sum = pwd4;
        printf("%d\n", sum);
    }
    return 0;
}
