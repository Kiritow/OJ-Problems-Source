#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int f[20010],r[20010],n;
int map[20010];
int xp[20],ans;
void init()
{
    for(int i=0;i<=n;i++)
    {
        f[i]=i;
        r[i]=0;
    }
}
int find(int x)
{
    if(x==f[x])
        return x;
    int t=find(f[x]);
    r[x]^=r[f[x]];//规x涓惰圭崇郴姹x涓硅圭崇郴
    f[x]=t;
    return f[x];
}
bool Union(int x,int y,int k)
{
    int a=find(x);
    int b=find(y);
    if(a==b)
    {
        if((r[x]^r[y])==k)
            return true;
        return false;
    }
    if(a==n)
        swap(a,b);
        f[a]=b;
        r[a]=r[x]^r[y]^k;
    return true;
}
bool query(int m)
{
    memset(map,0,sizeof(map));
    for(int i=0;i<m;i++)
    {
        map[find(xp[i])]++;
        ans^=r[xp[i]];
    }
    int flag=0;
    for(int i=0;i<m;i++)
    {
        int t=find(xp[i]);
        if(map[t]%2!=0 && t!=n)
        {flag=1;break;}
    }
    if(flag)
        return false;
     return true;
}
int main()
{
    char s[2],c;
    int a,b,v,Q,cas=0;  
    while(scanf("%d %d",&n,&Q)==2 &&(n||Q))
    {
        init();
        printf("Case %d:\n",++cas);
    int fact=0,flag=0;
    while(Q--)
    {
        scanf("%s%d%d",s,&a,&b);
        if(s[0]=='I')
        {
            fact++;
            c=getchar();
            if(c==' ')
            {
                scanf("%d",&v);
                if(flag)continue;
                if(!Union(a,b,v))
                {
                    printf("The first %d facts are conflicting.\n",fact);
                    flag=1;
                }
            }
            else
                {
                    if(flag)continue;
                    if(!Union(a,n,b))
                    {
                      printf("The first %d facts are conflicting.\n",fact);
                      flag=1;
                    }
                }
        }
        else
        {
            xp[0]=b;
            for(int i=1;i<a;i++)
                scanf("%d",&xp[i]);
            if(flag)continue;
            ans=0;
            if(query(a))
                printf("%d\n",ans);
            else printf("I don't know.\n");
        }
     }
    printf("\n");
    }
    return 0;
}
