#include <iostream>
#include <algorithm>
using namespace std;
int f[201];
int main()
{
    int t, n, i, j, s, e;
    cin >> t;
    while( t-- ){
        memset( f, 0, sizeof(f) );
        cin >> n;    
        for( i=0; i<n; i++ ){
            cin >> s >> e;    
            s = (s+1)/2;
            e = (e+1)/2;
            if( s > e ){    
                int temp = s;
                s = e;
                e = temp;
            }
            for( j=s; j<=e; j++)
                f[j]++;        
        }
        int consume = 0;
        for( i=1; i<=200; i++ )
            consume = max( consume, f[i] );
        cout << consume*10 << endl;
    }
    return 0;
}
