#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
const int MAXL = 80 + 10;
const int MAXN = 10000 + 10;
char szLine[MAXN];
char szWord[MAXN][MAXL];
int n;
int nWordCnt;
int dp[MAXN];
int nLastTo[MAXN];
int nSum[MAXN];
void Read()
{
    getchar();
    nWordCnt = 0;
    while (gets(szLine))
    {
        if (szLine[0] == '\0') break;
        sscanf(szLine, "%s", szWord[++nWordCnt]);
        for (int i = 0; szLine[i] != '\0'; ++i)
        {
            if (szLine[i] == ' ')
            {
                while (szLine[i] == ' ')
                {
                    i++;
                }
                sscanf(szLine + i, "%s", szWord[++nWordCnt]);
            }
        }
    }
}
void Init()
{
    nSum[0] = 0;
    for (int i = 1; i <= nWordCnt; ++i)
    {
        nSum[i] = nSum[i - 1] + strlen(szWord[i]);
    }
}
int Sum(int i, int j)
{
    return nSum[j] - nSum[i - 1];
}
int LeastLen(int i, int j)
{
    return Sum(i, j) + j - i;
}
int Badness(int i, int j)
{
    if (i == j)
    {
        return 500;
    }
    int nBlankCnt = n - Sum(i, j);
    int nGapCnt = j - i;
    int nGapLen = nBlankCnt / nGapCnt;
    int nRemain = nBlankCnt % nGapCnt;
    return (nGapLen - 1) * (nGapLen - 1) * (nGapCnt - nRemain) + nGapLen * nGapLen * nRemain;
}
void Dp()
{
    memset(dp, 0x3f, sizeof(dp));
    dp[nWordCnt + 1] = 0;
    for (int i = nWordCnt; i >= 1; --i)
    {
        for (int j = i; j <= nWordCnt && LeastLen(i, j) <= n; ++j)
        {
            if (dp[j + 1] + Badness(i, j) <= dp[i])
            {
                dp[i] = dp[j + 1] + Badness(i, j);
                nLastTo[i] = j;
            }
        }
    }
}
void PrintBlank(int nNum)
{
    for (int i = 0; i < nNum; ++i)
    {
        putchar(' ');
    }
}
void Output()
{
    int nL = 1;
    while (true)
    {
        int nR = nLastTo[nL];
        if (nL == nR)
        {
            puts(szWord[nL]);
        }
        else
        {
            int nBlankCnt = n - Sum(nL, nR);
            int nGapCnt = nR - nL;
            int nGapLen = nBlankCnt / nGapCnt;
            int nRemain = nBlankCnt % nGapCnt;
            printf("%s", szWord[nL]);
            for (int i = 0; i < nGapCnt - nRemain; ++i)
            {
                PrintBlank(nGapLen);
                printf("%s", szWord[nL + 1 + i]);
            }
            for (int i = 0; i < nRemain; ++i)
            {
                PrintBlank(nGapLen + 1);
                printf("%s", szWord[nR - nRemain + 1 + i]);
            }
            puts("");
        }
        if (nR == nWordCnt) break;
        nL = nR + 1;
    }
    puts("");
}
int main()
{
    while (scanf("%d", &n) == 1 && n)
    {
        Read();
        Init();
        Dp();
        Output();
    }
    return 0;
}
