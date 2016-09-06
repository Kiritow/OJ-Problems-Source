#include<cstdio>
#include<cstring>
#define MAXN 1000010
char str[MAXN];
bool isOK(int len) {
    if (str[0] != 'M') {
        return false;
    }
    for (int i = 1; i < len; i++) {
        if (str[i] == 'M') {
            return false;
        }
    }
    return true;
}
int main() {
    int T;
    int len;
    int cnt;
    int i;
    scanf("%d", &T);
    while (T--) {
        scanf(" %s", str);
        len = strlen(str);
        if (isOK(len)) {
            cnt = 0;
            for (i = 1; i < len; i++) {
                if (str[i] == 'U') {
                    cnt += 3;
                } else {
                    cnt++;
                }
            }
            if (len == 2 && str[1] == 'I') {
                puts("Yes");
            } else if (cnt % 6 == 2 || cnt % 6 == 4) {
                puts("Yes");
            } else {
                puts("No");
            }
        } else {
            puts("No");
        }
    }
    return 0;
}
