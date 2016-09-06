#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<set>
#include<vector>
#include<string>
#define LL long long
#define N 25
using namespace std;
int num[N];
int n,summ,xj,xk;
int Case;
struct node
{
    int x,y,z;
    bool operator < (const struct node &a) const
    {
        return (x!=a.x)?(x<a.x):(y!=a.y?(y<a.y):(z<a.z));
    }
}temp,ans;
set<struct node> hashx;
void dfs(int);
int main()
{
    scanf("%d",&Case);
    for(int c=0;c<Case;c++)
    {
        summ=0;hashx.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&num[i]);
            summ+=num[i];
        }
        temp.x=num[1];temp.y=0;
        if(n<3)
        {
            printf("%d\n",0);
            continue;
        }
        dfs(2);
        printf("%d\n",hashx.size());
    }
    return 0;
}
void dfs(int x)
{
    if(x>n)
    {
                xj=temp.x;
                xk=temp.y;
                if(((xj+xk)>(summ-xj-xk))&&(summ-xk>xk)&&(summ-xj>xj))
                {
                    ans.x=max(xj,max(summ-xj-xk,xk));
                    ans.z=min(xj,min(summ-xj-xk,xk));
                    if(xj!=ans.x&&xj!=ans.z) ans.y=xj;
                    else if(xk!=ans.x&&xk!=ans.z) ans.y=xk;
                    else ans.y=summ-ans.x-ans.z;
                    hashx.insert(ans);
                }
                return;
    }
    dfs(x+1);
    temp.x+=num[x];
    dfs(x+1);
    temp.x-=num[x];
    temp.y+=num[x];
    dfs(x+1);
    temp.y-=num[x];
}
