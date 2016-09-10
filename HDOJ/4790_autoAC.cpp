#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
long long gcd(long long a,long long b)
{
    if(b == 0)return a;
    return gcd(b,a%b);
}
int main()
{
    long long a,b,c,d,p,m;
    int T;
    int iCase = 0;
    scanf("%d",&T);
    while(T--)
    {
        iCase++;
        scanf("%I64d%I64d%I64d%I64d%I64d%I64d",&a,&b,&c,&d,&p,&m);
        long long ans = 0;
        if(b+c <= a+d)
        {
            long long t1 = (a+c)%p;
            long long add = (m - t1 + p)%p;
            long long cnt1 = (a+c + add-m)/p;
            long long t2 = (b+c-1)%p;
            long long sub = (t2 - m + p)%p;
            long long cnt2 = (b+c-1-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+add) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2 * p;
            t1 = (b+c)%p;
            add = (m - t1 + p)%p;
            cnt1 = (b+c+add-m)/p;
            t2 = (a+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (a+d-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(b-a+1);
            t1 = (a+d+1)%p;
            add = (m - t1 + p)%p;
            cnt1 = (a+d+1+add-m)/p;
            t2 = (b+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+d-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+sub) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2*p;
        }
        else
        {
            long long t1 = (a+c)%p;
            long long add = (m - t1 + p)%p;
            long long cnt1 = (a+c + add-m)/p;
            long long t2 = (a+d-1)%p;
            long long sub = (t2 - m + p)%p;
            long long cnt2 = (a+d-1-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+add) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2 * p;
            t1 = (a+d)%p;
            add = (m - t1 + p)%p;
            cnt1 = (a+d+add-m)/p;
            t2 = (b+ c)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+c-sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(d-c+1);
            t1 = (b+c+1)%p;
            add = (m - t1 + p)%p;
            cnt1 = (b+c+1+add-m)/p;
            t2 = (b+d)%p;
            sub = (t2 - m + p)%p;
            cnt2 = (b+d - sub-m)/p;
            ans += (cnt2 - cnt1 + 1)*(1+sub) + (cnt2 - cnt1 + 1)*(cnt2 - cnt1)/2*p;
        }
        long long tot = (b-a+1)*(d-c+1);
        long long GCD = gcd(ans,tot);
        ans /= GCD;
        tot /= GCD;
        printf("Case #%d: %I64d/%I64d\n",iCase,ans,tot);
    }
    return 0;
}
