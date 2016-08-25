#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio>
using namespace std;
#define maxn 1000010
bool prime[maxn];
void Prime()
{
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=0;
    for(int i=2;i*i<maxn;i++)
        if(prime[i])
            for(int j=2*i;j<maxn;j+=i)
                prime[j]=0;
}
int main()
{
    Prime();
    int n,ans,p;
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(int i=1;;i++)
        {
            int tmp=3*i*i+3*i+1;
            if(tmp>n)
                break;
            if(prime[tmp])
                ans++;
        }
        if(ans)
            printf("%d\n",ans);
        else
            printf("No Special Prime!\n");
    }
    return 0;
}
