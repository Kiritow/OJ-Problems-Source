#include <map>
#include <stdio.h>
typedef __int64 LL;
using namespace std;
#define N 650
bool np[N];
int prime[120],fac[9],F_top,p;
LL ans;
void get_prime()
{
    int top = -1;
    for(int i=2;i<N;i++)
        if(!np[i])
        {
            prime[++top] = i;
            for(int j=i+i;j<N;j+=i)
                np[j] = true;
        }
}
void Div(int n)
{
    F_top = 0;
    for(int i=0;prime[i]*prime[i]<=n;i++)
    {
        if(n % prime[i])
            continue;
        while(n % prime[i] == 0)
            n /= prime[i];
        fac[F_top++] = prime[i];
    }
    if(n != 1)
        fac[F_top++] = n;
}
LL PreSum(int n)
{
    return (LL)n*(n+1)/2;
}
void dfs(int i,int cnt,int m,int n,int num,int x)       
{
    if(cnt == m)
    {
        LL sum = num * PreSum(x/num);
        m&1 ? ans -= sum : ans += sum;
        return ;
    }
    if(num*fac[i] > x || n-i < m-cnt)
        return ;
    dfs(i+1,cnt+1,m,n,num*fac[i],x);
    dfs(i+1,cnt,m,n,num,x);
}
LL sovle(int n)
{
    ans = PreSum(n);
    for(int m=1;m<=F_top;m++)
        dfs(0,0,m,F_top,1,n);
    return ans;
}
int gcd(int a,int b)
{
    return b ? gcd(b,a%b) : a;
}
int main()
{
    int z,n,Q,cmd,a,b;
    get_prime();
    scanf("%d",&z);
    map<int,int> M;
    while(z--)
    {
        M.clear();
        scanf("%d%d",&n,&Q);
        while(Q--)
        {
            scanf("%d",&cmd);
            if(cmd == 1)
            {
                scanf("%d%d%d",&a,&b,&p);
                Div(p);
                ans = sovle(b) - sovle(a-1);
                for(map<int,int>::iterator it=M.begin();it!=M.end();it++)
                    if((*it).first >= a && (*it).first <= b)
                    {
                        if(gcd((*it).first,p) == 1)
                            ans -= (*it).first;
                        if(gcd((*it).second,p) == 1)
                            ans += (*it).second;
                    }
                printf("%I64d\n",ans);
            }
            else
            {
                scanf("%d%d",&a,&b);
                M[a] = b;
            }
        }
    }
    return 0;
}
