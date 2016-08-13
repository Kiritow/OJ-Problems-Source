#include<stdio.h>
#include<string.h>
int record[110][110];
int a1[110],weishu[110];
void cheng(int a)
{
    int i,m,c,chushu,temp;
    m=weishu[a-1];
    c=0;
    for(i=0;i<=m;++i)
    {
        a1[i]=a1[i]*(4*a-2)+c;
        c=a1[i]/10000;
        a1[i]%=10000;
    }
    if(c>0)
    {
        ++m;
        a1[m]=c;
    }
     chushu=a+1,temp=a1[m];
    if(m==0)
        a1[0]/=chushu;
    else
    {
        for(i=m;i>=0;--i)
        {
            if(temp<chushu)
            {
                if(i==m)
                {
                    --m;
                }
                else
                    a1[i]=0;
            }
            else
            {
                a1[i]=temp/chushu;
                temp%=chushu;
            }
            temp=temp*10000+a1[i-1];
        }
    }
    weishu[a]=m;
    for(i=0;i<=weishu[a];++i)
    {
        record[a][i]=a1[i];
    }
}
int main()
{
    int a,i,n;
    record[1][0]=1;
    weishu [1]=0;
    a1[0]=1;
    for(i=2;i<=100;++i)
    {
        cheng(i);
    }
    while(scanf("%d",&n)&&n!=-1)
    {
        printf("%d",record[n][weishu[n]]);
        for(i=weishu[n]-1;i>=0;--i)
        {
            printf("%.4d",record[n][i]);
        }
        printf("\n");
    }
}
