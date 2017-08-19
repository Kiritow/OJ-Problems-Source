#include <vector>
#include <cstdio>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        vector<int> vec;
        int temp;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            vec.push_back(temp);
        }
        sort(vec.begin(),vec.end(),greater<int>());
        int cnt=1;
        for(int i=0;i<n-1;i++)
        {
            if(vec[i]-vec[i+1]<=k) ++cnt;
            else break;
        }
        printf("%d\n",cnt);
    }

    return 0;
}