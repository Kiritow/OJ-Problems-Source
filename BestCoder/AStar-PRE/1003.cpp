#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

/// std::cin and std::cout is so slow.
struct ippack
{
    int a,b,c,d;
};

int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        printf("Case #%d:\n",tt);
        vector<ippack> ip;
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n;i++)
        {
            ippack s;
            scanf("%d.%d.%d.%d",&s.a,&s.b,&s.c,&s.d);
            ip.push_back(s);
        }
        for(int i=0;i<m;i++)
        {
            vector<unsigned long> ans;
            ippack s;
            scanf("%d.%d.%d.%d",&s.a,&s.b,&s.c,&s.d);
            for(int j=0;j<n;j++)
            {
                ippack k=ip.at(j);
                k.a&=s.a;
                k.b&=s.b;
                k.c&=s.c;
                k.d&=s.d;
                unsigned long tmp=(k.a<<24)|(k.b<<16)|(k.c<<8)|(k.d);
                int sz=ans.size();
                bool flag_isfound=false;
                for(int k=0;k<sz;k++)
                {
                    if(ans.at(k)==tmp)
                    {
                        flag_isfound=true;
                        break;
                    }
                }
                if(!flag_isfound)
                {
                    ans.push_back(tmp);
                }
            }
            printf("%d\n",ans.size());
        }
    }
    return 0;
}
