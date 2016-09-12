#include <iostream>                                                                
#include <cstdio>                                                                 
#include <cmath>                                                                    
#include <cstdlib>                                                                  
#include <cstring>                                                                  
#include <vector>                                                                   
#include <ctime>                                                                    
#include <deque>                                                                    
#include <queue>                                                                    
#include <algorithm>                                                               
#include <map>                                                                     
#include <cmath>                                                                   
using namespace std;                                                               
#define pb push_back                                                               
#define mp make_pair                                                             
#define X first                                                                     
#define Y second                                                                    
#define all(a) (a).begin(), (a).end()                                               
#define fillchar(a, x) memset(a, x, sizeof(a))                                      
typedef pair<int, int> pii;                                                         
typedef long long ll;                                                               
typedef unsigned long long ull;                                                     
#ifndef ONLINE_JUDGE                                                                
void RI(vector<int>&a,int n){a.resize(n);for(int i=0;i<n;i++)scanf("%d",&a[i]);}    
void RI(){}void RI(int&X){scanf("%d",&X);}template<typename...R>                    
void RI(int&f,R&...r){RI(f);RI(r...);}void RI(int*p,int*q){int d=p<q?1:-1;          
while(p!=q){scanf("%d",p);p+=d;}}void print(){cout<<endl;}template<typename T>      
void print(const T t){cout<<t<<endl;}template<typename F,typename...R>              
void print(const F f,const R...r){cout<<f<<", ";print(r...);}template<typename T>   
void print(T*p, T*q){int d=p<q?1:-1;while(p!=q){cout<<*p<<", ";p+=d;}cout<<endl;}   
#endif // ONLINE_JUDGE                                                              
template<typename T>bool umax(T&a, const T&b){return b<=a?false:(a=b,true);}        
template<typename T>bool umin(T&a, const T&b){return b>=a?false:(a=b,true);}        
template<typename T>                                                                
void V2A(T a[],const vector<T>&b){for(int i=0;i<b.size();i++)a[i]=b[i];}            
template<typename T>                                                                
void A2V(vector<T>&a,const T b[]){for(int i=0;i<a.size();i++)a[i]=b[i];}            
const double PI = acos(-1.0);                                                       
const int INF = 1e9 + 7;                                                            
unsigned long long Pre[64], Suf[64];
struct BitSet {
    vector<unsigned long long> s;
    static void init() {
        Pre[0] = 1;
        Suf[63] = (unsigned long long)1 << 63;
        for (int i = 1; i < 64; i ++) {
            Pre[i] = (unsigned long long)1 << i | Pre[i - 1];
        }
        for (int i = 62; i >= 0; i --) {
            Suf[i] = (unsigned long long)1 << i | Suf[i + 1];
        }
    }
    void resize(int n) {
        int p = s.size(), t = (n - 1) / 64 + 1;
        s.resize(t);
    }
    BitSet(int n) {
        resize(n);
    }
    BitSet() {}
    BitSet operator & (BitSet &that) {
        int sz = that.s.size(), n = this->s.size(), len = max(sz, n);
        if (sz < len) that.resize(len);
        if (n < len) this->resize(len);
        BitSet ans(len * 64);
        for (int i = len - 1; i >= 0; i --) {
            ans.s[i] = this->s[i] & that.s[i];
        }
        return ans;
    }
    BitSet operator | (BitSet &that) {
        int sz = that.s.size(), n = this->s.size(), len = max(sz, n);
        if (sz < len) that.resize(len);
        if (n < len) this->resize(len);
        BitSet ans(len * 64);
        for (int i = len - 1; i >= 0; i --) {
            ans.s[i] = this->s[i] | that.s[i];
        }
        return ans;
    }
    BitSet operator ^ (BitSet &that) {
        int sz = that.s.size(), n = this->s.size(), len = max(sz, n);
        if (sz < len) that.resize(len);
        if (n < len) this->resize(len);
        BitSet ans(len * 64);
        for (int i = len - 1; i >= 0; i --) {
            ans.s[i] = this->s[i] ^ that.s[i];
        }
        return ans;
    }
    BitSet operator << (int x) {
        int sz = s.size(), c = x / 64, r = x % 64;
        BitSet ans(64 * sz);
        for (int i = sz - 1; i - c >= 0; i --) {
            ans.s[i] = (s[i - c] & Pre[63 - r]) << r;
            if (r && i - c - 1 >= 0) ans.s[i] |= (s[i - c - 1 ] & Suf[64 - r]) >> (64 - r);
        }
        return ans;
    }
    BitSet operator >> (int x) {
        int sz = s.size(), c = x / 64, r = x % 64;
        BitSet ans(64 * sz);
        for (int i = 0; i + c < sz; i ++) {
            ans.s[i] = (s[i + c] & Suf[r]) >> r;
            if (r && i + c + 1 < sz) ans.s[i] |= (s[i + c + 1] & Pre[r - 1]) << (64 - r);
        }
        return ans;
    }
    bool get(int p) {
        int c = p / 64, r = p % 64;
        return s[c] & ((unsigned long long)1 << r);
    }
    bool zero() {
        int n = s.size();
        for (int i = 0; i < n; i ++) {
            if (s[i]) return false;
        }
        return true;
    }
    void setval(int L, int R, bool val) {
        int p = L / 64, tp = L % 64, q = R / 64, tq = R % 64;
        for (int i = p + 1; i < q; i ++) {
            s[i] = val? ((unsigned long long)-1) : 0;
        }
        if (p == q) {
            unsigned long long buf = Suf[tp] & Pre[tq];
            s[p] = val? s[p] | buf : s[p] & ~buf;
            return ;
        }
        s[p] = val? s[p] | Suf[tp] : s[p] & ~Suf[tp];
        s[q] = val? s[q] | Pre[tq] : s[q] & ~Pre[tq];
    }
    void print() {
        int n = s.size();
        for (int i = n - 1; i >= 0; i --) {
            unsigned long long x = s[i];
            for (int i = 63; i >= 0; i --) {
                if (((unsigned long long)1 << i) & x)
                    putchar('1');
                else
                    putchar('0');
            }
        }
        putchar('\n');
    }
};
struct StringHash {
    const static unsigned int hack = 1301;
    const static int maxn = 1e5 + 7;
    unsigned long long H[maxn], C[maxn];
    void init(char s[], int n) {
        for (int i = 0; s[i]; i ++) {
            H[i] = (i? H[i - 1] * hack : 0) + s[i];
        }
        C[0] = 1;
        for (int i = 1; i <= n; i ++) C[i] = C[i - 1] * hack;
    }
    unsigned long long get(int L, int R) {
        return H[R] - (L? H[L - 1] * C[R - L + 1] : 0);
    }
} ;
StringHash hsh, hshrev;
const int maxn = 1e5 + 7;
bool pre[maxn], suf[maxn];
char s[maxn], revs[maxn];
int F[maxn];
int main() {
    BitSet::init();
    int T;
    cin >> T;
    while (T --) {
        scanf("%s", s);
        int n = strlen(s), total = n * 2 - 1;
        hsh.init(s, n);
        for (int i = 0; i < n; i ++) revs[i] = s[n - i - 1];
        hshrev.init(revs, n);
        for (int i = 0; i < total; i ++) {
            int L = i / 2, R = (i + 1) / 2;
            int minlen = 0, maxlen = min(L + 1, n - R);
            while (minlen < maxlen) {
                int midlen = (minlen + maxlen + 1) >> 1;
                int lpos = L - midlen + 1, rpos = R + midlen - 1;
                if (hsh.get(lpos, L) == hshrev.get(n - rpos - 1, n - R - 1)) minlen = midlen;
                else maxlen = midlen - 1;
            }
            F[i] = minlen;
        }
        fillchar(pre, 0);
        fillchar(suf, 0);
        pre[0] = suf[n - 1] = true;
        BitSet bs1(n), bs2(n);
        bs1.setval(0, 0, 1);
        bs2.setval(0, 0, 1);
        for (int i = 1; i < n; i ++) {
            pre[i] = F[i] == i / 2 + 1;
            if (pre[i]) bs1.setval(i, i, 1);
        }
        for (int i = n - 2; i >= 0; i --) {
            suf[i] = F[i + n - 1] == (n - i + 1) / 2;
            if (suf[i]) bs2.setval(n - i - 1, n - i - 1, 1);
        }
        bool ok = false;
        for (int i = 0; i < total; i ++) {
            int L = i / 2, R = (i + 1) / 2;
            int len = F[i], lpos = L - len + 1, rpos = R + len - 1;
            if (len == 0) continue;
            BitSet buf, result, newbuf(n);
            if (n - R >= L + 1) {
                buf = bs2 >> (n - R - L - 1);
                result = bs1 & buf;
                newbuf.setval(max(0, lpos - 1), L - 1, 1);
            }
            if (L + 1 > n - R) {
                buf = bs1 >> (L + 1 - n + R);
                result = buf & bs2;
                newbuf.setval(max(0, n - rpos - 2), n - R - 2, 1);
            }
            newbuf = newbuf & result;
            if (!newbuf.zero()) {
                ok = true;
                break;
            }
        }
        puts(ok? "Yes" : "No");
    }
    return 0;
}
