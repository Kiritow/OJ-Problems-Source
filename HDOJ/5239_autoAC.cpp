#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned long long ull;
struct uint64{
    static const ull MODN = 9223372034707292160;
    ull n;
    uint64(ull n = 0):n(n){}
    static uint64 ass(ull n){
        if(n >= MODN)
            return uint64(n - MODN);
        else
            return uint64(n);
    }
    inline uint64 operator-() const{
        return uint64(MODN - n);
    };
    friend inline uint64 operator*(const uint64& a, const uint64& b){
        uint64 tmp;
        ull a1 = (a.n >> 32), a0 = (a.n & 0xffffffff);
        ull b1 = (b.n >> 32), b0 = (b.n & 0xffffffff);
        tmp = ass(a1 * b1);
        tmp = tmp + ass(a1 * b0);
        tmp = tmp + ass(a0 * b1);
        for(int i = 0; i < 32; i ++)
            tmp = tmp + tmp;
        tmp = tmp + ass(a0 * b0);
        return tmp;
    }
    friend inline uint64 operator+(const uint64& a, const uint64& b){
        ull n = a.n + b.n;
        return uint64((n < a.n || n >= MODN) ? (n - MODN) : n);
    }
    friend inline uint64 operator-(const uint64& a, const uint64& b){
        return (a.n < b.n) ? (a.n + MODN - b.n) : (a.n - b.n);
    }
    inline uint64 sqr(){
        return (*this) * (*this);
    }
};
const int MAXN = 131072;
ull arr[MAXN];
int N, M;
class Segtree{
public:
    static const int MAXK = 30;
    struct NODE{
        int flg;  
        uint64 d[MAXK];
    }node[MAXN<<1];
    inline void popup(int id){
        int j;
        for(j = 0; j < MAXK; j ++)
            node[id].d[j] = node[id<<1].d[j] + node[id<<1|1].d[j];
    }
    inline void shift(int id, int k){
        node[id].flg += k;
        for(int j = 0; j <= MAXK - 2; j ++){
            node[id].d[j] = node[id].d[min(j + k, MAXK - 1)];
        }
    }
    inline void pushdown(int id){
        int flg = node[id].flg;
        if(flg > 0){
            shift(id<<1, flg);
            shift(id<<1|1, flg);
            node[id].flg = 0;
        }
    }
    void build(int id, int l, int r){
        int mid = (l + r) >> 1;
        if(l == r){
            node[id].d[0] = uint64::ass(arr[l]);
            node[id].flg = 0;
            for(int j = 1; j < MAXK; j ++)
                node[id].d[j] = node[id].d[j - 1].sqr();
        }else{
            node[id].flg = 0;
            build(id<<1, l, mid);
            build(id<<1|1, mid+1, r);
            popup(id);
        }
    }
    uint64 query(int id, int l, int r, int L, int R){
        uint64 ret;
        if(l == L && r == R){
            ret = node[id].d[0];
            shift(id, 1); 
            return ret;
        }
        int mid = (L + R) >> 1;
        pushdown(id);
        if(l > mid){
            ret = query(id<<1|1, l, r, mid + 1, R);
        }else if(r <= mid){
            ret = query(id<<1, l, r, L, mid);
        }else{
            ret = query(id<<1, l, mid, L, mid) + query(id<<1|1, mid + 1, r, mid + 1, R);
        }
        popup(id);
        return ret;
    }
}tree;
int main(){
    int i, T, l, r;
    uint64 ans;
    scanf("%d", &T);
    for(i = 1; i <= T; i ++){
        printf("Case #%d:\n", i);
        scanf("%d%d", &N, &M);
        for(l = 1; l <= N; l ++){
            scanf("%I64u", &arr[l]);
        }
        tree.build(1, 1, N);
        ans = 0;
        while(M --){
            scanf("%d%d", &l, &r);
            ans = ans + tree.query(1, l, r, 1, N);
            printf("%I64u\n", ans.n);
        }
    }
    return 0;
}
