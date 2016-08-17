#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;
const int M = 1005;
const int N = 3005;
struct node {
    int to;
    int next;
}num[N];
int ins[M];
int belong[M];
int dfn[M];
int low[M];
int rdu[M];
int sccf[M];
int head[M];
int sum[M];
stack<int>s;
int index, cont;
int ans;
int T, n, m, e, e1;
void init() {
    e = 0;
    index = 1;
    cont = 0;
    e1 = 0;
    memset(num, 0, sizeof(num));
    memset(head, -1, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
    memset(sccf, 0, sizeof(sccf));
    memset(rdu, 0, sizeof(rdu));
    memset(belong, 0, sizeof(belong));
    memset(sum, 0, sizeof(sum));
}
void add(int a, int b) {
    num[e].to = b;
    num[e].next = head[a];
    head[a] = e++;
}
void Tanjian(int u) {  
    int v;
    dfn[u] = low[u] = index++;
    ins[u] = 1;
    s.push(u);
    for(int k = head[u]; k != -1; k = num[k].next) {
        v = num[k].to;
        if(!dfn[v]) {
            Tanjian(v);
            low[u] = min(low[u], low[v]);
        }
        else if(ins[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if(low[u] == dfn[u]) {
        cont++;
        do {
            v = s.top();
            s.pop();
            sccf[v] = cont;
            belong[cont]++;   
            ins[v] = 0;
        }while(u != v);
    }
}
int main()
{
    int a, b;
    while(scanf("%d%d", &n, &m) != EOF) {
     init();
     for(int i = 1; i <= n; i++) {
        scanf("%d", &sum[i]);
     }
    for(int i = 0; i < m; i++) {
        scanf("%d%d", &a, &b);
           add(a, b);
    }
    for(int i = 1; i <= n; i++) {
        if(!dfn[i]) {
            Tanjian(i);
        }
    }
    int v;
    ans = 0;
    int conum = 0;
    for(int i = 1; i <= n; i++) {
        for(int k = head[i]; k != -1; k = num[k].next) {
            v = num[k].to;
            if(sccf[i] != sccf[v]) {
                rdu[sccf[v]]++;
            }
        }
    }
    for(int i = 1; i <= cont; i++) {
        if(rdu[i] == 0) {
            conum++;
        int minn = 99999999;
        for(int j = 1; j <= n; j++) {
            if(sccf[j] == i) {
                minn = min(sum[j], minn);
            }
         }
         ans += minn;
        }
    }
  printf("%d %d\n", conum, ans);
  }
    return 0;
}
