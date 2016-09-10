#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
using namespace std;
typedef __int64 LL;
LL gcd(LL a, LL b)
{
    if(b==0)
        return a;
    return gcd(b, a%b);
}
int main()
{
    LL a, b, c;
    int T;
    vector<LL> v;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%I64d%I64d%I64d", &a, &b, &c);
        LL temp = gcd(a, b);
        v.clear();
        int cnt = 0;
        for(LL i=1; i*i<=temp; ++i)
        {
            if(temp%i==0)
             {
                 v.push_back(i);
                 if(i*i!=temp)
                    v.push_back(temp/i);
             }
        }
        sort(v.begin(), v.end());
        if(v.size() >= c)
            printf("%I64d\n", v[v.size()-c]);
        else
            printf("-1\n");
    }
    return 0;
}
