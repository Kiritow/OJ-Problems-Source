#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>v[20][20];
int n,m,k;
int q[1005];
char ch[22];
bool work(int a)
{
    int i,j;
    int res=0;
     for(i=0;i<v[m][a].size();i++)
     {    res=0;
         for(j=1;j<=n;j++)
         {     
             if((v[m][a][i]^q[j])==v[m][a][i]+q[j])
             {    
                     res++;
             }    
         }
         if(res>=k) return true;
     }
     return false;
}                 
int main()
{
    int i,j,a,b,c;
    v[1][0].push_back(0);
    v[1][1].push_back(1);
    for(i=2;i<=15;i++)
    {
          for(j=0;j<i;j++)
          {
              for(int k=0;k<v[i-1][j].size();k++)
              {
                  v[i][j].push_back(v[i-1][j][k]<<1);
                  v[i][j+1].push_back(v[i-1][j][k]<<1^1);
              }
          }
     }    
    while(scanf("%d%d%d",&n,&m,&k)!=EOF)
    {
        for(i=1;i<=n;i++)
        {
            q[i]=(1<<m)-1;
            scanf("%s %d",ch,&a);
            for(j=0;j<a;j++)
            {
                scanf("%d",&b);
                q[i]^=(1<<(b-1));
            }
        }
        int l=0,r=m,mid;
        while(l+1<r)
        {
            mid=(l+r)>>1;
            if(work(mid))   l=mid;
            else
            r=mid-1;
        }
        if(work(r))  { printf("%d\n",r);}
        else printf("%d\n",l);
    }
    return 0;
}
