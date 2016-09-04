#include <cstdio>
#include <cstring>
#include <cctype>
#define MAX_LEN 1000010
char buf[MAX_LEN];
char *ignore(char *p) {
    while (*p && isspace (*p)) ++p;
    return p;
}
int main() {
    while (gets(buf)) {
        char *p = buf + strlen(buf);
        while (gets(p) != NULL, *p) {
            p += strlen(p);
        }
        p = buf;
        while (*p) {
            p = ignore(p);
            if (*p == 'w') {
                p += 7;
                while (*p != '"') {
                    putchar(*p);
                    ++p;
                }
                puts("");
                break;
            }
            p += 3;
            if (*p == '1') p += 2;
            else {
                p += 2;
                int cnt = 1;
                while (*p && cnt) {
                    p = ignore(p);
                    if (*p == 'w') {
                        while (*p != ')') ++p;
                        ++p;
                        continue;
                    }
                    if (*p == 'i') {
                        ++cnt;
                        p += 5;
                        continue;
                    }
                    if (*p == 'e') {
                        --cnt;
                        p += 4;
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}
