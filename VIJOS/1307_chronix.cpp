#include <iostream>

int main(){
    long long re,n;
    std::cin>>n;
    re=n*(n+1)*(2*n+1);
    re/=6;
    std::cout<<re;
    return 0;
}
