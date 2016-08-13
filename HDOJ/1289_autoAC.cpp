#include <cstdio>
#include <cmath>
#include <iostream>
 using namespace std;
int main() {
     float x;
     while (cin >> x) {
         int cnt = 0;
         while (fabs(x) >= 2.0) x /= 2.0, cnt++;
        while (fabs(x) < 1.0) x *= 2.0, cnt--;
         printf("%d %.6f\n", cnt, x);
     }
    return 0;
 }
