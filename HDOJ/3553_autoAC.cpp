#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#define MAXN 100000
#define MAXM 128            
int head[MAXN], succ[MAXN], succRank[MAXN];
int sa[MAXN], rank[MAXN];
int letter[MAXM];
void da(char* str, int len) {  
    memset(letter, 0, sizeof(letter));
    for (int i = 0; i < len; ++i)
        if (!letter[str[i]])
            letter[str[i]] = 1;
    int total = -1;
    for (int i = 0; i < MAXM; ++i)
        if (letter[i])
            letter[i] = ++total;
    memset(head, 255, sizeof(head));
    for (int i = len - 1; i >= 0; --i) { 
        rank[i] = letter[str[i]];
        succ[i] = head[rank[i]];
        head[rank[i]] = i;
    }
    int j = 0;
    for (int i = 0; i < len; ++i) {
        while (head[j] == -1) ++j;
        sa[i] = head[j];
        head[j] = succ[head[j]];
    }
    for (int k = 1; k < len; k <<= 1) {
        for (int i = len - 1; i >= 0; --i)       
            if (sa[i] - k >= 0) {
                succRank[sa[i] - k] = rank[sa[i]];
                succ[sa[i] - k] = head[rank[sa[i] - k]];
                head[rank[sa[i] - k]] = sa[i] - k;
            }
        for (int i = len - 1; i >= len - k; --i) {   
            succRank[i] = -1;                   
            succ[i] = head[rank[i]];
            head[rank[i]] = i;
        }
        j = 0; total = -1;
        int preSuccRank = 0, preRank = 0;
        for (int i = 0; i < len; ++i) {
            while (head[j] == -1) ++j;
            sa[i] = head[j];
            if (i == 0 || preRank != rank[sa[i]] || preSuccRank != succRank[sa[i]]) {
                preRank = rank[sa[i]];
                rank[sa[i]] = ++total;  
            } else {
                preRank = rank[sa[i]];
                rank[sa[i]] = total;
            }
            preSuccRank = succRank[sa[i]];
            head[j] = succ[head[j]];
        }
    }
}
int height[MAXN];
long long mem[MAXN + 1], *sumLength = mem + 1;
void calcHeight(char* str, int len) {
    int i, j, k = 0;
    for (i = 0; i < len; ++i) {
        if (k != 0)             
            --k;
        if (rank[i] == 0)
            continue;
        j = sa[rank[i] - 1];
        while (str[i + k] == str[j + k])       
            ++k;
        height[rank[i]] = k;   
    }
}
int minData[MAXN + 1][18];
inline int minHeight(int x, int y) {
    return height[x] <= height[y] ? x : y;
}
inline void initRMQ(int s, int e) {
    if (s > e)
        return;
    for (int i = s; i <= e; ++i)
        minData[i][0] = i;
    int h = (int)(log(e - s + 1.0) / log(2.0));
    for (int j = 1; j <= h; ++j)
        for (int i = s; i + (1 << j) - 1 <= e; ++i)
            minData[i][j] = minHeight(minData[i][j - 1], minData[i + (1 << (j - 1))][j - 1]);
}
inline int askRMQ(int a, int b) {
    int l = (int)(log(b - a + 1.0) / log(2.0));
    return minHeight(minData[a][l], minData[b - (1 << l) + 1][l]);
}
inline int lcp(int a, int b) {
    return height[askRMQ(std::min(rank[a], rank[b]) + 1, std::max(rank[a], rank[b]))];
}
char buf[MAXN + 2];
long long k;
int rk, rl;
void getAnswer(long long a, long long b) {
    int h = 0;
    while (a != b) {
        int idx = askRMQ(a + 1, b) - 1;
        if (k <= (height[idx + 1] - h) * (b - a + 1)) {
            rk = a; rl = h + 1 + (k - 1) / (b - a + 1);
            return;
        }
        k -= (height[idx + 1] - h) * (b - a + 1);
        if (k <= sumLength[idx] - sumLength[a - 1] - height[idx + 1] * (idx - a + 1)) {
            b = idx; h = height[idx + 1];
            continue;
        }
        k -= sumLength[idx] - sumLength[a - 1] - height[idx + 1] * (idx - a + 1);
        a = idx + 1;
        h = height[idx + 1];
    }
    rk = a; rl = h + k;
}
int main() {
    int test;
    scanf("%d", &test);
    for (int cas = 1; cas <= test; ++cas) {
        scanf("%s%I64d", buf, &k);
        int len = strlen(buf);
        da(buf, len);
        calcHeight(buf, len);
        for (int i = 0; i < len; ++i)
            sumLength[i] = sumLength[i - 1] + len - sa[i];
        initRMQ(1, len - 1);
        getAnswer(0, len - 1);
        printf("Case %d: ", cas);
        for (int i = 0; i < rl; ++i)
            putchar(buf[sa[rk] + i]);
        putchar('\n');
    }
    return 0;
}
