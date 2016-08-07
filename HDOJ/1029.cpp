#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        int target=(n+1)/2;
        int tmp,ans;
        map<int,int> p;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            p[tmp]++;
        }
        for(map<int,int>::iterator iter=p.begin();iter!=p.end();iter++)
        {
            if(iter->second >=target)
            {
                ans=iter->first;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
