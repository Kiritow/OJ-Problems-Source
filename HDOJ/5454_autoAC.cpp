#include<cstdio>  
#include<algorithm>  
#include<cstring>  
using namespace std;  
typedef __int64 LL;  
const int maxn = 300005;  
struct tree  
{  
    LL suml[maxn << 2], sumr[maxn << 2], sum[maxn << 2];  
    LL add[maxn << 2];  
    inline void pushup(int id, int L, int R)  
    {  
        LL mid = L + R >> 1;  
        sum[id] = sum[id << 1] + sum[id << 1 | 1];  
        suml[id] = suml[id << 1] + (mid - L + 1)*sum[id << 1 | 1] + suml[id << 1 | 1];  
        sumr[id] = sumr[id << 1 | 1] + sumr[id << 1] + (R - mid)*sum[id << 1];  
    }  
    inline void pushdown(int id, int L, int R)  
    {  
        int mid = L + R >> 1;  
        if (add[id])  
        {  
            LL ln = mid - L + 1;  
            LL rn = R - mid;  
            add[id << 1] += add[id];  
            add[id << 1 | 1] += add[id];  
            sum[id << 1] += add[id] * ln;  
            sum[id << 1 | 1] += add[id] * rn;  
            suml[id << 1] += add[id] * (1 + ln)*ln >> 1;  
            suml[id << 1 | 1] += add[id] * (1 + rn)*rn >> 1;  
            sumr[id << 1] += add[id] * (1 + ln)*ln >> 1;  
            sumr[id << 1 | 1] += add[id] * (1 + rn)*rn >> 1;  
            add[id] = 0;  
        }  
    }  
    void build()  
    {  
        memset(sum, 0, sizeof(sum));  
        memset(suml, 0, sizeof(suml));  
        memset(sumr, 0, sizeof(sumr));  
        memset(add, 0, sizeof(add));  
    }  
    LL queL(int id, int L, int R, int l, int r)  
    {  
        if (l <= L&&R <= r) return (L - l)*sum[id] + suml[id];  
        else  
        {  
            pushdown(id, L, R);  
            int mid = L + R >> 1;  
            LL res = 0;  
            if (l <= mid) res += queL(id << 1, L, mid, l, r);  
            if (mid<r) res += queL(id << 1 | 1, mid + 1, R, l, r);  
            return res;  
        }  
    }  
    LL queR(int id, int L, int R, int l, int r)  
    {  
        if (l <= L&&R <= r) return (r - R)*sum[id] + sumr[id];  
        else  
        {  
            pushdown(id, L, R);  
            int mid = L + R >> 1;  
            LL res = 0;  
            if (l <= mid) res += queR(id << 1, L, mid, l, r);  
            if (mid<r) res += queR(id << 1 | 1, mid + 1, R, l, r);  
            return res;  
        }  
    }  
    LL que(int id, int L, int R, int l, int r)  
    {  
        if (l <= L&&R <= r) return sum[id];  
        else  
        {  
            pushdown(id, L, R);  
            int mid = L + R >> 1;  
            LL res = 0;  
            if (l <= mid) res += que(id << 1, L, mid, l, r);  
            if (mid<r) res += que(id << 1 | 1, mid + 1, R, l, r);  
            return res;  
        }  
    }  
    void op(int id, int L, int R, int l, int r)  
    {  
        if (l <= L&&R <= r)  
        {  
            LL sn = R - L + 1;  
            add[id]++;  
            sum[id] += sn;  
            suml[id] += (1 + sn)*sn >> 1;  
            sumr[id] += (1 + sn)*sn >> 1;  
        }  
        else  
        {  
            pushdown(id, L, R);  
            int mid = L + R >> 1;  
            if (l <= mid) op(id << 1, L, mid, l, r);  
            if (mid<r) op(id << 1 | 1, mid + 1, R, l, r);  
            pushup(id, L, R);  
        }  
    }  
}tz, tf;  
int main()  
{  
    int T;  
    scanf("%d", &T);  
    int ks = 0;  
    while (T--)  
    {  
        printf("Case #%d:\n", ++ks);  
        tz.build();  
        tf.build();  
        int n, m;  
        scanf("%d %d", &n, &m);  
        while (m--)  
        {  
            int op;  
            scanf("%d", &op);  
            if (op == 1)  
            {  
                int l, r;  
                scanf("%d %d", &l, &r);  
                tf.op(1, 1, n << 1, l, r);  
            }  
            else if (op == 2)  
            {  
                int l, r;  
                scanf("%d %d", &l, &r);  
                l += n;  
                r += n;  
                tz.op(1, 1, n << 1, l, r);  
            }  
            else  
            {  
                int x1, y1, x2, y2;  
                scanf("%d %d %d %d", &x1, &x2, &y1, &y2);  
                LL ans = 0;  
                int A, B, C, D;  
                A = x1 - y1 + n;  
                B = x1 - y2 + n;  
                C = x2 - y2 + n;  
                D = x2 - y1 + n;  
                if (D >= max(A, C) + 1) ans += tz.queR(1, 1, n << 1, max(A, C) + 1, D);  
                if (B <= min(A, C) - 1) ans += tz.queL(1, 1, n << 1, B, min(A, C) - 1);  
                ans += tz.que(1, 1, n << 1, min(A, C), max(A, C))*(min(y2 - y1, x2 - x1) + 1);  
                A = x1 + y1;  
                B = x1 + y2;  
                C = x2 + y2;  
                D = x2 + y1;  
                if (A <= min(B, D) - 1) ans += tf.queL(1, 1, n << 1, A, min(B, D) - 1);  
                if (C >= max(B, D) + 1) ans += tf.queR(1, 1, n << 1, max(B, D) + 1, C);  
                ans += tf.que(1, 1, n << 1, min(B, D), max(B, D))*(min(y2 - y1, x2 - x1) + 1);  
                printf("%I64d\n", ans);  
            }  
        }  
    }  
    return 0;  
}
