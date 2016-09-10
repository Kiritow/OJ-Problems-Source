#include <cstdio>
#include <cstring>
#define LEN 100
#define HLE 50
using namespace std;
typedef struct fbn {
    int a[LEN];
    int pn;
    void init() {
        memset(a, 0, sizeof(a));
        pn = 0;
    }
    void print() {
        bool b = false;
        for (int i = 0; i < HLE; i++) {
            if (a[i] != 0) b = true;
            if (b == true) printf("%d", a[i]);
        }
        if (pn != 0) {
            printf(".");
            for (int i = 0; i < pn; i++)
                printf("%d", a[i + HLE]);
        }
        printf("\n");
    }
}FBN;
bool check(FBN a)
{
    bool t = true;
    for (int i = 0; i < LEN; i++) {
        if (a.a[i] > 1) {t = false; break;}
        if ((i != LEN - 1) && a.a[i] == 1 && a.a[i + 1] == 1) {t = false; break;}
    }
    return t;
}
FBN normalize(FBN a)
{
    int t;
    do {
        for (int i = 0; i < LEN; i++) {
            if (a.a[i] > 1) {
                t = a.a[i] / 2;
                a.a[i] %= 2;
                a.a[i - 1] += 1;
                a.a[i + 2] += 1;
            }
            if ((i != LEN - 1) && a.a[i] == 1 && a.a[i + 1] == 1) {
                a.a[i - 1] += 1;
                a.a[i] = 0;
                a.a[i + 1] = 0;
            }
        }
    } while (!check(a));
    for (int i = LEN - 1; i >= HLE; i--) {
        if (a.a[i] != 0) {
            a.pn = i - HLE + 1;
            break;
        }
    }
    return a;
}
FBN add(FBN a, FBN b)
{
    FBN ans;
    ans.init();
    for (int i = 0; i < LEN; i++) {
        ans.a[i] = a.a[i] + b.a[i];
    }
    ans = normalize(ans);
    return ans;
}
int main()
{
    int n, i;
    FBN twob[30], ans;
    for (i = 0; i < 30; i++) twob[i].init();
    twob[0].a[HLE - 1] = 1;
    twob[0].pn = 0;
    for (i = 1; i < 30; i++) {
        twob[i] = add(twob[i - 1], twob[i - 1]);
    }
    while (scanf("%d", &n) != EOF) {
        i = 0;
        ans.init();
        while (n > 0) {
            if ((n & 1) == 1) ans = add(ans, twob[i]);
            n >>= 1;
            i++;
        }
        ans.print();
    }
    return 0;
}
