#include<stdio.h>
#include "math.h"
int e[2001][2];//杈[0],to.[1]next;
int a[1001][5];//[0],ID,[1]next;2x3y4z
int c[1001];
int cnum;
int max;int m;
bool sign[1001];
int n;//圭扮
int en;//杈圭扮
void initt();
void init();
int DFS(int s);
int eq(int x);
int main()
{
    while(1)
    {
        scanf("%d",&n);
        if(n==0)return 0;
        initt();
        init();
        int min=1000;
        int i;
        for(i=1;i<=n;i++)//n娆DFS
        {
            max=0;
            m=0;
            DFS(i);
            if(max<min)min=max,c[1]=a[i][0],cnum=1;
            else if(max==min)cnum++,c[cnum]=a[i][0];
            else ;
        }
         if(cnum==1)printf("%d",c[1]);
         else 
         {
             if(c[1]>c[2])printf("%d %d",c[2],c[1]);
             else printf("%d %d",c[1],c[2]);
         }
         printf("\n");
    }
}
int DFS(int s)
{
    if(sign[s])return 0;
    if((!e[a[s][1]][1])&&sign[e[a[s][1]][0]]){
        if(max<m){max=m; return 0;}
        else return 0;}
    m++;
    sign[s]=true;
    int next=a[s][1];
    while(next)
    {
        DFS(e[next][0]);
        next=e[next][1];
    }
    m--;sign[s]=false;
    return 0;
}
void initt()
{
    int i;
    cnum=0;
    for(i=0;i<=n;i++)
        a[i][1]=0;
    for(i=0;i<=2*n;i++)
         e[i][1]=0;
}
void init()
{
    int k=0;int en=0;
        k++;
        int id;int x;int y;int z;
        scanf("%d%d%d%d",&id,&x,&y,&z);
        a[k][0]=id;a[k][2]=x,a[k][3]=y,a[k][4]=z;
    while(k<n)
    {
        k++;
        scanf("%d%d%d%d",&id,&x,&y,&z);
        a[k][0]=id;a[k][2]=x,a[k][3]=y,a[k][4]=z;
        int ee;ee=eq(k);
        en++;e[en][0]=ee;e[en][1]=a[k][1];a[k][1]=en;
        en++;e[en][0]=k;e[en][1]=a[ee][1];a[ee][1]=en;
    }
}
int eq(int x)
{
    int i;double min=10000;int xx;
    for(i=1;i<x;i++)
    {
        double temp=((a[x][3]-a[i][3])*(a[x][3]-a[i][3])+(a[x][4]-a[i][4])*(a[x][4]-a[i][4])+(a[x][2]-a[i][2])*(a[x][2]-a[i][2]));
        double val=sqrt(temp);
         if(val<min)min=val,xx=i;
    }
    return xx;
}
