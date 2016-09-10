#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
using namespace std;
const int maxn = 1015;
const int maxm = maxn*maxn;
const int inf1 = 0x3f3f3f3f;
const double inf2 = 9999999999;
struct Point {
    double x,y;
}pnt[ maxn ];
struct Edge{
    int u,v;
    double val;
    int id;
}edge[ maxn<<1 ];
int cnt_edge;
double mat[ maxn ][ maxn ];
double dis[ maxn ];
bool vis[ maxn ];
int pre[ maxn ];
double LenPrim1;
double LenPrim2;
int fa[ maxn ],ran[ maxn ];
int find( int x ){
    if( x==fa[x] ) return x;
    else return fa[ x ] = find( fa[x] );
}
void init( int n ){
    for( int i=0;i<n;i++ ){
        fa[ i ] = i;
        ran[ i ] = 1;
    }
    return ;
} 
double dist( int i,int j ){
    return sqrt( (pnt[i].x-pnt[j].x)*(pnt[i].x-pnt[j].x)+(pnt[i].y-pnt[j].y)*(pnt[i].y-pnt[j].y) );
} 
int cmp( Edge a,Edge b ){
    return a.val<b.val;
}    
void GetMap( int n ){
    for( int i=0;i<n;i++ )
        for( int j=0;j<n;j++ ){
            mat[i][j] = dist( i,j );
        }
    return ;
}
double prim( int n,int Belong ){
    for( int i=0;i<n;i++ ){
        dis[ i ] = mat[0][i];
        vis[ i ] = false;
        pre[ i ] = 0;
    }
    vis[0] = true;
    double ans = 0;
    for( int i=0;i<n;i++ ){
        int id = -1;
        double M = inf2;
        for( int j=0;j<n;j++ ){
            if( !vis[j] && M>dis[j] ){
                M = dis[j];
                id = j;
            }
        }
        if( id==-1 ) break;
        vis[ id ] = true;
        ans += M;
        edge[ cnt_ ].u = pre[ id ];
        edge[ cnt_ ].v = id;
        edge[ cnt_ ].id = Belong;
        edge[ cnt_ ].val = mat[ id ][ pre[id] ];
        cnt_edge ++ ;
        for( int j=0;j<n;j++ ){
            if( !vis[j] && dis[j]>mat[id][j] ){
                dis[j] = mat[id][j];
                pre[ j ] = id;
            }
        }
    }
    return ans;
}    
void Deal( int n ){
    for( int i=0;i<cnt_edge;i++ ){
        mat[ edge[i].u ][ edge[i].v ] = inf2;
        mat[ edge[i].v ][ edge[i].u ] = inf2;
    }
}
double Kruskal( int n,int id ){
    double ans = 0;
    init( n );
    int cnt = 0;
    for( int i=0;i<cnt_edge;i++ ){
        if( i==id ) continue;
        int fx = find( edge[i].u );
        int fy = find( edge[i].v );
        if( fx!=fy ){
            if( ran[ fx ]<ran[ fy ] ){
                ran[ fy ] += ran[ fx ];
                fa[ fx ] = fy;
            }
            else {
                ran[ fx ] += ran[ fy ];
                fa[ fy ] = fx;
            }
            cnt ++ ;
            ans += edge[i].val;
            if( cnt==n-1 ) break;
        }
       }
       return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    while( T-- ){
        int n;
        double k;
        scanf("%d%lf",&n,&k);
        for( int i=0;i<n;i++ )
            scanf("%lf%lf",&pnt[i].x,&pnt[i].y);
        GetMap( n );
        cnt_edge = 0;
        LenPrim1 = prim( n,1 );
        Deal( n );
        LenPrim2 = prim( n,2 );
        double ans = LenPrim1;
        double temp_ans = 0;
        sort( edge,edge+cnt_edge,cmp );
        for( int i=0;i<cnt_edge;i++ ){
            if( edge[i].id==1 && edge[i].u!=0 && edge[i].v!=0 ){
                temp_ans = Kruskal( n,i );
                if( temp_ans>ans )
                    ans = temp_ans;
            }
        }
        printf("%.2lf\n",ans*k);
    }
    return 0;
}
