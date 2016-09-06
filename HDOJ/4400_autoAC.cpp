#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
using namespace std;
const int maxn = 110005;
const int inf = 2000000005;
struct NODE{
    int y, dis;
    NODE(){
    }
    NODE(int _y, int _dis){
        y = _y; dis = _dis;
    }
    bool operator <(const NODE &tmp)const{
        if(y == tmp.y) return dis < tmp.dis;
        return y < tmp.y;
    }
};
struct POINT{
    int x, y, dis;
    POINT() {
    }
    POINT(int _x, int _y, int _dis){
        x = _x;
        y = _y;
        dis = _dis;
    }
}df[maxn], myque[1111111];
int n, m, has[maxn], num;
vector<NODE>mygraph[maxn];
void init(){
    num = 0;
    for(int i = 0; i < maxn; i++) mygraph[i].clear();
}
void readdata(){
    for(int i = 1; i <= n ; i++){
        scanf("%d%d%d", &df[i].x, &df[i].y, &df[i].dis);
        has[num++] = df[i].x;
    }
    sort(has, has + num);
    num = unique(has, has + num) - has;
    for(int i = 1; i <= n; i++){
        int id = lower_bound(has, has + num, df[i].x) - has;
        mygraph[id].push_back(NODE(df[i].y, df[i].dis));
    }
}
int fuckit(int fuckid){
    int head = 0, tail = 0, ret = 0;
    vector<NODE>::iterator vectoriterator1, vectoriterator2, tmpvectoriterator;
    myque[tail++] = POINT(df[fuckid].x, df[fuckid].y, df[fuckid].dis);
    while(head < tail){
        POINT now = myque[head++];
        int pos1 = lower_bound(has, has + num, now.x - now.dis) - has;
        int pos2 = upper_bound(has, has + num, now.x + now.dis) - has;
        for(; pos1 != pos2; pos1++){
            int fucknum = has[pos1];
            int fucky = now.dis - abs(fucknum - now.x);
            int id = lower_bound(has, has + num, fucknum) - has;
            vectoriterator1 = lower_bound(mygraph[id].begin(), mygraph[id].end(), NODE(now.y - fucky, -1));
            vectoriterator2 = upper_bound(mygraph[id].begin(), mygraph[id].end(), NODE(now.y + fucky, inf));
            tmpvectoriterator = vectoriterator1;
            for(; vectoriterator1 != vectoriterator2; vectoriterator1++){
                NODE tmp  = *vectoriterator1;
                myque[tail++] = POINT(fucknum, tmp.y, tmp.dis);
                ret++;
            }
            mygraph[id].erase(tmpvectoriterator, vectoriterator2);
        }
    }
    return ret;
}
int main(){
    int testcases = 0;
    while(scanf("%d", &n) != EOF && n){
        init();
        readdata();
        printf("Case #%d:\n", ++testcases);
        for(int i = 0; i < num; i++) {
            sort(mygraph[i].begin(), mygraph[i].end());
        }
        scanf("%d", &m);
        for(int i = 1; i <= m; i++){
            int k;
            scanf("%d", &k);
            int sum = fuckit(k);;
            printf("%d\n", sum);
        }
    }
    return 0;
}
