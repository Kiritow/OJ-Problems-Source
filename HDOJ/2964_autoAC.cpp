#include <iostream>
#include <cstring>
using namespace std;
const int prime[21]= {2,3,5,7,11,13,17,19,23,29,31,37,39,41,43,47,51,53,57,59};
int a[21];
__int64 bases[21];
int main()
{
    bases[0]=1;
    for(int i=1; i<=20; i++)
        bases[i]=bases[i-1]*prime[i-1];
    int n,r;
    while(cin>>n&&n)
    {
        for(int i=0; i<=20; i++)
        {
            if(bases[i]<=n && bases[i+1]>n)
            {
                r=i;
                break;
            }
        }
        memset(a,0,sizeof(a));
        int m=n;
        for(int i=r; i>=0; i--)
        {
            a[i]=n/bases[i];
            n=n%bases[i];
        }
        cout<<m<<" = ";
        for(int i=0; i<=r; i++)
        {
            if(a[i])
            {
                cout<<a[i];
                for(int j=0; j<i; j++)
                    cout<<"*"<<prime[j];
                if(i!=r)
                    cout<<" + ";
            }
        }
        cout<<endl;
    }
    return 0;
}
