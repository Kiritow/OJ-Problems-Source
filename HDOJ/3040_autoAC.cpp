#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 50005
struct node
{
    int x;
    __int64 tt;
    int id;
}a[N],b[N];
int mark[15];
int fun(char *s)
{
    int a,b,c;
    sscanf(s,"%d:%d:%d",&a,&b,&c);
    return a*3600+b*60+c;
}
int cmp(const void *a,const void *b)
{
    node *c,*d;
    c=(node *)a;d=(node *)b;
    if(c->tt!=d->tt)
        return c->tt<d->tt?1:-1;
    else
        return c->x-d->x;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        int i,j,k;
        j=0;
        char s[15];
        while(scanf("%s",s),strcmp(s,"#end")!=0)
        {
            a[j].x=fun(s);
            scanf("%I64d%d",&a[j].tt,&a[j].id);
            j++;
        }
        qsort(a,j,sizeof(a[0]),cmp);
        k=1;
        b[0]=a[0];
        for(i=1;i<j;i++)
        {
            if(a[i].tt!=a[i-1].tt||a[i].x-a[i-1].x>=60)
                b[k++]=a[i];
        }
        memset(mark,0,sizeof(mark));
        for(i=0;i<k;i++)
            mark[b[i].id]++;
        printf("The result is :\n");
        for(i=1;i<=n;i++)
        {
            printf("%02d : ",i);
            for(j=1;j<=mark[i];j++)
                printf("*");
            printf("\n");
        }
    }
    return 0;
}
