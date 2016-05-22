#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define MAXN 30005

int parent[MAXN];
int parentdis[MAXN];
int child[MAXN];
int childdis[MAXN];

int backfrom;

int father(int pos)
{
    if(parent[pos]!=pos)
    {
        parent[pos]=father(parent[pos]);
        parentdis[pos]=parentdis[pos]+parentdis[backfrom];

    }
    backfrom=pos;
    return parent[pos];
}


int son(int pos)
{
    if(child[pos]!=pos)
    {
        child[pos]=son(child[pos]);
        childdis[pos]=childdis[pos]+childdis[backfrom];
    }
    backfrom=pos;
    return child[pos];
}

void put_a_on_b(int a,int b)
{
    int A1=father(a);
    int A2=father(b);
    int B1=son(a);
    int B2=son(b);
    int x1=parentdis[a];
    int y1=childdis[a];
    int x2=parentdis[b];
    int y2=childdis[b];

    parent[A2]=A1;
    parentdis[A2]=x1+y1+1;
    if(A2!=B2)
    {
        parent[B2]=A1;
        parentdis[B2]+=x1+y1+1;
    }
    child[A1]=B2;
    childdis[A1]+=x2+y2+1;
    if(A1!=B1)
    {
        child[B1]=B2;
        childdis[B1]=x2+y2+1;
    }
}

inline void init()
{
    for(int i=0;i<MAXN;i++)
    {
        parent[i]=child[i]=i;
        parentdis[i]=childdis[i]=0;
    }
}

char buff[32];
int main()
{
    int n;
    scanf("%d%*c",&n);
    int a,b;
    init();
    for(int i=0;i<n;i++)
    {
        char ccc;
        scanf("%c %d%*c",&ccc,&a);
        switch(ccc)
        {
        case 'M':
            {
                scanf("%d%*c",&b);
                put_a_on_b(a,b);
            }
            break;
        case 'C':
            {
                son(a);
                father(a);
                printf("%d\n",childdis[a]);
            }
            break;
        }
    }
    return 0;
}
