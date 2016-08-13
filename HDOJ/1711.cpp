#include <string>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define MAXA 1000005
#define MAXN 10010
#define MAXNEXT 10050

/*
int f[MAXN];


void getfill(int* s,int LenS,int* f)
{
    //memset(f,0,sizeof(f));  //根据其前一个字母得到
    for(int i=1;i<LenS;i++)
    {
        int j=f[i];
        while(j && s[i]!=s[j])
            j=f[j];
        f[i+1]=(s[i]==s[j])?j+1:0;
    }
}

int KMP(int* a,int LenA,int* s,int LenS)
{
    f[0]=0;
    getfill(s,LenS,f);
    int j=0;
    for(int i=0;i<LenA;i++)
    {
        while(j && a[i]!=s[j])
            j=f[j];
        if(a[i]==s[j])
            j++;
        if(j==LenS){
            return i-LenS+1;
        }
    }
    return -2;
}
//*/

/*** New ***/
int Next[MAXNEXT];
int a[MAXA];
int b[MAXN];
void MakeNext(int* P,int M,int* Next){
    Next[0] = -1;
    int i = 0, j = -1;
    while(i<M){
        if(j==-1||P[i]==P[j]){
            i++,j++;
            if(P[i]!=P[j])Next[i] = j;
            else Next[i] = Next[j];
        }
        else j = Next[j];
    }
}
int KMP(int* T,int N,int* P,int M)
{
    MakeNext(P,M,Next);
    int i=0,j=0;
    while(i<N&&j<M){
        if(T[i]==P[j]||j==-1)i++,j++;
        else j = Next[j];
    }
    if(j==M)return i-M;
    else return -2;
}

/*** End **/

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int sza,szb;
        scanf("%d %d",&sza,&szb);
        for(int i=0;i<sza;i++)
        {
            scanf("%d",&a[i]);
        }
        for(int i=0;i<szb;i++)
        {
            scanf("%d",&b[i]);
        }
        printf("%d\n",KMP(a,sza,b,szb)+1);
    }
    return 0;
}
