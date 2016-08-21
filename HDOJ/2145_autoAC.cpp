#include<stdio.h>
#include<string.h>
#include<queue>
using namespace std;
int n,m,q;
int e;
struct A
{
    int s;
    int v;
    int num;
    int len;
    double ans;
}E[333];
struct B
{
    int dis;
    int flag;
}city[333];
struct node
{
    int num;
    int dis;
    friend bool operator<(node n1,node n2)
    {
        return n2.dis<n1.dis;
    }
};
struct Eage
{
    int from;
    int to;
    int len;
    int next;
}eage[5055];
int tot;
int head[333];
void add(int a,int b,int c)
{
    eage[tot].from=a;
    eage[tot].to=b;
    eage[tot].len=c;
    eage[tot].next=head[a];
    head[a]=tot++;
}
int cmp(const void *a,const void *b)
{
    struct A *c,*d;
    c=(struct A *)a;
    d=(struct A *)b;
    if(c->ans>d->ans)        return 1;
    else if(c->ans<d->ans)    return -1;
    if(c->len!=d->len)        return d->len-c->len;
    return d->num-c->num;
}
void Dij()
{
    priority_queue<node>q;
    node cur,next;
    int temp;
    cur.num=e;
    cur.dis=0;
    q.push(cur);
    while(!q.empty())
    {
        cur=q.top();
        q.pop();
        if(!city[cur.num].flag)    continue;
        temp=head[cur.num];
        while(temp!=-1)
        {
            if(city[cur.num].dis+eage[temp].len<city[eage[temp].to].dis)
            {
                city[eage[temp].to].dis=city[cur.num].dis+eage[temp].len;
                next.num=eage[temp].to;
                next.dis=city[eage[temp].to].dis;
                q.push(next);
            }
            temp=eage[temp].next;
        }
    }
}
int main()
{
    int a,b,c;
    int i;
    while(scanf("%d%d%d",&n,&m,&q)!=-1)
    {
        tot=0;
        memset(head,-1,sizeof(head));
        while(q--)
        {
            scanf("%d%d%d",&a,&b,&c);
            add(b,a,c);
        }
        scanf("%d",&e);
        for(i=0;i<m;i++)    scanf("%d",&E[i].s);
        for(i=0;i<m;i++)    {scanf("%d",&E[i].v);E[i].num=i+1;}
        for(i=1;i<=n;i++)    {city[i].dis=11111111;city[i].flag=1;}
        city[e].dis=0;
        Dij();
        for(i=0;i<m;i++)    {E[i].len=city[E[i].s].dis;E[i].ans=1.0*E[i].len/E[i].v;}
        qsort(E,m,sizeof(E[0]),cmp);
        if(E[0].len==11111111)    printf("No one\n");
        else                    printf("%d\n",E[0].num);
    }
    return 0;
}
