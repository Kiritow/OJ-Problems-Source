#include <cstdio>
class Solution {
public:
    bool isPalindrome(int x) {
        /*
        // Converting to string is too slow!!
        char buff[64] = { 0 };
        sprintf(buff, "%d", x);
        int len = strlen(buff);
        int L = 0, R = len - 1;
        while (L < R)
        {
            if (buff[L] != buff[R]) return false;
            ++L;
            --R;
        }
        return true;
        */
        if (x < 0) return false;
        int buff[64] = { 0 };
        int c = 0;
        int tx = x;
        while (tx > 0)
        {
            buff[c++] = tx % 10;
            tx /= 10;
        }
        int L = 0, R = c - 1;
        while (L < R)
        {
            if (buff[L] != buff[R]) return false;
            ++L;
            --R;
        }
        return true;
    }
};
