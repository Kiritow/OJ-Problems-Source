#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;
#define MAXN 10010
#define MP(x,y) make_pair(x,y)
#define FI first
#define SE second
map<pair<int,int>,int>ma;
const int dis[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
struct _no
{
    int x,y,c;
    int to[4];
    _no(int _x,int _y)
    {
        x=_x,y=_y;
        c=-1;
        for(int i=0;i<4;++i)    to[i]=-1;
    }
    _no(){}
}no[MAXN];
int top,fa[MAXN],col[MAXN],xy[MAXN];
int que[MAXN];
bool vi[MAXN];
int findfa(int n)
{
    if(fa[n]!=n)
        fa[n]=findfa(fa[n]);
    return fa[n];
}
inline void smu(int a,int b)
{
    a=findfa(a),b=findfa(b);
    if(a==b)    return ;
    fa[b]=a;
    col[a]+=col[b];
}
void del(int h)
{
    int he=0,ta=0;
    que[ta++]=h;
    while(he<ta)
    {
        h=que[he++];
        for(int i=0;i<4;++i)
        {
            int p=no[h].to[i];
            if(p!=-1)
            {
                if(no[p].c==no[h].c&&!vi[p])
                    que[ta++]=p,vi[p]=1;
                else    if(no[p].c==!no[h].c)
                    ++col[findfa(p)];
            }
        }
        no[h].c=-1;
    }
}
int main()
{
    int ncase,n;
    scanf("%d",&ncase);
    while (ncase--)
    {
        memset(vi,0,sizeof(vi));
        top=0;
        ma.clear();
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            if(ma.find(MP(x,y))==ma.end())
            {
                ma[MP(x,y)]=top;
                xy[i]=top;
                no[top++]=_no(x,y);
            }
            else    xy[i]=ma[MP(x,y)];
        }
        for(int i=0;i<top;++i)
            for(int j=0;j<4;++j)
            {
                int tx=no[i].x+dis[j][0],ty=no[i].y+dis[j][1];
                map<pair<int,int>,int> ::iterator ite=ma.find(MP(tx,ty));
                if(ite!=ma.end())
                    no[i].to[j]=ite->SE;
            }
        for(int i=0;i<n;++i)    fa[i]=i,col[i]=0;
        for(int i=0;i<n;++i)
        {
            int p=xy[i];
            int c=no[p].c=i&1;
            vi[p]=0;
            for(int j=0;j<4;++j)
            {
                int tx=no[p].x+dis[j][0],ty=no[p].y+dis[j][1];
                if(tx>0&&ty>0&&(no[p].to[j]==-1||no[no[p].to[j]].c==-1))
                    ++col[p];
            }
            for(int j=0;j<4;++j)
            {
                int tmp=no[p].to[j];
                if(tmp!=-1&&no[tmp].c!=-1)
                {
                    --col[findfa(tmp)];
                    if(no[tmp].c==c)
                        smu(tmp,p);
                }
            }
            for(int j=0;j<4;++j)
            {
                int tmp=no[p].to[j];
                if(tmp!=-1&&no[tmp].c==!c&&col[findfa(tmp)]==0)
                    del(tmp);
            }
            for(int j=0;j<4;++j)
            {
                int tmp=no[p].to[j];
                if(tmp!=-1&&no[tmp].c==c&&col[findfa(tmp)]==0)
                    del(tmp);
            }
            if(no[p].c!=-1&&col[findfa(p)]==0)   del(p);
        }
        int nb=0,nw=0;
        for(int i=0;i<top;++i)
            if(no[i].c==0)
                ++nb;
            else    if(no[i].c==1)
                ++nw;
        printf("%d %d\n",nb,nw);
    }
    return 0;
}
