#include<iostream>
using namespace std;
int main()
{
int m,n,i,v;
int w[25],c[25],f[30001];
cin>>m>>n;
for(i=1;i<=n;i++)
{
cin>>w[i]>>c[i];
c[i]*=w[i];
}
for(i=1;i<=n;i++)
for(v=m;v>=w[i];v--)
if(f[v]<f[v-w[i]]+c[i])
f[v]=f[v-w[i]]+c[i];
cout<<f[m];
return 0;
}
