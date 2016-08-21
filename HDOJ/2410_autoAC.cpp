#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
char str1[15], str2[15];
LL dfs(int pos, LL cur1, LL cur2) {
    LL ret = 0;
    if (cur1 < cur2) return 0;
    if (cur1 > cur2) {
        ret = 1;
        while (str1[pos]) {
            if (str1[pos] == '?') ret *= 10;
            pos++;
        }
        return ret;
    }
    if (str1[pos] == 0 || str2[pos] == 0) return 0;
    if (str1[pos] == '?') {
        for (int i = 0; i <= 9; i++) {
            if (i < str2[pos] - '0') continue;
            ret += dfs(pos + 1, cur1 * 10 + i, cur2 * 10 + str2[pos] - '0');
        }
    } else {
        ret += dfs(pos + 1, cur1 * 10 + str1[pos] - '0', cur2 * 10 + str2[pos] - '0');
    }
    return ret;
}
int main() {
    while (cin >> str1 && str1[0] != '#') {
        cin >> str2;
        cout << dfs(0, 0, 0) << endl;
    }
    return 0;
}
