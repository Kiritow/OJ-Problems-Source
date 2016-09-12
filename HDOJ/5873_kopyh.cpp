//kopyh
#include <bits/stdc++.h>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define N 1123456
using namespace std;
long long n,m,sum,res,flag,a[N];
int main()
{
    #ifndef ONLINE_JUDGE
        freopen("test.txt","r",stdin);
    #endif
    int i,j,k,cas,T,t,x,y,z;
    while(scanf("%I64d",&n)!=EOF)
        while(n--)
        {
            flag=1; sum=0;
            scanf("%I64d",&m);
            for(i=0;i<m;i++)
            {
                scanf("%I64d",&a[i]);
                sum+=a[i];
            }
            if(sum!=m*(m-1))flag=0;
            else
            {
                sort(a,a+m);
                res=0;
                for(i=0;i<m;i++)
                {
                    res+=a[i];
                    if(res<i*(i+1)){flag=0;break;}
                }
            }
            printf(flag?"T\n":"F\n");
        }
    return 0;
}
