/** SPFA 单源最短路径算法 不支持负环*/
namespace SPFA
{
const int MAXN = 1005;
int d[MAXN];/// distance [ From S to ... ]
int v[MAXN];/// visit
int q[MAXN];/// 基于数组的队列(也可用queue等...)
int mp[MAXN][MAXN]; /// mp[i][j] i<--> j is connected.
int n;/// n is the number of max Point .

void spfa(int StartPoint) /// d[i] is the min distance from StartPoint to i ( Both >=1 )
{
    memset(d,0x3f,sizeof(d));
    memset(v,0,sizeof(v));
    /*
    for(int i=1;i<MAXN;i++)
        d[i]=INF,v[i]=0;*/
    int cnt=0;
    q[cnt++]=StartPoint;
    v[StartPoint]=1;
    d[StartPoint]=0;
    while(cnt>0)
    {
        int c=q[--cnt];
        v[c]=0;
        for(int i=1;i<=n;i++)
        {
            /// Here : if your mp[i][j] use INF as infinite, then use mp[c][i]!=INF.
            /// Or you may use mp[i][j]!=-1 && d[i] > d[c] + mp[c][i]
            if( mp[c][i]!=INF && d[i]>d[c]+mp[c][i] )
            {
                d[i]=d[c]+mp[c][i];
                if(!v[i])   v[i]=1,q[cnt++]=i;
            }
        }
    }
}

}/// End of NameSpace SPFA
