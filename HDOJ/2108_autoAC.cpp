#include<stdio.h>
struct Point 
{
    int x,y;
};
typedef struct Point point;
int main()
{
    point a[10001],s,t;
    int i,n,flag;
    while(scanf("%d",&n)!=EOF&&n!=0)
    {
        flag=1;
        for(i=0;i<n;i++)
        {
            scanf("%d %d",&a[i].x,&a[i].y);
        }
        a[n]=a[0];
        a[n+1]=a[1];
        for(i=0;i<n;i++)
        {
            s.x=a[i+1].x-a[i].x;
            s.y=a[i+1].y-a[i].y;
            t.x=a[i+2].x-a[i+1].x;
            t.y=a[i+2].y-a[i+1].y;
            if((s.x*t.y-s.y*t.x)<0)
            {
                flag=0;
                break;
            }
        }
        if(flag)
        {
            printf("convex\n");
        }
        else
        {
            printf("concave\n");
        }
    }
    return 0;
}
