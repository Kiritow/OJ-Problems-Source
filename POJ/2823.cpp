#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
#define MAXN 1000100
int bus[MAXN];

int aval[MAXN];
int apos[MAXN];
int abegin,aend;

int bval[MAXN];
int bpos[MAXN];
int bbegin,bend;

int aans[MAXN];
int bans[MAXN];
int cnt;

int main()
{
    int N,K;
    scanf("%d %d",&N,&K);
    abegin=0;
    aend=0;
    bbegin=0;
    bend=0;
    cnt=0;
    /*
        8 3
        1 3 -1 -3 5 3 6 7
    */
    for(int i=0;i<K;i++)
    {
        int t;
        scanf("%d",&t);

        while(abegin<aend&&aval[aend-1]<=t) aend--;
        aval[aend]=t;
        apos[aend++]=i;

        while(bbegin<bend&&bval[bend-1]>=t) bend--;
        bval[bend]=t;
        bpos[bend++]=i;
    }
    aans[cnt]=aval[abegin];
    bans[cnt++]=bval[bbegin];
    for(int i=K;i<N;i++)
    {
        int t;
        scanf("%d",&t);

        while(abegin<aend&&i-apos[abegin]>=K) abegin++;
        while(abegin<aend&&aval[aend-1]<=t) aend--;
        aval[aend]=t;
        apos[aend++]=i;

        while(bbegin<bend&&i-bpos[bbegin]>=K) bbegin++;
        while(bbegin<bend&&bval[bend-1]>=t) bend--;
        bval[bend]=t;
        bpos[bend++]=i;

        aans[cnt]=aval[abegin];
        bans[cnt++]=bval[bbegin];
    }

    for(int i=0;i<cnt-1;i++)
    {
        printf("%d ",bans[i]);
    }
    printf("%d\n",bans[cnt-1]);

    for(int i=0;i<cnt-1;i++)
    {
        printf("%d ",aans[i]);
    }
    printf("%d\n",aans[cnt-1]);

    return 0;
}
