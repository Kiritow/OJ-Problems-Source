#include<stdio.h>
int main()
{
    int i,j,n;
    int s[100],e[100];
    while(scanf("%d\n",&n)!=EOF&&n)
    {
        for(i=0;i<n;i++)
        scanf("%d%d",&s[i],&e[i]);
        int k=0,l=0;
        for(i=0;i<n;i++)
         for(j=i+1;j<n;j++)
         {
             if(e[i]>e[j])
             {
                 l=s[i];
                 s[i]=s[j];
                 s[j]=l;    
                 k=e[i];
                 e[i]=e[j];
                 e[j]=k;
            }
         }
         int count=0,m=0;
         for(i=0;i<n;i++)
         {
             if(s[i]>=m)
             {
                     count++;
                     m=e[i];
            }         
         }
        printf("%d\n",count); 
    }
    return 0;
}
