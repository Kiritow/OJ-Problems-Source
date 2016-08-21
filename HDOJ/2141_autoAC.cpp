#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1000002;
int sum[maxn];
int a_1[maxn];
int  b_1[maxn];
int c_1[maxn];
int main()
{
    int a,b,c;
    int i,j,k=0;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        cout<<"Case "<<++k<<":"<<endl;
    for(i=0;i<a;i++)
    {
        scanf("%d",&a_1[i]);
    }
    for(i=0;i<b;i++)
    {
        scanf("%d",&b_1[i]);
    }
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            sum[b*i+j]=a_1[i]+b_1[j];
        }
    }
    sort(sum,sum+a*b);
    for(i=0;i<c;i++)
    {
        scanf("%d",&c_1[i]);
    }
    int t,x,n;
    scanf("%d",&t);
    int flag;
    while(t--)
    {
        scanf("%d",&x);
      flag=0;
        for(i=0;i<c;i++)
        {
            if((binary_search(sum,sum+a*b,x-c_1[i])!=0))
                {
                    flag=1;
                }
        }
        if(flag==1)
        cout<<"YES"<<endl;
        else
        {
            cout<<"NO"<<endl;
        }
    }
    }
    return 0;
}
