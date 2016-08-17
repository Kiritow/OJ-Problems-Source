#include<iostream>
using namespace std;
int main()
{
    int k,m,x,n;
    while(cin>>n)
    {
        k=1;
        x=2;
        if(n%2==0||n==1)
            cout<<"2^? mod "<<n<<" = 1"<<endl;
        else
        {
            while(k++)
            {
                x*=2;
                x=x%n;
                if(x==1)
                break;
            }
        cout<<"2^"<<k<<" mod "<<n<<" = 1"<<endl;
    }
    }
    return 0;
}
