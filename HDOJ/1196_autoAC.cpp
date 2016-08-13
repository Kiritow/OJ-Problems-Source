#include<iostream>
using namespace std;
int lowbit(int x)
{
    return x&-x;
}
int main()
{
    int n;
    while(cin>>n&&n)
        cout<<lowbit(n)<<endl;
    return 0;
}
