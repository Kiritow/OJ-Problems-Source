#include<iostream>
#include<queue>
using namespace std;
int main()
{
    int t, n, i, j, x, m, p, q, num;
    bool flag = 1;
    cin >> t;
    while(t--)
    {
        flag = 1;
        cin >> n;
        x = n % 2;
        cin >> m;
        while(m--)
        {
            cin >> num;
            if( num % 2 != x )
                flag = 0;
            x ^= 1;
        }
        x = n % 2;
        cin >> p;
        while( p -- )
        {
            cin >> num;
            x ^= 1;
            if( num % 2 != x )
                flag = 0;
        }
        x = n % 2;
        cin >> q;
        while( q -- )
        {
            cin >> num;
            if( num % 2 != x )
                flag = 0;
            x ^= 1;
        }
        if( flag )
            cout << "true" << endl;
        else 
            cout << "false" << endl;
    }
    return 0;
}
