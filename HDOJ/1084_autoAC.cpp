#include <cstdio>
#include <algorithm>
using std::sort;
struct Node{
    int pos, num, s, val;
} stu[102];
int arr[6];
bool cmp1(Node a, Node b)
{
    if(a.num == b.num) return a.s < b.s;
    return a.num > b.num;
}
bool cmp2(Node a, Node b)
{
    return a.pos < b.pos;
}
int main()
{
    int n, h, m, s, num;
    while(scanf("%d", &n) == 1 && n > 0){
        for(int i = 1; i < 6; ++i) arr[i] = 0;
        for(int i = 0; i < n; ++i){
            scanf("%d %d:%d:%d", &num, &h, &m, &s);
            s += m * 60 + h * 3600;
            stu[i].pos = i;
            stu[i].num = num;
            stu[i].s = s;
            stu[i].val = 100 - (5 - num) * 10;
            ++arr[num];
        }
        sort(stu, stu + n, cmp1);
        for(int i = 4, pos = 0; i; --i){
            if(arr[i]){
                while(stu[pos].num != i) ++pos;
                if(arr[i] == 1) stu[pos++].val += 5;            
                for(int j = 0; j < arr[i] / 2; ++j)
                    stu[pos++].val += 5;
            }
        }
        sort(stu, stu + n, cmp2);
        for(int i = 0; i < n; ++i)
            printf("%d\n", stu[i].val);
        printf("\n");
    }
    return 0;
}
