#include<stdio.h>
#include<string.h>
char hash[12000005];
int main()
{
    int N,i,A,B,j,p,q,temp;
    char s[100];
    while(scanf("%d",&N)!=EOF)
    {
        memset(hash,0,sizeof(hash));
        scanf("%d %d",&p,&q);
        if(p>q)
        {
                  temp=p;
                     p=q;
                     q=temp;
        }
        for(i=0;i<N;i++)
        {
              scanf("%d %d",&A,&B);
              if(A>B)
              {
                  temp=A;
                   A=B;
                   B=A;
              }
              for(j=A;j<=B;j++)
              {
                 if(j<0)
                     hash[-j]++;
                 else
                     hash[j]++;
              }
              gets(s);
        }
        for(i=q;i>=p;i--)
        {
            if(i>=0&&hash[i]==0)
            {
                printf("%d\n",i);
                break;
            }
            if(i<0&&hash[-i]==0)
            {
                printf("%d\n",i);
                break;
            }
        }
        if(i<p)
            printf("Badly!\n");
    }
}
