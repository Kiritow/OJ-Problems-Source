#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<math.h>
#include<vector>
#include<map>
#include<set>
#include<stdlib.h>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;
typedef __int64 ll;
const int N=200025;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int cnt;
int head[N],inu[N],circ[N];
int dep[N][2],pto[N][2],cto[N][2];
int que[N],lop[N];
int to[N<<1],nxt[N<<1];
void addedge(int u,int v)
{
    to[cnt]=v;nxt[cnt]=head[u];head[u]=cnt++;
    to[cnt]=u;nxt[cnt]=head[v];head[v]=cnt++;
}
//相同路径数的索引号选择
void isvalid(int& a,int& b,int c,int d)
{
    int cmpr=min(a,b)-min(c,d);
    if(cmpr>0 || (cmpr==0 && max(a,b)>max(c,d)))
        a=c,b=d;
}
void bfs(int n)
{
    memset(dep,0,sizeof(dep));
    memset(circ,0,sizeof(circ));
    int tai=0,hed=0,i,u,v;
    for(i=0;i<n;i++)
    {
        if(inu[i]==1)que[tai++]=i;
        pto[i][0]=pto[i][1]=cto[i][0]=cto[i][1]=i;//深度为0，则端点就是本身
    }
    while(tai!=hed)
    {
        u=que[hed++];inu[u]--;
        if(circ[u]==dep[u][0]+dep[u][1])
        {
            isvalid(cto[u][0],cto[u][1],pto[u][0],pto[u][1]);
        }
        else if(circ[u]<dep[u][0]+dep[u][1])
        {
            circ[u]=dep[u][0]+dep[u][1];
            cto[u][0]=pto[u][0];
            cto[u][1]=pto[u][1];
        }
        for(i=head[u];i!=-1;i=nxt[i])
        {
            v=to[i];
            if(inu[v]<=0)continue;
            if(dep[v][0]<dep[u][0]+1)
            {
                if(dep[v][1]<dep[v][0])
                {
                    dep[v][1]=dep[v][0];
                    pto[v][1]=pto[v][0];
                }
                else if(dep[v][1]==dep[v][0] && pto[v][1]>pto[v][0])
                {
                    pto[v][1]=pto[v][0];
                }
                dep[v][0]=dep[u][0]+1;
                pto[v][0]=pto[u][0];
            }
            else if(dep[v][0]==dep[u][0]+1 && pto[v][0]>pto[u][0])
            {
                pto[v][0]=pto[u][0];
            }
            else if(dep[v][1]<dep[u][0]+1)
            {
                dep[v][1]=dep[u][0]+1;
                pto[v][1]=pto[u][0];
            }
            else if(dep[v][1]==dep[u][0]+1 && pto[v][1]>pto[u][0])
            {
                pto[v][1]=pto[u][0];
            }
            if(circ[v]==circ[u])
            {
                isvalid(cto[v][0],cto[v][1],cto[u][0],cto[u][1]);
            }
            else if(circ[v]<circ[u])
            {
                circ[v]=circ[u];
                cto[v][0]=cto[u][0];
                cto[v][1]=cto[u][1];
            }
            if(--inu[v]==1)
            {
                que[tai++]=v;
            }
        }
    }
}
int main()
{
    int t,n,u,v,ans,bestu,bestt,i;
    scanf("%d",&t);
    for(int h=1;h<=t;h++)
    {
        ans=99999999;bestu=99999999;bestt=99999999;
        memset(head,-1,sizeof(head));cnt=0;
        memset(inu,0,sizeof(inu));
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&u,&v);u--,v--;
            addedge(u,v),inu[u]++,inu[v]++;
        }
        bfs(n);
        int lpl=0,max1=-99999999,pmax1=99999999,max2=-99999999,pmax2=99999999;
        for(i=0;inu[i]==0;i++);
        for(u=i;inu[u]>=2;u=to[v])
        {
            lop[lpl++]=u;
            for(v=head[u];v!=-1 && inu[to[v]]<2;v=nxt[v]);
            if(v==-1)break;
            inu[u]--;
        }
        lop[lpl]=lop[0];
        for(i=0;i<lpl;i++)
        {
            if(circ[lop[i]]==dep[lop[i]][0]+dep[lop[i]][1])
            {
                isvalid(cto[lop[i]][0],cto[lop[i]][1],pto[lop[i]][0],pto[lop[i]][1]);
            }
            else if(circ[lop[i]]<dep[lop[i]][0]+dep[lop[i]][1])
            {
                circ[lop[i]]=dep[lop[i]][0]+dep[lop[i]][1];
                cto[lop[i]][0]=pto[lop[i]][0];
                cto[lop[i]][1]=pto[lop[i]][1];
            }
        }
        for(i=0;i<lpl;i++)
        {
            int tmp=2*n-lpl-circ[lop[i]];//s and t are put in the same trees
            if(ans==tmp)
            {
                isvalid(bestu,bestt,cto[lop[i]][0],cto[lop[i]][1]);
            }
            else if(ans>tmp)
            {
                ans=tmp;
                bestu=cto[lop[i]][0];
                bestt=cto[lop[i]][1];
            }
            //notice:The loop can walk without 1 edge
            if(pmax1!=99999999)
            {
                tmp=2*n-(i+dep[lop[i]][0]+max1)-2;
                if(ans==tmp)
                {
                    isvalid(bestu,bestt,pto[lop[i]][0],pto[lop[pmax1]][0]);
                }
                else if(ans>tmp)
                {
                    ans=tmp;
                    bestu=pto[lop[i]][0];
                    bestt=pto[lop[pmax1]][0];
                }
            }
            if(max1<dep[lop[i]][0]-i)
            {
                max1=dep[lop[i]][0]-i;
                pmax1=i;
            }
            else if(max1==dep[lop[i]][0]-i && pto[lop[pmax1]][0]>pto[lop[i]][0])
            {
                pmax1=i;
            }
            if(pmax2!=99999999)
            {
                tmp=2*n-(lpl-i+dep[lop[lpl-i-1]][0]+max2)-2;
                if(ans==tmp)
                {
                    isvalid(bestu,bestt,pto[lop[lpl-i-1]][0],pto[lop[pmax2]][0]);
                }
                else if(ans>tmp)
                {
                    ans=tmp;
                    bestu=pto[lop[lpl-i-1]][0];
                    bestt=pto[lop[pmax2]][0];
                }
            }
            if(max2<dep[lop[lpl-i-1]][0]+i)
            {
                max2=dep[lop[lpl-i-1]][0]+i;
                pmax2=lpl-i-1;
            }
            else if(max2==dep[lop[lpl-i-1]][0]+i && pto[lop[pmax2]][0]>pto[lop[lpl-i-1]][0])
            {
                pmax2=lpl-i-1;
            }
        }
        printf("Case #%d: %d %d %d\n",h,ans,min(bestu,bestt)+1,max(bestu,bestt)+1);
    }
    return 0;
}
