#include<stdio.h>
#include<stdlib.h>
int n;
__int64 que[5][210],a[41000],b[41000];
int cmp(const void*a,const void*b)
{
    if(*(__int64 *)a-*(__int64 *)b > 0)
    return 1;
    return -1;
}
void fun()
{
    int i,f,ji=0;
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            a[ji]=que[0][i]+que[1][f];
            ji++;            
        }        
    }
    qsort(a,n*n,sizeof(a[0]),cmp);
    ji=0;    
    for(i=0;i<n;i++)
    {
        for(f=0;f<n;f++)
        {
            b[ji]=que[2][i]+que[3][f];
            ji++;            
        }        
    }    
    qsort(b,n*n,sizeof(b[0]),cmp);
}
int sea(__int64 x)
{
    int head=0,tail=n*n-1;
    while(1)
    {
        if(x == a[head]+b[tail])
        {
            return 1;
        }
        if(a[head]+b[tail] > x)
        {
            tail--;
            if(-1 == tail)
            {
                break;
            }
        }
        else
        {
            head++;
            if(n*n == head)
            {
                break;
            }
        }    
    }
    return 0;
}
int main()
{
    int i,num,f,g;
    scanf("%d",&num);
    for(i=0;i<num;i++)
    {
        scanf("%d",&n);
        for(f=0;f<5;f++)
        {
            for(g=0;g<n;g++)
            {
                scanf("%I64d",&que[f][g]);            
            }
        }
        fun();
        for(g=0;g<n;g++)
        {
            if(1 == sea(-que[4][g]))
            {
                printf("Yes\n");
                break;
            }
        }
        if(g == n)
        {
            printf("No\n");
        }
    }
    return 0;
}
