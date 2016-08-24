#include <iostream>
using namespace std;
const int size = 1010;
char str[size];
int h[size];
int cnt[size];
int main()
{
    cin.sync_with_stdio(false);
    int n , m , ans , sum , maxH , area;
    while( cin >> n >> m )
    {
        memset( cnt , 0 , sizeof(cnt) );
        memset( h , 0 , sizeof(h) );
        ans = 0;
        for( int i = 1 ; i<=n ; i++ )
        {
            maxH = sum = 0;
            cin >> str;
            for( int j = 0 ; str[j]!='\0' ; j++ )
            {
                if( str[j]=='1' )
                    h[j+1] ++;
                else
                    h[j+1] = 0;
                cnt[ h[j+1] ] ++;
                if( maxH < h[j+1] )
                    maxH = h[j+1];            
            }
            for( int k = 0 ; k<=maxH ; k++ )
            {
                if( cnt[k]!=0 )
                {
                    area = k * (m-sum);
                    sum += cnt[k];
                    if( area>ans )
                        ans = area;
                }
                cnt[k] = 0;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
