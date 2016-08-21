#include<iostream>
#include<string.h>
using namespace std;
#define N 1010
bool is[N];
__int64 res[N];            
short prim[N];            
int main()
{
    memset(is,true,sizeof(is));
    __int64 i,j,a,b;
    for(i=2;(i<<1)<1001;i++)    
    {
        for(j=2;i*j<1001;j++)
            is[j*i]=false;
    }
    int sum=0;
    for(i=2;i<=1000;i++)
        if(is[i])
            prim[sum++]=i;
        int cnt=0;
        while(scanf("%I64d%I64d",&a,&b)!=EOF)
        {
            b%=10007;
            printf("Case %d: ",++cnt);
            int total=0;
            memset(res,0,sizeof(res));
            for(i=0;a!=1&&i<sum;i++)        
            {
                if(a%prim[i]==0)
                {
                    while(a%prim[i]==0)
                    {
                        res[total]++;
                        a/=prim[i];
                    }
                    total++;
                }
            }
            if(a!=1)                
                res[total++]=1;
            __int64 ans=1;
            for(i=0;i<total;i++)            
            {
                __int64 s;
                s=(((b*res[i]+1)*(b*res[i]+2))/2)%10007;     
                s*=s;
                ans=(ans*s)%10007;
            }
            printf("%I64d\n",ans);
        }
        return 0;
}
