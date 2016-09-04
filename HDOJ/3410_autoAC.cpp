#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 50010;
int main()
{
    int iCase, n, ic = 1;
    int arr[MAXN], que[MAXN];
    int rear, front;
    int l[MAXN], r[MAXN];
    bool flag;
    scanf("%d", &iCase);
    while (iCase--) {
        arr[0] = 0;
        memset(que, 0, sizeof(que));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i)
            scanf("%d", &arr[i]);
        front = 0, rear = -1;
        for (int i = 1; i <= n; ++i) {
            flag = false;
            while (front <= rear && arr[que[rear]] < arr[i]) {
                flag = true;
                rear--;
            }
            if (flag) l[i] = que[rear+1];
            else l[i] = 0;
            que[++rear] = i;
        }
        front = 0, rear = -1;
        for (int i = n; i >= 1; --i) {
            flag = false;
            while (front <= rear && arr[que[rear]] < arr[i]) {
                flag = true;
                rear--;
            }
            if (flag) r[i] = que[rear+1];
            else r[i] = 0;
            que[++rear] = i;
        }
        printf("Case %d:\n", ic++);
        for (int i = 1; i <= n; ++i) {
            printf("%d %d\n", l[i], r[i]);
        }
    }
    return 0;
}
