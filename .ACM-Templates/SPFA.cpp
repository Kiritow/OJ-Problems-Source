/** SPFA 单源最短路径算法 不支持负环*/
namespace SPFA
{
const int MAXN = 1005;
int d[MAXN];/// distance [ From S to ... ]
int v[MAXN];/// visit
int q[MAXN];/// 基于数组的队列(也可用queue等...)
int mp[MAXN][MAXN]; /// mp[i][j] ???<--> j ?? ?1??
int n;

int spfa(int s,int t)
{
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    /*
    for(int i=1;i<MAXN;i++)
        d[i]=INF,v[i]=0;*/
    int cnt=0;
    q[cnt++]=1;
    v[1]=1;
    d[1]=0;
    while(cnt>0)
    {
        int c=q[--cnt];
        v[c]=0;
        for(int i=1;i<=n;i++)
        {
            if(mp[c][i]!=-1&&d[i]>d[c]+mp[c][i])
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q[cnt++]=i;
            }
        }
    }
    return d[t];
}

}/// End of NameSpace SPFA
