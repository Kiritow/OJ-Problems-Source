#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#define pii pair<int,LL>
using namespace std;
typedef long long LL;
const int N = 100005;
struct Trie {
    Trie *next[2];
    vector<pii> a;
}*root , s[N << 2];
char ope[10];
int tot = 0 , can[N] , ok[1025] , idx = 0;
LL ip (int a , int b , int c , int d) {
    LL ret = 0;
    ret |= (LL)a << 24;
    ret |= (LL)b << 16;
    ret |= (LL)c << 8;
    ret |= d;
    return ret;
}
Trie *newnode () {
    Trie *t = &s[tot ++];
    t -> next[0] = t -> next[1] = NULL;
    t -> a.clear();
    return t;
}
void insert (Trie *p , LL ip , int l , int id) {
    for (int i = 0 ; i < l ; i ++) {
        int c = (ip >> (31 - i)) & 1;
        if (p -> next[c] == NULL)
            p -> next[c] = newnode ();
        p = p -> next[c];
    }
    LL num = ip & ((1 << (32 - l)) - 1);
    p -> a.push_back (make_pair (id , num));
}
void down (LL ip) {
    Trie *p = root;
    for (int i = 31 ; i >= 0 ; i --) {
        int c = (ip >> i) & 1;
        if (p -> next[c] == NULL) return ;
        p = p -> next[c];
        for (int j = 0 ; j < p -> a.size() ; j ++) {
            if (can[p -> a[j].first] && p -> a[j].second <= (ip & ((1 << (i - 1)) - 1)))
                ok[p -> a[j].first] = idx;
        }
    }
}
bool up (LL ip) {
    Trie *p = root;
    for (int i = 31 ; i >= 0 ; i --) {
        int c = (ip >> i) & 1;
        if (p -> next[c] == NULL) return false;
        p = p -> next[c];
        for (int j = 0 ; j < p -> a.size() ; j ++) {
            if (can[p -> a[j].first] && p -> a[j].second <= (ip & ((1 << (i - 1)) - 1)) && ok[p -> a[j].first] == idx)
                return true;
        }
    }
    return false;
}
int main () {
    root = newnode ();
    while (scanf ("%s" , ope) != EOF) {
        if (ope[0] == 'E') {
            int id , k , a , b , c , d , u;
            scanf ("%d %d" , &id , &k);
            for (int i = 0 ; i < k ; i ++) {
                scanf ("%d.%d.%d.%d/%d" , &a , &b , &c , &d , &u);
                insert (root , ip (a , b , c , d) , u , id);
            }
            can[id] = 1;
        }
        else if (ope[0] == 'D') {
            int id;scanf ("%d" , &id);
            can[id] = 0;
        }
        else {
            idx ++;
            int a , b , c , d;
            scanf ("%d.%d.%d.%d" , &a , &b , &c , &d);
            down (ip (a , b , c , d));
            scanf ("%d.%d.%d.%d" , &a , &b , &c , &d);
            puts (up (ip (a , b , c , d)) ? "F" : "D");
        }
    }
    return 0;
}
