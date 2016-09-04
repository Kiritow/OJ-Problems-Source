#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
typedef long long LL;
void Solve(LL a,LL b,LL n)
{
    LL cnt=0;
    LL max=b+a*n;
    for(LL i=0;i<64;i++)
    {
        LL m=(LL)1<<i;
        LL mm=m;
        if(m>max) break;
        m<<=1;
        LL cur=a+b;
        LL j=0;
        while(j<m&&j<n)
        {
            LL upper=cur+(mm-(cur%mm))-(LL)1;
            LL step=(upper-cur)/a+(LL)1;
            if(j+step>=n) step=n-j;
            if(j+step>=m) step=m-j;
            if(cur&(LL)1<<i)
            {
                cnt+=step*(n/m);
                if(j+step<(n%m)) cnt+=step;
                else if(j<(n%m)) cnt+=(n%m)-j;
            }
            cur+=a*step;
            j+=step;
        }
    }
    cout<<cnt<<endl;
}
int main()
{
    int t,k=1;
    LL a,b,n,i,j;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>n;
        cout<<"Case #"<<k++<<": ";
        Solve(a,b,n);
    }
    return 0;
}
