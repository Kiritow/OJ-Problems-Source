//#include "stdafx.h"
#include <cstdio>
#include <string>
#include <cmath>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define LL long long
LL t[1000010];
#define MAXN 1e9
int Count = 0;
//直接取结果
int calc(int n){
    return std::lower_bound(t, t + Count, n) - t;
}

int main() {

    int T;
    LL p = 0;
    //初始化整个数组
    memset(t, 0, sizeof(t));

    for (LL i = 4; i < 1000010; i++) {

        if ((i % 4)==0) {
            t[i] = i * i / 8;
            p = t[i] - t[i - 1];
        }
        else if ((i & 1)==0) {

            t[i] = t[i - 1] + p;
        }
        else {
            t[i] = t[i - 1] + (i + 1) / 4 - 1;
        }
        Count = i;
        if (t[i] > MAXN)
            break;
    }

    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        cout << calc(n) << endl;
    }
}