#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXV 500
#define MAXE 1000
#define INF 0x7fffffff
int list[MAXV];
char s[MAXV];
int f[MAXV + 1][26];
bool equal[MAXV];
int n;
struct Edge {
    int ed, next;
} edge[MAXE];
int head[MAXV], nEdge;
void init() {
    memset(head, 0xff, sizeof(head));
    nEdge = 0;
}
void addEdge(const int a, const int b) {
    edge[nEdge].ed = b;
    edge[nEdge].next = head[a];
    head[a] = nEdge++;
}
bool find(int cur, int tar){
    int i, p;
    if (cur >= n) return false;
    if (tar >= n) return true;
    for (i = head[cur]; ~i; i = edge[cur].next){
        p = edge[i].ed;
        if (p == tar) return true;
        return find(p, tar);
    }
    return false;
}
int imin(int a, int b){
    return a < b ? a : b;
}
void calc(){
    int i, j, k;
    for (i = 0; i < n - 1; i++){
        equal[i] = find(list[i + 1] + 1, list[i] + 1);
    }
    equal[i] = true;
    for (i = n - 1; i >= 0; i--){
        for (j = 0; j < 26; j++){
            f[i][j] = n + 1;
            for (k = j + 1 - equal[i]; k < 26; k++){
                f[i][j] = imin(f[i + 1][k], f[i][j]);
            }
            if (s[list[i]] != j + 'a') f[i][j]++;
        }
    }
    j = n + 1;
    for (i = 0; i < 26; i++)
        j = imin(j, f[0][i]);
    if (j > n) j = -1;
    printf("%d\n", j);
}
int main(){
    int i;
    while(scanf("%d", &n) != EOF){
        scanf("%s", s);
        init();
        memset(f, 0, sizeof(f));
        memset(equal, 0, sizeof(equal));
        for (i = 0; i < n; i++) scanf("%d", &list[i]);
        for (i = 0; i < n - 1; i++){
            addEdge(list[i + 1], list[i]);
        }
        calc();
    }
    return 0;
}
