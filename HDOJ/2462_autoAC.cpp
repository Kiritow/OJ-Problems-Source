#include <vector>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define LL long long
#define MAXN 400010
using namespace std;
bool vis[MAXN];
vector<LL> hav;
vector<int> prime;
LL gcd(LL a, LL b) {
    return b==0 ? a : gcd(b, a%b);
}
void gen_primes() {
    for(int i=2; i<MAXN; ++i) {
        if(!vis[i]) {
            prime.push_back(i);
            if(i < 1111) {
                for(int j=i*i; j<MAXN; j+=i) {
                    vis[j] = true;
                }
            }
        }
    }
    return ;
}
LL euler_phi(LL n) {
    LL ans = n;
    for(int i=0; (LL)(prime[i]*prime[i])<=n; ++i) {
        if(n%prime[i] == 0) {
            ans = ans/prime[i]*(prime[i]-1);
            n /= prime[i];
            while(n%prime[i] == 0)
                n /= prime[i];
        }
    }
    if(n > 1) {
        ans = ans/n*(n-1);
    }
    return ans;
}
LL Mul(LL a, LL b, LL c) {
    LL ans = 0;
    while(b) {
        if(b & 1)
            ans = (ans+a)%c;
        a = a*2%c;
        b >>= 1;
    }
    return ans;
}
LL Pow(LL a, LL b, LL c) {
    LL ans = 1;
    while(b) {
        if(b & 1)
            ans = Mul(ans, a, c);
        a = Mul(a, a, c);
        b >>= 1;
    }
    return ans;
}
void get_hav(LL n) {
    hav.clear();
    for(int i=0; i<prime.size()&&n>1; ++i) {
        while(n%(LL)prime[i] == 0) {
            n /= prime[i];
            hav.push_back(prime[i]);
        }
    }
    if(n > 1)
        hav.push_back(n);
}
int main(void) {
    LL n, m, x, cas = 1;
    gen_primes();
    while(cin >> n && n) {
        m = 9*n/gcd(n, 8LL);
        if(gcd(m, 10LL) != 1) {
            cout << "Case " << cas++ << ": 0" << endl;
            continue;
        }
        x = euler_phi(m);
        get_hav(x);
        for(int i=0; i<hav.size(); ++i) {
            if(Pow(10LL, x/hav[i], m) == 1)
                x /= hav[i];
        }
        cout << "Case " << cas++ << ": " << x << endl;
    }
    return 0;
}
