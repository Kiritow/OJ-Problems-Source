#include<iostream>
#include<cmath>
#include<cstdio> 
using namespace std;
const double s = (sqrt(5.0)+1.0)/2;
int main()
{
    int n,i;
    double bit;
    int fac[21] = { 0 , 1 };
    for(i = 2; i < 21; i++) 
        fac[i] = fac[i-1] + fac [i-2];
    while(cin >> n)
    {
        if(n <= 20) {
            cout << fac[n] << endl;
            continue;
        }
        else{
            bit = -0.5*log(5.0)/log(10.0)+((double)n)*log(s)/log(10.0);
            bit = bit - floor(bit); 
            bit = pow(10.0,bit); 
            while(bit < 1000) 
                bit = 10.0 * bit; 
            cout << (int)bit << endl;    
        }
    }
    return 0;
}
