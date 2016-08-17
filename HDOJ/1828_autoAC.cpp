#include<algorithm>
#include<iostream>
#include<cstdio>
const int maxn=5010;
const int CONST=10001;
using namespace std;
struct Line
{
    int l,r,h;
    char lab;
}line[maxn*2];
struct node
{
    int lc,rc,cnt,len,num;
    char rn,ln;
}tree[maxn*2*4];
int n,pos[maxn*2],m,ans,tmpl,tmpr;
int abs(int a){return a>0?a:-a;}
bool cmp(Line a,Line b)
{
    return a.h<b.h;
}
void built(int i,int l,int r)
{
    tree[i].lc=l,tree[i].rc=r;
    tree[i].len=tree[i].num=tree[i].rn=tree[i].ln=tree[i].cnt=0;
    if(l==r-1)return;
    int mid=(l+r)/2;
    built(2*i,l,mid);
    built(2*i+1,mid,r);
}
void update_len(int i)
{
    if(tree[i].cnt)
    {
        tree[i].len=pos[tree[i].rc]-pos[tree[i].lc];
        tree[i].num=1;
        tree[i].ln=tree[i].rn=1;
    }
    else 
    {
        tree[i].len=tree[2*i].len+tree[2*i+1].len;
        tree[i].num=tree[2*i].num+tree[2*i+1].num;
        if(tree[2*i].rn&&tree[2*i+1].ln)tree[i].num--;
        tree[i].rn=tree[2*i+1].rn;
        tree[i].ln=tree[2*i].ln;
    }
}
void update(int i,char val)
{
    if(pos[tree[i].lc]>tmpr||pos[tree[i].rc]<tmpl)return;
    if(pos[tree[i].lc]>=tmpl&&pos[tree[i].rc]<=tmpr)
    {
        tree[i].cnt+=val;
        update_len(i);
    }
    if(tree[i].lc==tree[i].rc-1)return;
    update(2*i,val);
    update(2*i+1,val);
    update_len(i);
}
void scan()
{
    int now=2*n;
    int last=0,lh=line[2*n].h;
    while(now)
    {
        ans+=tree[1].num*2*(lh-line[now].h);
        lh=line[now].h;
        tmpl=line[now].l,tmpr=line[now].r;
        update(1,line[now].lab);
        ans+=abs(tree[1].len-last);
        last=tree[1].len;
        --now;
    }
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        int x1,y1,x2,y2;
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            //x1+=CONST,x2+=CONST,y1+=CONST,y2+=CONST;
            line[i].l=x1,line[i].r=x2,line[i].h=y1,line[i].lab=1;
            line[n+i].l=x1,line[n+i].r=x2,line[n+i].h=y2,line[n+i].lab=-1;
            pos[i]=x1,pos[n+i]=x2;
        }
        sort(line+1,line+1+2*n,cmp);
        sort(pos+1,pos+1+2*n);
        m=1;
        ans=0;
        for(int i=2;i<=2*n;i++)
            if(pos[i]!=pos[i-1])pos[++m]=pos[i];
        built(1,1,m);
        scan();
        printf("%d\n",ans);
    }
}
