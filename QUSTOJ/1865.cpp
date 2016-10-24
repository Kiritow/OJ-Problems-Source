#include <iostream>
using namespace std;

double ans[50];
int vis[50];

double dfunc(int n,int x)
{
    if(n==0) return 1;
    if(n==1) return x;
    if(vis[n]) return ans[n];
    vis[n]=1;
    return ans[n]=double((2*n-1)*x*dfunc(n-1,x)-(n-1)*dfunc(n-2,x))/n;
}

int main()
{
    int a,b;
    cin>>a>>b;
    cout<<dfunc(a,b);
    return 0;
}
