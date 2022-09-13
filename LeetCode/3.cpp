#include <cstdlib>
#include <cstring>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sz = s.size();
        int bin[256];
        int maxlen = 0;
        int clen = 0;
        int L = 0;
        while (L < sz)
        {
            memset(bin, 0, sizeof(int) * 256);
            int i;
            for (i = L; i < sz; i++)
            {
                if (bin[s[i]])
                {
                    maxlen = clen > maxlen ? clen : maxlen;
                    clen = 0;
                    L++;
                    break;
                }
                else
                {
                    bin[s[i]] = 1;
                    clen++;
                }
            }
            if (i == sz)
            {
                maxlen = clen > maxlen ? clen : maxlen;
                break;
            }
        }
        return maxlen;
    }
};
