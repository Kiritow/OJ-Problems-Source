#include<iostream>
using namespace std;
int ran[105][105];
int b[105];
int cmp(int *a,int *b,int n)
{
 int i;
 for(i=1;i<=n;i++)
   if(a[i]>b[i])
    break;
   if(i==n+1)
            return -1;
 for(i=1;i<=n;i++)
   if(a[i]<b[i])
    break;
   if(i==n+1)
            return 1;
   return 0;
}
int main()
{
    int c,i,j,max,temp,m,n;
    cin>>c;
    while(c--)
    {
     cin>>m>>n;
        for(i=1;i<=n;i++)
      for(j=1;j<=m;j++)
      {
       scanf("%d",&temp);
       ran[temp][i]=j;
      }
      for(i=1;i<=m;i++)
      {
       max=i;
             for(j=1+i;j<=m;j++)
        if(cmp(ran[j],ran[max],n)==1)
         max=j;
        if(max!=i)
        {
         for(j=1;j<=n;j++)
         {
          temp=ran[max][j];
          ran[max][j]=ran[i][j];
          ran[i][j]=temp;
         }
        }
      }
      for(i=1;i<=m;i++)
       b[i]=1;
      for(i=1;i<=m;i++)
      {
       max=-1;
       for(j=1;j<i;j++)
       { 
        if(cmp(ran[i],ran[j],n)==-1)
        {
         if(b[j]>max)
          max=b[j];
        }
       }
        if(max+1>b[i])
         b[i]=max+1;
      }
      max=-1;
      for(i=1;i<=m;i++)
      {
       if(b[i]>max)
        max=b[i];
      }
      cout<<max<<endl;
    }
    return 0;
}
