#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int H,W;
char Map[105][105];
int direct[][2] = {{-1,0}, {1,0}, {0,-1}, {0, 1}};
void DFS(int i, int j) {
    if(i<1 || i>H || j<1 || j>W)
        return;
    Map[i][j] = '.';
    for(int k=0; k<4; ++k)
        if(Map[i+direct[k][0]][j+direct[k][1]] == '#')
            DFS(i+direct[k][0], j+direct[k][1]);
}
int main()
{
    int T;
    cin >> T;
    while(cin >> H >> W) {
        for(int i=1; i<=H; ++i)
            for(int j=1; j<=W; ++j)
                cin >> Map[i][j];
        int counts = 0;
        for(int i=1; i<=H; ++i)
            for(int j=1; j<=W; ++j)
                if(Map[i][j] == '#') {
                    DFS(i, j);
                    ++counts;
                }
        cout << counts << endl;
    }
    return 0;
}
