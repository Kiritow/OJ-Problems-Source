#include<cstdio>
#include<cstring>
const int N = 100005;
typedef __int64 LL;
LL attack[N];
int main()
{
    int n, l, r, m, k, pos;
    LL d, hp;
    while(~scanf("%d",&n) && n) {
        memset(attack, 0, sizeof(attack));
        scanf("%d",&m);
        while(m--) {
            scanf("%d%d%I64d", &l, &r, &d);
            attack[l] += d;
            attack[r+1] -= d;
        }
        for(int i = 2; i <= n; i++) 
            attack[i] += attack[i-1];
        for(int i = n - 1; i > 0; i--)
            attack[i] += attack[i+1];
        int ans = 0;
        scanf("%d",&k);
        while(k--) {
            scanf("%I64d%d",&hp, &pos);
            if(attack[pos] < hp)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}
