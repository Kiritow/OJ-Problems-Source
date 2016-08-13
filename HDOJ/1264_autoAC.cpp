#include <stdio.h>
#include <string.h>
#define SWAP(a,b){int t=a;a=b;b=t;}
int hash[102][102];
void HashTable(int x1,int y1,int x2,int y2)
{
    for(int i = x1;i < x2;i++)
      for(int j = y1;j < y2;j++)
         hash[i][j] = 1;
}
int CountHash(int minx,int miny,int maxx,int maxy)
{
    int cnt = 0;
    for(int i = minx;i < maxx;i++)
      for(int j = miny;j < maxy;j++)if(hash[i][j])
      {
          cnt++;
      }
    return cnt;
}
int main()
{
    int x1,x2,y1,y2,minx,miny,maxx,maxy;
    while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2))
    {
        memset(hash,0,sizeof(hash));
        if(x1+x2+y1+y2==-8)break;
        if(x1+x2+y1+y2==-4){puts("0");continue;}
        if(x1>x2)SWAP(x1,x2);
        if(y1>y2)SWAP(y1,y2);
        minx = x1; miny = y1;
        maxx = x2; maxy = y2;
        HashTable(x1,y1,x2,y2);
        while(scanf("%d%d%d%d",&x1,&y1,&x2,&y2),(x1+x2+y1+y2!=-4&&x1+x2+y1+y2!=-8))
        {
            if(x1>x2)SWAP(x1,x2);
            if(y1>y2)SWAP(y1,y2);
            if(minx>x1)minx = x1;
            if(miny>y1)miny = y1;
            if(maxx<x2)maxx = x2;
            if(maxy<y2)maxy = y2;
            HashTable(x1,y1,x2,y2);
        }
        int cnt=CountHash(minx,miny,maxx,maxy);
        printf("%d\n",cnt);
        if(x1+x2+y1+y2==-8)break;
    }
    return 0;
}
