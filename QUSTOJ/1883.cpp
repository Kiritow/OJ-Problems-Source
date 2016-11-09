#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct pack
{
    string man,woman;
};
int main()
{
    int n;
    cin>>n;
    queue<string> manbus;
    queue<string> womanbus;
    string name,sexual;
    while(n--)
    {
        cin>>name>>sexual;
        if(sexual=="M")
        {
            manbus.push(name);
        }
        else
        {
            womanbus.push(name);
        }
    }
    cout<<"The dancing partners are:"<<endl;
    while(!manbus.empty()&&!womanbus.empty())
    {
        cout<<womanbus.front()<<"  "<<manbus.front()<<endl;
        manbus.pop();
        womanbus.pop();
    }
    if(!manbus.empty())
    {
        cout<<"The first man to get a partner is:"<<manbus.front()<<endl;
    }
    else if(!womanbus.empty())
    {
        cout<<"The first woman to get a partner is:"<<womanbus.front()<<endl;
    }

    return 0;
}
