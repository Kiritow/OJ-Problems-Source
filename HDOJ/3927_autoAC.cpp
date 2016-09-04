#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <memory.h>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;
const int N = 200;
int mtx[N][N], n;
int row[N], col[N], dia[2];
map<int, int> M;
int cunt;
void Change(int r1, int c1, int r2, int c2) {
    int d = mtx[r1][c1] - mtx[r2][c2];
    if (d == 0) return;
    int res = 0;
    if ((M[row[r1]]--) == 1) res--;
    if ((M[col[c1]]--) == 1) res--;
    if ((M[row[r2]]--) == 1) res--;
    if ((M[col[c2]]--) == 1) res--;
    if (r1 == c1 && (M[dia[0]]--) == 1) res--;
    if (r1 == n - c1 - 1 && (M[dia[1]]--) == 1) res--;
    if (r2 == c2 && (M[dia[0]]--) == 1) res--;
    if (r2 == n - c2 - 1 && (M[dia[1]]--) == 1) res--;
    swap(mtx[r1][c1], mtx[r2][c2]);
    row[r1] -= d; col[c1] -= d; row[r2] += d; col[c2] += d;
    if (r1 == c1) dia[0] -= d;
    if (r1 == n - c1 - 1) dia[1] -= d;
    if (r2 == c2) dia[0] += d;
    if (r2 == n - c2 - 1) dia[1] += d;
    if ((M[row[r1]]++) == 0) res++;
    if ((M[col[c1]]++) == 0) res++;
    if ((M[row[r2]]++) == 0) res++;
    if ((M[col[c2]]++) == 0) res++;
    if (r1 == c1 && (M[dia[0]]++) == 0) res++;
    if (r1 == n - c1 - 1 && (M[dia[1]]++) == 0) res++;
    if (r2 == c2 && (M[dia[0]]++) == 0) res++;
    if (r2 == n - c2 - 1 && (M[dia[1]]++) == 0) res++;
    if (res >= 0) {
        cunt += res;
        return;
    }
    M[row[r1]]--; M[col[c1]]--; M[row[r2]]--; M[col[c2]]--;
    if (r1 == c1) M[dia[0]]--;
    if (r1 == n - c1 - 1) M[dia[1]]--;
    if (r2 == c2) M[dia[0]]--;
    if (r2 == n - c2 - 1) M[dia[1]]--;
    swap(mtx[r1][c1], mtx[r2][c2]);
    row[r1] += d; col[c1] += d; row[r2] -= d; col[c2] -= d;
    if (r1 == c1) dia[0] += d;
    if (r1 == n - c1 - 1) dia[1] += d;
    if (r2 == c2) dia[0] -= d;
    if (r2 == n - c2 - 1) dia[1] -= d;
    M[row[r1]]++; M[col[c1]]++; M[row[r2]]++; M[col[c2]]++;
    if (r1 == c1)  M[dia[0]]++;
    if (r1 == n - c1 - 1) M[dia[1]]++;
    if (r2 == c2) M[dia[0]]++;
    if (r2 == n - c2 - 1) M[dia[1]]++;
}
int main() {
    int T, C, m, idx, s1, s2;
    int r1, c1, r2, c2;
    scanf("%d", &T);
    for (C = 1; C <= T; C++) {
        scanf("%d", &n);
        idx = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mtx[i][j] = ++idx;
        M.clear();
        cunt = 0;
        for (int i = 0; i < n; i++) {
            s1 = 0, s2 = 0;
            for (int j = 0; j < n; j++) {
                s1 += mtx[i][j];
                s2 += mtx[j][i];
            }
            row[i] = s1; col[i] = s2;
            if ((M[s1]++) == 0) cunt++;
            if ((M[s2]++) == 0) cunt++;
        }
        s1 = s2 = 0;
        for (int i = 0; i < n; i++) {
            s1 += mtx[i][i];
            s2 += mtx[i][n-i-1];
        }
        dia[0] = s1; dia[1] = s2;
        if ((M[s1]++) == 0) cunt++;
        if ((M[s2]++) == 0) cunt++;
        m = 2 * n + 2;
        while (cunt < m) {
            r1 = rand() % n;
            r2 = rand() % n;
            c1 = rand() % n;
            c2 = rand() % n;
            Change(r1, c1, r2, c2);
        }
        printf("Case #%d:\n", C);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j) printf(" ");
                printf("%d", mtx[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
