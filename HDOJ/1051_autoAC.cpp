#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <map>
#define MAXINT 99999999
#define MININT -1
using namespace std;
struct Node{
       int l;
       int w;
       }node[5000+4];
int vis[5000+4];
bool cmp(Node x,Node y)
{if(x.l<y.l)
 return true;
 else if(x.l==y.l)
 {if(x.w<=y.w)
  return true;
 }
 return false;
}
int main()
{
    int n;
    int m;
    int i,j,k;
    scanf("%d",&m);
    while(m--)
    {
              scanf("%d",&n);
              for(i=0;i<n;i++)
              {
                              scanf("%d%d",&node[i].l,&node[i].w);
              }           
              sort(node,node+n,cmp);            
              for(i=0;i<n;i++)
              {vis[i]=0;}
              int countn=0;
              for(i=0;i<n;i++)
              {
                              if(vis[i])
                              continue;
                              vis[i]=1;
                              countn++;
                              int pre=i;
                              for(j=i+1;j<n;j++)
                              {             
                                              if(vis[j]==0)
                                              {
                                                           if(node[j].w>=node[pre].w)
                                                           {vis[j]=1;pre=j;}
                                              }
                              }
              }
              cout<<countn<<endl;
    }
    return 0;
}
