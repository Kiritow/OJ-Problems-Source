#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef struct
{
    int p,d;
}Data;
Data dt[1000003];
bool cmp1(Data d1,Data d2)
{
    if(d1.p==d2.p) return d1.d<d2.d;
    return d1.p<d2.p;
}
bool cmp2(Data d1,Data d2)
{
    if(d1.p==d2.p) return d1.d>d2.d;
    return d1.p>d2.p;
}
bool cmp3(Data d1,Data d2)
{
     return d1.d<d2.d;
}
bool cmp4(Data d1,Data d2)
{
     return d1.d>d2.d;
}
void print()
{
    static int cnt=0;
    printf("Case %d\n",++cnt);
}
int main()
{
    int n,k1,k2;
    while(scanf("%d %d %d",&n,&k1,&k2),n&&k1&&k2)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d",&dt[i].p);
            dt[i].d=i+1;
        }
        sort(dt,dt+n,cmp1);
        print();
        sort(dt,dt+k1,cmp3);
        printf("%d",dt[0].d);
        for(int i=1;i<k1;i++)
        printf(" %d",dt[i].d);
        printf("\n");
        sort(dt,dt+n,cmp2);
        sort(dt,dt+k2,cmp4);
        printf("%d",dt[0].d);
        for(int i=1;i<k2;i++)
        printf(" %d",dt[i].d);
        printf("\n");
    }
    return 0;
}
