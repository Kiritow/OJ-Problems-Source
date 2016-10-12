#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 100005
int t;
int N,R,Q;
int N2;

struct player
{
    int id,ability,score;
};

player a[MAXN*2];
player b[MAXN];/// Winner
player c[MAXN];/// Failed

bool cmp(const player& a,const player& b)
{
    if(a.score==b.score)
    {
        return a.id<b.id;
    }
    return (a.score>b.score);
}
void Solve()/// Use N2
{
    int cb=0;
    int cc=0;
    for(int i=0; i<N2; i+=2)
    {
        if(a[i].ability>a[i+1].ability)
        {
            b[cb]=a[i];
            ++b[cb++].score;
            c[cc++]=a[i+1];
        }
        else
        {
            b[cb]=a[i+1];
            ++b[cb++].score;
            c[cc++]=a[i];
        }
    }

    int cib=0;
    int cic=0;
    int ci=0;
    while(cib<cb&&cic<cc)
    {
        if(b[cib].score>c[cic].score || (b[cib].score==c[cic].score&&b[cib].id<c[cic].id) )
        {
            a[ci++]=b[cib++];
        }
        else
        {
            a[ci++]=c[cic++];
        }
    }
    while(cib<cb) a[ci++]=b[cib++];
    while(cic<cc) a[ci++]=c[cic++];
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&N,&R,&Q);
        N2=N*2;
        for(int i=0; i<N2; i++)
        {
            scanf("%d",&a[i].score);
            a[i].id=i+1;
        }
        for(int i=0; i<N2; i++)
        {
            scanf("%d",&a[i].ability);
        }
        sort(a,a+N2,cmp);

        while(R--) Solve();

        printf("%d\n",a[Q-1].id);
    }
    return 0;
}
