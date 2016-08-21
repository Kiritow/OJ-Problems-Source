#include<stdio.h>
#include<iostream>  
#include<algorithm>  
using namespace std;
int main()
{
    int t,n,i,a[10010],cun[10010],j,max;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            cun[i]=1;
        }
        sort(a,a+n);j=0;
        for(i=0;i<n;i++)
        {
            if(a[i]==a[i+1])
            cun[j]++;
            else
            j++;
        }
        max=cun[0];
        for(i=1;i<=j;i++)
        {
            if(cun[i]>max)
            max=cun[i];
        }
        printf("%d\n",max);
    }
    return 0;
 }
