#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
    int temp;
    while(cin>>temp&&temp!=-1)
    {
        vector<int> v;
        v.push_back(temp);
        while(cin>>temp&&temp!=0)
            v.push_back(temp);
        int sum=0;
        for(int i=0;i!=v.size();++i)
        {
            auto b=find(v.cbegin(),v.cend(),2*v[i]);
            if(b!=v.cend())
                sum++;
        }
        cout<<sum<<endl;
    }
    return 0;
}
