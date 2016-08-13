#include<iostream>
#include<iomanip>
int point(double );
using namespace std;
int main()
{
    int n;
    while(cin>>n)
    {
        double sum=0,s,p,c=0;
        while(n--)
        {
            cin>>s>>p;
            if(p==-1)
                continue;
            else
            {
                sum+=s;
                c+=s*point(p);
            }
        }
        if(c==0)
            cout<<"-1\n";
        else
            cout<<setiosflags(ios::fixed)<<setprecision(2)<<c/sum<<endl;
    }
    return 0;
}
int point(double g)
{
    if(g>=90)
        return 4;
    else if(g>=80)
        return 3;
    else if(g>=70)
        return 2;
    else if(g>=60)
        return 1;
    else
        return 0;
}
