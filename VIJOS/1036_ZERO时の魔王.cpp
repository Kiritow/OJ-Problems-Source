#include<stdio.h>
#include<stdlib.h>
struct map
{int x;
int y;
int p;
int k;
long long value;}city[100001];
int n,ex,ey,sum=0;
int cmp1(const void*a,const void *b)
{struct map*c=(struct map*)a;
struct map*d=(struct map*)b;
if(c->x!=d->x)return c->x-d->x;
else
return c->y-d->y;
}




int cmp2(const void*a,const void *b)
{struct map*c=(struct map*)a;
struct map*d=(struct map*)b;
if(c->y!=d->y)return c->y-d->y;
else
return c->x-d->x;
}




int searchx()
{int i,add=0;
for(i=1;;i++)
{add+=city[i].value;
if(add>=sum/2)
break;}
return city[i].x;	
}




int searchy()
{int i,add=0;
for(i=1;;i++)
{add+=city[i].value;
if(add>=sum/2)
break;}
return city[i].y;	
}




int main()
{scanf("%d\n",&n);
int i;
for(i=1;i<=n;i++)
{scanf("%d %d %d %d\n",&city[i].x,&city[i].y,&city[i].p,&city[i].k);
city[i].value=city[i].p*city[i].k;
sum+=city[i].value;}
qsort(&city[1],n,sizeof(city[0]),cmp1);
ex=searchx();
qsort(&city[1],n,sizeof(city[0]),cmp2);
ey=searchy();
printf("%d %d",ex,ey);
return 0;
}
