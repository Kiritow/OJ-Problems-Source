#include<stdio.h>
#include<stdlib.h>
int main()
{
   int T,n,x;
   __int64 num[40002];
   scanf( "%d",&T );
   for( int i=1; i<=T; i++ )
   {
        scanf( "%d",&n );
        __int64 ans=0,m=1000003;
        m*=n;
        num[0]=1;
        for( int j=1;j<=40000;j++ )
        {
           num[ j ]=num[j-1]<<1;
           if( num[j]>=m )
                 num[j]-= m;     
        }
        for( int j=0;j<n; j++ )
        {
             scanf( "%d",&x );
             ans+=num[x];
             if( ans >= m )
                ans -= m;      
        }
        ans/=n;
        printf( "Case %d:%I64d\n",i,ans );
   } 
   return 0;  
}
