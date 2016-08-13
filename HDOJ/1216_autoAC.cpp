#include<stdio.h>
#include<string.h>
#define M 34000
int n,num[M],ss[3001],t=0;
int main()
{
    int i,j,k;
    memset(num,0,sizeof(num));
    for(i=2;i<M;i++)
    {
        if(!num[i])
        {
            ss[t++]=i;k=0;
            for(j=i+1;j<M;j++)
            if(!num[j])
            {
                k++;
                if(k==i)
                {
                    k=0;
                    num[j]=1;
                }
            }
        }
        if(t==3000)
        {break;}
    }
    while(scanf("%d",&n),n!=0)
    {
        printf("%d\n",ss[n-1]);
    }
    return 0;
}
