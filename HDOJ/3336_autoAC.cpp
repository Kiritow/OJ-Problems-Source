#include <cstdio>
#include <cstring>
int const MAX = 200000 + 5;
int const MOD = 10007;
int next[MAX];
char s[MAX];
void get_next()
{
    int i = 0, j = -1;
    next[0] = -1;
    while(s[i] != '\0')
    {
        if(j == - 1 || s[i] == s[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
            j = next[j];
    }
}
int main()
{
    int T, len, ans;
    scanf("%d", &T);
    while(T--)
    {
        memset(next, 0, sizeof(next));
        scanf("%d %s", &len, s);
        get_next();
        ans = len;
        for(int i = 1; i <= len; i++)
        {
            int tmp = next[i];
            while(tmp)
            {
                ans = (ans + 1) % MOD;
                tmp = next[tmp];
            }
        }
        printf("%d\n", ans);
    }
}
