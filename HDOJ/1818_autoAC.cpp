#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
int n,m;
int v[1100005];
struct node
{
    int yes;
    int no;
    int kill;
    int add;
    int time;
}tr[105];
struct node1
{
    int bug;
    int step;
    bool operator < (const node1 &a)const
    {
        return step > a.step;
    }
};
priority_queue <node1> Q;
bool ok(int bug,node t)
{
    if((t.no&bug)!=0)return false;
    if((t.yes&bug)!=t.yes)return false;
    return true;
}
int fix(int bug,node t)
{
    int tmp=bug;
    bug=((~t.kill)&bug);
    bug=(t.add|bug);
    if(tmp==bug)return -1;
    return bug;
}
void bfs()
{
    node1 w,e;
    while(!Q.empty())
    {
        w=Q.top();
        Q.pop();
        if(w.bug==0){printf("Fastest sequence takes %d seconds.\n",w.step);return;}
        //cout<<"----"<<endl;
        for(int k=0;k<m;k++)
        {
            e=w;
            if(ok(w.bug,tr[k]))
            {
                e.bug=fix(e.bug,tr[k]);
                if(e.bug<0)continue;
                e.step += tr[k].time;
                if(v[e.bug]!=-1 && e.step >= v[e.bug])continue;
                v[e.bug] = e.step;
                Q.push(e);
            }
        }
    }
    printf("Bugs cannot be fixed.\n");
}
int main()
{
    char a[200],b[200];
    node1 w;
    int CASE=1;
    while(scanf("%d%d",&n,&m)!=EOF && n && m)
    {
        int g = 0;
        g = (1 <<n) - 1;
        memset(v,-1,sizeof(v));
        memset(tr,0,sizeof(tr));
        while(!Q.empty())Q.pop();
        for(int i=0;i<m;i++)
        {
            scanf("%d %s %s",&tr[i].time,a,b);
            {
                for(int j=0;j<n;j++)
                {
                    if(a[j]=='+')
                    tr[i].yes+=(1<<(n-j-1));
                    else if(a[j]=='-')
                    tr[i].no+=(1<<(n-j-1));
                }
                for(int j=0;j<n;j++)
                {
                    if(b[j]=='+')
                    tr[i].add+=(1<<(n-j-1));
                    else if(b[j]=='-')
                    tr[i].kill+=(1<<(n-j-1));
                }
            }
        }
        w.bug = g;
        w.step=0;
        Q.push(w);
        printf("Product %d\n",CASE++);
        bfs();
        putchar(10);
    }
    return 0;
}
