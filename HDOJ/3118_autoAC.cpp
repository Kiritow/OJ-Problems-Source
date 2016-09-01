#include<stdio.h>
#include<string.h>
#define INF 1000000000
int tou[305],wei[305];
int ji1[20],ji2[20];
int poww(int a,int b)
{
   int sum=1;
   for(int i=0;i<b;i++)
     {
       sum*=a;        
     }    
   return sum;
}
int main()
{
   int T,n,m;
   scanf("%d",&T);
   while(T--)
     {
       scanf("%d%d",&n,&m);
       for(int i=0;i<m;i++)        
        {
          scanf("%d%d",&tou[i],&wei[i]);     
        }
       int min=INF,sum;
       int k=poww(2,n-1);
       for(int i=0;i<=k;i++)
        {
           int k=i;
           int count=0;
           sum=0;
           memset(ji1,0,sizeof(ji1));
           while(k)
             {
                ji1[count++]=k%2;
                k/=2;
             }    
           for(int j=0;j<m;j++)
             {
                if(ji1[tou[j]]==ji1[wei[j]])     sum++;    
                if(sum>min)   break;
             }
           if(sum<min)  min=sum;  
        }
       printf("%d\n",min);
     }    
}
