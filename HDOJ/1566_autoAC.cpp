#include <stdio.h> 
short last[60],an[60],temp[60];
short a[60][4];
void mult(short *a,short *b,short *c)
{
    int i,j,m,n,k;
    if(a[0]==1&&a[1]==0||b[0]==1&&b[1]==0)  
    {
        c[0]=1;c[1]=0;return;
    }
      m=a[0];n=b[0];
    k=n+m-1;
    for(i=0;i<=k;i++)c[i]=0;
    for(i=1;i<=m;i++) {
    if(a[i])for(j=1;j<=n;j++)if(b[j])c[i+j-1]+=a[i]*b[j];
    }
    for(i=k;i>=1;i--)if(c[i]>9){  c[i-1]+=c[i]/10;c[i]%=10;}
    if(c[0]>0)
    {k++; for(i=k;i>=1;i--)c[i]=c[i-1];   }c[0]=k;
}
void dectoB(int sum,int b,short *S)
{ 
    int i,j,k=0,t,d[20];
    while(sum>0) {  d[++k]=sum%b; sum/=b;  }  
    S[0]=k;
    for(i=1,j=k;i<=k;i++,j--) {S[i]=d[j];}
}  
void copy(short *a,short *b)
{
    int i;
     for(i=0;i<=b[0];i++)
      a[i]=b[i];
}
void answer()
{
     int i;
     printf("%d",an[0]);          
    last[0]=1;last[1]=1;
    for(i=1;i<=an[0];i++)
    {
        printf(" %d",an[i]);
        mult(last,a[an[i]],temp);
        copy(last,temp);                     
    }
    printf("\n");
    for(i=1;i<=last[0];i++)
        printf("%d",last[i]);
        printf("\n");
}
int main()
{
    int i,sum,n,res;
      for(i=1;i<=50;i++)
      dectoB(i,10,a[i]);
      while(scanf("%d",&n)!=EOF)
      {
          if(n<5) {printf("2 1 %d\n%d\n",n-1,n-1);continue;}
          an[0]=0;sum=0;                          
          for(i=2;i<=50;i++)
          {
              if(sum+i>n) break;
              sum+=i;
              an[++an[0]]=i;
          }
          res=n-sum;
        if(res)
        {
              while(1)
               {
                for(i=an[0];i>=1;i--)    
                  {an[i]++;res--;if(res==0) goto loop;}
               }
        }
        loop: answer();
      }
    return 0;  
}
