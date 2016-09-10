#include<iostream>
#include<map>
#define ll long long
#define maxn 100+5
using namespace std;
ll a[maxn];
map<int,int>mapp;
int main()
{
    int n;
    while(cin>>n)
    {
        mapp.clear();
        ll sum=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            for(int j=0;j<i;j++)
            {
                if(mapp.find(a[i]+a[j])==mapp.end())
                {
                    sum+=(a[i]+a[j]);
                    mapp[a[i]+a[j]]=1;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
