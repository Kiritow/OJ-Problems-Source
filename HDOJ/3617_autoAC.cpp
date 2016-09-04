#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <algorithm>
#define maxn 1010
using namespace std;
int cor[maxn];
struct Tr{
    int a, b;
} r[maxn];
bool cmp(const Tr &a, const Tr &b){
    return (a.a<b.a || a.a==b.a&&a.b<b.b);
}
bool equ(const Tr &a, const Tr &b){
    return (a.a==b.a && a.b==b.b);
}
int n;
void init(){
    scanf("%d", &n);
    for (int i=0; i<n; i++) scanf("%d", &r[i].a);
    for (int i=0; i<n; i++) scanf("%d", &r[i].b);
    sort(r, r+n, cmp);
}
void solve(){
    int i=0, last=0; memset(cor, 0, sizeof cor);
    int ret = 0;
    while (i<n){
        int cnt=1;
        while (i+1!=n && equ(r[i], r[i+1])){
            i++; cnt++;
        }
        while (last!=r[i].a){
            last++;
            cor[last] = max(cor[last], cor[last-1]);
        }
        int tmp = (n+1 - (r[i].a+r[i].b) + 1);
        int maxcor = min(tmp, cnt);
        cor[last+tmp] = max(cor[last+tmp], cor[last] + maxcor);
        ret = max(ret, cor[last+tmp]);
        i++;
    }
    printf("%d\n", ret);
}
int main(int argc, char** argv) {
    int test;
    scanf("%d", &test);
    while (test--){
        init();
        solve();
    }
    return 0;
}
