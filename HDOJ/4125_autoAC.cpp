#include<stdio.h>
#include<string.h>
char s[2000000],ss[10000];
int sta[700000],top,root,ch[700000][2],cnt;
int zhu[700000],C[700000];
inline void f()
{
    zhu[root]=0;cnt=0;
    sta[0]=root,top=1;
    if(!ch[root][0]&&!ch[root][1])
    {
        s[0]=root%2+'0';
        return;
    }
    int t=root;
    while(t-root||((zhu[t]==1&&ch[t][1])||zhu[t]==0))
    {
        s[cnt++]=t%2+'0';
        if(top<0)
            return;
        if(zhu[t]==0)
        {
            if(ch[t][0])
            {
                zhu[t]=1;
                t=ch[t][0];
                zhu[t]=0;
                sta[top++]=t;
            }
            else if(ch[t][1])
            {
                zhu[t]=2;
                t=ch[t][1];
                zhu[t]=0;
                sta[top++]=t;
            }
            else if(t==root)
                return ;
            else
                zhu[t]=2,t=sta[--top-1];
        }
        else if(zhu[t]==1)
        {
            if(ch[t][1])
            {
                zhu[t]=2;
                t=ch[t][1];
                zhu[t]=0;
                sta[top++]=t;
            }
            else if(t==root)
                return ;
            else
                t=sta[--top-1];
        }
        else if(t==root)
            return ;
        else
            t=sta[--top-1];
    }
    s[cnt++]=root%2+'0';
}
int P[10000];
inline void scan(int &u)
{
    char c;
    while(c=getchar(),c<'0'||c>'9');
    u=c-'0';
    while(c=getchar(),c<='9'&&c>='0')
        u=u*10+c-'0';
}
int ff(int l)
{
    int i,j,ans=0;
    P[0]=-1;
    for(i=1,j=-1;i<l;i++)
    {
        while(j+1&&ss[j+1]-ss[i])
            j=P[j];
        if(ss[j+1]==ss[i])
            j++;
        P[i]=j;
    }
    for(i=0,j=-1;i<cnt;i++)
    {
        while(j+1&&ss[j+1]-s[i])
            j=P[j];
        if(ss[j+1]==s[i])
            j++;
        if(j==l-1)
            ans++;
    }
    return ans;
}
int N,Min,Max;
int cal(int n)
{
    int ans=0;
    while(n>=1)
        ans+=C[n],n-=n&(-n);
    return ans;
}
void update(int n)
{
    while(n<=N)
        C[n]++,n+=n&(-n);
}
void insert(int n)
{
    update(n);
    int t=cal(n);
    if(!root)
    {
        root=n;
        Min=Max=n;
        return;
    }
    if(n>Max)
    {
        ch[Max][1]=n;
        Max=n;
        return;
    }
    if(n<Min)
    {
        ch[Min][0]=n;
        Min=n;
        return;
    }
    int l=1,r=n-1,mid;
    Min=Min<n?Min:n;
    Max=Max>n?Max:n;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(cal(mid)==t-1)
            r=mid;
        else
            l=mid+1;
    }
    l=r;
    if(!ch[l][1])
    {
        ch[l][1]=n;
        return;
    }
    l=n+1,r=N;
    while(l<r)
    {
        mid=(l+r)>>1;
        if(cal(mid)-t)
            r=mid;
        else
            l=mid+1;
    }
    ch[r][0]=n;
}
int main()
{
    int t,n,i,j;
    scanf("%d",&t);
    for(int ii=1;ii<=t;ii++)
    {
        memset(ch,0,sizeof(ch));
        memset(C,0,sizeof(C));
        Min=1000000,Max=0;
        root=0;
        scanf("%d",&n);N=n;
        for(i=1;i<=n;i++)
            scanf("%d",&j),insert(j);
        f();
        scanf("%s",ss);
        printf("Case #%d: %d\n",ii,ff(strlen(ss)));
    }
}
