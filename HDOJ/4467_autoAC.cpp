#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int N = 101010;
int n, m;
LL ans[3], sum[N][2];
vector<LL> c[N];
vector<int> lin[N];
int color[N], key[N], deg[N];
struct node{
    int a,b; LL c;
    bool operator < (const node &tmp)const{
        return (a<tmp.a)||(a==tmp.a&&b<tmp.b);    
    }
}e[N];
void init(){
    int lim = (int)sqrt(n);        
    for(int i = 0; i <= n; i++) c[i].clear(), lin[i].clear();
    memset( sum, 0, sizeof(sum));
    memset( ans, 0, sizeof(ans));
    memset( key, 0, sizeof(key));
    memset( deg, 0, sizeof(deg));
    for(int i = 1; i <= n; i++) scanf("%d", &color[i] );
    for(int i = 1; i <= m; i++){
        scanf("%d%d%I64d",&e[i].a,&e[i].b,&e[i].c);
        if( e[i].a > e[i].b ) swap( e[i].a, e[i].b );        
    }    
    sort( e+1, e+m+1 );
    int t = 1;
    for(int i = 2; i <= m; i++) 
        if( e[i].a != e[t].a || e[i].b != e[t].b ) e[++t] = e[i];
        else    e[t].c += e[i].c;
    m = t; 
    for(int i = 1; i <= m; i++){
        int a = e[i].a, b = e[i].b; 
        ans[ color[a]+color[b] ] += e[i].c;
        deg[a]++; deg[b]++;    
    }        
    lim = round(sqrt(n));    
    for(int i = 1; i <= n; i++) if( deg[i] > lim ) key[i] = 1;
    for(int i = 1; i <= m; i++){
        int a = e[i].a, b = e[i].b;
        sum[a][ color[b] ] += e[i].c;
        sum[b][ color[a] ] += e[i].c;
        if( key[a] && key[b] ){
            lin[a].push_back(b); c[a].push_back(e[i].c);
            lin[b].push_back(a); c[b].push_back(e[i].c);    
        }     
        if( key[a] == 0 ) lin[a].push_back(b),c[a].push_back(e[i].c);
        if( key[b] == 0 ) lin[b].push_back(a),c[b].push_back(e[i].c);
    }
}
void change(int x){
    if( key[x] ){ 
        for(int i = 0; i < (int)(lin[x].size()); i++){
            sum[ lin[x][i] ][ color[x] ] -= c[x][i];
            sum[ lin[x][i] ][ color[x]^1 ] += c[x][i]; 
        }    
    }
    else{ 
        sum[x][0] = sum[x][1] = 0;
        for(int i = 0; i < (int)(lin[x].size()); i++){
            sum[x][ color[ lin[x][i] ] ] += c[x][i];
            if( key[ lin[x][i] ] ){
                sum[ lin[x][i] ][ color[x] ] -= c[x][i];
                sum[ lin[x][i] ][ color[x]^1 ] += c[x][i];
            }        
        }
    }    
    ans[ color[x]+0 ] -= sum[x][0]; ans[ color[x]+1 ] -= sum[x][1];
    ans[ (color[x]^1)+0 ] += sum[x][0]; ans[ (color[x]^1)+1 ] += sum[x][1];
    color[x] ^= 1;    
} 
int main(){
    int Case = 1;
    while( scanf("%d%d",&n,&m) != EOF){
        printf("Case %d:\n", Case++);
        init();
        char op[110]; int Q, a, b;
        scanf("%d", &Q );
        while( Q-- ){
            scanf("%s", op);
            if( op[0] == 'A' ){
                scanf("%d%d",&a,&b);
                printf("%I64d\n", ans[a+b] );
            }
            else{
                scanf("%d",&a);
                change( a );
            }        
        }
    }
    return 0;
}
