#include <iostream>
using namespace std;
int x[10];
int main()
{
    int m, p;
    int i;
    int t;
    scanf("%d", &t);
    while(t--)
    {
        for (i=1; i<=9; i++) scanf("%d", &x[i]);
        m = 0;
        p = 0;
        int k=0;
        while(1)
        {
            for (i=1; i<=8; i++)
            {
                if (x[i]!=0) break;
            }
            p >>= 1;
            if (i>8 && p==0 && x[9]==0) break;
            int ct = 0;
            for (i=1; i<=8; i++)
            {
                if (x[i]&1) ct++;
            }
            int y = (ct&1);
            int z = ((x[9]&1)+(p&1))&1;
            int tm = y^z;
            if (tm)
            {
                p += (8-ct);
            }
            else
            {
                p += ct;
            }
            m += (tm<<k);
            k++;
            for (i=1; i<=9; i++) x[i]>>=1;
        }
        printf("%d\n", m);
    }
    return 0;
}
