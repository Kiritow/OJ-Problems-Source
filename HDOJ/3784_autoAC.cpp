#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
int main()
{
    int n;
    int a[1005],i,flag[1005];
    while(cin >> n && n)
    {
        memset(flag,0,sizeof(flag));
        for(i = 0; i<n; i++)
        {
            cin >> a[i];
            flag[a[i]] = 1;
        }
        for(i = 0; i<n; i++)
        {
            int t;
            t = a[i];
            if(!flag[t])
                continue;
            while(t>1)
            {
                if(t%2)
                    t = (t*3+1)/2;
                else
                    t = t/2;
                if(t<=1000)
                {
                    flag[t] = 0;
                }
            }
        }
        int k = 1;
        for(i = n-1; i>=0; i--)
        {
            if(flag[a[i]])
            {
                if(k)
                {
                    cout << a[i];
                    k = 0;
                }
                else
                {
                    cout << " " << a[i];
                }
            }
        }
        cout << endl;
    }
    return 0;
}
