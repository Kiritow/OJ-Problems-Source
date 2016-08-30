#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1005;
int pre[N],count[N];
void build(int n)
{
    int i;
    for(i=1;i<=n;i++)    {pre[i]=i;count[i]=0;}
}
int find(int k)
{
    if(pre[k]==k)    return k;
    pre[k]=find(pre[k]);
    return pre[k];
}
void get_map(int m)
{
    int a,b,f1,f2;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        f1=find(a);
        f2=find(b);
        if(f1==f2)    count[f1]++;
        else
        {
            pre[f2]=f1;
            count[f1]+=count[f2]+1;
        }
    }
}
int Judge(int n)
{
    int flag=0;
    for(int i=1;i<=n;i++)
    {
        if(pre[i]!=i)    continue;
        if(count[i]%2)    {flag=1;break;}
    }
    return flag;
}
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        build(n);
        get_map(m);
        if(Judge(n))    cout<<"No"<<endl;
        else            cout<<"Yes"<<endl;
    }
    return 0;
}
