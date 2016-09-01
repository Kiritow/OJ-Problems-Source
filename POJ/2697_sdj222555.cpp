#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#define MAXN 100005
#define MAXM 1000005
using namespace std;
struct Trie
{
    int flag;
    int next[3];
    void init()
    {
        memset(next, 0, sizeof(next));
        flag = 0;
    }
} trie[MAXM];
int e;
void init()
{
    for(int i = 0; i < MAXM; i++) trie[i].init();
    e = 0;
}
int getid(char c)
{
    if(c == '*') return 0;
    else if(c == 'b') return 1;
    else return 2;
}
void make_trie(char s[6][6])
{
    int u = 0, index;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            index = getid(s[i][j]);
            if(!trie[u].next[index]) trie[u].next[index] = ++e;
            u = trie[u].next[index];
        }
    trie[u].flag = 1;
}
bool match(char s[6][6])
{
    int u = 0, index;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
        {
            index = getid(s[i][j]);
            u = trie[u].next[index];
        }
    return trie[u].flag;
}
char s1[6][6];
char s2[6][6];
char tmp[22];
int xx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int yy[] = {1, 0, -1, 0, -1, 1, -1, 1};
struct P
{
    char s[6][6];
    int num;
    P() {}
    P(char _s[6][6], int _num)
    {
        num = _num;
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                s[i][j] = _s[i][j];
    }
} q[MAXM];
bool findit(P tp)
{
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(tp.s[i][j] != s2[i][j]) return false;
    return true;
}
bool isok(int x, int y, char s[6][6])
{
    if(x < 0 || y < 0 || x >= 4 || y >= 4 || s[x][y] != '*') return false;
    return true;
}
void bfs()
{
    int ans = -1;
    int h = 0, t = 0;
    q[t++] = P(s1, 0);
    make_trie(s1);
    while(h < t)
    {
        P tp = q[h++];
        if(findit(tp))
        {
            ans = tp.num;
            break;
        }
        char fk;
        if(tp.num % 2 == 0) fk = 'w';
        else fk  = 'b';
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
            {
                if(tp.s[i][j] == fk)
                {
                    for(int k = 0; k < 8; k++)
                    {
                        int tx = i, ty = j;
                        tx += xx[k];
                        ty += yy[k];
                        while(isok(tx, ty, tp.s))
                        {
                            tx += xx[k];
                            ty += yy[k];
                        }
                        tx -= xx[k];
                        ty -= yy[k];
                        swap(tp.s[i][j], tp.s[tx][ty]);

                        if(!match(tp.s))
                        {


                            q[t++] = P(tp.s, tp.num + 1);
                            make_trie(tp.s);
                        }
                        swap(tp.s[i][j], tp.s[tx][ty]);
                    }
                }
            }

    }
    printf("%d\n", ans);
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        init();
        for(int i = 0; i < 4; i++) scanf("%s", s1[i]);
        for(int i = 0; i < 4; i++) scanf("%s", s2[i]);
        bfs();
    }
    return 0;
}
