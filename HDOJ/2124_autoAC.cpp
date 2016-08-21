#include<iostream>
#include<string>
#include <cstdio>
#include <cmath>
#include<vector>
#include<algorithm>
#include<sstream>
#include<cstdlib>
using namespace std;
typedef __int64 ll;
bool comp(ll a,ll b){
    return a>b;
}
int main()
{
    int n;
    ll L,ai;
    vector<ll> buf;
    while(cin>>L>>n)
    {
         for(int i=0;i<n;i++)
         {
             cin>>ai;
             buf.push_back(ai);
         }
         sort(buf.begin(),buf.end(),comp);
         int min=0;
         ll sum=0;
         for(vector<ll>::size_ i=0;i!=buf.size()&&sum<L;i++)
         {
             if(sum+buf[i]<L){
                 sum+=buf[i];
                 min++;
             }
             else {
                 sum=L;
                 min++;
             }
         }
         if(sum<L)cout<<"impossible"<<endl;
         else cout<<min<<endl;
         buf.clear();
    }
    return 0;
}
