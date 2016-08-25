#include<stdio.h>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
#include<queue>
#include<map>
#include<stack>
#include<set>
#include<math.h>
using namespace std;
typedef long long int64;
typedef pair<int64,int64> PII;
#define MP(a,b) make_pair((a),(b)) 
const int maxn = 115;
const int inf = 0x7fffffff;
const double pi=acos(-1.0);
const double eps = 1e-8;
struct Node{
    char s[ maxn ];
    int cnt;
}a[ maxn ],q[ maxn ];
int Find( char s[],int n ){
    for( int i=1;i<n;i++ ){
        if( strcmp( s,a[i].s)==0 ) 
            return i;
    }
    return -1;
}
bool cmp( Node a,Node b ){
    if( a.cnt!=b.cnt ) return a.cnt>b.cnt;
    else {
        if( strcmp( a.s,b.s )<=0 ) return true;
        else return false;
    }
}
int main(){
    int T;
    scanf("%d",&T);
    while( T-- ){
        int n;
        scanf("%d",&n);
        char ID[ maxn ],Web[ maxn ];
        int Cnt = 1;
        int cc;
        while( n-- ){
            scanf("%s%s",ID,Web);
            cc = Find( Web,Cnt );
            if( ID[0]=='V' ){
                if( cc==-1 ){
                    strcpy( a[Cnt].s,Web );
                    a[ Cnt ].cnt = 1;
                    Cnt++;
                }
                else{
                    a[ cc ].cnt++;
                }
            }
            else{
                int pp = 0;
                for( int k=1;k<Cnt;k++ ){
                    bool f = false;
                    for( int i=0;Web[i]!='\0';i++ ){
                        if( Web[i]!=a[k].s[i] ){
                            f = true;
                            break;
                        }
                    }
                    if( f==false ){ 
                        q[ pp++ ] = a[ k ];
                    }
                }
                sort( q,q+pp,cmp );
                for( int i=0;i<pp;i++ ){
                    printf("%s\n",q[i].s);
                }
                printf("\n");
            }
        }
    }
    return 0;
}
