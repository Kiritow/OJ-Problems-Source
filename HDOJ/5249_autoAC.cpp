#include <stdio.h>
#include <string.h>
#include <set>
#include <queue>
#include <algorithm>
using namespace std;
set<int> A, B;
queue<int> q;
int n, cas = 1;
int main() {
    while (scanf("%d", &n) == 1) {
        printf("Case #%d:\n", cas++);
        while (!q.empty())
            q.pop();
        A.clear();
        B.clear();
        char str[10];
        int m = 0, d;
        while (n--) {
            scanf("%s", str);
            if (str[0] == 'i') {
                scanf("%d", &d);
                q.push(d);
                if (A.size() == 0 || d <= *A.rbegin())
                    A.insert(d);    
                else
                    B.insert(d);
                m++;
            }
            else if (str[0] == 'o') {
                int temp = q.front();
                q.pop();
                if (A.find(temp) == A.end())
                    B.erase(temp);
                else
                    A.erase(temp);
                m--;
            }
            else
                printf("%d\n", *A.rbegin());
            while (m > 0 && A.size() < m / 2 + 1) {
                int temp = *B.begin();
                A.insert(temp);
                B.erase(temp);
            }
            while (m > 0 && A.size() > m / 2 + 1) {
                int temp = *A.rbegin();
                B.insert(temp);
                A.erase(temp);
            }
        }
    }
    return 0;
}
