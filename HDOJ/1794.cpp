#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int mp[31][31];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        vector<int> zerocntvec;
        int zerocnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                scanf("%d",&mp[i][j]);
                if(mp[i][j]==0)
                {
                    ++zerocnt;
                    int cnt=1;
                    for(int sz=2;sz<=n;sz++)
                    {
                        for(int line=0;line<sz;line++)
                        {
                            for(int col=0;col<sz;col++)
                            {
                                /// 求这个方框的左上角和右下角
                                int luline=i-line;
                                int lucol=j-col;
                                int rdline=i+sz-line-1;
                                int rdcol=j+sz-col-1;
                                if(luline>=0&&lucol>=0&&rdline<n&&rdcol<n) ++cnt;
                            }
                        }
                    }
                    zerocntvec.push_back(cnt);
                }
            }
        }
        int m;
        scanf("%d",&m);
        vector<int> fillvec;
        for(int i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            fillvec.push_back(x);
        }
        sort(zerocntvec.begin(),zerocntvec.end(),greater<int>());
        sort(fillvec.begin(),fillvec.end(),greater<int>());
        long long ans=0;
        for(int i=0;i<zerocnt;i++)
        {
            ans+=zerocntvec[i]*fillvec[i];
        }
        printf("%lld\n",ans);
    }
    return 0;
}
