#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m;
string A[1050], B[1050];
struct pos
{
    int L, R;
} p[10050];
bool cmp(pos A, pos B)
{
    if (A.L != B.L)
    {
        return A.L < B.L;
    }
    return A.R < B.R;
}
void solve()
{
    int cnt = 0;
    for (int i = 1; i <= m; i++)
    {
        int lenB = B[i].length();
        int q = 1;
        for (int j = 0; j < lenB; j++)
        {
            for (int k = 1; k <= n; k++)
            {
                int lenA = A[k].length();
                if (j+lenA-1 >= lenB) continue;
                if (A[k][0] == B[i][j] && A[k][lenA-1] == B[i][j+lenA-1])
                {
                    bool ok = true;
                    for (int l = 0; l < lenA; l++)
                    {
                        if (A[k][l] != B[i][j+l])
                        {
                            ok = false;
                            break;
                        }
                    }
                    if (ok)
                    {
                        p[q].L = j;
                        p[q++].R = j+lenA-1;
                    }
                }
            }
        }
        p[0].L = p[0].R = -100;
        sort(p+1, p+q, cmp);
        for (int i = q-1; i >= 1; i--)
        {
            if (p[i].L > p[i-1].R)
            {
                cnt++;
            }
            else
            {
                for (int j = i-1; j >= 1; j--)
                {
                    if (p[i].L <= p[j].R) ;
                    else
                    {
                        i = j+1;
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout << cnt << endl;
}
int main()
{
    while (cin >> n >> m && (n && m))
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> A[i];
        }
        getchar();
        for (int i = 1; i <= m; i++)
        {
            getline(cin, B[i]);
        }
        solve();
    }
    return 0;
}
