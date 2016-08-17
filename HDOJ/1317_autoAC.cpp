#include <cstdlib>
#include <iostream>
using namespace std;
const int maxn=102;
struct node
{
    int to;
    int next;
};
node edge[maxn*maxn];
node edge1[maxn*maxn];
int head[maxn];
int head1[maxn];
bool ac[maxn];
int isin[maxn];
int point[maxn];
int total[maxn];
int stack[maxn+10];
void dfs(int x)
{
    isin[x]=1;
    ac[x]=true;
    for(int k=head1[x];k!=-1;k=edge1[k].next)
    {
        if(!isin[edge1[k].to])
            dfs(edge1[k].to);
    }
}
int main()
{
    int n,i,j,k,t,x,c,ptr,top;
    while(scanf("%d",&n)==1)
    {
        if(n==-1) break;
        if(n==1)
        {
            printf("winnable\n");
            continue;
        }
        for(i=1;i<=n;i++)
        {
            head[i]=-1;
            head1[i]=-1;
            total[i]=-1;
            isin[i]=0;
            ac[i]=false;
        }          
        c=0;   
        for(i=1;i<=n;i++)
        {
            scanf("%d%d",&point[i],&t);
            for(j=1;j<=t;j++)
            {
                scanf("%d",&x);
                edge[c].to=x;
                edge[c].next=head[i];
                head[i]=c;
                edge1[c].to=i;
                edge1[c].next=head1[x];
                head1[x]=c++;
            }
        }
        dfs(n);
        if(!ac[1]) printf("hopeless\n");
        else 
        {
            for(i=1;i<=n;i++) isin[i]=0;
            bool ju=false;
            total[1]=100;
            ptr=0;
            stack[++ptr]=1;
            while(ptr&&!ju)
            {
                top=stack[ptr--];
                isin[top]=2;
                for(k=head[top];k!=-1&&!ju;k=edge[k].next)
                {
                    if(ac[edge[k].to])
                    {
                        int temp=total[top]+point[edge[k].to];
                        if(temp>0&&temp>total[edge[k].to])
                        {
                            total[edge[k].to]=temp;                              
                            if(edge[k].to==n||isin[edge[k].to]==2) ju=true;
                            else if(!isin[edge[k].to])
                            {
                                stack[++ptr]=edge[k].to;
                                isin[edge[k].to]=1;
                            }
                        }
                    }
                }
            }
            if(ju) printf("winnable\n");
            else printf("hopeless\n");
        }
    }                                                                                                                                                                                                                                                                
    return 0;
}
