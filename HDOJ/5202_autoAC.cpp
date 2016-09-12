#include <stdio.h>
#include <string.h>
const int N = 1005;
char str[N];
int n, pos[N], num, len, cnt;
bool judge() {
    for (int i = 0, j = len - 1; i < len; i++, j--)
        if (str[i] != str[j])
            return false;
    return true;
}
int main() {
    while (scanf("%d", &n) == 1) {
        scanf("%s", str);
        num = 0;
        len = strlen(str);
        for (int i = 0; i < len; i++) {
            if (str[i] == '?') {
                str[i] = 'a';
                pos[num++] = i;
            }
        }
        if (num == 0 && !judge()) {
            printf("%s\n", str);
            continue;
        }
        if (num == 0 && judge() || len == 1) {
            printf("QwQ\n");
            continue;
        }
        if (len & 1) {
            if (!judge()) {
                printf("%s\n", str);
                continue;
            }
            bool flag = judge();
            if (flag && pos[num - 1] != len / 2) {
                str[pos[num - 1]] = 'b';
                printf("%s\n", str);
            }
            else if (flag && pos[num - 1] == len / 2 && num == 1)
                printf("QwQ\n");
            else if (flag && pos[num - 1] == len / 2 && num > 1) {
                str[pos[num - 2]] = 'b';
                printf("%s\n", str);
            }
        }
        else {
            if (judge())
                str[pos[num - 1]] = 'b';
            printf("%s\n", str);
        }
    }
    return 0;
}
