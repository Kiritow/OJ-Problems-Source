#include<iostream>
#include<string.h>
#include<cstdio>
using namespace std;
#define M 1000
int num[M],a[M],b[M];
int  c1[M],c2[M];
#define mod 100
#define LL long long
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        for(int i=0;i<n;i++)
            cin>>a[i]>>b[i];
        memset(c1,0,sizeof(c1));
        memset(c2,0,sizeof(c2));
        for(int i=a[0];i<=b[0];i++)
        {
            c1[i]=1;
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                for(int k=a[i];k+j<=m&&k<=b[i];k++)
                {
                    c2[j+k]+=c1[j];
                }
            }
            for(int j=0;j<=m;j++)
            {
                c1[j]=c2[j];
                c2[j]=0;
            }
        }
        cout<<c1[m]<<endl;
    }
    return 0;
}
