#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<cstring>
#include<map>
#define MAX_V 110
#define INF 0x7ffffff
using namespace std;
map <string,int> name;
int ans[MAX_V][MAX_V],d[MAX_V][MAX_V],dd[MAX_V][MAX_V];
bool ok[MAX_V][MAX_V];
int main()
{
    int n,m,a,b;
    while(~scanf("%d%d",&n,&m))
    {
        memset(d,0,sizeof(d));
        memset(ans,0,sizeof(ans));
        memset(ok,0,sizeof(ok));
        while(m--)
        {
            scanf("%d%d",&a,&b);
            ans[a][b]=ans[b][a]=d[a][b]=d[b][a]=1;
            ok[a][b]=ok[b][a]=1;
        }
        int times=6;
        while(times--){
            memset(dd,0,sizeof(dd));
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    for(int k=0;k<n;k++){
                        dd[i][j]+=ans[i][k]*d[k][j];
                    }
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    ans[i][j]=dd[i][j];
                }
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ans[i][j]!=0) ok[i][j]=1;
                }
            }
        }
        int flag=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(ok[i][j]==0)
                    flag=0;
            }
        }
        puts(flag?"Yes":"No");
    }
    return 0;
}
