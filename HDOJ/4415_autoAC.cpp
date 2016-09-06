#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
struct px
{
    int a,b;
} node;
vector<struct px> a,b;
bool cmp(const struct px &x,const struct px &y)
{
    return x.a<y.a;
}
int main()
{
    int tt;
    int x,y,n,m,ida,idb;
    scanf("%d",&tt);
    for(int cas=1; cas<=tt; ++cas)
    {
        int ans=0,bx=0,mm=0,mn=0,ansn=0;
        a.clear();
        b.clear();
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d%d",&node.a,&node.b);
            if(node.b!=0) a.push_back(node);
            else          b.push_back(node);
        }
        sort(a.begin(),a.end(),cmp);
        sort(b.begin(),b.end(),cmp);
        ida=0;
        idb=b.size()-1;
        for(int i=0; i<b.size(); ++i)
        {
            if(m-mn>=b[i].a)
            {
                ansn++;
                mn+=b[i].a;
            }
        }
        if(a.size()>0&&a[0].a<=m)
        {
            node=a[0];
            mm+=node.a;
            for(int i=0; i<a.size(); i++)
            {
                bx+=(a[i].b-1);
                ans++;
            }
            bx++;
        }
        if(a.size()>0&&a[0].a<=m-mn)
        {
            node=a[0];
            mn+=node.a;
            for(int i=0; i<a.size(); i++)
                ansn++;
        }
        for(; bx!=0&&idb>=0; --idb,--bx,++ans);
        if(idb<0)
        {
            if(ans>ansn) printf("Case %d: %d %d\n",cas,ans,mm);
            else if(ans<ansn) printf("Case %d: %d %d\n",cas,ansn,mn);
            else printf("Case %d: %d %d\n",cas,ansn,mn>mm?mm:mn);
        }
        else
        {
            int i,j;
            for(i=1,j=0; i<a.size()&&j<=idb;)
            {
                if(a[i].a<=b[j].a)
                {
                    if(m>=a[i].a+mm)
                    {
                        mm+=a[i].a;
                        i++;
                        ans++;
                        idb--;
                    }
                    else break;
                }
                else
                {
                    if(m>=b[j].a+mm)
                    {
                        mm+=b[j].a;
                        ans++;
                        j++;
                    }
                    else break;
                }
            }
            for(;j<=idb;++j)
            {
                    if(m>=b[j].a+mm)
                    {
                        mm+=b[j].a;
                        ans++;
                        j++;
                    }
                    else break;
            }
            if(ans>ansn) printf("Case %d: %d %d\n",cas,ans,mm);
            else if(ans<ansn) printf("Case %d: %d %d\n",cas,ansn,mn);
            else printf("Case %d: %d %d\n",cas,ansn,mn>mm?mm:mn);
        }
    }
    return 0;
}
