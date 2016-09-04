#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstdlib"
#include "cstring"
using namespace std;
#define _ASSERT(a) ({fprintf(stderr,"%s:%d: %s\n", __FILE__, __LINE__, #a); exit(-1);})
#define _FOREACH(a, b) for(__typeof(b.begin())a=b.begin(), a##ed__=b.end(); a!=a##ed__; a++)
#define _FOREACHC(a, b, cond) for (__typeof(b) a=b;(cond); b++, a=b)
#define _QUEUEPROC(cond, U, V) \
    for(int u=(U);cond;u=(U))\
        _FOREACH(v, V) 
#define _STACKPROC(cond, U, V) \
    for (int u=(U); cond; u=(U))\
        for (bool child=false; !child; child=true)\
            _FOREACHC(v, (V), !child)
#define _INCREMENT(over, ...)\
 do\
 {\
 static int over = 0;\
 (over)++;\
 __VA_ARGS__;\
    }while(0)
#define rangedo(i, s, t)\
 i=s; i!=t; i++
#define each(a, b)\
 __typeof(b.begin())a=b.begin(), a##ed__=b.end(); a!=a##ed__; a++
int T;
int N, M;
int f[16][16][16][16];
int vst[16][16][16][16];
struct Save{
    int x1, y1, x2, y2;
}sav[1001];
const int modulo = 100000;
int iter[4];
int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &N, &M);
        memset(vst, 0, sizeof(vst));
        for (int i=0; i<M; i++)
            scanf("%d%d%d%d", &sav[i].x1, &sav[i].y1, &sav[i].x2, &sav[i].y2);
        for (rangedo(iter[0], 0, N+1))
        for (rangedo(iter[1], 0, N+1))
        for (rangedo(iter[2], 0, N+1))
        for (rangedo(iter[3], 0, N+1))
        for (int rangedo(i, 0, M))
            if ( (iter[sav[i].x1-1] < sav[i].y1)!=
             (iter[sav[i].x2-1] < sav[i].y2) )
            {
                vst[iter[0]][iter[1]][iter[2]][iter[3]]=true;
                break;
            }
        memset(f , 0, sizeof( f));
        f[0][0][0][0]=1;
        for (int rangedo(color, 1, 257))
        {
            for (int rangedo(colum, 0, 4))
            for (rangedo(iter[0], 0, N+1))
            for (rangedo(iter[1], 0, N+1))
            for (rangedo(iter[2], 0, N+1))
            for (rangedo(iter[3], 0, N+1))
                if (iter[colum])
                {
                    int &dp = f[iter[0]][iter[1]][iter[2]][iter[3]];
                    iter[colum]--;
                    dp += f[iter[0]][iter[1]][iter[2]][iter[3]];
                    iter[colum]++;
                    if (dp>=modulo) dp-=modulo;
                }
            for (rangedo(iter[0], 0, N+1))
            for (rangedo(iter[1], 0, N+1))
            for (rangedo(iter[2], 0, N+1))
             for (rangedo(iter[3], 0, N+1))
                if (vst[iter[0]][iter[1]][iter[2]][iter[3]])
                    f[iter[0]][iter[1]][iter[2]][iter[3]]=0;
        }
        _INCREMENT(ncase,
                printf("Case %d: %05d\n", ncase, f[N][N][N][N]));
    }
}
