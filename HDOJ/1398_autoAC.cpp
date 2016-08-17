#include<iostream>
using namespace std;
int main()
{
    int a[350],b[350],i,j,k,n;
    while(cin>>n&&n)
    {
        for(i=0;i<=n;i++)
        {
            a[i]=1;
            b[i]=0;
        }
        for(i=2;i<=17;i++)
        {
            for(j=0;j<=n;j++)
                for(k=0;k+j<=n;k+=i*i)
                    b[k+j]+=a[j];
            for(j=0;j<=n;j++)
            {
                a[j]=b[j];
                b[j]=0;
            }
        }
        cout<<a[n]<<'\n';
    }
    return 0;
}
