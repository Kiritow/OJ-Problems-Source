/**
LINK=
http://acm.hust.edu.cn/vjudge/contest/view.action?cid=115784#problem/F
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

#define MAXN 105

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        vector<int> pool[MAXN*2+8];
        for(int i=0;i<n;i++)
        {
            int a,b;
            scanf("%d %d",&a,&b);
            pool[a].push_back(b);
        }
        int k=INT_MAX;
        int cnt=0;
        for(int i=0;i<MAXN*2+8;i++)
        {
            if(k<i)
            {
                ++cnt;
                k=INT_MAX;
            }
            for(int j=0;j<pool[i].size();j++)
            {
                k=min(k,pool[i].at(j));
            }
        }
        if(k<INT_MAX)
        {
            ++cnt;
        }
        printf("%d\n",cnt);
    }
    /// End of main loop
    return 0;
}
