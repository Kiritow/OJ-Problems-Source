#include <cstdio>
#define size 24
using namespace std;
const int opt[][size] =
{
    { 2, 1, 6, 3, 4, 5, 11, 7, 8, 9, 10, 15, 12, 13, 14, 20, 16, 17, 18, 19, 22, 21, 0, 23 },
    { 0, 3, 2, 8, 4, 5, 6, 7, 12, 9, 10, 11, 17, 13, 14, 15, 16, 21, 18, 19, 20, 23, 22, 1 }, 
    { 0, 1, 2, 3, 10, 4, 5, 6, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 19, 13, 14, 15, 16, 17, 18, 20, 21, 22, 23 },
    { 0, 23, 2, 1, 4, 5, 6, 7, 3, 9, 10, 11, 8, 13, 14, 15, 16, 12, 18, 19, 20, 17, 22, 21 },
    { 22, 1, 0, 3, 4, 5, 2, 7, 8, 9, 10, 6, 12, 13, 14, 11, 16, 17, 18, 19, 15, 21, 20, 23 },
    { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15, 16, 17, 18, 19, 13, 20, 21, 22, 23 },
    { 0, 1, 2, 3, 5, 6, 7, 8, 9, 10, 4, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23 },
    { 6, 7, 8, 11, 12, 15, 16, 17 },
};
const char optlist[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
int sharp[size];
char path[size];
bool judge(int node[]){
    for (int i = 0; i < 8; i++)
    if (node[opt[8][0]] != node[opt[8][i]])
        return false;
    return true;
}
int get_h(int node[]){
    int cnt[4] = { 0 };
    for (int i = 0; i < 8; i++)
        cnt[node[opt[8][i]]]++;
    int max = 0;
    for (int i = 1; i <= 3; i++)
        max < cnt[i] ? max = cnt[i] : 0;
    return 8 - max;
}
bool ida(int curr[], int expr, int depth, char path[]){
    if (expr == depth) {
        if (judge(curr)) {
            path[expr] = '\0';
            printf("%s\n%d\n", path, curr[6]);
            return true;
        }
        else
            return false;
    }
    if (get_h(curr) + expr > depth) return false;
    int next[size];
    for (int i = 0; i < 8; i++){
        for (int j = 0; j < size; j++) next[j] = curr[opt[i][j]];
        path[expr] = optlist[i];
        if (ida(next, expr + 1, depth, path)) return true;
    }
    return false;
}
int main(){
    while (scanf("%d", sharp), sharp[0]){
        for (int i = 1; i < size; i++){
            scanf("%d", sharp + i);
        }
        if (judge(sharp)){
            printf("No moves needed\n%d\n", sharp[6]);
            continue;
        }
        for (int i = get_h(sharp);; i++){
            if (ida(sharp, 0, i, path))
                break;
        }
    }
    return 0;
}
