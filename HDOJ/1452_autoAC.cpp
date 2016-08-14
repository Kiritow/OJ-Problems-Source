#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <vector>
#include <cmath>
#include <string>
#include <stack>  
#include <queue>
using namespace std;
const int n=29;
long long pow_mod(long long a,long long i,long long n)
{    if(i==0)    return 1;
    int temp=pow_mod(a,i>>1,n);
        temp=temp*temp%n;
    if(i&1)    temp=(long long)temp*a%n;
    return    temp; 
}
int main()
{    int X,S;
    while(cin>>X)
    {    if(X==0)    break;
        S=((pow_mod(2,2*X+1,n)+28)*(pow_mod(3,X+1,n)+28)*(pow_mod(167,X+1,n)+28)*9)%n;
        cout<<S<<endl;
    }
    return 0;
}
