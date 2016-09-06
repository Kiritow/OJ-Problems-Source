#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
using namespace std;
int main()
{
    int n, id, p;
    while(cin >> n,n)
    {
        map<int,int>mp;
        mp[1000000000]=1;
        for(int i=1; i<=n; i++)
        {
            scanf("%d%d",&id,&p);
            map<int,int>::iterator it=mp.lower_bound(p);
            if(it==mp.begin()) cout << id << " " << it->second <<endl;
            else
            {
                map<int,int>::iterator a=it, b=--it;
                if((a->first)-p>=p-(b->first))cout << id << " " << b->second <<endl;
                else cout << id << " " << a->second <<endl;
            }
            mp[p]=id;
        }
    }
    return 0;
}
