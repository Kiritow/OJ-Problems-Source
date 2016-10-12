#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
int t;
/**
如果 n 是 奇数，直接输出 0. (奇数+奇数+偶数 或 偶数+偶数+偶数 ==== 偶数)
如果是偶数，并且是 2 的某个次方，输出 0.
否则统计二进制中 1 的个数。
两个 1 答案为 1
三个 1 答案为 4
四个 1 答案为 13
五个 1 答案为 40
六个 1 答案为 121
可以把答案单独开个数组  F[ N ] = F [ N -1 ] * 3 +1;
求得通项公式为
a(n)=(3^(n-1)-1)/2

*/
inline int getTbyte(LL inc)
{
    int c=0;
    while(inc>0)
    {
        if(inc&1) ++c;
        inc>>=1;
    }
    return c;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        LL inc;
        scanf("%lld",&inc);
        int n=getTbyte(inc);
        if(inc&1 || n == 1)
        {
            printf("0\n");continue;
        }
        printf("%lld\n",((LL)pow(3,n-1)-1)/2);
    }
    return 0;
}
