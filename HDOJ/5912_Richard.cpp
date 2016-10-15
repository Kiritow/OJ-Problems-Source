#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

long long gcd(long long x,long long y)
{
    return y?gcd(y,x%y):x;
}

int main()
{
    int t;
    cin>>t;
    for(int cases=1;cases<=t;cases++)
    {
        int n;
        cin>>n;
        long long a[20];
        long long b[20];
        for(int i=1;i<=n;i++)
            cin>>a[i];
        for(int i=1;i<=n;i++)
            cin>>b[i];
        long long fenzi=b[n];
        long long fenmu=a[n];
        long long fenzi2=fenzi;
        long long fenmu2=fenmu;
        for(int i=n-1;i>=1;i--)
        {
            fenzi2=b[i]*fenmu;
            fenmu2=fenmu*a[i]+fenzi;
            long long temp=gcd(fenzi2,fenmu2);
            fenzi=fenzi2/temp;
            fenmu=fenmu2/temp;
        }
        long long temp=gcd(fenzi2,fenmu2);
        fenzi=fenzi2/temp;
        fenmu=fenmu2/temp;
        cout<<"Case #"<<cases<<": ";
        cout<<fenzi<<" "<<fenmu<<endl;
    }
    return 0;
}
