#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        int x,t=0,a,b,c;
        cin>>x;
        a=x/2;
        b=(x-a)*2/3;
        c=x-a-b;
        t+=a/10;
        if(a%10)
            t++;
        t+=b/10;
        if(b%10)
            t++;
        t+=c/10;
        if(c%10)
            t++;
        cout<<t<<endl;
    }
}
