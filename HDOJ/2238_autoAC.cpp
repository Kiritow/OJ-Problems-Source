#include<iostream>
#include<cstdio>
#include<string.h>
using namespace std;
struct sta{
        int s[4];
};
struct node{
        int m[8][8];
}res,temp,mod;
int getnum( sta a )
{
     int m,n,index;
     m=n=0;
     for( int i=0;i<4;i++ )
          if( m<a.s[i] )
               m=a.s[i],index=i;
    m=0;
    for( int i=0;i<4;i++ )
         m=m*10+a.s[(index+i)%4],
         n=n*10+a.s[(4+index-i)%4];
    return m>n?m:n;
}
int h[4444];
void dfs( sta a,sta b,int at )
{
      if( at>3 )
      {
           int n1=getnum(a);
           int n2=getnum(b);
           temp.m[h[n1]][h[n2]]++;
           return ;
     }
     for( int i=0;i<=a.s[at];i++ )//1->2
     for( int j=0;i+j<=a.s[at];j++ )//1->0
     {
            sta x=b;
            x.s[at]=x.s[at]-i-j;
            x.s[(at+1)%4]+=i;
            x.s[(at+3)%4]+=j;
            dfs( a,x,at+1 );
       }
}
node matriXmult( node a,node b )
{
      node c;
      memset( c.m,0,sizeof(c.m) );
      for( int i=0;i<8;i++ )
      for( int k=0;k<8;k++ )
      if( a.m[i][k] )
      for( int j=0;j<8;j++ )
            c.m[i][j]+=a.m[i][k]*b.m[k][j];
     for( int i=0;i<8;i++ )
     for( int j=0;j<8;j++ )
           c.m[i][j]%=9937;
     return c;
}
void matrixPower( int n )
{
      memset( res.m,0,sizeof(res.m) );
      for( int i=0;i<8;i++ )
      {
            res.m[i][i]=1;
            for( int j=0;j<8;j++ )
                   mod.m[i][j]=temp.m[i][j];
     }
      for( int i=0;i<32;i++ )
      {
            if( n&(1<<i) )
                  res=matriXmult( res,mod );
            mod=matriXmult( mod,mod );
     }
}
int main()
{
     memset( temp.m,0,sizeof(temp.m) );
     for( int i=0;i<8;i++ )
          res.m[i][i]=1;
     int a[8][4]={ 1,1,1,1,2,0,2,0,2,1,0,1,
                    2,1,1,0,2,2,0,0,3,0,1,0,
                  3,1,0,0,4,0,0,0 };
    h[1111]=0;h[2020]=1;h[2101]=2;
    h[2110]=3;h[2200]=4;h[3010]=5;
    h[3100]=6;h[4000]=7;
    sta s;
    for( int i=0;i<8;i++ ){
          for( int j=0;j<4;j++ )
               s.s[j]=a[i][j];
         dfs( s,s,0 );
    }
    int n;
    while( scanf( "%d",&n )!=EOF )
    {
            matrixPower(n);
            printf( "%d\n",res.m[0][0] );
     }
     return 0;
}
