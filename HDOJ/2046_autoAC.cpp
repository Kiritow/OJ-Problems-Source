#include<iostream>
int main()
{
    using namespace std;
    __int64 a[51]={0,1,2},n;
    for(int i=3;i<=50;i++)
        a[i]=a[i-1]+a[i-2];
    while(cin>>n)
    {
        cout<<a[n]<<endl;
    }
}
