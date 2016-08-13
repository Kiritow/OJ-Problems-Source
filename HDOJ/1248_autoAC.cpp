#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int temp;
        cin>>temp;
        int m1=temp/150;
        int m2=temp/200;
        int m3=temp/350;
        int sum=temp;
        for(int i=0;i<=m1;++i)
            for(int j=0;j<=m2;++j)
            for(int k=0;k<=m3;++k)
        {
            int sum1=temp-150*i-200*j-350*k;
            if(sum1<sum&&sum1>=0)
                sum=sum1;
        }
        cout<<sum<<endl;
    }
    return 0;
}
