#include<iostream>
#include<algorithm>
#include<stdlib.h>
using namespace std;
struct Node
{
    int value1,value,sub;
}node[10005],ex;
int T,P,N;
int i,sum;
bool cmp1(struct Node p,struct Node q)  
{ 
    if(p.value!=q.value)
        return p.value>q.value;
    else return p.sub<q.sub;
}
int cmp2(const void *p,const void *q)  
{  
    int c = (*(struct Node*)p).sub - (*(struct Node*)q).sub;  
    if(c>0) return 1;  
    else return -1;  
}
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>P>>N;
        sum=0;
        for(i=0;i<N;i++)
        {
            scanf("%d",&node[i].value);
            node[i].sub=i;
            node[i].value1=node[i].value;
            sum+=node[i].value;
        }
        if(sum<P)
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        sort(node,node+N,cmp1);
        int ln=N,lp=P,x;
        while(lp>0)
        {
            x=node[ln-1].value;
            if(lp/ln<x) x=lp/ln;
            if(x>0)
            {
                int pre_ln=ln;
                for(i=0;i<pre_ln;i++)
                {
                    node[i].value-=x;
                    if(!node[i].value) ln--;
                }
                lp-=x*pre_ln;
            }
            else
            {
                for(i=0;i<lp;i++)
                    node[i].value--;
                lp=0;
            }
        }
        qsort(node,N,sizeof(struct Node),cmp2);
        for(i=0;i<N-1;i++)
            printf("%d ",node[i].value1-node[i].value);
        printf("%d\n",node[N-1].value1-node[N-1].value);
    }
    return 0;
}
