#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <cmath>
using namespace std;
int b1[9][9], b2[9][9];
int p3[][3] = {
    {0,1,2},
    {0,2,1},
    {1,0,2},
    {1,2,0},
    {2,0,1},
    {2,1,0}
};
int *colseg, *rowseg;
int *col[3];
int check3(int r, int *m);
int check4(int r, int *p, int *m)
{
    int i, j, k, l;
    int r1, c1, r2, c2;
    int v1, v2;
    int m2[10];
    memcpy(m2, m, sizeof(int)*10);
    for (j = 0; j < 3; j++)
        for (k = 0; k < 3; k++)
            for (l = 0; l < 3; l++) {
                r1 = p[j] + rowseg[r]*3;
                c1 = colseg[k]*3 + col[k][l];
                r2 = j + r*3;
                c2 = k*3 + l;
                v1 = b1[r1][c1];
                v2 = b2[r2][c2];
                if (v2) {
                    if (!m2[v2])
                        m2[v2] = v1;
                    else if (m2[v2] != v1)
                        return 0;
                }
            }
    return check3(r + 1, m2);
}
int check3(int r, int *m)
{
    int i;
    if (r == 3)
        return 1;
    for (i = 0; i < 6; i++) 
        if (check4(r, p3[i], m))
            return 1;
    return 0;
}
int check2()
{
    int i, j, k;
    for (i = 0; i < 6; i++) 
        for (j = 0; j < 6; j++)
            for (k = 0; k < 6; k++) {
                int m[10] = {};
                col[0] = p3[i];
                col[1] = p3[j];
                col[2] = p3[k];
                if (check3(0, m))
                    return 1;
            }
    return 0;
}
int check()
{
    int i, j;
    for (i = 0; i < 6; i++) {
        for (j = 0; j < 6; j++) {
            colseg = p3[i];
            rowseg = p3[j];
            if (check2())
                return 1;
        }
    }
    return 0;
}
int solve()
{
    int i, j, b[9][9];
    if (check())
        return 1;
    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            b[i][j] = b1[8-j][i];
    memcpy(b1, b, sizeof(b));
    return check();
}
int main()
{
    int T, i;
    scanf("%d", &T);
    for (; T--; ) {
        for (i = 0; i < 81; ++i) scanf(" %1d", b1[i/9]+i%9);
        for (i = 0; i < 81; ++i) scanf(" %1d", b2[i/9]+i%9);
        printf(solve() ? "Yes\n" : "No\n");
    }
    return 0;
}
