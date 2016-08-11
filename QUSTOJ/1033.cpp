#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define INF 0x3f3f3f3f
#define MAXN 21
int pool[MAXN][MAXN][MAXN];

int w(int a,int b,int c)
{
    if(a<=0||b<=0||c<=0) return pool[0][0][0];
    else if(a>20||b>20||c>20) return w(20,20,20);
    if(pool[a][b][c]!=INF) return pool[a][b][c];
    if(a<b&&b<c)
    {
        return pool[a][b][c]=w(a,b,c-1)+w(a,b-1,c-1)-w(a,b-1,c);
    }
    else
    {
        return pool[a][b][c]=w(a-1,b,c)+w(a-1,b-1,c)+w(a-1,b,c-1)-w(a-1,b-1,c-1);
    }
}
int main()
{
    int a,b,c;
    int ans;
    while(scanf("%d %d %d",&a,&b,&c)==3&&!(a==-1&&b==-1&&c==-1))
    {
        memset(pool,0x3f,sizeof(int)*MAXN*MAXN*MAXN);
        pool[0][0][0]=1;
        ans=w(a,b,c);
        printf("w(%d, %d, %d) = %d\n",a,b,c,ans);
    }
    return 0;
}
