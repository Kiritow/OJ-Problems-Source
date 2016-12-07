#include <iostream>
#include <string>

using namespace std;
struct
{
    string a,b,c,d;
}p[5];
int main()
{
    for(int i=0;i<5;i++)
    {
        cin>>p[i].a>>p[i].b>>p[i].c>>p[i].d;
    }
    int n;
    cin>>n;
    --n;
    cin>>p[n].a>>p[n].b>>p[n].c>>p[n].d;
    for(int i=0;i<5;i++)
    {
        cout<<"name:"<<p[i].a<<" address:"<<p[i].b<<" city:"<<p[i].c<<" mail:"<<p[i].d<<endl;
    }
    return 0;
}
