#include<cstdio>
#include<cstring>
int d[105][20005];
int main()
{
    int t,c=1;
    scanf("%d",&t);
    while(t--)
    {
        memset(d,0,sizeof(d));
        int n,ans=0,m,i,j,k,p=0,x=0,a[105];
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%d",a+i);
            if(a[i]>a[p])
                p=i;
        }
        x=3*a[p]*m;
        d[0][0]=1;        
        for(i=0;i<n;i++)    
            for(j=1;j<=m;j++)
                for(k=0;k<=x;k++)
                    if(d[j-1][k])
                    {
                        d[j][k]=1;
                        d[j][k+a[i]]=1;
                        d[j][k+2*a[i]]=1;
                        if(p!=i)
                            d[j][k+3*a[i]]=1;            
                    }
        for(i=0;i<=x;i++)
            if(d[m][i])
                ans++;
        printf("Scenario #%d:\n",c++);
        printf("%d\n\n",ans);    
    }
}
