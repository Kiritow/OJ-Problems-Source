#include<stdio.h>
#include<string.h>
#define MAXN 10010
#define INF 0x3fffffff
int v[MAXN],cur[MAXN];     
int min(int x,int y)
{
    return x<y?x:y;
}
int main()
{
    int n,t,ans;
    int i,j,s,sub;                
    for(scanf("%d",&t);t;t--)
    {
        scanf("%d",&n);
        if(!n)
        {
            puts("0");
            continue;
        }
        for(i=1;i<=n;i++)
            scanf("%d",v+i);
        memset(cur,0,sizeof(cur));
        v[n+1]=-INF;
        for(i=1;v[i]==0;i++);         
        j=i;
        s=0;
        ans=INF;
        while(i<=n)
        {
            if(i>j)
            {
                s=0;
                j=i;
            }
            while(j<=n && v[j]-cur[j]<=v[j+1])    
                j++;
            if(ans>j-i+1)
                ans=j-i+1;                       
            sub=v[j]-cur[j]-v[j+1];
            cur[j]+=min(sub,v[i]-s);        
            s+=min(sub,v[i]-s);
            while(!(v[i]-s))            
            {
                s-=cur[i];               
                i++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
