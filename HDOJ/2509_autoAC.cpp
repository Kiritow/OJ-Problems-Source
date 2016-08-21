#include<iostream>
using namespace std;
int main()
{
    int N,x,i,s,a;
    while(cin>>N)
    {
        s=a=0;
        for (i=0;i<N;i++)
        {
            cin>>x;
            s^=x;
            if(x>1)
                a=1;
        }
        if(a==0)
        {
            if(N%2)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
        else
        {
            if(s==0)
                cout<<"No"<<endl;
            else
                cout<<"Yes"<<endl;
        }
    }
    return 0;
}
