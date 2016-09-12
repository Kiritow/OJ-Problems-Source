#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAX_N = 200 + 10;
int Next[MAX_N];
const char *str = "anniversary";
char pat[MAX_N], pat_sub[MAX_N];
char sub_1[MAX_N], sub_2[MAX_N], sub_3[MAX_N];
void get_nextval(char *W, int Next[])
{
    int i = 0, j = -1;
    int Len_W = strlen(W);
    Next[0] = -1;
    if (W[0] == '\0')
        return;
    while (i < Len_W)
    {
        if (j == -1 || W[i] == W[j])
        {
            ++i;
            ++j;
            Next[i] = j;
        } else
            j = Next[j];
    }
}
int KMP_Matcher(char T[], char P[], int Next[])
{
    int i = 0, j = 0;
    int TLen = strlen(T);
    int PLen = strlen(P);
    if (TLen == 0)
        return -2;
    while (i < TLen && j < PLen)
    {
        if (j == -1 || T[i] == P[j])
        {
            i++;
            j++;
        } else
            j = Next[j];
    }
    if (j == PLen)
        return i - j;
    else
        return -1;
}
int main()
{
    int case_times, len;
    scanf("%d", &case_times);
    len = strlen(str);
    while (case_times--)
    {
        int len_s;
        bool ans = false;
        scanf("%s", pat);
        strcpy(pat_sub, pat);
        len_s = strlen(pat);
        for (int i = 1; i < len; ++i)
        {
            if (ans)
                break;
            for (int j = i + 1; j < len; ++j)
            {
                int m_1, m_2, m_3;
                strncpy(sub_1, str, i);
                sub_1[i] = '\0';
                strncpy(sub_2, str + i, j - i);
                sub_2[j - i] = '\0';
                strncpy(sub_3, str + j, len - j);
                sub_3[len - j] = '\0';
                strcpy(pat_sub, pat);
                get_nextval(sub_1, Next);
                m_1 = KMP_Matcher(pat_sub, sub_1, Next);
                if (m_1 >= 0)
                {
                    for (int k = 0; k <= len_s - i; ++k)
                        pat_sub[k] = pat[m_1 + i + k];
                }
                get_nextval(sub_2, Next);
                m_2 = KMP_Matcher(pat_sub, sub_2, Next);
                if (m_2 >= 0)
                {
                    for (int k = 0; k <= len_s - j; ++k)
                        pat_sub[k] = pat_sub[m_2 + j - i + k];
                }
                get_nextval(sub_3, Next);                
                m_3 = KMP_Matcher(pat_sub, sub_3, Next);
                if (m_1 >= 0 && m_2 >= 0 && m_3 >= 0)
                {
                    ans = true;
                    break;
                }
            }
        }
        if (ans)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
