#include <stdio.h>
#include <string.h>
#define LL __int64
struct corns {
    int q, p, n, m;
}a[1111];
int s[11] , ss[11], D, Y;
LL ans , val[1002];
void solve1(int i) {
    LL cur = Y;
    int day = 0, j;
    while(day <= D) {
        if(day + a[i].n <= D) {
            LL tot = cur/a[i].q;
            for(j = 9;j >= 1; j--) if(s[j]) {
                if(j*a[i].p > a[i].q)   {
                    if(tot <= s[j]) {
                        cur += tot * (LL)( j*a[i].p - a[i].q );
                        tot = 0;
                        break;
                    }
                    else {
                        cur += (LL)s[j] * ( j*a[i].p - a[i].q );
                        tot -= s[j];
                    }
                }
                else    break;
            }
        }
        day += a[i].n;
    }
    if(cur > ans)        ans = cur;
}
void solve2(int i) {
    int j, k, l;
    memset(val, 0, sizeof(val));
    LL cur = Y;
    for(j = 1;j <= 9; j++)    ss[j] = s[j];
    for(j=  0;j <= D; j++) {
        cur += val[j];
        LL tot = cur/a[i].q;
        for(k = 9;k >= 1; k--) if(ss[k]){
            int to = j+a[i].n;
            if(to > D)    break;
            LL now = k*a[i].p;
            now += (LL)(D-to)/a[i].m * k*a[i].p;
            if(now > a[i].q) {
                LL get;
                if(tot > ss[k])    get = ss[k];
                else    get = tot;
                ss[k] -= (int)get;
                tot -= get;
                cur -= get*a[i].q;
                val[to] += get * k *a[i].p;
                for(l = to+a[i].m;l <= D; l += a[i].m)    val[l] += get *k * a[i].p;
            }
            else    break;
        }
    }
    if(cur > ans)    ans = cur;
}
int main() {
    int t, w, h, A, i;
    scanf("%d", &t);
    while(t--) {
        scanf("%d%d%d%d%d", &w, &h, &A, &D, &Y);
        memset(s, 0, sizeof(s));
        s[9] = (w/3) * (h/3);
        s[(w%3)*3] += h/3;
        s[(h%3)*3] += w/3;
        if((w%3) * (h%3) == 1) {
            s[5]++;    s[3] -= 2; s[1] += 2;
        }
        else if((w%3) * (h%3) == 4) {
            s[8]++; s[6] -= 2; s[4] += 2;
        }
        else if((w%3)*(h%3) == 2) {
            s[7]++; s[6]--; s[3]--; s[2] += 2;
        }
        else    s[(w%3)*(h%3)] ++;
        for(i =0;i < A; i++)    scanf("%d%d%d%d", &a[i].q, &a[i].p, &a[i].n, &a[i].m);
        ans = Y;
        for(i = 0;i < A ; i++) {
            if(a[i].m == 0)    solve1(i);
            else    solve2(i);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
