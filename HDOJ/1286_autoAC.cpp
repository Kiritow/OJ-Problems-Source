#include<iostream>
using namespace std;
const int maxn=32790;
int euler[maxn+2];
void make()
{
    euler[1]=0;
    for(int i=2;i<=maxn;++i)
        euler[i]=i;
    for(int i=2;i<=maxn;++i)
        if(euler[i]==i)
            for(int j=i;j<=maxn;j+=i)
                euler[j]=euler[j]/i*(i-1);
}
int main()
{
    make();
    int n,t,sum;
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<euler[n]<<endl;
    }
    return 0;
}
