#include<stdio.h>
#include<string.h>
#define i64 __int64
int Max(int a,int b){return a>b?a:b;}
int Min(int a,int b){return a<b?a:b;}
int n,m;
int main()
{
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        int hash[5555][2];
        int i,maxw,maxl,j;
        i64 a_min,a_max,temp;
        a_min=a_max=0;
        maxw=maxl=0;
        for(i=0;i<5555;i++)hash[i][0]=hash[i][1]=0;
        for(i=0;i<n;i++)
        {
            scanf("%d",&temp);
            maxw=Max(temp,maxw);
            hash[temp][0]++;
        }
        for(i=0;i<m;i++)
        {
            scanf("%d",&temp);
            maxl=Max(temp,maxl);
            hash[temp][1]++;
        }
        if(maxw!=maxl)
        {
            printf("No solution.\n");
            continue;
        }
        for(i=1;i<=maxw;i++)
        {
            if(hash[i][0]||hash[i][1])
            {
                a_min+=Max(hash[i][0],hash[i][1])*i;
            }
            temp=0;
            if(hash[i][0])
            {
                for(j=1;j<=maxl;j++)
                {
                    if(hash[j][1])temp+=Min(i,j)*hash[j][1];
                }
            }
            a_max+=temp*hash[i][0];
        }
        printf("%I64d %I64d\n",a_min,a_max);
    }
}
