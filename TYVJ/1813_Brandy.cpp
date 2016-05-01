#include <iostream>

using namespace std;

int R, C;
char map[1002][1002];
int sum = 0;

int main() {
    cin >> R >> C;
    char cu;
    bool right = true;
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> cu;
            map[i][j] = cu;
            if (cu == '#') {
                if (map[i - 1][j] == '#') {
                    if (map[i][j - 1] == '#' && map[i - 1][j - 1] == '#') {
                        continue;
                    }
                    if (map[i][j - 1] == '#' && map[i - 1][j - 1] != '#') {
                        right = false;
                        cout << "Bad placement.";
                        return 0;
                    }
                    if (map[i][j - 1] != '#' && map[i - 1][j - 1] == '#') {
                        right = false;
                        cout << "Bad placement.";
                        return 0;
                    }
                    if (map[i][j - 1] != '#' && map[i - 1][j - 1] != '#') {
                        continue;
                    }
                } else {
                    if (map[i][j - 1] == '#' && map[i - 1][j - 1] == '#') {
                        right = false;
                        cout << "Bad placement.";
                        return 0;
                    }
                    if (map[i][j - 1] == '#' && map[i - 1][j - 1] != '#') {
                        continue;
                    }
                    if (map[i][j - 1] != '#' && map[i - 1][j - 1] == '#') {
                        sum++;
                        continue;
                    }
                    if (map[i][j - 1] != '#' && map[i - 1][j - 1] != '#') {
                        sum++;
                        continue;
                    }
                }
            }
        }
    }
    cout << "There are " << sum << " ships.";
    //system("pause");
    return 0;
}
