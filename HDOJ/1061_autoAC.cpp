#include <iostream>
#include <stdio.h>
using namespace std;
bool l[10];
int r[10];
int main()
{
    int t;
    while(cin>>t)
    {
        while(t--)
        {
            memset(l,0,sizeof(l));
            memset(r,0,sizeof(r));
            unsigned long n;
            cin>>n;
            int a=n%10;
            int b=a;
            int i=1;
            l[b]=true;r[0]=b;
            b=(b*a)%10;
            while(!l[b])
            {
                l[b]=true;
                r[i++]=b;
                b=(b*a)%10;
            }
            cout<<r[(n-1)%i]<<endl;
        }
    }
    return 0;
}
