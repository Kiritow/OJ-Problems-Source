#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int num,top,ii;
struct node
{
   int x;
   int y;
}a[105],mis[50005]; 
struct
{
      node b[25];
      int to;
}an[25];
int cmp(const void *c,const void *d)
{
   int ans;
   struct node *p1=(node *)c;
   struct node *p2=(node *)d;
   ans=(p1->x-a[0].x)*(p2->y-a[0].y)-(p2->x-a[0].x)*(p1->y-a[0].y);        
   if (ans>0) return -1;
   else if (ans<0) return 1;
   else 
   {
     if (abs(a[0].x-p1->x)<abs(a[0].x-p2->x)) return 1;
      return -1;
   }
}
int find( int p2,int p1,int p0)   
{
    return (an[ii].b[p1].x-an[ii].b[p0].x)*(a[p2].y-an[ii].b[p0].y)-(a[p2].x-an[ii].b[p0].x)*(an[ii].b[p1].y-an[ii].b[p0].y);
}
int find2( node p2,node p1,node p0) 
{
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
void Graham(int n)
{
     int i;
     a[n]=a[num];       
     a[num]=a[0];
     a[0]=a[n];
     qsort(a+1,n-1,sizeof(a[0]),cmp);  
     an[ii].b[0]=a[0];
     an[ii].b[1]=a[1];
     top=1;
     for (i=2;i<n;i++)
     {
         while (find(i,top,top-1)<0) top--;    
              an[ii].b[++top]=a[i];                 
     }
}
int main ()
{
    int n,i,j,k,h,minx=10005,miny=10005,dis,max,misnum,sum;
    double area;
    ii=0;
    while(scanf("%d",&n),n!=-1)
    {
    minx=10005;miny=10005;
    for (i=0;i<n;i++)
    {
        scanf("%d %d",&a[i].x,&a[i].y);
        if (a[i].y<miny || (miny==a[i].y && a[i].x<minx))   
        {
            miny=a[i].y;minx=a[i].x;num=i;
        }
    }
     Graham(n);
     an[ii].to=top;
     ii++;
     }
      i=0;
     while(scanf("%d%d",&mis[i].x,&mis[i].y)!=EOF)
          i++;
     misnum=i;area=0;
     for(i=0;i<ii;i++)
     {
          for(j=0;j<misnum;j++)
          {
               for(k=0;k<=an[i].to;k++)
               {
                    if(k==an[i].to)
                    {
                         if(find2(mis[j],an[i].b[0],an[i].b[k])<0)
                               break;
                    }                
                    else if(find2(mis[j],an[i].b[k+1],an[i].b[k])<0)
                         break;
               }
                if(k==an[i].to+1) 
                {
                     sum=0;
                     for(h=0;h<an[i].to;h++)
                          sum+=an[i].b[h].x*an[i].b[h+1].y-an[i].b[h].y*an[i].b[h+1].x;
                      sum+=an[i].b[h].x*an[i].b[0].y-an[i].b[h].y*an[i].b[0].x;
                      area+=sum*1.0/2;
                      break;
                }
          }
     }
     printf("%.2f\n",area);
     return 0;
}
