#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <map>
#include <cstdlib>
#include <cstring>
using namespace std;
bool plane[202][202];
int main() {
    int n;
    int tx, ty;
    map<int, vector<int> > point;
    while (cin >> n) {
        point.clear();
        memset(plane, 0, sizeof(plane));
        for (int i = 0; i < n; i++) {
            cin >> tx >> ty;
            tx += 100;
            ty += 100;
            plane[tx][ty] = true;
            if (point.find(ty) == point.end()) {
                vector<int> temp;
                temp.push_back(tx);
                point[ty] = temp;
            }
            else {
                point[ty].push_back(tx);
            }
        }
        int ans = 0;

        //对每一行的点进行排序
        for (auto ityi = point.begin(); ityi != point.end(); ityi++)
            sort((*ityi).second.begin(), (*ityi).second.end());

        //开始枚举，每个点都枚举自己右上象限的点
        for (auto ityi = point.begin(); ityi != point.end(); ityi++) {
            for (auto ityj = ityi ; ityj != point.end(); ityj++) {
                for (auto itxi = (*ityi).second.begin(); itxi != (*ityi).second.end(); itxi++) {
                    for (auto itxj = (*ityj).second.begin(); itxj != (*ityj).second.end(); itxj++) {
                        if (*itxj < *itxi)
                            continue;//左上方 剪枝
                        int dx = *itxj - *itxi;
                        int dy = ityj->first - ityi->first;
                        int x = *itxi;
                        int y = ityi->first;
                        if (dx>0&&x - dy >= 0 && y + dx + dy <= 200 && plane[x - dy][y + dx] && plane[x + dx - dy][y + dx + dy]) {
                            ans++;
                            //cout << "P1 " << x << " " << y << endl;
                            //cout << "P2" << *itxj << " " << ityj->first << endl;
                            //cout << "P3" << x - dy << " " << y + dx << endl;
                            //cout << "P4" << x + dx - dy << " " << y + dx + dy << endl;
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}