#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#define N 1000000
using namespace std;
struct ty
{
    int x,y,len,bj;
    int linkx[75];
    int linky[75];
}pipe[50];
struct ty2
{
    int v,bj,link;
}f[120];
int ans;
int ok()
{
    int i,j,ii,flag[50],k;
    ans=0;
    memset(flag,0,sizeof(flag));
    flag[1]=1;
    for(i=0;i<=110;i++)f[i].link=-1;
    for(i=0;i<=110;i++)
    {
        if((pipe[1].y<=i)&&(i<pipe[1].y+pipe[1].len))f[i].v+=1;
        if(i<pipe[1].y)f[i].v+=10000000;
    }
    for(j=1;j<=pipe[1].linky[0];j++)
        f[pipe[1].linky[j]].link=pipe[1].linkx[j];
    if(pipe[1].bj!=-1)f[pipe[1].bj].bj=1;
    while(1)
    {
        for(i=110;i>=0;i--)
        {
            if(f[i].v>=10000000)return f[i+2].bj;
            if(f[i+1].bj==1)return 1;
            ans+=f[i].v;
            f[i].v=0;
            if((f[i].link>=0)&&(flag[f[i].link]==0))
            {
                k=f[i].link;
                f[i].link=-1;
                flag[k]=1;
                for(j=0;j<=110;j++)
                {
                    if((pipe[k].y<=j)&&(j<pipe[k].y+pipe[k].len))f[j].v+=1;
                    if(j<pipe[k].y)f[j].v+=1000000000;
                }
                for(j=1;j<=pipe[k].linky[0];j++)
                      f[pipe[k].linky[j]].link=pipe[k].linkx[j];
                if(pipe[k].bj!=-1)f[pipe[k].bj].bj=1;
                break;
            }
        }
        if(i==-1)return 0;
    }
}
int main()
{
    int t,p,l,x,y,len,t1,t2;
    scanf("%d",&t);
    while(t--)
    {
        memset(pipe,0,sizeof(pipe));
        memset(f,0,sizeof(f));
        scanf("%d",&p);
        for(int i=1;i<=p;i++)
        {
            scanf("%d%d%d",&pipe[i].x,&pipe[i].y,&pipe[i].len);
            pipe[i].bj=-1;
        }
        scanf("%d",&l);
        for(int i=1;i<=l;i++)
        {
            scanf("%d%d%d",&x,&y,&len);
            for(int j=1;j<=p;j++)
            {
                if(pipe[j].x+1==x)t1=j;
                if(pipe[j].x==x+len)t2=j;
            }
            pipe[t1].linkx[++pipe[t1].linkx[0]]=t2;
            pipe[t1].linky[++pipe[t1].linky[0]]=y;
            pipe[t2].linkx[++pipe[t2].linkx[0]]=t1;
            pipe[t2].linky[++pipe[t2].linky[0]]=y;
        }
        scanf("%d%d",&x,&y);
        pipe[x].bj=y;
        if(y<pipe[x].y||y>pipe[x].y+pipe[x].len){printf("No Solution\n");continue;}
        if(ok())printf("%d\n",ans);
        else    printf("No Solution\n");
    }
    return 0;
}
