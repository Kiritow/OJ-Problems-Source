#include <cstdio>  
#include <cmath>  
#include <iostream>  
#include <algorithm>  
#define mod 10007  
int Pow(int a,int b)  
{  
    int ans=1;  
    while(b)  
    {  
        if(b&1)  
        {  
            b--;  
            ans*=a;  
            ans%=(3*mod);  
        }  
        else  
        {  
            b/=2;  
            a*=a;  
            a%=(3*mod);  
        }  
    }  
    return ans;  
}  
int solve(int n)  
{  
    if(n&1)  
    {  
        n++;  
        n/=2;  
        int ans=Pow(4,n-1);  
        ans+=5;  
        ans/=3;  
        return ans%mod;  
    }  
    else  
    {  
        n/=2;  
        int ans=2*Pow(4,n-1);  
        ans+=4;  
        ans/=3;  
        return ans%mod;  
    }  
}  
int main()  
{  
    int t;  
    scanf("%d",&t);  
    for(int i=1;i<=t;i++)  
    {  
        int n;  
        scanf("%d",&n);  
        printf("Case #%d: %d\n",i,solve(n));  
    }  
    return 0;  
}
