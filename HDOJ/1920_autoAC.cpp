#include <iostream>
#define ll long long
using namespace std;
ll gcd(ll a,ll b){
    return b?gcd(b,a%b):a;
}
ll lcm(ll a,ll b){
    return a*b/gcd(a,b);
}
int main()
{
    int T,n;
    cin>>T;
    while(T--){
            cin>>n;
            ll t=0;
            cin>>t;
            for(int i=2;i<=n;i++){
                   ll tmp;
                   cin>>tmp;
                   t=lcm(t,tmp);
            }
            if(t<=1e9)
                cout<<t<<endl;
            else
                cout<<"More than a billion."<<endl;
    }
    return 0;
}
