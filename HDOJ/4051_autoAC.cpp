#include <stdio.h>
#include <string.h>
#include <map>
#include <algorithm>
using namespace std;
char ss[4][10], str[600];
int l[5], c[4], n, mul[10], len, cn;
int maxl[5];
char stmp[10];
bool pd(int x);
int a[30], stri;
bool check(int ssx){
    int i, x;
    for (i = 0; ss[ssx][i]; i++){
        if (ss[ssx][i] < 10){
            if (!check(ss[ssx][i])){
                return false;
            }
        }else{
            x = ss[ssx][i];
            if (a[x] == -1){
                a[x] = str[stri];
            }
            if (a[x] != str[stri]) return false;
            stri++;
        }
    }
    return true;
}
bool wk(int x, int p){
    int i;
    if (l[x] > len) return false;
    if (p == c[x]){
        maxl[x] = max(maxl[x + 1], l[x]);
        return pd(x - 1);
    }
    for (i = x + 1; i < n; i++){
        l[x] += l[i];
        ss[x][p] = i;
        if (wk(x, p + 1)) return true;
        l[x] -= l[i];
    }
    ss[x][p] = cn++;
    l[x]++;
    if (wk(x, p + 1)) return true;
    cn--;
    l[x]--;
    ss[x][p] = 0;
    if (wk(x, c[x])) return true;
    return false;
}
bool pd(int x){
    if (mul[x] * maxl[x + 1] < len){
        return false;
    }
    if (x < 0){
        if (l[0] != len) return false;
        memset(a, -1, sizeof(a));
        stri = 0;
        return check(0);
    }
    l[x] = 0;
    if (wk(x, 0)) return true;
    return false;
}
map<char, int> mp;
int main(){
    int i, s, ss;
    while (scanf("%d", &n) != EOF){
        s = 1;
        for (i = 0; i < n; i++){
            scanf("%d", &c[i]);
            s += c[i] - 1;
        }
        ss = 0;
        mul[0] = c[0];
        for (i = 1; i < n; i++){
            mul[i] = mul[i - 1] * c[i];
        }
        l[n] = 1;
        maxl[n] = 1;
        scanf("%s", str);
        mp.clear();
        for (i = 0; str[i]; i++){
            if (mp.count(str[i]) == 0){
                mp[str[i]] = 1;
                ss++;
            }
        }
        if (ss > s){
            printf("No\n");
            continue;
        }
        len = strlen(str);
        if (len <= s){
            printf("Yes\n");
            continue;
        }
        cn = 10;
        if (pd(n - 1)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    return 0;
}
