#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long n,m,v,k;
        cin>>n>>m>>v>>k;
        if(m>=n)
        {
            cout<<0<<endl;
        }
        else
        {
            int co=0;
            while(m<n)
            {
                if((m-v)*k>m)
                {
                    m=(m-v)*k;
                    co++;
                }
                else
                {
                    co=-1;
                    break;
                }
            }
            cout<<co<<endl;
        }
    }
    return 0;
}
