#include <cstring>  
#include <iostream>  
#include <algorithm>  
#include <cmath>  
#include <cstdio>  
using namespace std;  
const int maxn = 1000010 ;  
int a[maxn],b[maxn];  
int n,k;  
int solve(int n)  
{  
    int i=0,j=0;  
    a[0]=1,b[0]=1;  
    while(a[i]<n)  
    { 
        i++;  
        a[i]=b[i-1]+1;  
        while(a[j+1]*k<a[i])  
            j++;  
        if(a[j]*k<a[i])  
            b[i]=b[j]+a[i];
        else  
            b[i]=a[i];  
    }  
    if(n==a[i])  
        return -1;  
    int ans;  
   while(n)  
   {  
       if(n>=a[i])  
            n-=a[i],ans=a[i];  
       i--;  
   }  
   return ans;  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int cas=1;cas<=t;cas++)  
    {  
        scanf("%d%d",&n,&k);  
        int ans = solve(n);  
        printf("Case %d: ",cas);  
        if(ans==-1)  
            printf("lose\n");  
        else  
            printf("%d\n",ans);  
    }  
    return 0;  
}
