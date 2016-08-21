#include<iostream>
using namespace std;
long long powe(int n);
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int *p=new int[n];
        for(int i=0;i!=n;++i)
            cin>>p[i];
        int i;
        for(i=0;i!=m;++i)
        {
            if(p[i]==1)
                break;
        }
        long long sum;
        if(i==m)
           sum=10000*(powe(n-i)-1);
        if(i<m)
           sum=10000*(powe(n-i-1)-1);
        cout<<sum<<" RMB\n";
    }
}
long long powe(int n)
{
    long long sum=1;
    for(int i=1;i<=n;++i)
        sum*=2;
    return sum;
}
