#include<iostream>
#include<cmath>
using namespace std;
int main(){
int  i;
long long a[32] = { 0, 0, 0 }, c = 0, b = 2,t;
for (i = 3; i < 32; ++i)
{
    a[i] = a[i - 1] * 4 + (long long)(pow(2, i - 1) - 2) * 2 + (c + b) * 2;
    t = c  + b*2;
    b = (c + b)*2 + 2;
    c = t;
}
for (i = 2; i < 32; ++i)
    cout << "N=" << i <<": " << a[i] << endl;
}
