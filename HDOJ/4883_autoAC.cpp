#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;
int main()
{
    int a[2000];
    int T,m,i;
    scanf("%d",&T);
    while(T--)
    {
        int n,h1,h2,m1,m2;
        int sum1,sum2,maxx=0;
        scanf("%d",&m);
        memset(a,0,sizeof(a));
        while(m--)
        {
            scanf("%d%d:%d%d:%d",&n,&h1,&m1,&h2,&m2);
            sum1=h1*60+m1;
            sum2=h2*60+m2;
            for(i=sum1;i<sum2;i++)
            {
                a[i]+=n;
                maxx=max(maxx,a[i]); 
            }
        }
        printf("%d\n",maxx);
    }
    return 0;
}
