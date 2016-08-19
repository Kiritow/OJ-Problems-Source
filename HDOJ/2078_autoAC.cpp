#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
int a[45];
int main()
{
    int t,m,n,i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        int s=(100-a[0])*(100-a[0]);
        printf("%d\n",s);
    }
    return 0;
}
