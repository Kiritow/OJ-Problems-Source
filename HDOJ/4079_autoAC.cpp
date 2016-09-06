#include"stdio.h"
#include"string.h"
#define N 10002
struct node
{
    int x,y;
}A[N];
int main()
{
    int i,j,k;
    int n,m;
    int s,d,x,y;
    while(scanf("%d%d",&n,&m),n||m)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&s,&d); 
            scanf("%d%d",&x,&y);
            A[i].x=x;
            A[i].y=x+y;
        }
        for(i=0;i<m;i++)
         {
            scanf("%d%d",&x,&y);
            y=x+y;
            for(k=0,j=0;j<n;j++)
              {
                  if(A[j].y>x&&A[j].x<y)
                       k++;
              }
            printf("%d\n",k);
         }
    }
    return 0;
}
