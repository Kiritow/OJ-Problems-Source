#include<iostream>
#define N 100010
using namespace std;
int a[N],d[N];
int main()
{
    int test,n,i,max,k,f,e;
    cin>>test;
    k=1;
    while(test--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            cin>>a[i];
        d[1]=a[1];
        for(i=2;i<=n;i++)
        {
            if(d[i-1]<0) d[i]=a[i];
            else d[i]=d[i-1]+a[i];
        }
        max=d[1];e=1;
        for(i=2;i<=n;i++)
        {
            if(max<d[i])
            {
                max=d[i];e=i;
            }
        }
        int t=0;
        f=e;
        for(i=e;i>0;i--)
        {
            t=t+a[i];
            if(t==max)    f=i;
        }
        cout<<"Case "<<k++<<":"<<endl<<max<<" "<<f<<" "<<e<<endl;
        if(test) cout<<endl;
    }
    return 0;
}
