#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j,rank[100],s,t;
    char str[20];
    while(scanf("%d",&n)!=EOF)
    {
        for(i=0;i<n;i++)
        {
            getchar();
            for(j=0;j<20;j++)
            {
                scanf("%c",&str[j]);
                if(str[j]==' ')
                    break;
            }
            scanf("%d",&rank[i]);
            getchar();
        }
        for(i=0;i<n;i++)
            for(j=i+1;j<n;j++)
            {
                if(rank[j]<rank[i])
                {
                    t=rank[j];rank[j]=rank[i];rank[i]=t;
                }
            }
        s=0;
        for(i=0;i<n;i++)
            s+=abs(i+1-rank[i]);
        printf("%d\n",s);
    }
    return 0;
}
