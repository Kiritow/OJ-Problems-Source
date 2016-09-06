#include"iostream"
#include"cstdio"
#include"cstring"
using namespace std;
const int N=1006;
const int mod=10007;
int n,lowbit[N];
__int64 C[N],ans[N];
char str[N];
void update(int k,int dir)
{
    while(0<k && k<=n)
    {
        C[k]=(C[k]+dir)%mod;
        k+=lowbit[k];
    }
}
int sum(int k)
{
    __int64 p=0;
    while(0<k && k<=n)
    {
        p=(p+C[k])%mod;
        k-=lowbit[k];
    }
    return p;
}
int main()
{
    int T,Case;
    int i,l;
    __int64 a,b,t;
    __int64 hehe;
    for(i=1;i<=1000;i++)    lowbit[i]=i&(-i);
    cin>>T;
    for(Case=1;Case<=T;Case++)
    {
        hehe=0;
        scanf("%s",str+1);
        memset(C,0,sizeof(C));
        memset(ans,0,sizeof(ans));
        for(n=1;str[n];n++);
        n--;
        for(i=n;i>=1;i--)
        {
            ans[i]=1;
            update(i,1);
            for(l=n;l>i;l--)
            {
                if(str[l]==str[i])
                {
                    a=sum(i);
                    b=sum(l-1);
                    t=(b-a)%mod;
                    while(t<0)    t+=mod;
                    ans[i]=(ans[i]+1+t)%mod;
                    update(l,1+t);
                }
            }
        }
        hehe=0;
        for(i=1;i<=n;i++)    hehe=(hehe+ans[i])%mod;
        printf("Case %d: %I64d\n",Case,hehe);
    }
    return 0;
}
