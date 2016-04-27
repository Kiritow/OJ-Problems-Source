#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;
class pack
{
public:
    int real;
    int absed;
    pack(int a):real(a),absed(abs(a)) {}
};

bool cmp(const pack& a,const pack& b)
{
    return a.absed>b.absed;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) return 0;
        vector<pack> bus;
        for(int i=0; i<n; i++)
        {
            int tmp;
            cin>>tmp;
            bus.push_back(pack(tmp));
        }
        sort(bus.begin(),bus.end(),cmp);
        for(int i=0; i<n-1; i++)
        {
            cout<<bus.at(i).real<<" ";
        }
        cout<<bus.at(n-1).real<<" "<<endl;
    }
    return 0;
}
