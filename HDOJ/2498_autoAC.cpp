#include<iostream>
using namespace std;
int f(int x)
{
    int sum=0;
    while(x)
    {
        x=x/10;
        sum++;
    }
    return sum;
}
int main()
{
    string a;
    while(cin>>a)
    {
        if(a[0]=='E'){break;}
        int l=a.size();
        if(l==1&&a[0]=='1'){cout<<1<<endl;continue;}
        for(int i=1;;i++)
        {
            if(l==f(l))
            {
                cout<<i+1<<endl;break;
            }
            else
            {
                l=f(l);
            }
        }
    }
    return 0;
}
