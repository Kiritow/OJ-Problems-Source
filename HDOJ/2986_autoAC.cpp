#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
map<string, int> val;
int con(char *str) {
    int a, b;
    sscanf(str, "%d.%d", &a, &b);
    return a * 10 + b;
}
bool check(int a, int b, char *p) {
    if (!strcmp(p, "=")) return a == b;
    if (!strcmp(p, "<=")) return a <= b;
    if (!strcmp(p, ">=")) return a >= b;
    if (!strcmp(p, "<")) return a < b;
    if (!strcmp(p, ">")) return a > b;
    return false;
}
int main() {
    int n, m;
    char buf[2][100];
    while (cin >> n >> m) {
        for (int i = 0; i < n; i++) {
            for (int i = 0; i < 2; i++) cin >> buf[i];
            val[buf[0]] = con(buf[1]);
        }
        for (int cas = 1; cas <= m; cas++) {
            int sum = 0;
            while (true) {
                cin >> buf[0];
                sum += val[buf[0]];
                cin >> buf[0];
                if (buf[0][0] != '+') break;
            }
            int x;
            cin >> x;
            cout << "Guess #" << cas << " was " << (check(sum, x * 10, buf[0]) ? "correct." : "incorrect.") << endl;
        }
    }
    return 0;
}
