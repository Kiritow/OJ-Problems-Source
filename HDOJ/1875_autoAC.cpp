#include<stdio.h>
#include<math.h>
#include<algorithm>
using namespace std;
int x[10005],y[10005],fa[1000005];
double fun(int x1,int y1,int x2,int y2)
{
    return sqrt(pow(x1-x2,2.0)+pow(y1-y2,2.0));
}
int find(int x)
{
    int k,j,r;    
    r=x;    
    while(r!=fa[r])          
    r=fa[r];        
    k=x;    
    while(k!=r)               
    {        
        j=fa[k];               
        fa[k]=r;              
        k=j;                      
    }    
    return r;    
}
int main()
{
    int t,n,i,j,k;
    double len;
    scanf("%d",&t);
    while(t--)
    {
        pair<int,int> pa;
        pair< double,pair<int,int> > p[10005];
        k=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d %d",&x[i],&y[i]);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
            {
                if(i==j) continue;
                len=fun(x[i],y[i],x[j],y[j]);
                if(len>=10&&len<=1000)
                {
                    pa=make_pair(i,j);
                    p[k++]=make_pair(len,pa);
                }
            }
        sort(p,p+k);
        for(i=0;i<=n;i++)
            fa[i]=i;
        int a,b,ans=0;
        double cnt=0;
        for(i=0;i<k;i++)
        {
            a=find(p[i].second.first);
            b=find(p[i].second.second);
            if(a!=b)
            {
                fa[a]=b;
                cnt+=p[i].first;
                ans++;
            }
        }
        if(ans==n-1)
            printf("%.1lf\n",cnt*100);
        else
            printf("oh!\n");
    }
    return 0;
}
