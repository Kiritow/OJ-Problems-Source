#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=40000;
int T;
int n;
long long a[100],x,cnt;
long long vis[maxn];
int main()
{
    scanf("%d",&T);
    while(T--){
        memset(vis,0,sizeof(vis));
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%I64d",&a[i]);
        cnt=0;
        for(int i=0;i<n;i++){
            x=a[i];
            for(long long j=2;j*j<=x;j++){
                while(x%j==0){
                    x/=j;
                    vis[cnt++]=j;
                }
            }
            if(x>1)
                vis[cnt++]=x;
        }
        sort(vis,vis+cnt);
        if(cnt<2)
            printf("-1\n");
        else
            printf("%I64d\n",vis[0]*vis[1]);
    }
    return 0;
}
