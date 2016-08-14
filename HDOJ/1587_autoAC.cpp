#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        vector<int> v;
        int t;
        while(n--)
        {
            cin>>t;
            v.push_back(t);
        }
        sort(v.begin(),v.end());
        cout<<(m/v[0])<<endl;
    }
    return 0;
}
