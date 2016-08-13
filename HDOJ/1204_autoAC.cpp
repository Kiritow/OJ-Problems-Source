#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
int main()
{
    int N,M;
    double p,q,rate,k;
    while(cin>>N>>M>>p>>q)
    {
        if(N==0){cout<<"0.00"<<endl;continue;}
        if(M==0){cout<<"1.00"<<endl;continue;}
        if(p==0||q==1){cout<<"0.00"<<endl;continue;}
        if(q==0||p==1){cout<<"1.00"<<endl;continue;}
        if(p==q) rate=1.0*N/(M+N);   
        else
        {
            k = q*(1-p)/(p*(1-q));
            rate = (1.0-pow(k,N))/(1.0-pow(k,M+N));      
        }
        cout<<fixed<<setprecision(2)<<rate<<endl;    
    }
    return 0;
}
