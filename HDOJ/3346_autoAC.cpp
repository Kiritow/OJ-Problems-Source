#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
    int n,m,sum1,sum2;
    cin>>n; 
    while(n--)
    {
    cin>>m;
    sum1=0;
    sum2=0;
    if(m%8==0)
    {cout<<"Lucky number!"<<endl;}
    else
    {
    while(m)
    {
    sum1+=m%10;
    sum2+=(m%10)*(m%10);
    m=m/10;
    }
    if(sum1%8==0||sum2%8==0)
    cout<<"Lucky number!"<<endl;
    else
    cout<<"What a pity!"<<endl;
    }
    }
    return 0;
}
