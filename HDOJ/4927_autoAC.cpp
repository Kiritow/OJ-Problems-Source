#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4
class BigInt
{
private:
    int a[500];
    int len;
public:
    BigInt() {len = 1; memset(a, 0, sizeof(a));}
    BigInt(const int);
    BigInt(const char *);
    BigInt(const BigInt &);
    BigInt &operator = (const BigInt &);
    BigInt operator + (const BigInt &) const;
    BigInt operator - (const BigInt &) const;
    BigInt operator * (const BigInt &) const;
    BigInt operator / (const int &) const;
    bool operator > (const BigInt &T) const;
    bool operator < (const BigInt &T) const;
    bool operator == (const BigInt &T) const;
    bool operator > (const int &t) const;
    bool operator < (const int &t) const;
    bool operator == (const int &t) const;
    void print();
};
bool BigInt::operator == (const BigInt &T) const {
    return !(*this > T) && !(T > *this);
}
bool BigInt::operator == (const int &t) const {
    BigInt T = BigInt(t);
    return *this == T;
}
bool BigInt::operator < (const BigInt &T) const {
    return T > *this;
}
bool BigInt::operator < (const int &t) const {
    return BigInt(t) > *this;
}
BigInt::BigInt(const int b) {
    int c, d = b;
    len = 0;
    memset(a, 0, sizeof(a));
    while(d > MAXN) {
        c = d - (d / (MAXN + 1)) * (MAXN + 1);
        d = d / (MAXN + 1);
        a[len++] = c;
    }
    a[len++] = d;
}
BigInt::BigInt(const char *s) {
    int t, k, index, l, i;
    memset(a, 0, sizeof(a));
    l = strlen(s);
    len = l / DLEN;
    if(l % DLEN)
        len++;
    index = 0;
    for(i = l - 1; i >= 0; i -= DLEN)
    {
        t = 0;
        k = i - DLEN + 1;
        if(k < 0)
            k = 0;
        for(int j = k;j <= i; j++)
            t = t * 10 + s[j] - '0';
        a[index++] = t;
    }
}
BigInt::BigInt(const BigInt &T) : len(T.len)
{
    int i;
    memset(a, 0, sizeof(a));
    for(i = 0; i < len; i++)
        a[i] = T.a[i];
}
BigInt & BigInt::operator = (const BigInt &n)
{
    int i;
    len = n.len;
    memset(a, 0, sizeof(a));
    for(i = 0; i  < len; i++)
        a[i] = n.a[i];
    return *this;
}
BigInt BigInt::operator + (const BigInt &T) const{
    BigInt t(*this);
    int i, big;
    big = T.len > len ? T.len : len;
    for(int i = 0; i < big; i++)
    {
        t.a[i] += T.a[i];
        if(t.a[i] > MAXN)
        {
            t.a[i+1]++;
            t.a[i] -= MAXN + 1;
        }
    }
        if(t.a[big] != 0)
            t.len = big + 1;
        else
            t.len = big;
        return t;
}
BigInt BigInt::operator - (const BigInt &T) const {
    int i, j, big;
    bool flag;
    BigInt t1, t2;
    if(*this > T)
    {
        t1 = *this;
        t2 = T;
        flag = 0;
    }
    else
    {
        t1 = T;
        t2 = *this;
        flag = 1;
    }
    big = t1.len;
    for(i = 0; i < big; i++)
    {
        if(t1.a[i] < t2.a[i])
        {
            j = i + 1;
            while(t1.a[j] == 0)
                j++;
            t1.a[j--]--;
            while(j > i)
                t1.a[j--] += MAXN;
            t1.a[i] +=  MAXN + 1 - t2.a[i];
        }
        else
            t1.a[i] -= t2.a[i];
    }
    t1.len = big;
    while(t1.a[t1.len - 1] == 0 && t1.len > 1)
    {
        t1.len--;
        big--;
    }
    if(flag)
        t1.a[big-1] = 0 - t1.a[big-1];
    return t1;
}
BigInt BigInt::operator * (const BigInt &T) const {
    BigInt ret;
    int i, j, up;
    int tmp, temp;
    for(i = 0; i < len; i++)
    {
        up = 0;
        for(j = 0; j < T.len; j++)
        {
            temp = a[i] * T.a[j] + ret.a[i+j] + up;
            if(temp > MAXN)
            {
                tmp = temp - temp / (MAXN + 1) * (MAXN + 1);
                up = temp / (MAXN + 1);
                ret.a[i + j] = tmp;
            }
            else
            {
                up = 0;
                ret.a[i + j] = temp;
            }
        }
        if(up != 0)
            ret.a[i + j] = up;
    }
    ret.len = i + j;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
BigInt BigInt::operator / (const int &b) const {
    BigInt ret;
    int i, down = 0;
    for(i = len - 1; i >= 0; i--)
    {
        ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
        down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
    }
    ret.len = len;
    while(ret.a[ret.len - 1] == 0 && ret.len > 1)
        ret.len--;
    return ret;
}
bool BigInt::operator > (const BigInt &T) const {
    int ln;
    if(len > T.len)
        return true;
    else if(len == T.len)
    {
        ln = len - 1;
        while(a[ln] == T.a[ln] && ln >= 0)
            ln--;
        if(ln >= 0 && a[ln] > T.a[ln])
            return true;
        else
            return false;
    }
    else
        return false;
}
bool BigInt::operator > (const int &t) const {
    BigInt b(t);
    return *this > b;
}
void BigInt::print()
{
    printf("%d",a[len-1]);
    for(int i = len - 2; i >= 0; i--)
        printf("%04d", a[i]);
    printf("\n");
}
int main()
{
    int n, T, i, j, a[3005];
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        BigInt positive(0), negative(0), C(1), tmp;
        for(i = 0; i <= n - 1; i++)
        {
            if(i > 0) C = (C * (BigInt)(n - i)) / i;
            tmp = C * (BigInt)(a[n-i]);
            if(i&1)
                negative = negative + tmp;
            else
                positive = positive + tmp;
        }
        BigInt ans = positive - negative;
        ans.print();
    }
    return 0;
}
