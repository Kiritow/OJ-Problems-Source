#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 50005
struct pack
{
    long a,b,c;
};
pack PK[MAXN];
int W[16];
bool cmp(pack a,pack b){
    return (a.a>b.a) || (a.a==b.a && a.c<b.c);
}

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=0;i<10;i++)
    {
        scanf("%d",&W[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%ld",&PK[i].a);
        PK[i].c=i+1;
    }
    sort(PK,PK+n,cmp);
    for (int i=0;i<n;i++){
        PK[i].b=i;
        PK[i].a+=W[PK[i].b%10];
    }
    sort(PK,PK+n,cmp);
    for (int i=0;i<k;i++){
        printf("%ld",PK[i].c);
        if (i+1==k) printf("\n");
        else printf(" ");
    }
    return 0;
}
