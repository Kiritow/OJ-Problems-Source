#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    int n;
    cin>>n;
    int tmp;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        vec.push_back(tmp);
    }
    int m;
    cin>>m;
    bool flag=false;
    for(int i=0;i<n;i++)
    {
        if(vec.at(i)==m)
        {
            flag=true;
            vec.erase(vec.begin()+i);
            for(int j=0;j<n-2;j++)
            {
                cout<<vec.at(j)<<" ";
            }
            cout<<vec.at(n-2)<<endl;
            cout<<"You deleted "<<m<<endl;

            break;///BREAK??
        }
    }
    if(!flag)
    {
        cout<<"sorry,what you delete is not in the list."<<endl;
    }

    return 0;
}
