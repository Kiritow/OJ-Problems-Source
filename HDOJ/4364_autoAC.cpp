#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int ans[5][5]={{2,3,1,1},{1,2,3,1},{1,1,2,3},{3,1,1,2}};
int matrix[5][5];
int a[5][5];
void multi()
{
   for(int i=0;i<4;i++)
   {
       for(int j=0;j<4;j++)
       {
           for(int k=0;k<4;k++)
           {
              int t=matrix[k][j];
              t<<=1;
              if(t>0xFF)//225
              t=(t^0x1B)%(0xFF+1);
              if(ans[i][k]==1)
              {
                  a[i][j]^=matrix[k][j];
              }
              else if(ans[i][k]==2)
              {
                  a[i][j]^=t;
              }
              else if(ans[i][k]==3)
              {
                  t^=matrix[k][j];
                  a[i][j]^=t;
              }
           }
       }
   }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(a,0,sizeof(a));
        for(int i=0;i<4;i++)
        for(int j=0;j<4;j++)
         scanf("%X",&matrix[i][j]);
        multi();
        for(int i=0;i<4;i++)
        {
            for(int j=0;j<4;j++)
            {
              if(j!=0)
              cout<<' ';
              printf("%02X",a[i][j]);
            }
          puts("");
        }
        if(cas != 0)
        puts("");
    }
    return 0;
}
