#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    int m;
    double a,b,c;
    cin>>m;
    while(m--){
        cin >> a >> b >> c;
        if(a>b) swap(a,b);
        if(b>c) swap(b,c);
        if(a+b>c) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
