#include<cstdio>
#include<cstring>
using namespace std;
int tree[1010][1010];
int sum[1010][1010];
int main()
{ int i,j,k,n,m,x,y,ans,l,r,p,l2,r2,res;
  while(~scanf("%d%d",&n,&m))
  { memset(tree,0,sizeof(tree));
    for(i=1;i<=m;i++)
    { scanf("%d%d",&x,&y);
      tree[x][y]=1;
    }
    for(i=1;i<=n;i++)
     for(j=1;j<=n;j++)
      sum[i][j]=sum[i][j-1]+tree[i][j];
    ans=0;
    l2=1;r2=n;
    while(l2<r2)
    { i=(l2+r2+1)/2;
      res=0;ans=0;
      for(j=1;j<=n-i+1;j++)
      { l=j;r=j+i-1;p=0;
        for(k=1;k<=n;k++)
        { if(sum[k][r]-sum[k][l-1]>0)
           p=0;
          else
          { p++;
            if(p>=i)
            { ans=i;
              break;
            }
          }
        }
      }
      if(ans>0)
       l2=i;
      else
       r2=i-1;
    }
    printf("%d\n",l2);
  }
}
