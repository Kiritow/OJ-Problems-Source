#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstdlib"
#include "cstring"
#include "iterator"
using namespace std;
#define $FOREACH(a, b) for(__typeof(b.begin())a=b.begin(), a##ed__=b.end(); a!=a##ed__; a++)
#define $FOREACHC(a, b, cond)   for (__typeof(b) a=b;(cond); b++, a=b)
#define $QUEUEPROC(cond, U, V) \
    for(int u=(U);cond;u=(U))\
        $FOREACH(v, V)  
#define $STACKPROC(cond, U, V) \
    for (int u=(U); cond; u=(U))\
        for (bool child=false; !child; child=true)\
            $FOREACHC(v, (V), !child)
#define $ASSERT(a) ({fprintf(stderr,"%s:%d: %s\n", __FILE__, __LINE__, #a); exit(-1);})
char* ran = "  23456789TJQKA";
char* suit = "SHDC";
int revers[256];
int rev[256];
int card[200];
int tot=0;
int dist[4];
int ihcp[15];
inline void pre()
{
    for (int i=0; i<15; i++) revers[(int)ran[i]]=i, 
                 ihcp[i] = (i>10?i-10:0);         
    for (int i=0; i<4;  i++) rev[(int)suit[i]]=i;
}
int hcp;
bool read()
{
    char s[1024];
    if (!gets(s)) return false;
    fill(dist, dist+4, 0);
    hcp=0;
    for (int i=0, j=0; j<13; i+=3, j++)
    {
        card[j] = rev[(int)s[i]] * 20 + revers[(int)s[i+1]],
        dist[rev[(int)s[i]]]++,
        hcp+=ihcp[revers[(int)s[i+1]]];
    }
    return true;
}
char suits[][1000]={
    "Spades",
    "Hearts",
    "Diamonds",
    "Clubs",
    "No Trump",
    "Pass",
};
inline void bid(int level, int suit)
{
    static int ncase = 0;
    if (suit < 5)
        printf("Hand #%d: %d %s\n", ++ncase, level, suits[suit]);
    else
        printf("Hand #%d: %s\n", ++ncase, suits[suit]);
}
inline bool check(int *z, int a, int b, int c, int d)
{
    if (z[0] != a || z[1]!=b || z[2]!=c || z[3]!=d) return false;
    return true;
}
inline bool stopped(int *dist)
{
    int stop = 0;
    for (int i=0; i<4; i++)
    {
        if (
                find(card, card+13, i*20+14)!=card+13 ||
                find(card, card+13, i*20+13)!=card+13 && dist[i]>1||
                find(card, card+13, i*20+12)!=card+13 && dist[i]>2||
                find(card, card+13, i*20+11)!=card+13 && dist[i]>3
        ) stop++;
    }
    return stop>=3;
}
int main()
{
    pre();
    while (read())
    {
        int r = find(dist, dist+4, *max_element(dist, dist+4))-dist;
        int m = dist[r];
        #ifdef Debug
        for (int i=0; i<4; i++) printf("%d ", dist[i]);
        puts("");
        printf("%d %d %d\n", m, r, hcp);
        #endif
        int z[4];
        copy(dist, dist+4, z);
        sort(z, z+4, greater<int>());
        if (hcp >= 10 && m>=8)
            bid(4, r);
        else if (hcp >= 10 && hcp <= 13 && m == 7)
            bid(3, r);
        else if (hcp >= 8 && hcp <= 9 && (dist[0] >= 7 || dist[1]>=7))
        {
            if (dist[1] < 7 || dist[0] >= dist[1])
                bid(2, 0);
            else
                bid(2, 1);
        }
        else if (hcp >= 8 && hcp <= 11  && (dist[0]>=6 || dist[1]>=6))
        {
            if (dist[1] < 6 || dist[0] >= dist[1])
                bid(2, 0);
            else
                bid(2, 1);
        }
        else if (hcp >= 11 && hcp <= 15 && 
                (check(z,4,4,4,1)||check(z, 5,4,4,0))
                && dist[0] >= 4)
            bid(2, 2);
        else if (hcp >=15 && hcp <= 17 && 
                (check(z, 4,3,3,3) || check(z, 4,4,3,2) || check(z,5,3,3,2))&&
                stopped(dist))
            bid(1, 4);
        else if (hcp >= 20 && hcp <= 22 && (check(z, 4,3,3,3) || check(z, 4,4,3,2) || check(z,5,3,3,2)))
            bid(2, 4);
        else if (hcp >= 22)
            bid(2, 3);
        else if (hcp >= 13 && hcp <= 16 && (dist[0]>=5 || dist[1]>=5))
        {
            if (dist[1] < 5 || dist[0] >= dist[1])
                bid(1, 0);
            else
                bid(1, 1);
        }
        else if (hcp >= 13 && hcp <= 16)
            if (dist[2] >= dist[3])
                bid(1, 2);
            else
                bid(1, 3);
        else if (hcp >= 17)
        {
            for (int i=3; i>=0; i--)
                if (dist[i] == m)
                {
                    bid(1, i);
                    break;
                }
        }
        else
            bid(0, 5);
    }
}
