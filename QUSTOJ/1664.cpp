#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
 
using namespace std;
 
 
class seat
{
public:
    friend bool operator < (const seat&,const seat&);
    friend bool operator > (const seat&,const seat&);
    int x,width;
};
 
bool operator < (const seat& a,const seat& b)
{
    return (a.x<b.x);
}
 
bool operator > (const seat& a,const seat& b)
{
    return (a.x>b.x);
}
 
vector<seat> pos;
seat tmp;
 
int main()
{
    int n,m,i;
    while(cin>>n>>m)
    {
        pos.clear();
        for(i=0;i<n;i++)
        {
            cin>>tmp.x>>tmp.width;
            pos.push_back(tmp);
        }
        sort(pos.begin(),pos.end());
        int count=2;
        for(i=0;i<n-1;i++)
        {
            double ans=pos[i+1].x-pos[i].x-pos[i+1].width/2.0-pos[i].width/2.0-m;
            if(ans>0)
            {
                count+=2;
            }
            else if(ans<0)
            {
                continue;
            }
            else
            {
                ++count;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}
