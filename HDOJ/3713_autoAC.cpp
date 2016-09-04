#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<pair<int, int>, pair<int, int> > Node;
const int MAXN = 8;
int T, mat[2][MAXN][MAXN];
char stepto[MAXN][MAXN][MAXN][MAXN], mo[] = {'D','L','R','U'};
Node s, t, fa[MAXN][MAXN][MAXN][MAXN];
queue<Node> Q;
void ReadMat()
{
    for (int i = 1; i <= 6; i++)
        for (int j = 1; j <= 6; j++)
        {
            scanf("%d", &mat[1][i][j]);
            if (mat[1][i][j]&(1<<5))
                s.second = make_pair(i, j);
            if (mat[1][i][j]&(1<<6))
                t.second = make_pair(i, j);
        }
}
void PrintAns(Node v)
{
    if (stepto[v.first.first][v.first.second][v.second.first][v.second.second] == 'X')
        return;
    PrintAns(fa[v.first.first][v.first.second][v.second.first][v.second.second]);
    printf("%c", stepto[v.first.first][v.first.second][v.second.first][v.second.second]);
}
int main()
{
    scanf("%d", &T);
    ReadMat();
    while (--T)
    {
        memset(stepto, 0, sizeof(stepto));
        memcpy(mat[0], mat[1], MAXN*MAXN*sizeof(int));
        s.first = s.second;
        t.first = t.second;
        ReadMat();
        while (!Q.empty()) Q.pop();
        bool flag = 0;
        Q.push(s);
        stepto[s.first.first][s.first.second][s.second.first][s.second.second] = 'X';
        while (!Q.empty())
        {
            Node u = Q.front(); Q.pop();
            if (u == t)
            {
                flag = 1;
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                Node v = u;
                if (i == 0)
                {
                    if (!(mat[0][u.first.first][u.first.second]&(1<<1)))
                        v.first.first++;
                    if (!(mat[1][u.second.first][u.second.second]&(1<<1)))
                        v.second.first++;
                }
                else if (i == 1)
                {
                    if (!(mat[0][u.first.first][u.first.second]&(1<<0)))
                        v.first.second--;
                    if (!(mat[1][u.second.first][u.second.second]&(1<<0)))
                        v.second.second--;
                }
                else if (i == 2)
                {
                    if (!(mat[0][u.first.first][u.first.second]&(1<<2)))
                        v.first.second++;
                    if (!(mat[1][u.second.first][u.second.second]&(1<<2)))
                        v.second.second++;
                }
                else
                {
                    if (!(mat[0][u.first.first][u.first.second]&(1<<3)))
                        v.first.first--;
                    if (!(mat[1][u.second.first][u.second.second]&(1<<3)))
                        v.second.first--;
                }
                if (v.first.first < 1 || v.first.first > 6)
                    continue;
                if (v.first.second < 1 || v.first.second > 6)
                    continue;
                if (v.second.first < 1 || v.second.first > 6)
                    continue;
                if (v.second.second < 1 || v.second.second > 6)
                    continue;
                if (!(mat[0][v.first.first][v.first.second]&(1<<4)) || !(mat[1][v.second.first][v.second.second]&(1<<4)))
                    continue;
                if (!stepto[v.first.first][v.first.second][v.second.first][v.second.second])
                {
                    Q.push(v);
                    stepto[v.first.first][v.first.second][v.second.first][v.second.second] = mo[i];
                    fa[v.first.first][v.first.second][v.second.first][v.second.second] = u;
                }
            }
        }
        if (flag)
            PrintAns(t);
        else
            printf("-1");
        printf("\n");
    }
    return 0;
}
