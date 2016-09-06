#include<iostream>
using namespace std;
int main()
{
    int s,a,b,c,t,d=1;
    cin>>s;
    while(s--)
    {
        cin>>a>>b>>c;
        if(a<b)
        {
            t=a;
            a=b;
            b=t;
        }
        if(a<c)
        {
            t=a;
            a=c;
            c=t;
        }
        cout<<"Case "<<d++<<": ";
        if(b*b+c*c==a*a) cout<<"Right triangle"<<endl;
        else if(b*b+c*c<a*a) cout<<"Obtuse triangle"<<endl;
        else cout<<"Acute triangle"<<endl;
    }
    return 0;
}
