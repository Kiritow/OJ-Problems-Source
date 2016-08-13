#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[10002];
double b[10002];
double p[10002]; 
int n,m;
void dp()
{
    memset(p,0,sizeof(p));
    for(int i=1;i<=m;++i)
    {
        for(int j=n;j>=a[i];--j)
            p[j]=max(p[j],1-(1-p[j-a[i]])*(1-b[i]));
    }
}
int main()
{
    while(cin>>n>>m&&(m+n))
    {
        for(int i=1;i<=m;++i)
            cin>>a[i]>>b[i];
        dp();
        printf("%.1f%%\n",p[n]*100);
    }
    return 0;
}
