#include <iostream>
#include <map>
#include <ctime>
#include <algorithm>
using namespace std;
int a[15],n,m,ans;
int fun(int num)
{
    if(num == 0)return 1;
    int sum=1,i;
    for(i=2;i<=num;i++)sum*=i;
    return sum;
}
void dfs(int num,int sum,int ma)
{
    if(sum>m)return ;
    if(num == n)
    {
        if(sum == m)
        {
            ans+=fun(m)/ma;
        }
        return ;
    }
    int i;
    for(i=0;i<=a[num];i++)
    {
        dfs(num+1,sum+i,ma*fun(i));
    }
}
int main()
{
    int i,j;
    while(~scanf("%d %d",&n,&m))
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        ans=0;
        dfs(0,0,1);
        printf("%d\n",ans);
    }
    return 0;
}
