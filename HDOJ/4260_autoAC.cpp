#include<iostream>
#include<string>
using namespace std;
string s;
long long cal(long long x,char goal)
{
    for(long long i=x;i>=0;i--)
    if(s[i]!=goal) return cal(i-1,'A'^'B'^'C'^goal^s[i])+(1LL<<i);
    return 0;
}
int main()
{
    while(cin>>s,s!="X")
    {
        long long ans=cal(s.length()-1,'B');
        cout<<ans<<endl;
    }
    return 0;
}
