#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    int p[1001],vis[1001],k=0;
    memset(vis,0,sizeof(vis));
    memset(p,0,sizeof(p));
    for(int i=2; i*i<=1000; i++) 
        for(int j=i*i; j<=1000; j+=i)
            vis[j]=1;
    for(int i=1; i<=1000; i++)
        if(!vis[i])
            p[k++]=i;
    int n,m;
    while(cin>>n>>m)
    {
        int sum=0;
        for(int i=1; i<=n; i++)
            if(!vis[i])
                sum++;
        int c=(sum>>1)-m+(sum&1);
        c=(c<0)?0:c;
        printf("%d %d:", n, m);
        for(int i=c; i<c+2*m-(sum&1)&&i<sum; i++) 
            printf(" %d",p[i]);
        printf("\n\n");
    }
    return 0;
}
