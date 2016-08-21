#include <stdio.h>
int main(void)
{
    int n,k,i,j,flag,m,f[51],s[51],sum,x;
    while (scanf("%d%d",&n,&k)!=EOF&&(n&&k))
    {
          for(i=0;i<n;i++)
          {
                          f[i]=1;
                          scanf("%d",&s[i]);
                          }
          flag=1;m=1;
          while (flag)
          {
                flag=0;
                for(i=0;i<n-m;i++)
                {
                              if(s[i]>s[i+1])
                              {
                                             flag=1;
                                             x=s[i+1];
                                             s[i+1]=s[i];
                                             s[i]=x;
                                             }    
                                  }
                m++;
                }
          sum=0;
          for(i=0;i<n;i++)
          {
                          if(f[i]==0)
                          {
                                     continue;
                                     }
                          for(j=i+1;j<n;j++)
                          {
                                          if(f[j]==0) continue;
                                          if(s[i]*k==s[j])
                                          {
                                                          f[j]=0;
                                                          f[i]=0;
                                                          sum++;
                                                          break;
                                                          }
                                          }
                          }
          printf("%d\n",sum);
          }   
}
