#include<iostream>
#include<string.h>
using namespace std;
const int mod=9997;
int f[3][3],map[3][3];
int t[3][3]={{5,-7,4},{1,0,0},{0,1,0}};
int g[4][1]={1,2,6,19},n;
void multy_2(int v[][3],int u[][3])
{
     int c[3][3];
     memset(c,0,sizeof(c));
     for(int i=0;i<3;i++)
     {
         for(int j=0;j<3;j++)
         {
              for(int k=0;k<3;k++)
              {
                   c[i][j]=(c[i][j]+(v[i][k]*u[k][j]+mod)%mod+mod)%mod;
              }
         }
     }
     memcpy(v,c,sizeof(c));
}
void multy_1(int k)
{
     for(;k>0;k=k>>1)
     {
         if(k & 1) multy_2(map,f);
         multy_2(f,f);
     }
}
void run()
{
     multy_1(n-4);
     cout<<(g[3][0]*map[0][0]%mod+g[2][0]*map[0][1]%mod+g[1][0]*map[0][2]%mod)%mod<<endl;
}
int main()
{
     while(scanf("%d",&n) && n!=0)
     {
         if(n<=4)
         {
              cout<<g[n-1][0]<<endl;
              continue;
         }
         memcpy(f,t,sizeof(t));
         memset(g,0,sizeof(g));
         memset(map,0,sizeof(map));map[0][0]=map[1][1]=map[2][2]=1;
         g[0][0]=1;
         g[1][0]=2;
         g[2][0]=6;
         g[3][0]=19;
         run();
     }
     return 0;
}
