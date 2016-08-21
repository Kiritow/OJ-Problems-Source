#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<deque>
using namespace std;
struct PT {
    int x;
    int y;
};
void Fill(int n, int m, char Graph[][305]) {
    int i, j;
    for (i = 0; i <= n + 1; i++)
        Graph[i][0] = Graph[i][m + 1] = '*';
    for (i = 0; i <= m + 1; i++)
        Graph[0][i] = Graph[n + 1][i] = '*';
}
void BFS(int n, int m, char Graph[][305], int &O, int &V) {
    int i, j;
    int numO, numV, sumO = 0, sumV = 0;
    int plusX[] = {0, 1, 0, -1};
    int plusY[] = {1, 0, -1, 0};
    bool IsSurvive;
    deque<PT> Queue;
    int top = 0;
    PT pt, get;
    bool IsReturn;
RETURN:
    IsReturn = false;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= m; j++)
            if (Graph[i][j] != '#' && Graph[i][j] != '-') {
                pt.x = i;
                pt.y = j;
                Queue.push_back(pt);
                IsReturn = true;
                goto BFSSTART;
            }
BFSSTART:
    IsSurvive = true;
    numO = 0;
    numV = 0;
    while (!Queue.empty()) {
        get = Queue.front();
        Queue.pop_front();
        if (Graph[get.x][get.y] == 'v')
            numV++;
        if (Graph[get.x][get.y] == 'o')
            numO++;
        Graph[get.x][get.y] = '-';
        for (i = 0; i < 4; i++) {
            if (Graph[get.x + plusX[i]][get.y + plusY[i]] == '*')
                IsSurvive = false;
            if (Graph[get.x + plusX[i]][get.y + plusY[i]] == 'v') {
                pt.x = get.x + plusX[i];
                pt.y = get.y + plusY[i];
                Queue.push_back(pt);
                numV++;
                Graph[get.x + plusX[i]][get.y + plusY[i]] = '-';
            }
            if (Graph[get.x + plusX[i]][get.y + plusY[i]] == 'o') {
                pt.x = get.x + plusX[i];
                pt.y = get.y + plusY[i];
                Queue.push_back(pt);
                numO++;
                Graph[get.x + plusX[i]][get.y + plusY[i]] = '-';
            }
            if (Graph[get.x + plusX[i]][get.y + plusY[i]] == '.') {
                pt.x = get.x + plusX[i];
                pt.y = get.y + plusY[i];
                Queue.push_back(pt);
                Graph[get.x + plusX[i]][get.y + plusY[i]] = '-';
            }
        }
    }
    if (IsSurvive) {
        if (numV > numO)
            sumV += numV;
        else if (numV < numO)
            sumO += numO;
    }
    if (IsReturn)
        goto RETURN;
ANS:
    O = sumO;
    V = sumV;
}
int main() {
    char Graph[305][305];
    int n, m;
    int i, j;
    int O, V;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (i = 1; i <= n; i++)
            scanf("%s", &Graph[i][1]);
        Fill(n, m, Graph);
        BFS(n, m, Graph, O, V);
        printf("%d %d\n", O, V);
    }
    return 0;
}
