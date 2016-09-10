#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
    set<int>s1,s2;
    int n;
    while(~scanf("%d",&n))
    {
        s1.clear();
        s2.clear();
        int tt;
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&tt);
            s1.insert(tt);
        }
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&tt);
            s2.insert(tt);
        }
        if(s1.size() != s2.size())
        {
            printf("NO\n");
            continue;
        }
        int flag = 0;
        set<int>::iterator it1, it2;
        for(it1 = s1.begin(),it2 = s2.begin(); it1!=s1.end()&&it2!=s2.end(); it1++,it2++)
        {
            if(*it1 != *it2)
            {
                flag = 1;
                break;
            }
        }
        if(flag)
        {
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}
