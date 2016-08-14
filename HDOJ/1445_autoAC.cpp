#include<iostream>
#include<cmath>
using std::cin;
using std::cout;
using std::endl;
int main() {
    while(true) {
        int N;
        cin>>N;
        if(!N)
            break;
        double mint=1e36;
        double v,t0;
        while(N--) {
            cin>>v>>t0;
            if(t0>=0&&ceil(t0+4500*3.6/v)<mint)
                mint=ceil(t0+4500*3.6/v);
        }
        cout<<static_cast<long>(mint)<<endl;
    }
    return 0;
}
