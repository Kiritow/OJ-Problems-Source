#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 32
#define cls(a) memset(a, 0, sizeof(a))
#define cls1(a,i,j) memset(a+i, 1, (j-i+1)*sizeof(bool))
#define cls0(a, i)    memset(a, 0, i*sizeof(bool))
struct computer{
    bool able[1005];
    int pcent;
}cpt[N];
bool isSver[N];
int Sver[N];
int Clnt[N];
int rate[N][N];
int main()
{
    int d, n, t, k, s, i, j, l, st, ed, m, c;
    scanf("%d", &d);
    while(d--)
    {
        cls(isSver);
        cls(Clnt);
        cls(Sver);
        cls(cpt);
        cls(rate);
        scanf("%d%d", &n, &t);
        scanf("%d%d", &s, &k);
        for(i=0; i<s; i++)
        {
            scanf("%d", Sver+i);
            isSver[Sver[i]] = 1;
            cpt[Sver[i]].pcent = k;
        }
        for(c=0, i=1; i<=n; i++)
        {
            if(!isSver[i]) Clnt[c++] = i;
        }
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                scanf("%d", rate[i]+j);
            }
        }
        for(i=1; i<=n; i++)
        {
            scanf("%d", &m);
            for(j=0; j<m; j++)
            {
                scanf("%d%d", &st, &ed);
                if(st > t) continue;
                if(ed > t) ed = t;
                for(l=st; l<ed; l++) cpt[i].able[l] = 1;
            }
        }
        scanf("%d", &m);
        for(i=0; i<m; i++)
        {
            scanf("%d%d", &ed, &st);
            cls0(cpt[st].able, ed);
        }
        for(i=0; i<=t; i++)
        {
            for(j=0; j<c; j++)
            {
                if(cpt[Clnt[j]].able[i])
                {
                    for(l=0; l<s; l++)
                    {
                        if(cpt[Sver[l]].able[i])
                        {
                            cpt[Clnt[j]].pcent += rate[Clnt[j]][Sver[l]];
                        }
                    }
                }
            }
            for(j=0; j<c; j++)
                if(cpt[Clnt[j]].pcent >= k)
                {
                    isSver[Clnt[j]] = 1;
                    Sver[s++] = Clnt[j];
                    for(c--, l=j; l<c; l++)
                        Clnt[l] = Clnt[l+1];
                }
        }
        for(i=1; i<=n; i++)
        {
            printf("%d%%\n", cpt[i].pcent>=k ? 100 : (cpt[i].pcent*100/k));
        }
    }
    return 0;
}
