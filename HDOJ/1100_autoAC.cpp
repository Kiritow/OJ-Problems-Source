#include<stdio.h>
__int64 array[21];
int init()
{
    array[0]=1;
    array[1]=1;
    for(int i=2;i<=20;i++)
    {
        array[i]=0;
        for(int j=0;j<i;j++)
        {
            array[i]+=array[j]*array[i-j-1];
        }
    }
    return 0;
}
int dfs(int num,__int64 n)
{
    for(int i=0;i<=num-1;i++)
    {
        if(n>array[i]*array[num-1-i])
        {
            n-=array[i]*array[num-1-i];
        }
        else
        {
            __int64 x=n%array[num-1-i]==0?n/array[num-1-i]:n/array[num-1-i]+1;
            if(i!=0)
            {
                printf("(");
            dfs(i,x);
            printf(")");
            }
            printf("X");
            if(num-1-i!=0)
            {
                printf("(");
                dfs(num-1-i,n-array[num-1-i]*(x-1));
                printf(")");
            }
            return 0;
        }
    }
    return 0;
}
int main()
{
    __int64 n;
    init();
    while(scanf("%I64d",&n)!=EOF&&n>0)
    {
        __int64 temp=0;
        int num;
        for(int i=1;i<=20;i++)
        {
            if(temp+array[i]>=n)
            {
                n-=temp;
                num=i;
                break;
            }
            temp+=array[i];
        }
        dfs(num,n);
        printf("\n");
    }
    return 0;
}
