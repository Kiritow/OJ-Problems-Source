#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
#define LL unsigned __int64
struct node
{
    int cnt;
    struct node *fail;
    struct node *next[26];
    struct node *jump[26];
};
node root[33];
int num;
char str[10];
LL mod=10330176681277348905;
void insert(char word[])
{
    int i=0;
    node *tmp=root;
    while(word[i])
    {
        int b=word[i]-'a';
        if(tmp->next[b]==NULL)
        {
            tmp->next[b]=root+num;
            memset(root+num,0,sizeof(struct node));
            num++;
        }
        tmp=tmp->next[b];
        i++;
    }
    tmp->cnt=1;
}
node *q[33];
int head,tail;
void add_fail()
{
    head=tail=0;
    q[tail++]=root;
    while(head<tail)
    {
        node *x=q[head++];
        for(int i=0;i<26;i++)
        {
            node *t=x->fail;
            while(t!=NULL && t->next[i]==NULL)
                t=t->fail;
            if(x->next[i]!=NULL)
            {
                q[tail++]=x->next[i];
                if(t==NULL)
                    x->next[i]->fail=root;
                else
                {
                    x->next[i]->fail=t->next[i];
                    if(t->next[i]->cnt)
                        x->next[i]->cnt=1;
                }
                x->jump[i]=x->next[i];
            }
            else
            {
                if(t==NULL)
                    x->jump[i]=root;
                else
                    x->jump[i]=t->next[i];
            }
        }
    }
}
int m;
int n;
struct Mat
{
    LL a[2*33][2*33];
    void init()
    {
        int i,j;
        for(i=0;i<2*33;i++)
            for(j=0;j<2*33;j++)
                a[i][j]=0;
    }
};
int len;
Mat e;
Mat mul(Mat a,Mat b)
{
    Mat res;
    int i,j,k;
    for(i=0;i<2*len;i++)
    {
        for(j=0;j<2*len;j++)
        {
            res.a[i][j]=0;
            for(k=0;k<2*len;k++)
            {
                if(a.a[i][k]>0 && b.a[k][j]>0)
                {
                    res.a[i][j]+=a.a[i][k]*b.a[k][j];
                }
            }
        }
    }
    return res;
}
LL solve(Mat a,int k)
{
    Mat b,ans=e;
    int i,j;
    b.init();
    for(i=0;i<len;i++)  
        for(j=0;j<len;j++)
            b.a[i][j]=a.a[i][j];
    for(i=0;i<len;i++)  
    {
        for(j=len;j<2*len;j++)
            b.a[i][j]=(i==j-len);
    }
    for(i=len;i<2*len;i++) 
    {
        for(j=len;j<2*len;j++)
            b.a[i][j]=(i==j);
    }
    k++;
    while(k)
    {
        if(k&1)
        {
            ans=mul(ans,b);
        }
        b=mul(b,b);
        k/=2;
    }
    LL res=0;
    for(i=0;i<len;i++)
    {
        res+=ans.a[i][len];
    }
    return res-1;
}
LL sum(LL a,int k)
{
    Mat b;
    Mat ans=e;
    b.init();
    b.a[0][0]=26;b.a[0][1]=1;
    b.a[1][0]=0; b.a[1][1]=1;
    k++;
    while(k)
    {
        if(k&1)
        {
            ans=mul(ans,b);
        }
        b=mul(b,b);
        k/=2;
    }
    return ans.a[0][1]-1;
}
int main()
{
    int i,j,k;
    for(i=0;i<2*33;i++)
        for(j=0;j<2*33;j++)
            e.a[i][j]=(i==j);
    while(scanf("%d%d",&n,&m)==2)
    {
        num=1;
        memset(root,0,sizeof(struct node));
        for(i=0;i<n;i++)
        {
            scanf("%*c%s",str);
            insert(str);
        }
        add_fail();
        int id=0,id1;
        Mat res;
        for(i=0;i<num;i++)
        {
            if(root[i].cnt==0)
            {
                id1=0;
                for(j=0;j<num;j++)
                {
                    if(root[j].cnt==0)
                    {
                        LL count=0;
                        for(k=0;k<26;k++)
                        {
                            if(root[j].jump[k]==root+i)
                            {
                                count++;
                            }
                        }
                        res.a[id][id1]=count;
                        id1++;
                    }
                }
                id++;
            }
        }
        len=id;
        LL all=sum(26,m);
        LL left=solve(res,m); 
        all-=left;
        if(all<0)
            all+=mod;
        printf("%I64u\n",all);
    }
    return 0;
}
