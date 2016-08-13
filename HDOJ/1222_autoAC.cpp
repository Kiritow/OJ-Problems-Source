#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
__int64 gcd(__int64 a,__int64 b){
    if(a<b)return gcd(b,a);
    if(!b)return a;
    return gcd(b,a%b);
}
int main(void){
    __int64 n,T,m;
    cin>>T;
    while(T--){
        cin>>m>>n;
        if(gcd(m,n)==1)cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
