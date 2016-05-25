#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main()
{
    vector<int> bus;
    bus.clear();
    int tmp;
    for(int i=0;i<10;i++)
    {
        cin>>tmp;
        bus.push_back(tmp);
    }
    int x;
    for(x=0;x<10;x++)
    {
        if(bus[x]!=x+1)
        {
            break;
        }
    }
    if(x==10)
    {
        cout<<"10 9 8 7 6 5 4 3 2 1"<<endl;
        return 0;
    }
    sort(bus.begin(),bus.end());
    for(int i=9;i>=0;i--)
    {
        cout<<bus[i]<<" ";
    }
    cout<<endl;
    return 0;
}
