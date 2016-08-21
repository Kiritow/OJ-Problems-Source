#include "iostream"
#include "algorithm"
#include "cstdio"
#include "cstdlib"
#include "cstring"
using namespace std;
#define $FOREACH(a, b) for(__typeof(b.begin())a=b.begin(), a##ed__=b.end(); a!=a##ed__; a++)
#define $FOREACHC(a, b, cond) for (__typeof(b) a=b;(cond); b++, a=b)
#define $QUEUEPROC(cond, U, V) \
    for(int u=(U);cond;u=(U))\
        $FOREACH(v, V) 
#define $STACKPROC(cond, U, V) \
    for (int u=(U); cond; u=(U))\
        for (bool child=false; !child; child=true)\
            $FOREACHC(v, (V), !child)
#define $ASSERT(a) ({fprintf(stderr,"%s:%d: %s\n", __FILE__, __LINE__, #a); exit(-1);})
int mul[10000], gmul[10000];
int add[10000], gadd[10000];
int F[10000], G[10000];
void pre()
{
    for (int i=1; i<=6000; i++)
        mul[i] = add[i] = i,
        gmul[i] = gadd[i] = 0,
        F[i] = i, G[i]=0;
    for (int i=1; i<=6000; i++)
        for (int j=i-1; j>0; j--)
            if (i%j == 0 && 
                mul[i] > mul[j] + i/j + 2) 
                mul[i] = mul[j] + i/j + 2,
                gmul[i] = j;
    for (int i=1; i<=6000; i++)        add[i] = mul[i];
    for (int i=1; i<=6000; i++)
        for (int j=i-1; j>0; j--)
            if (add[i] > add[j] + mul[i-j] + 2)
                add[i] = add[j] + mul[i-j]+2,
                gadd[i]=j;
}
void printmul(int N)
{
    if (gmul[N] == 0)
        for (int i=0; i<N; i++)
            printf("|");
    else
    {
        printmul(gmul[N]);
        printf("x");
        for (int i=0; i<N/gmul[N]; i++)
            printf("|");
    }
}
void print(int N)
{
    if (gadd[N] == 0) printmul(N);
    else
    {
        print(gadd[N]);
        printf("+");
        printmul(N-gadd[N]);
    }
}
void printT(int N)
{
    if (G[N] == 0) for (int i=0; i<N; i++) printf("|");
    else 
        if (G[N] < 0)
        {
            printT(-G[N]);
            printf("x");
            for (int i=0; i<-N/G[N]; i++) printf("|");
        }else{
            printT(G[N]);
            printf("+");
            for (int i=0; i<N-G[N]; i++) printf("|");
        }
}
int main()
{
    pre();
    int N;
    while (scanf("%d", &N)!=EOF)
    {
        if (N==0) break;
        if (add[N] < mul[N])
        {
            printf("%d toothpicks: ", add[N]);
            print(N);
            printf("=%d\n", N);
        }else{
            printf("%d toothpicks: ", mul[N]);
            printmul(N);
            printf("=%d\n", N);
        }
    }
}
