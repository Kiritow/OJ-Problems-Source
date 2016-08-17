#include <cstdio>
#include<algorithm>
#include<cstring>
#include<functional>
using namespace std;
int a[10001][101];
int b[10001];
int main()
{
    int n,m,t,i,k,j,x,d;
    while(scanf("%d%d%d",&n,&m,&t)!=EOF)
    {
        x=0;
        for(i=0;i<n;i++)
        for(j=0;j<m;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            x++;
        }
        memset(b,0,sizeof(b));
        k=0;
        for(i=1;i<n;i++)
        {
            if(a[i][0]==0&&a[i][1]==0)
            {
                for(j=m-1;j>=0;j--)
                {
                    if(a[i-1][j]==0)
                        b[k]++;
                    else
                    break;
                 }
              k++;
            }
        }
        for(i=m-1;i>=0;i--)
        {
            if(a[n-1][i]==0)
                x--;
            else
                break;
        }
        sort(b,b+k,greater<int>());
        for(i=0;i<t-1;i++)
        x-=b[i];
        printf("%d\n",x-2*t);
    }
    return 0;
}
