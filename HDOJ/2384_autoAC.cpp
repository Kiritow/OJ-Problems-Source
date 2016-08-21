#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<map>
using namespace std;
int cas,t,r;
struct Team
{
    char name[25];
    int pid[15];
    int pid_fs[15];
    int icount;
    int tol_time;
    int a[15],fa[15];
} team[55];
int findTeam(char xx[])
{
    for(int i=0; i<t; i++)
        if(strcmp(xx,team[i].name)==0)
            return i;
    return -1;
}
int cmp( const void *a , const void *b )
{
    struct Team *c = (Team *)a;
    struct Team *d = (Team *)b;
    if(c->icount != d->icount)
        return d->icount - c->icount;
    else if(c->tol_time!=d->tol_time)
        return c->tol_time - d->tol_time;
    else
    {
        for(int i=c->icount; i>=1; i--)
        {
            if(c->a[i] != d->a[i])
                return c->a[i] - d->a[i];
            else if(c->fa[i] != d->fa[i])
                return d->fa[i] - c->fa[i];
        }
    }
    return strcmp(c->name,d->name);
}
void print()
{
    printf("1 %s %d %d\n",team[0].name,team[0].icount,team[0].tol_time);
        int c1=1,c2=1;
        for(int i=1; i<t; i++)
        {
            if(team[i-1].icount==team[i].icount)
            {
                if(team[i-1].tol_time==team[i].tol_time)
                {
                    for(int j=team[i].icount; j>=1; j--)
                    {
                        if(team[i-1].a[j]==team[i].a[j])
                        {
                            if(team[i-1].fa[j]==team[i].fa[j])
                            {
                                ;
                            }
                            else
                            {
                                c1=c1+c2;
                                printf("%d %s %d %d\n",c1,team[i].name,team[i].icount,team[i].tol_time);
                                c2=1;
                                goto to;
                            }
                        }
                        else
                        {
                            c1=c1+c2;
                            printf("%d %s %d %d\n",c1,team[i].name,team[i].icount,team[i].tol_time);
                            c2=1;
                            goto to;
                        }
                    }
                    c2++;
                    printf("%d %s %d %d\n",c1,team[i].name,team[i].icount,team[i].tol_time);
to:
                    ;
                }
                else
                {
                    c1=c1+c2;
                    printf("%d %s %d %d\n",c1,team[i].name,team[i].icount,team[i].tol_time);
                    c2=1;
                }
            }
            else
            {
                c1=c1+c2;
                printf("%d %s %d %d\n",c1,team[i].name,team[i].icount,team[i].tol_time);
                c2=1;
            }
        }
}
int main()
{
    scanf("%d",&cas);
    int ti,index,id;
    char name[25],res[15],ch;
    while(cas--)
    {
        scanf("%d %d",&t,&r);
        for(int i=0; i<t; i++)
        {
            scanf("%s",team[i].name);
            team[i].tol_time=0;
            team[i].icount=0;
            for(int j=0; j<15; j++)
            {
                team[i].pid[j]=0;
                team[i].pid_fs[j]=0;
            }
        }
        for(int i=0; i<r; i++)
        {
            scanf("%d %s %c %s",&ti,name,&ch,res);
            if(ti<=300)
            {
                index=findTeam(name);
                if(index==-1)
                    continue;
                id=ch-'A';
                if(team[index].pid[id]==1)
                    continue;
                else
                {
                    if(strcmp(res,"accepted")==0)
                    {
                        team[index].tol_time+=ti+team[index].pid_fs[id];
                        team[index].pid[id]=1;
                        team[index].icount++;
                        team[index].a[team[index].icount]=ti;
                        team[index].fa[team[index].icount]=ti+team[index].pid_fs[id];
                    }
                    else
                    {
                        team[index].pid_fs[id]+=20;
                    }
                }
            }
        }
        qsort(team,t,sizeof(team[0]),cmp);
        print();
    }
}
