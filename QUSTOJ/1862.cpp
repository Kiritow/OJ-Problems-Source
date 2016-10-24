#include <iostream>
using namespace std;

class clockx
{
public:

private:
    int y,m,d;
    int h,min,s;
    friend istream& operator >> (istream& is,clockx& c);
    friend ostream& operator << (ostream& os,clockx& c);
};
istream& operator >> (istream& is,clockx& c)
{
    is>>c.y>>c.m>>c.d>>c.h>>c.min>>c.s;
    return is;
}
ostream& operator << (ostream& os,clockx& c)
{
    os<<c.y<<" "<<c.m<<" "<<c.d<<endl<<c.h<<":"<<c.min<<":"<<c.s;
    return os;
}
int main()
{
    clockx s;
    cin>>s;
    cout<<s<<endl;
    return 0;
}
