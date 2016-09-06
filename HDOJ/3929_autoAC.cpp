#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
const int N=20;
LL w[N];
LL ans,n;
LL get(LL x)
{
    return x==0? 0:get(x-(x&-x))+1;
}
void dfs(LL beg,LL num,LL sym)
{
    ans+=((LL)1<<get(num))*sym;
    for(LL i=beg+1;i<=n;i++)
        dfs(i,num&w[i],-2*sym);
}
int main()
{
    LL k=1,t,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
           cin>>w[i];
        ans=0;
        for(i=1;i<=n;i++)
           dfs(i,w[i],1);
        cout<<"Case #"<<k++<<": "<<ans<<endl;
    }
    return 0;
}
