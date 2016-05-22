#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXD = 2000+5;
const int MAXM = 1000+5;
const int MAXN = 1000+ 5;
int N,M,L,K,D;

int XLine[MAXN];
int YLine[MAXM];

struct pack
{
    int value;
    int id;
    pack(int _Value,int _id) :
        value(_Value),id(_id){}
};

bool cmp1(const pack& a,const pack& b)
{
    return a.value>b.value;
}
bool cmp2(const pack& a,const pack& b)
{
    return a.id<b.id;
}
int main()
{
    scanf("%d %d %d %d %d",&M,&N,&K,&L,&D);
    for(int i=0;i<D;i++)
    {
        int a,b,c,d;
        scanf("%d %d %d %d",&a,&b,&c,&d);
        if(a==c)
        {
            YLine[min(b,d)]++;
        }
        else
        {
            XLine[min(a,c)]++;
        }
    }

    int cnt=0;
    /*
    for(int i=0;i<=N;i++)
    {
        if(XLine[i]>0)
        {
            ++mcnt;
        }
    }
    //*/
    vector<pack> vec;
    for(int i=0;i<=M;i++)
    {
        if(XLine[i]!=0)
        {
            vec.push_back(pack(XLine[i],i));
        }
    }
    sort(vec.begin(),vec.end(),cmp1);
    sort(vec.begin(),vec.begin()+K,cmp2);
    for(int i=0;i<K-1;i++)
    {
        printf("%d ",vec.at(i).id);
    }
    printf("%d\n",vec.at(K-1).id);

    vec.clear();
    cnt=0;

    /*for(int i=0;i<=M;i++)
    {
        if(YLine[i]>0)
        {
            ++mcnt;
        }
    }
    //*/
    for(int i=0;i<=N;i++)
    {
        if(YLine[i]!=0)
        {
            vec.push_back(pack(YLine[i],i));
        }
    }
    sort(vec.begin(),vec.end(),cmp1);
    sort(vec.begin(),vec.begin()+L,cmp2);
    for(int i=0;i<L-1;i++)
    {
        printf("%d ",vec.at(i).id);
    }
    printf("%d\n",vec.at(L-1).id);

    return 0;
}
