#include <cstdio>
#include <cstdlib>
#include <cstring>
#define MAXN 5000
#define MAXM 17
#define MAXC 17
using namespace std;
int num[MAXM];
bool status[MAXN];
int basis, sys, n;
struct Node{
    int mod;
    int dig;
    int pre;
    int step;
}Queue[MAXN], init = { 0, 0, -1 };
int cmp(const void *a, const void *b){
    return *(int *)a - *(int *)b;
}
void echo(int x){
    if (Queue[x].pre == -1) return;
    else echo(Queue[x].pre);
    if (Queue[x].dig <= 9)
        printf("%d", Queue[x].dig);
    else
        putchar(Queue[x].dig + 'A' - 10);
}
bool bfs(){
    Node curr, next;
    int front = 0, rear = 1, res;
    Queue[0] = init;
    memset(status, 0, sizeof(status));
    while (front != rear){
        curr = Queue[front];
        for (int i = 0; i < n; i++){
            res = (curr.mod * sys + num[i]) % basis;
            if (status[res] || (curr.pre == -1 && num[i] == 0) || curr.step >= 500) continue;
            status[res] = 1;
            Queue[rear].mod = res;
            Queue[rear].dig = num[i];
            Queue[rear].pre = front;
            Queue[rear].step = curr.step + 1;
            if (res == 0) { echo(rear); putchar('\n');  return true; }
            rear++;
        }
        front++;
    }
    return false;
}
int main(){
    int t;
    char tmp[3];
    scanf("%d", &t);
    while (t--){
        scanf("%d %d %d", &basis, &sys, &n);
        for (int i = 0; i < n; i++){
            scanf("%s", tmp);
            if (tmp[0] <= '9' && tmp[0] >= '0') num[i] = tmp[0] - '0';
            else if (tmp[0] <= 'F' && tmp[0] >= 'A') num[i] = tmp[0] - 'A' + 10;
        }
        qsort(num, n, sizeof(int), cmp);
        if (basis == 0){
            if (num[0] == 0)
                printf("0\n");
            else
                printf("give me the bomb please\n");
            continue;
        }
        if (!bfs())
            printf("give me the bomb please\n");
    }
    return 0;
}
