#include<iostream>
#include<math.h>
#define PI 3.1415926
using namespace std;
int main(){
    int m;
    double x, y;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        double s = PI * (x * x + y * y);
        int count = s / 100 + 1;
        cout<<"Property "<<i + 1<<
            ": This property will begin eroding in year "<<count<<"."<<endl;
    }
    cout<<"END OF OUTPUT."<<endl;
}
