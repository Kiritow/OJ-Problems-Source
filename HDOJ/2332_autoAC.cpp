#include <stdio.h>
#include <string.h>
const int MAXCUBE = 1048576 ;
int d ;
int n[21] ;
int mv[21] ;
char space[MAXCUBE] ;
int q[MAXCUBE] ;
int stp[MAXCUBE] ;
int front , rear ;
bool vst[MAXCUBE] ;
int p ;
int s , m , t , curs;
void visit(int pt){
    if ( !(pt >= 0 && pt < mv[d]) ) {
        return ;
    }
    if ( vst[pt] || space[pt] ) return ;
    vst[pt] = true ;
    stp[pt] = curs ;
    q[rear] = pt ;
    rear ++ ;
}
int bfs(int from , int to ){
    int curp , newp ;
    int i ;
    memset(vst , false , sizeof(vst)) ;
    front = 0 ;
    rear = 1 ;
    q[0] = from ;
    stp[from] = 0 ;
    vst[from] = true ;
    while ( front < rear ){
        curp = q[front ++] ;
        curs = stp[curp] + 1;
        if ( curp == to ) {
            front -- ;
            break ;
        }
        for ( i = 0 ; i < d ; i ++ ){
            if ( ( ( curp ) / mv[i] ) % n[i] != n[i] - 1 ){
                newp = curp + mv[i] ;
                visit(newp);
            }
            if ( ( ( curp ) / mv[i] ) % n[i] != 0 ){
                newp = curp - mv[i] ;
                visit(newp);
            }
        }
    }
    if ( front == rear ) return - 1;
    else return stp[curp] ;
}
char nextchar(){
    char ch ;
    do{
        ch = getchar() ;
    }while ( ch != '#' && ch != '.' && ch != 'S' && ch != 'M' && ch != 'T' ) ;
    if ( ch == 'S' ) s = p ;
    if ( ch == 'M' ) m = p ;
    if ( ch == 'T' ) t = p ;
    if ( ch == '#' ) return 1 ;
    else return 0 ;
}
void readmap(int layer){
    int i;
    if ( layer == 0 ){
        space[p ++ ] = nextchar() ;
        return ;
    }
    for ( i = 0 ; i < n[layer - 1] ; i ++ ) readmap( layer - 1 ) ;
}
int main(){
    int i ;
    int ans ;
    while (1){
        scanf("%d",&d);
        if ( d == 0 ) break ;
        for ( i = 0 ; i < d ; i ++ ){
            scanf("%d",n + i ) ;            
        }
        mv[0] = 1 ;
        for ( i = 1 ; i <= d ; i ++ ){
            mv[i] = n[i - 1] * mv[i - 1] ;
        }
        p = 0 ;
        readmap(d) ;
        ans = 0 ;
        space[m] = 1 ;
        i = bfs(t,s) ;
        if ( i == -1 ){
            ans = -1 ;
        }else{
            space[m] = 0 ;
            ans += i ;
            i = bfs(s,m) ;
            if ( i == -1 ){
                ans = -1 ;
            }else{
                ans += i ;
                i = bfs(m,t) ;
                if ( i == -1 ){
                    ans = -1 ;
                }else{
                    ans += i ;
                }
            }
        }
        if ( ans == -1 )puts("No solution. Poor Theseus!");
        else{
            printf("Theseus needs %d steps.\n",ans);
        }
    }    
    return 0 ;
}
