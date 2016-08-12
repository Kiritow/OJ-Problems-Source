#include<stdio.h>   
#include <memory.h>   
#include<stdlib.h>   
struct Exchange{  
    int room;  
    int javabean;  
};  
int cmp( const void *a , const void *b )   
{   
    struct Exchange *c = (Exchange *)a;   
    struct Exchange *d = (Exchange *)b;   
    if (d->room*1.0/d->javabean > c->room*1.0/c->javabean)  
        return 1;  
    else if (d->room*1.0/d->javabean < c->room*1.0/c->javabean)  
        return -1;  
    else return 0;  
}   
double summation(Exchange* ex,int len,int javabeans)  
{  
    double sum=0;  
    qsort(ex,len,sizeof(Exchange),cmp);  
    for(int i=0;i<len;i++)  
    {  
        if(javabeans-ex[i].javabean>0)  
        {  
            sum+=ex[i].room;  
            javabeans-=ex[i].javabean;  
        }  
        else  
        {  
            sum+=javabeans*1.0/ex[i].javabean*ex[i].room;  
            break;  
        }  
    }  
    return sum;  
}  
int main()  
{  
    int m,n;  
    while(scanf("%d%d",&m,&n)!=EOF)  
    {  
        if(m==-1&&n==-1)  
            break;  
        Exchange* e=new Exchange[n];  
        for(int i=0;i<n;i++)  
            scanf("%d%d",&(e[i].room),&(e[i].javabean));  
        double result=summation(e,n,m);  
        printf("%.3lf\n",result);  
    }  
    return 0;  
}
