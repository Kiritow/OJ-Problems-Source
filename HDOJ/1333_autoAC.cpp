#include <iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n;
bool isprime[10100];
vector<int> prime,a;
int sum(int n)
{
    int ans=0;
    while(n)
    {
        ans+=n%10;
        n/=10;
    }
    return ans;
}
void init()
{
    memset(isprime,0,sizeof(isprime));
    isprime[0]=isprime[1]=true;
    for(int i=2;i<=10010;i++)
    {
        if(isprime[i]==false)
        {
            prime.push_back(i);
            a.push_back(sum(i));
            for(int j=i+i;j<=10010;j+=i)
                isprime[j]=true;
        }
    }
}
bool issame(int n)
{
    int ans1=sum(n),ans2=0;
    if(n<=10010&&isprime[n]==false)
        return false;
    for(int i=0;i<prime.size()&&prime[i]*prime[i]<=n;i++)
    {
        while(n%prime[i]==0)
        {
            ans2+=a[i];n/=prime[i];
        }
        if(n==1)
            break;
    }
    if(ans2==0) return false;
    if(n!=1)
    ans2+=sum(n);
    if(ans1==ans2)
        return true;
    return false;
}
int main()
{
    init();
    while(scanf("%d",&n),n!=0)
    {
        while(!issame(n+1))
            n++;
            printf("%d\n",n+1);
    }
    return 0;
}
