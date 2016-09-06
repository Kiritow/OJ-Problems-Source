#include<cstdio>
#include<cstring>
int v1[1001],v2[1001];
int main()
{
    int n,m,k,x,y,p;
    char s1[10],s2[10];
    while(scanf("%d%d%d",&n,&m,&k),n||m||k)
    {
        memset(v1,0,sizeof(v1));
        memset(v2,0,sizeof(v2));
        int ans=n*m*k;
        scanf("%d",&p);
        while(p--)
        {
            scanf("%s%d%s%d",s1,&x,s2,&y);
            if(s1[0]=='c') 
            {
                v1[y]++;
                ans-=(k-v2[y]);
            }
            else 
            {
                v2[x]++;
                ans-=(n-v1[x]);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
