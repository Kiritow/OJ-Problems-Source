#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    for(int a=3;a!=201;++a)
    {
        for(int i=2;i<=200;++i)
        {
            for(int j=i;j<=200;++j)
            {
                for(int k=j;k<=200;++k)
                {
                    if(i*i*i+j*j*j+k*k*k==a*a*a)
                        cout<<"Cube = "<<a<<", Triple = ("<<i<<","<<j<<","<<k<<")\n";
                }
            }
        }
    }
    return 0;
}
