#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int n,i,j;
    while(cin>>n)
    {
        j = 0;
        if(n%2)j = j+1;
        for(i = 2;i<=sqrt(n);i++)
        {
            if(n%i==0)
            {
                if(i%2!=0)j = j+1;
                if(n/i%2!=0)j = j+1;
            }
        }
        cout <<j<<endl;
    }
}
