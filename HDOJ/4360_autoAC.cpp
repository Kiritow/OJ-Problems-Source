#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long lld;
const int mn=3333;
const int mm=33333;
const lld oo=1e15;
int  reach[mm], ne[mm], flow[mm], ch[mm];
lld  head[mn], que[mn], dis[mn][4], cnt[mn][4], inque[mn];
int n, edge;
void addedge(int u, int v, int c1, int c2,  char c)
{
    ch[edge]=c, reach[edge]=v, flow[edge]=c1, ne[edge]=head[u], head[u]=edge++;
    ch[edge]=c, reach[edge]=u, flow[edge]=c2, ne[edge]=head[v], head[v]=edge++;
}
int find(char c)
{
   if(c=='L') return 0;
   else if(c=='O') return 1;
   else if(c=='V') return 2;
   else return 3;
}
bool spfa()
{
    int l=0, h=0;
    memset(inque,0,sizeof(inque));
    for(int i=1; i<=n; i++)
        for(int j=0; j<4; j++) dis[i][j]=oo, cnt[i][j]=0;
    inque[1]=1;
    dis[1][0]=0;
    que[l++]=1;
    while(l!=h)
    {
        int u=que[h++];
        if(h==mn) h=0;
        inque[u]=0;
        for(int i=head[u]; i>=0; i=ne[i])
        {
            int s=find(ch[i]), v=reach[i], val=flow[i];
            if(dis[v][(s+1)%4]>=dis[u][s]+val)
            {
                if(dis[v][(s+1)%4]==dis[u][s]+val)
                {
                    if(cnt[u][s]+1>cnt[v][(s+1)%4]) cnt[v][(s+1)%4]=cnt[u][s]+1;
                    else continue;
                }
                else
                {
                    dis[v][(s+1)%4]=dis[u][s]+val;
                    cnt[v][(s+1)%4]=cnt[u][s]+1;
                }
                if(!inque[v])
                {
                    inque[v]=1;
                    que[l++]=v;
                    if(l==mn) l=0;
                }
            }
        }
    }
    if(dis[n][0]==oo||!cnt[n][0]) return false;
    else return true;
}
int main()
{
    int m, T, tcase=0;
    cin >> T;
    while(T--)
    {
        cin >> n >> m;
        edge=0;
        memset(head,-1,sizeof(head));
        int mp[4]={0,0,0,0}, ct=0;
        while(m--)
        {
            int u, v, val, se;
            char sh[3];
            scanf("%d%d%d%s",&u,&v,&val,sh);
            addedge(u,v,val,val,sh[0]);
            if(n==1&&u==1&&v==1)
            {
                se=find(sh[0]);
                if(!mp[se]) ct++, mp[se]=val;
                else mp[se]=min(mp[se],val);
            }
        }
        if(ct==4)
        {
           lld sum=mp[0]+mp[1]+mp[2]+mp[3];
           printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",++tcase,sum,ct/4);
           continue;
        }
        bool ok=spfa();
        if(!ok) printf("Case %d: Binbin you disappoint Sangsang again, damn it!\n",++tcase);
        else printf("Case %d: Cute Sangsang, Binbin will come with a donkey after travelling %I64d meters and finding %d LOVE strings at last.\n",++tcase,dis[n][0],cnt[n][0]/4);
    }
    return 0;
}
