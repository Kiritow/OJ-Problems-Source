#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
map<string,int> mp;
map<int,string> sp;
int head[2500];
int n,m,pos,cn;
struct edge
{
    int v,next;
}eg[2500*2500];
struct visit
{
    int v,cnt;
}vd[2500];
bool cmp(visit a,visit b)
{
    if(a.cnt==b.cnt)return sp[a.v]<sp[b.v];
    return a.cnt>b.cnt;
}
void find(int s)
{
    int vs[2500];int num=0;
    memset(vs,-1,sizeof(vs));
    bool vid[2500]={0};
    for(int i=0;i<2500;i++)vd[i].cnt=0;
    for(int i=head[s];i!=-1;i=eg[i].next)
        vid[eg[i].v]=1;
    for(int i=head[s];i!=-1;i=eg[i].next)
    {
        for(int j=head[eg[i].v];j!=-1;j=eg[j].next)
        {
            if(eg[j].v==s||vid[eg[j].v]==1)continue;
            if(vs[eg[j].v]==-1)
            {
                vd[num].v=eg[j].v;
                vd[num].cnt++;
                vs[eg[j].v]=num++;
            }
            else
                vd[vs[eg[j].v]].cnt++;
        }
    }
    sort(vd,vd+num,cmp);
    if(vd[0].cnt==0)printf("-");
    else
    {
        cout<<sp[vd[0].v];
        for(int i=1;i<num;i++)
        {
            if(vd[i].cnt==vd[0].cnt)
            {
                cout<<' '<<sp[vd[i].v];
            }
        }
    }
    printf("\n");
}
int main()
{
    int T,t,x,y;
    char s1[100],s2[100];
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        pos=1,cn=0;
        memset(head,-1,sizeof(head));
        mp.clear();sp.clear();
        scanf("%d%d",&n,&m);
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",s1);
            scanf("%s",s2);
            getchar();
            if(mp[s1]==0)
            {
             mp[s1]=pos;
             sp[pos++]=s1;
            }
            if(mp[s2]==0)
            {
             mp[s2]=pos;
             sp[pos++]=s2;
            }
            x=mp[s1];y=mp[s2];
            eg[cn].v=y;eg[cn].next=head[x];head[x]=cn++;
            eg[cn].v=x;eg[cn].next=head[y];head[y]=cn++;
        }
        printf("Case %d:\n",t);
        for(int i=0;i<m;i++)
        {
            scanf("%s",s1);
            getchar();
            int tem=mp[s1];
            find(tem);
        }
    }
    return 0;
}
