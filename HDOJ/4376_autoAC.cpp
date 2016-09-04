#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXL 22
#define KIND 9
#define MAXNODE 42
typedef long long LL;
vector<int> A, B, RA, RB;
char subA[MAXL], subB[MAXL];
int N, en[MAXNODE], suffix[MAXNODE], q[MAXNODE], child[MAXNODE][KIND];
LL dp[MAXL][3][3][3][3][MAXNODE][1 << 2];
int change(char ch) {
    return ch - '1';
}
void Trie() {
    memset(en, 0, sizeof(en));
    memset(child, 0, sizeof(child));
    N = 1;
    for(int i = 0; i < 2; ++i) {
        char* s = i == 0? subA: subB;
        int p = 1;
        for (int j = 0; s[j]; ++j) {
            int ch = change(s[j]);
            if (!child[p][ch]) child[p][ch] = ++N;
            p = child[p][ch];
        }
        en[p] |= 1 << i;
    }
}
void AC() {
    int ql = 0, qr = 0;
    for (int i = 0; i < KIND; ++i)
        if (child[1][i]) {
            suffix[child[1][i]] = 1;
            q[qr++] = child[1][i];
        }
        else child[1][i] = 1;
    while (ql < qr) {
        int u = q[ql++];
        for (int i = 0; i < KIND; ++i)
            if (child[u][i]) {
                suffix[child[u][i]] = child[suffix[u]][i];
                q[qr++] = child[u][i];
            }
            else child[u][i] = child[suffix[u]][i];
    }
    for (int i = 1; i <= N; ++i)
        for (int j = i; j != 1; j = suffix[j]) en[i] |= en[j];
}
int cal1(int pos, int val, int pre, vector<int>& vec) {
    if(pos >= vec.size()) return 2;
    if(pre != 0) return pre;
    if(val > vec[pos]) return 2;
    if(val < vec[pos]) return 1;
    return 0;
}
int cal2(int pos, int val, int pre, vector<int>& vec) {
    if(pos >= vec.size()) return 2;
    if(val > vec[pos]) return 2;
    if(val < vec[pos]) return 1;
    return pre;
}
int main() {
    int T;
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas) {
        LL a, b;
        cin >> a >> b;
        scanf("%s%s", subA, subB);
        LL sub = 0, rsub = 0;
        for(int i = 0; subA[i]; ++i)
            sub = sub * 10 + subA[i] - '0';
        for(int i = 0; subB[i]; ++i)
            rsub = rsub * 10 + subB[i] - '0';
        reverse(subB, subB + strlen(subB));
        Trie();
        AC();
        A.clear();
        B.clear();
        RA.clear();
        RB.clear();
        LL ta = a, tb = b;
        while(ta) {
            RA.push_back(ta % 10);
            ta /= 10;
        }
        while(tb) {
            RB.push_back(tb % 10);
            tb /= 10;
        }
        A = RA;
        B = RB;
        reverse(A.begin(), A.end());
        reverse(B.begin(), B.end());
        int l = B.size();
        memset(dp, 0, sizeof(dp));
        for(int j = 1; j < 10; ++j) {
            int s1 = cal1(0, j, 0, A);
            int s2 = cal1(0, j, 0, B);
            int rs1 = cal2(0, j, 0, RA);
            int rs2 = cal2(0, j, 0, RB);
            int v = child[1][j - 1];
            ++dp[0][s1][s2][rs1][rs2][v][en[v]];
        }
        for(int i = 0; i + 1 < l; ++i) {
            for(int s1 = 0; s1 < 3; ++s1) for(int s2 = 0; s2 < 3; ++s2) for(int rs1 = 0; rs1 < 3; ++rs1) for(int rs2 = 0; rs2 < 3; ++rs2)
                for(int u = 1; u <= N; ++u)
                    for(int mask = 0; mask < (1 << 2); ++mask) if(dp[i][s1][s2][rs1][rs2][u][mask]) {
                        for(int val = 1; val < 10; ++val) {
                            int ns1 = cal1(i + 1, val, s1, A);
                            int ns2 = cal1(i + 1, val, s2, B);
                            int nrs1 = cal2(i + 1, val, rs1, RA);
                            int nrs2 = cal2(i + 1, val, rs2, RB);
                            int v = child[u][val - 1];
                            dp[i + 1][ns1][ns2][nrs1][nrs2][v][mask | en[v]] += dp[i][s1][s2][rs1][rs2][u][mask];
                        }
                    }
        }
        LL res = 0;
        int la = A.size(), lb = B.size();
        for(int len = la; len < lb - 1; ++len) {
            for(int s1 = 0; s1 < 3; ++s1) for(int s2 = 0; s2 < 3; ++s2) for(int rs1 = 0; rs1 < 3; ++rs1) for(int rs2 = 0; rs2 < 3; ++rs2)
                for(int u = 1; u <= N; ++u)
                    for(int mask = 1; mask < (1 << 2); ++mask)
                        res += dp[len][s1][s2][rs1][rs2][u][mask];
        }
        if(la != lb) {
            for(int s1 = 0; s1 < 3; ++s1) for(int s2 = 0; s2 < 3; ++s2) for(int rs1 = 0; rs1 < 3; ++rs1) for(int rs2 = 0; rs2 < 3; ++rs2)
                for(int u = 1; u <= N; ++u)
                    for(int mask = 1; mask < (1 << 2); ++mask) {
                        bool flaga = false;
                        if(mask == 1 || mask == 3) {
                            if(s1 == 0 || s1 == 2) flaga = true;
                        }
                        if(mask == 2 || mask == 3) {
                            if(rs1 == 0 || rs1 == 2) flaga = true;
                        }
                        if(flaga)
                            res += dp[la - 1][s1][s2][rs1][rs2][u][mask];
                        bool flagb = false;
                        if(mask == 1 || mask == 3) {
                            if(s2 == 0 || s2 == 1) flagb = true;
                        }
                        if(mask == 2 || mask == 3) {
                            if(rs2 == 0 || rs2 == 1) flagb = true;
                        }
                        if(flagb)
                            res += dp[lb - 1][s1][s2][rs1][rs2][u][mask];
                    }
        } else {
            for(int s1 = 0; s1 < 3; ++s1) for(int s2 = 0; s2 < 3; ++s2) for(int rs1 = 0; rs1 < 3; ++rs1) for(int rs2 = 0; rs2 < 3; ++rs2)
                for(int u = 1; u <= N; ++u)
                    for(int mask = 1; mask < (1 << 2); ++mask) {
                        bool flag = false;
                        if(mask == 1 || mask == 3) {
                            if((s1 == 0 || s1 == 2) && (s2 == 0 || s2 == 1)) flag = true;
                        }
                        if(mask == 2 || mask == 3) {
                            if((rs1 == 0 || rs1 == 2) && (rs2 == 0 || rs2 == 1)) flag = true;
                        }
                        if(flag) res += dp[la - 1][s1][s2][rs1][rs2][u][mask];
                    }
        }
        printf("Case #%d: ", cas);
        cout << res << endl;
    }
    return 0;
}
