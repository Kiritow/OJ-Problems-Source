#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char mp[1024][1024];

int cat=0;
int girl=0;

void dp_girl(int i,int j,int step)
{
    switch(step)
    {
        case 1:if(mp[i][j]!='i') return;break;
        case 2:if(mp[i][j]!='r') return;break;
        case 3:if(mp[i][j]!='l') return;else ++girl;return;break;
    }
    dp_girl(i+1,j,step+1);
    dp_girl(i,j+1,step+1);
    dp_girl(i-1,j,step+1);
    dp_girl(i,j-1,step+1);
}

void dp_cat(int i,int j,int step)
{
    switch(step)
    {
        case 1:if(mp[i][j]!='a') return;break;
        case 2:if(mp[i][j]!='t') return;else ++cat;return;
    }
    dp_cat(i+1,j,step+1);
    dp_cat(i,j+1,step+1);
    dp_cat(i-1,j,step+1);
    dp_cat(i,j-1,step+1);
}////
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        cat=0;
        girl=0;
        memset(mp,0,1024*1024);
        for(int i=1;i<=n;i++)
        {
            scanf("%s",&mp[i][1]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(mp[i][j]=='g') dp_girl(i,j,0);
                else if(mp[i][j]=='c') dp_cat(i,j,0);
            }
        }
        printf("%d %d\n",girl,cat);
    }
    return 0;
}
