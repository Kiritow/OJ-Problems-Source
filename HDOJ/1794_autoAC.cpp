#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int map[31][31],a[10010];
struct op
{
    int num,count;
}p[31][31];
struct ed
{
    int x,y,cnt;
}e[1000];
int cmp(const void *a,const void *b)
{
    return *(int *)b-*(int *)a;
}
int amp(const void *a,const void *b)
{
    struct ed *c,*d;
    c=(ed *)a;
    d=(ed *)b;
    return d->cnt-c->cnt;
}
int MAX(int a,int b)
{
    if(a>b)return a;
    return b;
}
int main()
{
    int i,n,j,k,t,x,y,temp,m;
    __int64 sum;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&map[i][j]);
                p[i][j].num=n-MAX(i,j);
                p[i][j].count=p[i][j].num;
            }
        }
        scanf("%d",&m);
        for(i=0;i<m;i++)
            scanf("%d",&a[i]);
        qsort(a,m,sizeof(a[0]),cmp);
        for(i=0;i<n-1;i++)
        {
            for(j=0;j<n-1;j++)
            {
                x=i+1;y=j+1;temp=1;
                while(x<n&&y<n)
                {
                    p[x][y].count+=p[i][j].num-temp;
                    k=x-1;
                    while(k>=i)
                    {
                        p[k][y].count+=p[i][j].num-temp;
                        k--;
                    }
                    k=y-1;
                    while(k>=j)
                    {
                        p[x][k].count+=p[i][j].num-temp;
                        k--;
                    }
                    x++;y++;
                    temp++;
                }
            }
        }
        k=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                if(map[i][j]==0)
                {
                    e[k].x=i;
                    e[k].y=j;
                    e[k++].cnt=p[i][j].count;
                }
        }
        qsort(e,k,sizeof(e[0]),amp);
        for(i=0;i<k;i++)
        {
            x=e[i].x;
            y=e[i].y;
            sum+=p[x][y].count*a[i];
        }
        printf("%I64d\n",sum);            
    }
    return 0;
}
