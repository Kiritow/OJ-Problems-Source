#include <iostream>
using namespace std;
typedef long long LL;
LL gcd(LL a, LL b)
{
    return b ? gcd(b, a%b) : a;
}
LL extend_gcd(LL a, LL b, LL &x, LL &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    LL d = extend_gcd(b, a%b, x, y);
    LL t = x;
    x = y;
    y = t- a/b *y;
    return d;
}
int main()
{
    LL a, b;
    while (cin >> a >> b)
    {
        if (gcd(a, b) != 1)
            cout << "sorry" << endl;
        else
        {
            LL x, y;
            extend_gcd(a, b, x, y);
            while (x <= 0)
            {
                x+= b;
                y-= a;
            }
            cout << x << " "<< y<< endl;
        }
    }
    return 0;
}
