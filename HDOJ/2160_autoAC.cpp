#include<iostream>
using namespace std;
int pig[22];
int main()
{
    int t,n,i;
    pig[1]=1;pig[2]=2;pig[3]=3;
    for(i=4;i<=20;i++)
        pig[i]=pig[i-1]+pig[i-1]-pig[i-3];
    cin>>t;
    while(t--)
    {
        cin>>n;
        cout<<pig[n]<<endl;
    }
    return 0;
}
