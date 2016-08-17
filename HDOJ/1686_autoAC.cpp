#include <stdio.h>
#include <string.h>
#define MAX 10000
int next[MAX + 1];
char pattern[MAX + 1];
int init_next (char *pattern, int *next);
int KMP (char text, char *pattern, int len);
int main()
{
    int T;
    int len;
    char text = '\0';
    scanf ("%d", &T);
    getchar ();
    while (T --)
    {
        len = init_next (pattern, next);
        printf ("%d\n", KMP (text, pattern, len));
    }
    return 0;
}
int init_next (char *pattern, int *next)
{
    int q, i = 0;
    q = next[0] = -1;
    pattern[i ++] = getchar ();
    while ((pattern[i] = getchar ()) != '\n')
    {
        while (q >= 0 && pattern[q + 1] != pattern[i])
        {
            q = next[q];
        }
        if (pattern[q + 1] == pattern[i])
        {
            q ++;
        }
        next[i] = q;
        i ++;
    }
    return i;
}
int KMP (char text, char *pattern, int len)
{
    int q, i = 0;
    int count = 0;
    q = -1;
    while ((text = getchar ()) != '\n')
    {
        while (q >= 0 && pattern[q + 1] != text)
        {
            q = next[q];
        }
        if (pattern[q + 1] == text)
        {
            q ++;
        }
        if (q == len - 1)
        {
            q = next[q];
            count ++;
        }
    }
    return count;
}
