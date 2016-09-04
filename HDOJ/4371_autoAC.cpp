#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int test,n,m,tmin,t,i,k;
    scanf("%d",&test);
    for(k=1;k<=test;k++)
    {
        tmin=1000000;
        scanf("%d %d",&n,&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&t);
            if(tmin>t)
                tmin=t;
        }
        n=n/tmin;
        if(n&1) printf("Case #%d: Bob\n",k);
        else printf("Case #%d: Alice\n",k);
    }
    return 0;
}
