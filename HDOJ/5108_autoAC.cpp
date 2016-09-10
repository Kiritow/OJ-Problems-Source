#include<bitset>
#include<map>
#include<vector>
#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<stack>
#include<queue>
#include<set>
#define inf 0x3f3f3f3f
#define mem(a,x) memset(a,x,sizeof(a))
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
inline int in()
{
    int res=0;
    char c;
    while((c=getchar())<'0' || c>'9');
    while(c>='0' && c<='9')res=res*10+c-'0',c=getchar();
    return res;
}
const int N=32000;
bool vis[N];
int prime[10000];
int main()
{
    int p=1;
    prime[0]=2;
    for(int i=3;i<N;i+=2)
    {
        if(!vis[i])
        {
            prime[p++]=i;
            for(int j=i+i;j<N;j+=i)
            {
                vis[j]=1;
            }
        }
    }
    int n;
    while(~scanf("%d",&n))
    {
        int tmp=n;
        if(n==1)
        {
            puts("0");
            continue;
        }
        int t=n;
        for(int i=0;prime[i]*prime[i]<=n;i++)
        {
            while(n%prime[i]==0) n/=prime[i],t=prime[i];
        }
        t=max(t,n); 
        printf("%d\n",tmp/t);
    }
    return 0;
}
