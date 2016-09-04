#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<iostream> 
using namespace std;
const int size = 111111;
typedef long long ll;
typedef pair<int,int> pii;
ll gcd(ll a, ll b){
    return b? gcd(b, a%b):a;
}
char ch[100];
ll a, b, c, d, n,t;
void get(ll &a, ll &b){
    n = strlen(ch);
    ll aa = 0, bb = 1, cc = 0, dd = 1, f = 0;
    for(int i = 0; i < n && ch[i] != '[';i++){
        if(ch[i] == '.'){
            f = 1;
            continue;
        }
        aa = 10 * aa + ch[i] - '0';
        if(f)
            bb *= 10;        
    }
    f = gcd(aa, bb);
    aa /= f;
    bb /= f;
    for(int i = 0; i < n; i++)
        if(ch[i] == '['){
            for(int j = i+1; ch[j] != ']'; j++){
                cc = cc * 10 + ch[j] - '0';
                dd *= 10;
            }
            dd--;
            for(int j = i -1; ch[j] != '.';j--)
                dd *= 10;
            break;
        }
    f = gcd(cc, dd);
    cc /= f;
    dd /= f;
    f = gcd(bb,dd);
    b = bb/f*dd;
    aa = dd/f*aa +bb/f*cc;
    a = aa; 
}
int work(ll a, ll b, ll c, ll d, ll p){
    ll x = a *p / b + 1;
    ll y = c *p /d;
    if(c*p%d == 0)
        y--;
    if(x <= y)
        return 1;
    return 0;
}
int main()
{
    cin >> t;
    for(int ca = 1; ca <= t; ca++){
        cin >> ch;
        get(a,b);
        cin >> ch;
        get(c,d);
        ll low = 1;
        while(work(a,b,c,d,low) == 0)
            low++;
        ll x = a * low / b + 1;
        printf("Case %d: %I64d/%I64d\n", ca, x, low);
    }
}
