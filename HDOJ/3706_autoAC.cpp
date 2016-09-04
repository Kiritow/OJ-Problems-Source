#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define INF 0x7fffffff
using namespace std;
int main()
{
    int n,A,B;
    int q[100001],id[100001];
    while(scanf("%d%d%d",&n,&A,&B)!=EOF)
    {
        __int64 Ti=1,s=1;
        int head=0,tail=0;
        for(int i=1;i<=n;i++)
        {
            s=(s*A)%B;
            while(head<tail && q[tail]>=s) tail--;
            q[++tail]=s;
            id[tail]=i;
            while(id[head+1]<i-A) head++;
            Ti=(Ti*q[head+1])%B;
        }
        printf("%I64d\n",Ti);
    }
    return 0;
}
