class Solution {
public:
    int maximumSwap(int num) {
        char buff[32];
        snprintf(buff, 32, "%d", num);
        int len = strlen(buff);
        for (int i = 0; i < len - 1; i++)
        {
            int maxIndex = i + 1;
            char maxChar = buff[i + 1];

            for (int j = i + 2; j < len; j++)
            {
                if (buff[j] >= maxChar) {
                    maxChar = buff[j];
                    maxIndex = j;
                }
            }

            if (buff[i] < maxChar) {
                swap(buff[i], buff[maxIndex]);
                break;
            }
        }

        int result;
        sscanf(buff, "%d", &result);
        return result;
    }
};
