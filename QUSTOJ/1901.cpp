#include <iostream>

using namespace std;

int main()
{
    int a,b,c;
    char x;
    int n;
    cin>>n;
    while(n--)
    {
        cin>>a>>x>>b>>x>>c;
        cout<<a<<":"<<b<<":"<<c<<endl;
        c+=2;
        if(c>=60) {b++;c-=60;}
        if(b>=60) {a++;b-=60;}
        if(a>=24) {a-=24;}
        cout<<a<<":"<<b<<":"<<c<<endl;
    }
    return 0;
}
