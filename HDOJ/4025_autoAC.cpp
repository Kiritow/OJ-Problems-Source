#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
struct Set{
    int k, num[5];
};
int ans_count, a1, a2, n, m;
int a[31][23];
Set s[23];
__int64 ans[(1<<22) + 2];
__int64 sum[(1<<22)+2];
__int64 final_ans;
int find(__int64 v)
{
    int left = 0, right = ans_count-1, mid;
    if (ans_count == 0) return -1;
    while (left < right-1) {
        mid = left + (right - left) / 2;
        if (v <= ans[mid]) right = mid;
        else  left = mid;
    }
    if (v == ans[left]) return left;
    if (v == ans[right]) return right;
    return -1;
}
void dfs_x1(int p, __int64 now)
{
    int i, j, x;
    __int64 tmp;
    if (p >= a2+1) {
        ans[ans_count++] = now;
        return;
    }
    for (i = 0; i < s[p].k; i++) {
        x = s[p].num[i];
        tmp = now;
        for (j = 1; j <= n; j++)   tmp ^= ((__int64)(a[j][p] * x)) << (2*(j-1));
        dfs_x1(p+1, tmp);
    }
}
void dfs_x2(int p, __int64 now)
{
    int i, j, x, ret;
    __int64 tmp;
    if (p >= a2+1) {
        ret = find(now);
        if (ret != -1) {
            final_ans += sum[ret];
        }
        return;
    }
    for (i = 0; i < s[p].k; i++) {
        x = s[p].num[i];
        tmp = now;
        for (j = 1; j <= n; j++)   tmp ^= ((__int64)(a[j][p] * x)) << (2*(j-1));
        dfs_x2(p+1, tmp);
    }
}
int main()
{
    int cs, tt, i, j, ss, n_count;
    scanf("%d", &tt);
    for (cs = 1; cs <= tt; cs++) {
        scanf("%d %d", &n, &m);
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        for (i = 1; i <= m; i++) {
            scanf("%d", &s[i].k);
            n_count = 0;
            ss = 0;
            for (j = 0; j < s[i].k; j++) {
                scanf("%d", &s[i].num[n_count]);
                if (ss & (1<<s[i].num[n_count])) continue;
                n_count++;
            }
            s[i].k = n_count;
        }
        ans_count = 0;
        a1 = 1;
        a2 = (m/2);
        dfs_x1(a1, 0LL);
        sort(ans, ans+ans_count);
        j = 0;
        sum[j] = 1;
        for (i = 1; i < ans_count; i++) {
            if (ans[j] == ans[i]) sum[j]++;
            else {
                ans[++j] = ans[i];
                sum[j] = 1;
            }
        }
        ans_count = j+1;
        final_ans = 0LL;
        a1 = a2 + 1;
        a2 = m;
        dfs_x2(a1, 0LL);
        printf("%I64d\n", final_ans);
    }
    return 0;
}
