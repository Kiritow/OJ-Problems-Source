#include <cstdio>  
#include <iostream>  
#include <cmath>  
#include <algorithm>  
#include <cstring>  
using namespace std;  
typedef __int64 LL;  
LL mod;  
struct Matrix  
{  
    LL m[3][3];  
}E,D;  
LL a,b,n;  
void init()  
{  
    for(int i=1;i<=2;i++)  
        for(int j=1;j<=2;j++)  
            E.m[i][j]=(i==j);  
    D.m[1][1]=1;  
    D.m[1][2]=1;  
    D.m[2][1]=1;  
    D.m[2][2]=0;  
}  
Matrix Multi(Matrix A,Matrix B)  
{  
    Matrix ans;  
    for(int i=1;i<=2;i++)  
        for(int j=1;j<=2;j++)  
        {  
            ans.m[i][j]=0;  
            for(int k=1;k<=2;k++)  
                ans.m[i][j]=(ans.m[i][j]+A.m[i][k]*B.m[k][j])%mod;  
        }  
    return ans;  
}  
Matrix Pow(Matrix A,LL k)  
{  
    Matrix ans=E;  
    while(k)  
    {  
        if(k&1)  
        {  
            k--;  
            ans=Multi(ans,A);  
        }  
        else  
        {  
            k/=2;  
            A=Multi(A,A);  
        }  
    }  
    return ans;  
}  
LL Fib(LL n)  
{  
    if(n==0)  
        return 1;  
    Matrix ans=Pow(D,n);  
    return ans.m[1][1]%mod;  
}  
void Print(Matrix A)  
{  
    for(int i=1;i<=2;i++)  
    {  
        for(int j=1;j<=2;j++)  
            cout<<A.m[i][j]<<" ";  
        cout<<endl;  
    }  
}  
LL get(Matrix A,Matrix B,LL fib)  
{  
    Matrix ans=Pow(A,fib-1);  
    ans=Multi(ans,B);  
    return ans.m[1][1];  
}  
LL Pow(LL a,LL b)  
{  
    LL ans=1;  
    while(b)  
    {  
        if(b&1)  
        {  
            b--;  
            ans=(ans*a)%mod;  
        }  
        else  
        {  
            b/=2;  
            a=(a*a)%mod;  
        }  
    }  
    return ans;  
}  
int main()  
{  
    init();  
    int t;  
    cin>>t;  
    init();  
    while(t--)  
    {  
        cin>>a>>b>>n>>mod;  
        LL aa=(1+Pow(a,(mod-1)/2))%mod;  
        LL bb=(1+Pow(b,(mod-1)/2))%mod;  
        if(aa==0||bb==0)  
        {  
            cout<<0<<endl;  
            continue;  
        }  
        Matrix T,cnt;  
        T.m[1][1]=2*(a+b)%mod;  
        T.m[1][2]=-(a-b)*(a-b)%mod;  
        T.m[2][1]=1;  
        T.m[2][2]=0;  
        cnt.m[1][1]=2*(a+b)%mod;  
        cnt.m[2][1]=2;  
        LL tmp;  
        mod--;  
        tmp=Fib(n);  
        mod++;  
        LL ans=get(T,cnt,tmp);  
        ans=4*ans%mod;  
        if(ans<0)  
            ans+=mod;  
        cout<<ans<<endl;  
    }  
    return 0;  
}
