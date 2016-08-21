#include<stdio.h>
#include<stdlib.h>
typedef struct line
{
    double x,h;
}node;
int cmp(const void *a,const void *b)
{
    return (*(node *)a).x-(*(node *)b).x;
}
node s[100010];
int main()
{
    long n,i,count;
    double a,b,temp,max;
    while(scanf("%ld",&n)>0,n)
    {
        count=0;
        for(i=0;i<n;i++)
            scanf("%lf%lf",&s[i].x,&s[i].h);
        scanf("%lf/%lf",&a,&b);
        qsort(s,n,sizeof(node),cmp);
         max=0;
        for(i=0;i<n;i++)
        {
            temp=s[i].h*b*1.0/a+s[i].x;
            if(max<temp)
            {
                max=temp;
                count++;
            }
        }
        printf("%ld\n",count);
    }
    return 0;
}
