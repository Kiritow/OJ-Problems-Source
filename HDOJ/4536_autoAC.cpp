#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 20;
int p[maxn], nervous[maxn], n, m, k, max_cnt;
int att[110][3];
void dfs(int cn) {
    if(max_cnt >= k) return ;
    if(cn >= k) {
        max_cnt = k; return ;
    }
    int a[3], bak[3];
    for(int v=0; v<3; v++) {    
        a[0] = att[cn][v];  
        a[1] = att[cn][(v+1)%3];
        a[2] = att[cn][(v+2)%3];
        bak[0] = nervous[a[0]];  
        bak[1] = nervous[a[1]];
        bak[2] = nervous[a[2]];
        nervous[a[0]] -= 2;
        if(nervous[a[0]] < 1) nervous[a[0]] = 1;
        nervous[a[1]] += 2;
        nervous[a[2]] += 2;
        for(int i=0; i<n; i++) {
            if(p[i] == p[a[1]] && i != a[1]) nervous[i]++;
            if(p[i] == p[a[2]] && i != a[2]) nervous[i]++;
        }
        int flag = true;
        for(int i=0; i<n; i++) {
            if(nervous[i] > 5) {
                max_cnt = max(max_cnt, cn);
                flag = false;
            }
        }
        if(flag) dfs(cn+1);
        for(int i=0; i<n; i++) {
            if(p[i] == p[a[1]] && i != a[1]) nervous[i]--;
            if(p[i] == p[a[2]] && i != a[2]) nervous[i]--;
        }
        nervous[a[0]] = bak[0];
        nervous[a[1]] = bak[1];
        nervous[a[2]] = bak[2];
    }
}
int main(){
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++) {
        scanf("%d%d%d", &n, &m, &k);
        for(int i=0; i<n; i++) {
            scanf("%d", &p[i]);
        }
        for(int i=0; i<n; i++) {
            scanf("%d", &nervous[i]);
        }
        for(int i=0; i<k; i++) {
            scanf("%d %d %d", &att[i][0], &att[i][1], &att[i][2]);
        }
        max_cnt = 0;
        printf("Case #%d: ", kase);
        dfs(0);
        printf("%d\n", max_cnt);
    }
    return 0;
}
