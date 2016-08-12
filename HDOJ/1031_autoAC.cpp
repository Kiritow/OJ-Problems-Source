#include<iostream>
#include<stdio.h>
#include<fstream>
using namespace std;
struct Node{
int num;
double times;
};
Node T[1000];
int cmp1( const void *a , const void *b )
{
struct Node *c = (Node *)a;
struct Node *d = (Node *)b;
if(c->times != d->times) return d->times - c->times;
}
int cmp2( const void *a , const void *b )
{
struct Node *c = (Node *)a;
struct Node *d = (Node *)b;
return c->num > d->num ? -1 : 1 ;
}
int main()
{
    int i,j,k,n,m;
    double temp;
    while(EOF != scanf("%d %d %d",&n,&m,&k))
    {
        for(i=0;i<m;i++)
        {
            T[i].num = i+1 ;
            T[i].times = 0;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%lf",&temp);
                T[j].times += temp;
            }
        }
        qsort(T,m,sizeof(T[0]),cmp1);
        qsort(T,k,sizeof(T[0]),cmp2);
        for(i=0;i<k;i++)
        {
            printf("%d",T[i].num);
            if(i!= k-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
