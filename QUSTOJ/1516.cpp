#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <sstream>
using namespace std;
int cnt[1005];
int main()
{
    int n,tmp;
    while(scanf("%d",&n)==1&&n!=0)
    {
        memset(cnt,0,sizeof(int)*1005);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&tmp);
            ++cnt[tmp];
        }
        int c=0;
        ostringstream ostr;
        for(int i=0;i<1005;i++)
        {
            if(cnt[i])
            {
                ++c;
                ostr<<i<<" ";
            }
        }
        printf("%d\n",c);
        string ans=ostr.str();
        ans.replace(ans.begin()+ans.size()-1,ans.end(),"\0");
        printf("%s\n\n",ans.c_str());
    }
    return 0;
}
 
