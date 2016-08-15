#include <iostream>
#include <math.h>
using namespace std;
int main(void) {
    for (int i, m, n, nMaxM, nMaxN, nCnt = 0; cin >> i; nCnt = 0) {
        bool aFlags[1000001] = {false};
        for (m = 2, nMaxM = (int)sqrt((float)i - 1); m <= nMaxM; ++m) {
            nMaxN = (int)sqrt((float)i - m * m);
            nMaxN = nMaxN >= m ? m - 1 : nMaxN;
            for (n = 1; n <= nMaxN; ++n) {
                if (n % 2 != m % 2) {
                    int a = m, b = n, c;
                    for(int r; (r = a % b) != 0; a = b, b = r);
                    if (b == 1) {
                        ++nCnt;
                        a = m * m - n * n, b = 2 * m * n, c = m * m + n * n;
                        for (int k = 0; c * k <= i; ++k) {
                            aFlags[a * k] = aFlags[b * k] = aFlags[c * k] = 1;
                        }
                    }
                }
            }
        }
        cout << nCnt << ' ';
        for (nCnt = 0, m = 1; m <= i; nCnt += !aFlags[m++]);
        cout << nCnt << endl;
    }
    return 0;
}
