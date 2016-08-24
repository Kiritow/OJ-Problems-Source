#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>
using namespace std;
#define M 1005
struct dance{
    char s[105];
}p[M];
int k;
bool judge1 (int i)
{
    if (i-1 >= 0 && !strcmp (p[i-1].s, "jiggle") ||
        i-2 >= 0 && !strcmp (p[i-2].s, "jiggle") ||
        i+1 < k && !strcmp (p[i+1].s, "twirl"))
        return true;
    return false;
}
bool judge2 ()
{
    if (k < 3) return false;
    if (strcmp (p[k-1].s, "clap") != 0 ||
        strcmp (p[k-2].s, "stomp") != 0 ||
        strcmp (p[k-3].s, "clap") != 0)
        return false;
    return true;
}
void solve ()
{
    int i, j, tw = 0, ho = 0, dip = 0, ans[10], has[10];
    memset (has, 0, sizeof(has));
    for (i = 0; i < k; i++)
    {
        if (!strcmp (p[i].s, "dip"))
        {
            if (!judge1 (i))
            {
                has[1] = 1;
                for (j = 0; j < 3; j++) p[i].s[j] -= 32;
            }
            dip = 1;
        }
        if (!strcmp (p[i].s, "twirl")) tw = 1;
        if (!strcmp (p[i].s, "hop")) ho = 1;
    }
    if (tw && !ho) has[3] = 1;
    if (!judge2 ()) has[2] = 1;
    if (!strcmp (p[0].s, "jiggle")) has[4] = 1;
    if (!dip) has[5] = 1;
    int id = 0;
    for (i = 1; i <= 5; i++)
        if (has[i])
            ans[id++] = i;
    if (id == 0) printf ("form ok:");
    else if (id == 1) printf ("form error %d:", ans[0]);
    else
    {
        printf ("form errors %d", ans[0]);
        for (i = 1; i < id-1; i++)
            printf (", %d", ans[i]);
        printf (" and %d:", ans[id-1]);
    }
    for (i = 0; i < k; i++)
        printf (" %s", p[i].s);
    printf ("\n");
}
int main ()
{
    while (~scanf ("%s", p[0].s))
    {
        k = 1;
        while (1)
        {
            char ch = getchar ();
            if (ch == '\n') break;
            scanf ("%s", p[k++].s);
        }
        solve ();
    }
    return 0;
}
