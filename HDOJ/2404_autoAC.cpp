#include <iostream>
#include <string.h>
using namespace std;
int reserve[1000];
int per[1000];
int n;
void permulation()
{
    int i, j;
    memset(per,0,sizeof(per));
    for ( i = 1; i <= n; ++i )
    {
        for ( j = 1; j <= n; ++j )
        {
            if(per[j] == 0)
            {
                if ( reserve[i] != 0 )
                    --reserve[i];
                else
                    break;
            }
        }
        per[j] = i;
    }
}
int main()
{
    int i;
    while(cin >> n && n != 0)
    {
        for(i=1; i <= n; ++i)
            cin >> reserve[i];
        permulation();
        cout << per[1];
        for(i = 2; i <= n; ++i)
            cout << ',' << per[i];
        cout << endl;
    }
    return 0;
}
