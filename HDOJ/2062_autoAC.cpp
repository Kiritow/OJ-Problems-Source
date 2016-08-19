#include<iostream>
using namespace std;
int main()
{
    int i,n,a[21];
    long long int m,t;
    long long int c[21] ={0};
    for (i=1;i<21;i++)
    {
        c[i]=c[i-1]*(i-1)+1;
    }
    while(cin>>n>>m)
    {
        for(i=0;i<21;i++)
        {
            a[i]=(int)i;
        }
        while(n--&&m)
        {
            if(t=m/c[n+1]+((m%c[n+1])?1:0))
            {
                cout<<a[t];
                for(i=(int)t;i<= n;i++)
                {
                    a[i]=a[i+1];
                }
                m-=(t-1)*c[i]+1;
                if(m==0)
                    cout<<endl;
                else
                    cout<<" ";
            }
        }
    }
    return 0;
}
