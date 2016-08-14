#include<iostream>
using namespace std;
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue> 
#define N 51
struct node{
     int x,y;   
     node(int a,int b)
     {
         x=a; y=b;     
     }    
     node(){};      
};
int key[4][2]={0,1,0,-1,1,0,-1,0};
int n,map[N][N],d[N][N];
long long f[N][N];
void find()
{
     int i;
     node s;
     queue<node> Q;
     memset(d,1,sizeof(d));
     d[n][n]=map[n][n];
     Q.push(node(n,n));
     while (!Q.empty())
     {
          s=Q.front(); 
          Q.pop();
          for (i=0;i<4;++i)
              {
              int x,y;
              x=s.x+key[i][0]; y=s.y+key[i][1];
              if (x>0&&x<=n && y>0&&y<=n)
                 {
                 if (d[x][y]>d[s.x][s.y]+map[x][y])
                     {
                     d[x][y]=d[s.x][s.y]+map[x][y];
                     Q.push(node(x,y));                              
                     }       
                 }
              }
     }     
}
long long dp(int x,int y)
{
    if (f[x][y]!=-1) return f[x][y];
    int i;
    long long t=0;
    for (i=0;i<4;++i)
        {
        int x1,y1;
        x1=x+key[i][0]; y1=y+key[i][1];
        if (x1>0&&x1<=n && y1>0&&y1<=n)
           if (d[x1][y1]<d[x][y])
              {
              t+=dp(x1,y1);            
              } 
        }    
    return f[x][y]=t;
}
int main()
{
    while (~scanf("%d",&n))
    {
    int i,j; 
    for (i=1;i<=n;++i)      
        for (j=1;j<=n;++j)
            scanf("%d",&map[i][j]);      
    find();
    memset(f,-1,sizeof(f));
    f[n][n]=1;
    dp(1,1); 
    printf("%I64d\n",f[1][1]);    
    }
    return 0; 
}
