#include<cstdio>
#include<cstring>
using namespace std;
const int m=150;
inline int lowbit(int x)
{
    return x&-x;
}
void add(int c[],int pos,int x)
{
    while(pos<=20000)
    {
        c[pos]+=x;
        pos+=lowbit(pos);
    }
}
int sum(int c[],int l,int r)
{
    int sum1=0,sum2=0;
    l--;
    while(l>0)
    {
        sum1+=c[l];
        l-=lowbit(l);
    }
    while(r>0)
    {
        sum2+=c[r];
        r-=lowbit(r);
    }
    return sum2-sum1;
}
struct data
{
    int s,a[2*m+5];
    data *next;
    int c[20005];
    data()
    {
        memset(c,0,sizeof(c));
        next=NULL;
    }
};
data *root;
void insert(int x,int pos)
{
    if(root==NULL)
    {
        root=new data;
        root->s=1;
        root->a[1]=x;
        add(root->c,x,1);
        return ;
    }
    data *k=root;
    while(pos>k->s && k->next!=NULL)
    {
        pos-=k->s;
        k=k->next;
    }
    memmove(k->a+pos+1,k->a+pos,sizeof(int)*(k->s-pos+1));
    k->s++;
    k->a[pos]=x;
    add(k->c,x,1);
    if(k->s==2*m)
    {
        data *t=new data;
        t->next=k->next;
        k->next=t;
        memcpy(t->a+1,k->a+m+1,sizeof(int)*m);
        for(int i=1;i<=m;i++)
        {
            add(k->c,t->a[i],-1);
            add(t->c,t->a[i],1);
        }
        t->s=k->s=m;
    }
}
void del(int pos)
{
    data *k=root;
    while(pos>k->s && k->next!=NULL)
    {
        pos-=k->s;
        k=k->next;
    }
    add(k->c,k->a[pos],-1);
    memmove(k->a+pos,k->a+pos+1,sizeof(int)*(k->s-pos));
    k->s--;
}
int find(int pos)
{
    data *k=root;
    while(pos>k->s && k->next!=NULL)
    {
        pos-=k->s;
        k=k->next;
    }
    return k->a[pos];
}
int work(int pos)
{
    int res=0;
    data *k=root;
    int x=find(pos);
    while(pos>k->s && k->next!=NULL)
    {
        pos-=k->s;
        res+=sum(k->c,x+1,20000);
        k=k->next;
    }
    for(int i=1;i<pos;i++) if(k->a[i]>x) res++;
    for(int i=pos+1;i<=k->s;i++) if(k->a[i]<x) res++;
    while(k->next!=NULL)
    {
        k=k->next;
        res+=sum(k->c,1,x-1);
    }
    return res;
}
void destroy(data *k)
{
    if(k->next!=NULL) destroy(k->next);
    delete k;
}
int main()
{
    int n,p;
    while(~scanf("%d %d",&n,&p))
    {
        root=NULL;
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            int x;
            scanf("%d",&x);
            insert(x,i);
            ans+=work(i);
        }
        while(p--)
        {
            int c;
            scanf("%d",&c);
            if(c==0)
            {
                int x,y;
                scanf("%d %d",&x,&y);
                x++;
                insert(y,x);
                ans+=work(x);
            }
            else
            {
                int x;
                scanf("%d",&x);
                ans-=work(x);
                del(x);
            }
            printf("%d\n",ans);
        }
        destroy(root);
    }
    return 0;
}
