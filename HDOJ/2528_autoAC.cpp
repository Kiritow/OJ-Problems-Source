#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
using namespace std;
const double eps=1e-8;
const int maxn = 505;
struct point{
    double x,y;
};
struct ploy{
    point node[ maxn ];
    int n;
};
point left,right,s;
ploy p,p1,p2;
double cross( point a,point b,point c ){
    return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}
double ploy_area( ploy res ){
    double ans=0;
    res.node[ res.n ]=res.node[0];
    for( int i=0;i<res.n;i++ ){
        ans+=cross( s,res.node[i],res.node[i+1] );
    }
    return ans;
}
int dblcmp(double a) {return a<-eps?-1:a>eps?1:0;}
ploy cut( ploy p,point s,point e ){
    point tmp;
    ploy bb;
    int cnt=0;
    for( int i=0;i<p.n;i++ ){
        int d1,d2;
        double s1,s2;
        d1=dblcmp(s1=cross( p.node[i],s,e ));//璺ㄧ
        d2=dblcmp(s2=cross( p.node[i+1],s,e ));//璺ㄧ
        if( d1>=0 ){
            bb.node[ cnt ]=p.node[ i ];
            cnt++;
        }
        if( d1*d2<0 ){
            tmp.x=(s2*p.node[i].x-s1*p.node[i+1].x)/(s2-s1);
            tmp.y=(s2*p.node[i].y-s1*p.node[i+1].y)/(s2-s1);
            bb.node[ cnt ]=tmp;
            cnt++;
        }
    }
    bb.n=cnt;
    bb.node[ cnt ]=bb.node[ 0 ];
    return bb;
}
int main(){
    while( scanf("%d",&p.n),p.n ){
        for( int i=0;i<p.n;i++ ){
            scanf("%lf%lf",&p.node[ i ].x,&p.node[ i ].y);
        }
        p.node[ p.n ]=p.node[ 0 ];
        scanf("%lf%lf%lf%lf",&left.x,&left.y,&right.x,&right.y);
        s.x=s.y=0;
        p1=cut( p,left,right );
        p2=cut( p,right,left );
        int res1,res2;
        res1=int(fabs(ploy_area( p1 ))/2+0.5);
        res2=int(fabs(ploy_area( p2 ))/2+0.5);
        printf("%d %d\n",res1>res2?res1:res2,res1>res2?res2:res1);
    }
    return 0;
}
