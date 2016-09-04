#include<iostream> 
using namespace std; 
int main()
 { 
      int a[4][1000],b;
      int n,i,j,count,t; 
       t=0; 
       while(cin>>n)
     {
        count=0; 
        if(n==0) break;
       for(i=1;i<3;i++)
         for(j=1;j<=n;j++)
    {         
          cin>>b; 
         if(i<3) 
        a[i][b]=j; 
    } 
       for(j=1;j<=n;j++)
         cin>>a[3][j]; 
        for(j=1;j<=n;j++)
  {
        if(a[1][j]<=a[3][j])
              count=count+3;
       else
    { 
        if(a[1][j]<a[2][j])
          count=count+2; 
       else 
       count=count+1;
    } 
  }
        cout<<"Case "<<++t<<": "<<count<<endl; 
    } 
 return 0;
 }
