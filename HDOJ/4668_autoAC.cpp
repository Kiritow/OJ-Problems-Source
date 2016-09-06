#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <algorithm>
#define lson step << 1
#define rson step << 1 | 1
#pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
typedef long long LL;
const int N = 5005;
struct Node {
    string s;
    int cnt;
    Node () {}
    Node (string _s , int c) :s(_s) , cnt(c) {}
    string cat () {
        string t = s;
        for (int i = 1 ; i < cnt ; i ++)
            s = s + t;
        cnt = 1;
        return s;
    }
    LL len () {
        return (LL)s.size() * cnt;
    }
    string prefix (int l) {
        string str = s;
        for (int i = 1 ; i < cnt && str.size() < l ; i ++) {
            str += s;
        }
        return str.substr (0 , l);
    }
    string suffix (int l) {
        string str = s;
        for (int i = 1 ; i < cnt && str.size() < l ; i ++) {
            str += s;
        }
        return str.substr (str.size() - l , l);
    }
}a[N];
char str[N] , pat[N];
int ne[N] , idx , l , p;
void get_next (char *s , int l) {
    ne[0] = -1;
    int i = 0 , j = -1;
    while (i < l) {
        if (j == -1 || s[i] == s[j]) {
            i ++; j ++;
            ne[i] = j;
        }
        else j = ne[j];
    }
}
void gao (string s , int tot) {
    if (s == "") return ;
    if (idx == 0 || s.size() * tot >= p || a[idx - 1].len() >= p) {
        a[idx ++] = Node (s , tot);
    }
    else {
        a[idx - 1].cat ();
        a[idx - 1].s += Node (s , tot).cat();
    }
} 
int match (string s , char *t , int p) {
    int l = s.size() ;
    int i = 0 , j = 0 , ans = 0;
    while (i < s.size()) {
        if (j == - 1 || s[i] == t[j]) {
            i ++; j ++;
            if (j == p) {
                ans ++;
                j = ne[j];
            }
        }
        else j = ne[j];
    }
    return ans;
} 
int main () {
    while (scanf ("%s %s" , str , pat) != EOF) {
        idx = 0;
        l = strlen (str);p = strlen (pat);
        get_next (pat , p);
        string s = "";
        int tot = 1;
        for (int i = 0 ; i < l ; i ++) {
            if (str[i] == '[') {
                if (s == "") continue;
                gao (s , tot);
                s = ""; tot = 1;
            }
            else if (str[i] == ']') {
                tot = 0;
                i ++;
                while (isdigit(str[i]))
                    tot = tot * 10 + str[i ++] - '0';
                i --;
                gao (s , tot);
                s = ""; tot = 1;
            }
            else s += str[i];
        }
        gao (s , tot);
        s = ""; tot = 1;
        LL ans = 0;
        for (int i = 0 ; i < idx ; i ++) {
            if (a[i].len() < p) continue;
            if (a[i].cnt == 1) ans += match (a[i].s , pat , p);
            else {
                int use = min(a[i].cnt , 1 + (p - 1 + (int)a[i].s.size() - 1) / (int)a[i].s.size());
                string s = "";
                for (int j = 1 ; j < use ; j ++) {
                    s += a[i].s;
                }
                s = a[i].s + s.substr (0 , min ((int)s.size() , p - 1));
                int tmp = match (s , pat , p);
                ans += (LL)tmp * (a[i].cnt - use + 1);
                if (p) {
                    s = "";
                    for (int j = 1 ; j < use ; j ++)
                        s += a[i].s;
                    ans += match (s , pat , p);
                }
            }
        }
        for (int i = 0 ; i < idx - 1 ; i ++) {
            s = a[i].suffix (min (a[i].len () , p - 1LL));
            if (a[i + 1].len () < p - 1) {
                s += a[i + 1].cat ();
                if (i + 2 < idx) {
                    s += a[i + 2].prefix (min (a[i + 2].len () , p - 1 - a[i + 2].len ()));
                }
            }
            else {
                s += a[i + 1].prefix (min (a[i + 1].len () , p - 1LL));
            }
            ans += match (s , pat , p);
        }
        printf ("%I64d\n" , ans);
    }
    return 0;
}
