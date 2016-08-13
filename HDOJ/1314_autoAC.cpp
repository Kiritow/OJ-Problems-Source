#include<cstdio>
#include<cmath>
#include<cstring>
int a[40], b[40], ca[40];
void add(int s[], int n) {
    int t = 0, i;
    s[39] += n;
    for (i = 39; i >= 0; --i) {
        s[i] += t;
        t = s[i] / 10;
        s[i] %= 10;
    }
}
void mul(int s[], int n) {
    int t = 0, i;
    for (i = 39; i >= 0; --i) {
        s[i] = s[i] * n + t;
        t = s[i] / 10;
        s[i] %= 10;
    }
}
void sub(int s[], int n) {
    int t = 0, i;
    s[39] -= n;
    for (i = 39; i >= 0; --i) {
        if (s[i] >= 0) {
            break;
        } else {
            s[i + 1]--;
            s[i] += 10;
        }
    }
}
int div_mod(int s[], int n) {
    int t = 0, i;
    for (i = 0; i < 40; ++i) {
        s[i] += 10 * t;
        t = s[i] % n;
        s[i] /= n;
    }
    return t;
}
int is_zero(int s[]) {
    int i;
    for (i = 0; i < 40; ++i)
        if (s[i])
            return 0;
    return 1;
}
char ss[40];
int main() {
    int le, i, ans;
    while (scanf("%s", ss) != EOF) {
        if (ss[0] == '*')
            break;
        le = strlen(ss);
        memset(a, 0, sizeof (a));
        memset(b, 0, sizeof (b));
        memset(ca, 0, sizeof (ca));
        if (ss[0] <= '9' && ss[0] >= '0') {
            for (i = 39; le > 0; --i)
                ca[i] = a[i] = ss[--le] - '0';
            for (i = 39; i >= 0; --i) {
                ans = div_mod(a, 26);
                if (!ans) {
                    b[i] = 26;
                    sub(a, 1);
                } else
                    b[i] = ans;
                if (is_zero(a))
                    break;
            }
            for (i = 0; i < 40; ++i)
                a[i] = ca[i];
        } else if (ss[0] <= 'z' && ss[0] >= 'a') {
            for (i = 39; le > 0; --i)
                b[i] = ss[--le] - 'a' + 1;
            for (i = 0; i < 40; ++i) {
                mul(a, 26);
                add(a, b[i]);
            }
        }
        for (i = 0; i < 40; ++i)
            if (b[i])
                break;
        ans = i;
        for (; i < 40; ++i)
            printf("%c", b[i] + 'a' - 1);
        ans -= 18;
        while (ans--)
            printf(" ");
        for (i = 0; i < 40; ++i)
            if (a[i])
                break;
        for (; i < 40; ++i) {
            printf("%c", a[i] + '0');
            if (i < 39 && i % 3 == 0)
                printf(",");
        }
        printf("\n");
    }
    return 0;
}
