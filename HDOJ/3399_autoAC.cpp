#include <iostream>
#include <string.h> 
using namespace std;
const int maxn=1100000,maxm=4*maxn;
struct Edge
{
int y;
int ne;
} e[maxm];
int st[maxn],ee;
void addedge(int x,int y)
{
e[ee].y=y;e[ee].ne=st[x];st[x]=ee++;
e[ee].y=x;e[ee].ne=st[y];st[y]=ee++;
}
int c[maxn];
int numn[maxn],numm[maxn],lost[maxn];
int s[maxn],head,tail;
void bfs(int k,int col)
{
int i;
head=0;tail=1;s[0]=k;
c[k]=col;
while (head<tail)
{
   k=s[head++];
   for (i=st[k];i!=-1;i=e[i].ne) 
   {
    numm[col]++;
    if (c[e[i].y]==0)
    {
     c[e[i].y]=col;
     s[tail++]=e[i].y;
    }
   }
}
numn[col]=tail;
}
int main()
{
int cass;
for (scanf("%d",&cass);cass--;)
{
   int n;
   scanf("%d",&n);
   int i,x,y,z1,z2;
   memset(st,-1,sizeof(st));
   ee=0;
   for (i=0;i<n;i++) 
   {
    scanf("%d.%d %d.%d",&z1,&x,&z2,&y);
    x=z1*1000000+x-1500000;
    y=z2*1000000+y-1500000;
    addedge(x,y);
   }
   memset(c,0,sizeof(c));
   memset(numn,0,sizeof(numn));
   memset(numm,0,sizeof(numm));
   memset(lost,-1,sizeof(lost));
   int col=0;
   for (i=0;i<maxn;i++) if (c[i]==0)
   {
    col++;
    bfs(i,col);
   }
   for (i=1;i<=col;i++) numm[i]/=2;
   for (i=0;i<maxn;i++) if (numn[c[i]]>numm[c[i]]) if (lost[c[i]]<i) lost[c[i]]=i;
   for (i=0;i<maxn;i++) 
    if (lost[c[i]]==i) break;
   printf("%d\n",i);
}
return 0;
}
