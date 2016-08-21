#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int a[200010],n;
int find(int x)
{
    int i=1,j=n;
    while(i<=j)
    {
        int mid=(i+j)/2;
        if(a[mid]==x||a[mid+1]==x)
            return 1;
        else if(a[mid]<x&&a[mid+1]>x)
            return 0;
        else if(a[mid]>x)
            j=mid-1;
        else
            i=mid+1;
    }
    return 0;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int k;
        cin>>n>>k;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        sort(a+1,a+n+1);
        __int64 sum=0;
        a[0]=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]!=a[i-1]&&a[i]<=k&&find(k-a[i]))
                sum++;
        }
        printf("%I64d\n",sum);
    }
}
