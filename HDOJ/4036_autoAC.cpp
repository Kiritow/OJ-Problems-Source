#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
typedef struct _point
{
    double x,y,v;
    double HP;
}point;
point Poin[ 1005 ];
point Tudo[ 1005 ];
int search( double X, int H )
{
    int m,l = 1,h = H;
    while ( l < h ) {
        m = (l+h+1)>>1;
        if ( Poin[ m ].x > X )
            h = m-1;
        else l = m;
    }
    return h;
}
int main()
{
    int T,N,M,W;
    scanf("%d",&T);
    for ( int t = 1 ; t <= T ; ++ t ) {
        scanf("%d%d%d",&N,&M,&W);
        for ( int i = 1 ; i <= N ; ++ i )
            scanf("%lf%lf",&Poin[ i ].x,&Poin[ i ].y);
        for ( int i = 1 ; i <= M ; ++ i )
            scanf("%lf%lf%d",&Tudo[ i ].x,&Tudo[ i ].v,&W);
        for ( int i = 1 ; i <= M ; ++ i ) {
            int s = search( Tudo[ i ].x, N );
            if ( Tudo[ i ].x == Poin[ s ].x )
                Tudo[ i ].y = Poin[ s ].y;
            else
                Tudo[ i ].y = Poin[ s ].y + (Poin[ s+1 ].y-Poin[ s ].y)/(Poin[ s+1 ].x-Poin[ s ].x)*(Tudo[ i ].x-Poin[ s ].x);
            Tudo[ i ].HP = 40.0*(Tudo[ i ].y-Poin[ 1 ].y) + Tudo[ i ].v*Tudo[ i ].v;
        }
        double Max = 0;
        for ( int i = 1 ; i <= M ; ++ i )
            if ( Max < Tudo[ i ].HP ) 
                Max = Tudo[ i ].HP;
        for ( int i = 2 ; i <= N ; ++ i ) {
            double HP = 40.0*(Poin[ i ].y-Poin[ 1 ].y);
            if ( Max < HP ) Max = HP;
        }
        printf("Case %d: %.2lf\n",t,sqrt(Max));
    }
    return 0;
}
