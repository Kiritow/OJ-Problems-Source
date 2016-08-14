#include<cstdio>
#include<cstring>
#define INF 1000000000
#define maxn 1000
struct idiom
{
    char front[5];
    char back[5];
    int T;
};
idiom dic[maxn];
int map[maxn][maxn];
int dist[maxn];
int vis[maxn];
int N;
void dij()
{
    int i,j,k;
    for(i=0; i<N; i++)
    {
        int min=INF,u=0;
        for(j=0; j<N; j++)
        {
            if(!vis[j] && dist[j]<min)
            {
                min=dist[j];
                u=j;
            }
        }
        vis[u]=1;
        for(k=0; k<N; k++)
        {
            if(!vis[k] && map[u][k]<INF && dist[u]+map[u][k]<dist[k])
                dist[k]=dist[u]+map[u][k];
        }
    }
}
int main()
{
    int i,j,k;
    char s[100];
    int len;
    while(scanf("%d",&N)!=EOF)
    {
        if(N==0) break;
        for(k=0; k<N; k++)
        {
            scanf("%d%s",&dic[k].T,s);
            len=strlen(s);
            for(i=0,j=len-1; i<4; i++, j--)
            {
                dic[k].front[i]=s[i];
                dic[k].back[3-i]=s[j];
            }
            dic[k].front[4]=dic[k].back[4]='\0';
        }
        for(i=0; i<N; i++)
        {
            for(j=0; j<N; j++)
            {
                map[i][j]=INF;
                if(i==j) continue;
                if(strcmp(dic[i].back, dic[j].front)==0)
                    map[i][j]=dic[i].T;
            }
        }
        for(i=0; i<N; i++)
        {
            dist[i]=map[0][i];
            vis[i]=0;
        }
        vis[0]=1;
        dist[0]=0;
        dij();
        if(dist[N-1]==INF) printf("-1\n");
        else printf("%d\n",dist[N-1]);
    }
    return 0;
}
