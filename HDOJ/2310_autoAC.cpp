#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
struct data
{
    int p,t;
    bool lg;
    data(){}
    data(int _p,int _t,bool _lg){p=_p;t=_t;lg=_lg;}
};
vector<data> po[10005];
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(int i=1;i<=m;i++)
            po[i].clear();
        int r,q,t,nn,mm,s;
        scanf("%d",&r);
        for(int i=0;i<r;i++)
        {
            scanf("%d%d%d%d",&t,&nn,&mm,&s);
            po[mm].push_back(data(nn,t,s));
        }
        scanf("%d",&q);
        for(int i=0;i<q;i++)
        {
            int x,y,len,ans=0,lx;
            scanf("%d%d%d",&x,&y,&mm);
            lx=x;
            len=po[mm].size();
            int cnt=0;
            for(int j=0;j<len;j++)
            {
                if(po[mm][j].t>y)
                {
                    if(cnt>0)
                        ans+=y-lx;
                    break;
                }
                else if(po[mm][j].t>=x)
                {
                    if(cnt>0)
                        ans+=po[mm][j].t-lx;
                    lx=po[mm][j].t;
                }
                if(po[mm][j].lg)
                    cnt++;
                else
                    cnt--;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
