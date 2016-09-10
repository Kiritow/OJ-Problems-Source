#include <iostream>  
#include <cstdlib>  
#include <cstdio>  
using namespace std;  
long long C[1000005] = {0LL};  
long long spow(long long x, int n)  
{  
    if (n == 1)   
        return x;  
    else {  
        long long v = spow(x, n/2);  
        if (n%2 == 0) return v*v%1000000007LL;
        else return v*v%1000000007LL*x%1000000007LL;
    }  
}
int main()  
{  
    C[1] = 1LL;  
    for (int i = 2 ; i < 1000001 ; ++ i) {  
        C[i] = C[i-1]*(4*i-2)%1000000007LL;   
        C[i] = C[i]*spow(i+1, 1000000005)%1000000007LL;
    }
    int n,m;  
    while (cin >> n)
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> m;
        cout << "Case #" << i << ":" << endl;
        cout << C[m] << endl;
    }
    return 0;  
}
