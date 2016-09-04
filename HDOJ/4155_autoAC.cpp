#include<stdio.h>
#include<string.h>
#define MAXD 16000
int sg[MAXD], h[7];
char b[30];
int dfs(int st)
{
    if(sg[st] != -1)
        return sg[st];
    int i, j, k, s[10], sum = 0;
    memset(s, 0, sizeof(s));
    for(i = 1; i <= 6; i ++)
        sum += h[i] * i;
    for(i = 1; i <= 6; i ++)
        if(h[i] < 4 && i + sum <= 31)
        {
            ++ h[i];
            for(j = 1, k = 0; j <= 6; j ++)
                k = k * 5 + h[j];
            s[dfs(k)] = 1;
            -- h[i];
        }
    for(i = 0; s[i]; i ++);
    return sg[st] = i;
}
void solve()
{
    int i, j, k, turn;
    memset(h, 0, sizeof(h));
    for(i = 0; b[i]; i ++)
        ++ h[b[i] - '0'];
    turn = i % 2;
    for(i = 1, j = 0; i <= 6; i ++)
        j = j * 5 + h[i];
    k = dfs(j);
    printf("%s ", b);
    if(turn == 0)
        printf("%s\n", k == 0 ? "B" : "A");
    else
        printf("%s\n", k == 0 ? "A" : "B");
}
int main()
{
    memset(sg, -1, sizeof(sg));
    while(scanf("%s", b) == 1)
    {
        solve();
    }
    return 0;
}
