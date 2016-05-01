#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
int data[101][101];
bool vis[101][101];
int ans[101][101];
 
int d(int i,int j,int MaxDepth)
{
    if(i==MaxDepth)
    {
        return data[i][j];
    }
    if(vis[i][j])
    {
        return ans[i][j];
    }
    int ret_a=d(i+1,j,MaxDepth);
    int ret_b=d(i+1,j+1,MaxDepth);
    int ret=(ret_a>ret_b)?(ret_a):(ret_b);
    ret+=data[i][j];
    ans[i][j]=ret;
    vis[i][j]=true;
    return ret;
}
int main()
{
    int n;
    scanf("%d",&n);
    int t;
    for(;n>0;n--)
    {
        scanf("%d",&t);
        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=i;j++)
            {
                scanf("%d",&data[i][j]);
            }
        }
        printf("%d\n",d(1,1,t));
        memset(vis,false,sizeof(bool)*101*101);
    }
    return 0;
}
