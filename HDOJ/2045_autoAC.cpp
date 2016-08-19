#include<stdio.h>
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    ll a[51];
    a[1] = 3;
    a[2] = 6;
    a[3] = 6;
    for(int i=4;i<51;++i){
        a[i] = a[i-1] + 2*a[i-2];
    }
    int n;
    while(cin >> n && n){
        cout << a[n] << endl;
    }
}
