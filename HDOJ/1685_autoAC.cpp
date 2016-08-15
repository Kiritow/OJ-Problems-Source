#include <stdio.h>
#include <math.h>
int n,num[15],lim;
bool flag;
int h()
{
    int i,r=0;
    if(num[0]!=1) r++;
    if(num[n-1]!=n) r++;
    for(i=0;i<n-1;i++) if(num[i]+1!=num[i+1]) r++;
    return r;
}
void dfs(int cnt)
{
    if(flag) return;
    int i;
    for(i=0;i<n;i++) if(num[i]!=i+1) break;
    if(i==n)
    {
        flag=1;
        return;
    }
    if(cnt>=lim) return;
    if(cnt+ceil(h()/3.0)>lim) return;
    int len,pos,j,p,temp[15];
    for(i=0;i<n;i++) temp[i]=num[i];
    for(i=0;i<n;i++)
    {
        for(len=1;len<=n-i;len++)
        {
            for(pos=0;pos<=n-len;pos++)
            {
                if(pos==i) continue;
                for(j=0;j<len;j++) num[pos+j]=temp[i+j];
                for(p=0,j=0;j<n;)
                {
                    if(pos==j) j+=len;
                    if(j>=n) break;
                    if(p==i) p+=len;
                    num[j++]=temp[p++];
                }
                dfs(cnt+1);
            }
        }
    }
    for(i=0;i<n;i++) num[i]=temp[i];
}
int main()
{
    int T,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++) scanf("%d",&num[i]);
        flag=0;
        for(lim=0;lim<5;lim++)
        {
            dfs(0);
            if(flag) break;
        }
        if(flag) printf("%d\n",lim);
        else printf("5 or more\n");
    }
}
