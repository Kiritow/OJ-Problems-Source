#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
using namespace std;
struct status_t
{
    int kill;
    int ctime;
    int ckill;
    status_t()
    {
        kill = 0;
        ctime = -50;
        ckill = 0;
    }
    void die()
    {
        kill = 0;
        ctime = -50;
        ckill = 0;
    }
    void killkill(const char *name, int t)
    {
// calc ckill
        if (t - ctime <= 10)
        {
            ctime = t;
            ckill++;
        }
        else
        {
            ctime = t;
            ckill = 1;
        }
        if (ckill == 2)
            printf("%s has Double Kill\n", name);
        else if (ckill == 3)
            printf("%s has Triple Kill\n", name);
        else if (ckill == 4)
            printf("%s has Ultra Kill\n", name);
        else if (ckill >= 5)
            printf("%s has Rampage\n", name);
// calc kill
        kill ++;
        if (kill == 3)
            printf("%s is Killing Spree\n", name);
        else if (kill == 4)
            printf("%s is Dominating\n", name);
        else if (kill == 5)
            printf("%s is Mega Kill\n", name);
        else if (kill == 6)
            printf("%s is Unstoppable\n", name);
        else if (kill == 7)
            printf("%s is Wicked Sick\n", name);
        else if (kill == 8)
            printf("%s is M-m-m-m...onster Kill\n", name);
        else if (kill == 9)
            printf("%s is Godlike\n", name);
        else if (kill >= 10)
            printf("%s is Beyond Godlike\n", name);

    }
};
int N, M;
int main()
{
    int T, i;
    int t1, t2, t;
    char s1[100], s2[100];
    scanf("%d", &T);
    while (T--)
    {
        map<string, status_t> m;
        scanf("%d", &N);
        bool isfirstkill = true;
        for (i=0; i<N; i++)
        {
            scanf("%s %*s %s %*s %d:%d", s1, s2, &t1, &t2);
            t = 60 * t1 + t2;
            string p1(s1), p2(s2);
            if (p1 == p2)
            {
                m[p1].die();
            }
            else
            {
                if (isfirstkill)
                {
                    printf("%s has First Blood\n", s1);
                    isfirstkill = false;
                }
// calc ckill
                m[p2].die();
                m[p1].killkill(s1, t);
            }
        }
    }
    return 0;
}
