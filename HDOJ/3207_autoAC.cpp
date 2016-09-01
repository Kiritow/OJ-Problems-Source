#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <cmath>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100001;
const int segCnt = 400;
const int inf = 0x7f7f7f7f;
int INIT, segLen = segCnt;
struct Segment {
    int e[segCnt];
    int Min;
    int add;
    int addTo;
    int lowest;
    void init() {
        Min = INIT;
        for (int i = 0; i < segLen; i++) {
            e[i] = INIT;
        }
        add = addTo = lowest = 0;
    }
    void update() {
        Min = inf;
        for (int i = 0; i < segLen; i++) {
            if (e[i] <= abs(lowest)) e[i] = 0;
            if (e[i]) {
                e[i] += add;
                e[i] = max(e[i], addTo);
            }
            Min = min(Min, e[i]);
        }
        add = addTo = lowest = 0;
    }
    void Add(int l, int r, int d) {
        for (int i = l; i <= r; i++) {
            if (e[i]) {
                e[i] = max(e[i] + d, 0);
            }
        }
        Min = inf;
        for (int i = 0; i < segLen; i++) {
            Min = min(Min, e[i]);
        }
    }
    void AddTo(int l, int r, int d) {
        for (int i = l; i <= r; i++) {
            if (e[i]) {
                e[i] = max(e[i], d);
            }
        }
        Min = inf;
        for (int i = 0; i < segLen; i++) {
            Min = min(Min, e[i]);
        }
    }
    void show() {
        puts("Elements: ");
        for (int i = 0; i < segLen; i++) {
            printf(" %d", e[i]);
        }
        puts("");
        printf("min %d add %d addto %d lowest %d\n", Min, add, addTo, lowest);
        puts("~~~");
    }
} seg[segCnt];
bool noBreak(int _l, int _r) {
    int segL = _l / segLen, segR = _r / segLen;
    int restL = _l % segLen, restR = _r % segLen;
    if (segL != segR) {
        seg[segL].update();
        seg[segR].update();
        for (int i = restL; i < segLen; i++) {
            if (!seg[segL].e[i]) return false;
        }
        for (int i = 0; i <= restR; i++) {
            if (!seg[segR].e[i]) return false;
        }
        for (int i = segL + 1; i < segR; i++) {
            if (!seg[i].Min) return false;
        }
    } else {
        seg[segL].update();
        for (int i = restL; i <= restR; i++) {
            if (!seg[segL].e[i]) return false;
        }
    }
    return true;
}
void Add(int _l, int _r, int _d) {
    int segL = _l / segLen, segR = _r / segLen;
    int restL = _l % segLen, restR = _r % segLen;
    if (segL != segR) {
        seg[segL].update();
        seg[segR].update();
        seg[segL].Add(restL, segLen - 1, _d);
        seg[segR].Add(0, restR, _d);
        for (int i = segL + 1; i < segR; i++) {
            seg[i].add += _d;
            if (seg[i].Min) seg[i].Min += _d;
            if (seg[i].addTo) seg[i].addTo += _d;
        }
    } else {
        seg[segL].update();
        seg[segL].Add(restL, restR, _d);
    }
}
bool Sub(int _l, int _r, int _d) {
    if (noBreak(_l, _r)) {
        int segL = _l / segLen, segR = _r / segLen;
        int restL = _l % segLen, restR = _r % segLen;
        if (segL != segR) {
            seg[segL].update();
            seg[segR].update();
            seg[segL].Add(restL, segLen - 1, -_d);
            seg[segR].Add(0, restR, -_d);
            for (int i = segL + 1; i < segR; i++) {
                seg[i].add -= _d;
                seg[i].addTo = max(seg[i].addTo - _d, 0);
                seg[i].Min = max(seg[i].Min - _d, 0);
                if (!seg[i].addTo) seg[i].lowest = min(seg[i].lowest, seg[i].add);
            }
        } else {
            seg[segL].update();
            seg[segL].Add(restL, restR, -_d);
        }
        return true;
    }
    return false;
}
void AddTo(int _l, int _r, int _d) {
    int segL = _l / segLen, segR = _r / segLen;
    int restL = _l % segLen, restR = _r % segLen;
    if (segL != segR) {
        seg[segL].update();
        seg[segR].update();
        seg[segL].AddTo(restL, segLen - 1, _d);
        seg[segR].AddTo(0, restR, _d);
        for (int i = segL + 1; i < segR; i++) {
            if (seg[i].Min < _d && seg[i].addTo < _d) {
                seg[i].addTo = _d;
                if (seg[i].Min) seg[i].Min = _d;
            }
        }
    } else {
        seg[segL].update();
        seg[segL].AddTo(restL, restR, _d);
    }
}
int main() {
    int N, M;
    while (~scanf("%d%d%d", &N, &M, &INIT) && (N + M + INIT)) {
        segLen = (int)sqrt((double) N) + 1;
        int op, a, b, c;
        int cnt = 0;
        for (int i = 0; i < segLen; i++) {
            seg[i].init();
        }
        for (int i = 1; i <= M; i++) {
            scanf("%d%d%d%d", &op, &a, &b, &c);
            switch (op) {
            case 1 :
                if (Sub(a, b, c)) {
                    cnt++;
                }
                break;
            case 2 :
                Add(a, b, c);
                break;
            case 3 :
                AddTo(a, b, c);
                break;
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
