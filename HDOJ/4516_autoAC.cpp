#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cctype>
#include <vector>
using namespace std;
char str[500];
int seq[10];
long long _pow(int a, int b) {
    long long ret = 1;
    for (int i = 0; i < b; ++i) {
        ret *= a;
    }
    return ret;
}
int jiechen[10] = {1, 1, 2, 6, 24, 120};
void qiudao(int *rec, int k) {
    for (int i = k; i <= 5; ++i) {
        rec[i-k] = jiechen[i] / jiechen[i-k] * seq[i];
    }
}
bool judge(int rec[], int x) {
    long long sum = 0;
    for (int i = 0; i <= 5; ++i) {
        sum += 1LL * rec[i] * _pow(x, i);
    }
    return sum == 0;
}
void gao(char ts[]) {
    int len = strlen(ts);
    int p = -1, a, b;
    for (int i = 0; i < len; ++i) {
        if (ts[i] == 'x') {
            if (isdigit(ts[i-1])) { 
                ts[i] = '\0';
            } else {
                ts[i] = '1';
            }
            p = -2;
        } else if (ts[i] == '^') {
            ts[i] = '\0';
            p = i+1;    
        }
    }
    a = atoi(ts);
    if (!a && p != -1) a = 1;
    if (p == -1) {
        b = 0;
    } else if (p == -2) {
        b = 1;
    }else {
        b = atoi(ts+p);
    }
    seq[b] += a;
}
void solve() {
    vector<int>v;
    int cnt = 0;
    memset(seq, 0, sizeof (seq));
    char ts[50], *p;
    p = strtok(str, "+");
    while (p) {
        strcpy(ts, p);
        gao(ts);
        p = strtok(NULL, "+");
    }
    for (int i = 5; i >= 0; --i) {
        if (seq[i] != 0) {
            cnt = i;
            break;
        }
    }
    for (int i = -1000; i <= 1000; ++i) { 
        for (int j = 0; j < cnt; ++j) {
            int rec[10]    = {0};
            qiudao(rec, j);
            if (judge(rec, i)) {
                v.push_back(i);
            } else {
                break;
            }
        }
    }
    if (v.size() != cnt || seq[cnt] != 1 || cnt == 0) {
        printf("-1\n");
    } else {
        sort(v.begin(), v.end());
        for (int i = v.size()-1; i >= 0; --i) {
            if (v[i] < 0) {
                printf("(x+%d)", -v[i]);
            } else if (v[i] == 0) {
                printf("x");    
            } else {
                printf("(x-%d)", v[i]);    
            }
        }
        puts("");
    }
}
int main() {
    int T, ca = 0;
    scanf("%d", &T);
    while (T--) {
        scanf("%s", str);
        int len = strlen(str);
        for (int i = 0; i < len; ++i) {
            if (str[i] == '-') {
                for (int j = len-1; j >= i; --j) {
                    str[j+1] = str[j];
                }
                str[i] = '+';
                len += 1;
                ++i;
                str[len] = '\0';
            }
        }
        printf("Case #%d: ", ++ca);
        solve();
    }
    return 0;
}
