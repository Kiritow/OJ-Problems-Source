#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int tmp;
    vector<int> vec;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        vec.push_back(tmp);
    }
    int p;
    cin>>p;
    tmp=vec.at(p-1);
    vec.at(p-1)=vec.at(p-2);
    vec.at(p-2)=tmp;
    for(int i=n-1;i>=1;i--)
    {
        cout<<vec.at(i)<<" ";
    }
    cout<<vec.at(0)<<endl;
    return 0;
}
