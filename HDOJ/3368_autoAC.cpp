#include<stdio.h>
#include<string.h>
const int maxn = 10;
char mat[ maxn ][ maxn ];
const int dx[]={-1,1,-1,1};
const int dy[]={1,-1,-1,1};
int max( int a,int b ){
    return a>b?a:b;
}
bool in( int x,int y ){
    if( x>=1&&x<=8&&y>=1&&y<=8 ) return true;
    else return false;
}
int solve( int x,int y ){
    int ans = 0;
    int pos;
    pos = -1;
    for( int i=y+1;i<=8;i++ ){
        if( mat[x][i]=='D' ){
            pos = i;
            break;
        }
    }
    if( pos!=-1 ){
        for( int i=y+1;i<=pos;i++ ){
            if( mat[x][i]=='*' ){
                pos = -1;
                break;
            }
        }
    }
    if( pos!=-1 ){
        for( int i=y+1;i<=pos;i++ ){
            if( mat[x][i]=='L' )
                ans++;
        }
    }
    pos = -1;
    for( int i=y-1;i>=1;i-- ){
        if( mat[x][i]=='D' ){
            pos = i;
            break;
        }
    }
    if( pos!=-1 ){
        for( int i=y-1;i>=pos;i-- ){
            if( mat[x][i]=='*' ){
                pos = -1;
                break;
            }
        }
    }
    if( pos!=-1 ){
        for( int i=y-1;i>=pos;i-- ){
            if( mat[x][i]=='L' )
                ans++;
        }
    }
    pos = -1;
    for( int i=x+1;i<=8;i++ ){
        if( mat[i][y]=='D' ){
            pos = i;
            break;
        }
    }
    if( pos!=-1 ){
        for( int i=x+1;i<=pos;i++ ){
            if( mat[i][y]=='*' ){
                pos = -1;
                break;
            }
        }
    }
    if( pos!=-1 ){
        for( int i=x+1;i<=pos;i++ ){
            if( mat[i][y]=='L' )
                ans++;
        }
    }
    pos = -1;
    for( int i=x-1;i>=1;i-- ){
        if( mat[i][y]=='D' ){
            pos = i;
            break;
        }
    }
    if( pos!=-1 ){
        for( int i=x-1;i>=pos;i-- ){
            if( mat[i][y]=='*' ){
                pos = -1;
                break;
            }
        }
    }
    if( pos!=-1 ){
        for( int i=x-1;i>=pos;i-- ){
            if( mat[i][y]=='L' )
                ans++;
        }
    }
    int posx,posy;
    int K;
    posx = -1;
    for( int k=1;k<=8;k++ ){
        int tx = x+k*dx[0];
        int ty = y+k*dy[0];
        if( in(tx,ty)==false ) break;
        if( mat[tx][ty]=='D' ){
            posx = tx;
            posy = ty;
            K = k;
            break;
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[0];
            int ty = y+k*dy[0];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='*' ){
                posx = -1;
                break;
            }
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[0];
            int ty = y+k*dy[0];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='L' )
                ans++;
        }
    }
    posx = -1;
    for( int k=1;k<=8;k++ ){
        int tx = x+k*dx[1];
        int ty = y+k*dy[1];
        if( in(tx,ty)==false ) break;
        if( mat[tx][ty]=='D' ){
            posx = tx;
            posy = ty;
            K = k;
            break;
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[1];
            int ty = y+k*dy[1];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='*' ){
                posx = -1;
                break;
            }
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[1];
            int ty = y+k*dy[1];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='L' )
                ans++;
        }
    }
    posx = -1;
    for( int k=1;k<=8;k++ ){
        int tx = x+k*dx[2];
        int ty = y+k*dy[2];
        if( in(tx,ty)==false ) break;
        if( mat[tx][ty]=='D' ){
            posx = tx;
            posy = ty;
            K = k;
            break;
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[2];
            int ty = y+k*dy[2];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='*' ){
                posx = -1;
                break;
            }
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[2];
            int ty = y+k*dy[2];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='L' )
                ans++;
        }
    }
    posx = -1;
    for( int k=1;k<=8;k++ ){
        int tx = x+k*dx[3];
        int ty = y+k*dy[3];
        if( in(tx,ty)==false ) break;
        if( mat[tx][ty]=='D' ){
            posx = tx;
            posy = ty;
            K = k;
            break;
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[3];
            int ty = y+k*dy[3];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='*' ){
                posx = -1;
                break;
            }
        }
    }
    if( posx!=-1 ){
        for( int k=1;k<=K;k++ ){
            int tx = x+k*dx[3];
            int ty = y+k*dy[3];
            if( in(tx,ty)==false ) break;
            if( mat[tx][ty]=='L' )
                ans++;
        }
    }
    return ans;
}
int main(){
    int T;
    scanf("%d",&T);
    int ca = 1;
    while( T-- ){
        for( int i=1;i<=8;i++ ){
            scanf("%s",mat[i]+1);
        }
        int ans = 0;
        for( int i=1;i<=8;i++ ){
            for( int j=1;j<=8;j++ ){
                if( mat[i][j]=='*' ){
                    ans = max( ans,solve( i,j ) );
                }
            }
        }
        printf("Case %d: %d\n",ca++,ans);
    }
    return 0;
}
