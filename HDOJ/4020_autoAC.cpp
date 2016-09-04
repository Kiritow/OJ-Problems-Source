#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int N,M,Q,U,C,L;
int name[500110],r[500110],q;
double click[500010],len[500110];
double ans[500110],res[500110];
int hash[100110];
int cmp(const void *_p,const void *_q)
{
    int *a=(int *)_p;
    int *b=(int *)_q;
    return click[*a]>click[*b]?-1:1;
}
int main()
{
    int i,j,k,n,t,tt,cur;
    scanf("%d",&t);
    for(tt=0;tt<t;tt++)
    {
        scanf("%d%d%d",&N,&M,&Q);
        for(i=0;i<M;i++)
        {
            scanf("%d%lf%lf",&name[i],&click[i],&len[i]);
            r[i]=i;
        }    
        qsort(r,M,sizeof(r[0]),cmp);    
        for(i=1;i<=N;i++)
            hash[i]=0;
        for(i=1;i<=M;i++)
            ans[i]=0.0;
        for(i=0;i<M;i++)
        {
            hash[name[r[i]]]++;
            ans[hash[name[r[i]]]]+=len[r[i]];
        }
        res[0]=0;
        for(i=1;i<=M;i++)
        {
            res[i]=ans[i]+res[i-1];
        }
        printf("Case #%d:\n",tt+1);
        for(i=0;i<Q;i++)
        {
            scanf("%d",&q);
            if(q>M)
                printf("%.0f\n",res[M]);
            else
                printf("%.0f\n",res[q]);
        }
    }
    return 0;    
}
