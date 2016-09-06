#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int hash[500024]={0};
int prime( int num[] )
{
    for( int i=3;i<=1000;i+=2 )
    {
         if( hash[i/2] )
           continue;
         int x=i<<1;
         for( int j=i*i; j<=1000000; j+=x ) 
            hash[j/2]=1;    
    }
    int count=0;
    num[++count]=2;
    for( int i=1;i<=500000;i++ )
    {
         if( hash[i]==0 )
         num[++count]=( i<<1 )+1;     
    }    
    return count;
}
bool  judge( int num[], int count , long long  number )
{
    long long t=( long long )sqrt( number ) ;
    for( int i=1;i<=count; i++ )
    {
         if( number==1 ) break;
         if( 0==(number%num[i]) )
         {
             number/=num[i];
             if( number%num[i]==0 )  return true;     
         }      
    }
    if( number!=1 )
    {
         t=( long long  )sqrt( number ) ;
             if( (t*t)==number )  
                return true;      
    }
    return false;     
}
int main( )
{
    int T,num[78550];
    int count = prime( num );
    scanf( "%d",&T );
    for( int i=1;i<=T; i++ )
    {
        long long number;
        scanf( "%I64d",&number );
        printf( "Case %d: ",i );
        bool t=judge( num,count,number );
        printf( t?"No\n":"Yes\n" );
    }
    return 0;    
}
