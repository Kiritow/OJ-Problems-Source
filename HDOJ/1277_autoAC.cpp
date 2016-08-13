#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
struct Tree
{
    int end,n,l[10];
    void init()
    {
        memset(l,-1,sizeof(l));
        end=n=0;
    }
}tr[700000];
int n,m,id;
char s[61000],tt[10000],ss[10005][67];
bool ok[11000];
void add(char*s,int No)
{
    int t=0;
    for(int i=0;s[i];i++)
    {
        int now=s[i]-'0';
        if(tr[t].l[now]==-1)
        {
            tr[id].init();
            tr[t].l[now]=id++;
        }
        t=tr[t].l[now];
    }
    tr[t].end=No;
}
void check(char*s)
{
    int t=0;
    for(int i=0;s[i];i++)
    {
        int now=s[i]-'0';
        if(tr[t].end&&ok[tr[t].end]==0)
        {
             printf(" [Key No. %d]",tr[t].end);
            ok[tr[t].end]=1;
        }
        if(tr[t].l[now]==-1) return;
        t=tr[t].l[now];
    }
}
void init()
{
    scanf("%d%d",&n,&m);
    int l=0;
    for(int i=0;i<n;i++)
    {
        scanf("%s",tt);
        for(int j=0;tt[j];j++) s[l++]=tt[j];
    }
    s[l]=0;
    id=1;
    tr[0].init();
    for(int i=1;i<=m;i++)
    {
        scanf("%s",ss[i]);scanf("%s",ss[i]);
        scanf("%s",ss[i]);scanf("%s",ss[i]);
        add(ss[i],i);
    }
    printf("Found key:");
    for(int i=0;s[i];i++)
    {
        check(s+i);
    }
    puts("");
}
int main()
{
    init();
    return 0;
}
