#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
using namespace std;  
double solve0(int m,int n)  
{  
    double ans=0;  
    for(int i=0;i<=n-1;i++)  
        ans+=pow(1.0*m,i);  
    return ans;  
}  
double solve1(int m,int n)  
{  
    double ans=0;  
    double tmp=1;  
    for(int i=1;i<=n;i++)  
    {  
        ans+=tmp;  
        tmp*=(m+0.0)/(m-i);  
    }  
    return ans;  
}  
int main()  
{  
    int t;  
    while(scanf("%d",&t)!=EOF)  
    {  
        while(t--)  
        {  
            int n,m,op;  
            scanf("%d%d%d",&op,&m,&n);  
            if(op==0)  
                printf("%.9lf\n",solve0(m,n));  
            else  
                printf("%.9lf\n",solve1(m,n));  
        }  
    }  
    return 0;  
}
