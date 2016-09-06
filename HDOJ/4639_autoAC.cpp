#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int V = 5050 + 50;
const int MaxN = 500 + 5;
const int mod = 10000 + 7;
int T, ans, num[V];
char ch[10100];
int main() {
    int i, j, k;
    scanf("%d", &T);
    num[0] = num[1] = 1;
    for(i = 2; i <= V; ++i)
        num[i] = (num[i - 1] + num[i - 2]) % mod;
    for(i = 1; i <= T; ++i) {
        ans = 1;
        int sum = 0;
        scanf("%s", &ch);
        int len = strlen(ch);
        for(j = 1; j < len; ++j) {
            if(ch[j] == 'e' && ch[j - 1] == 'h') {
                sum++;
                j++;
            }
            else {
                ans = (ans * num[sum]) % mod;
                sum = 0;
            }
        }
        ans = (ans * num[sum]) % mod;
        printf("Case %d: %d\n", i, ans);
    }
}
