#include<iostream>
#include<cstdio>
#include<memory.h>
using namespace std;
const int MAX=100005;
int s[MAX],h[MAX];
int n,a;
__int64 ans;
void merge(int l,int m,int r)
{
    int i=l,j=m+1,k=l;
    while(i<=m&&j<=r)
    {
        if(s[i]<s[j])
        {
            ans+=r-j+1;
            h[k++]=s[i++];
        }
        else
        {
            h[k++]=s[j++];
        }
    }
    while(i<=m)
            h[k++]=s[i++];
    while(j<=r)
            h[k++]=s[j++];
    for(i=l;i<=r;i++)
        s[i]=h[i];
}
void mergesort(int l,int r)
{
    int m=(l+r)/2;
    if(l<r)
    {
        mergesort(l,m);
        mergesort(m+1,r);
        merge(l,m,r);
    }
}
int main()
{
    int i,j,T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&a);
        s[0]=0;
        ans=0;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&j);
            j-=a;
            s[i]=s[i-1]+j;
        }
        mergesort(0,n);
        cout<<ans<<endl;
    }
    return 0;
}
