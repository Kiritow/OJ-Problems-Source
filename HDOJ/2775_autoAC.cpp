#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
int v[10],n,a[8][2],rest[20],now[8],occ[23],tot[100];
long long score[100];
char s[21];
int getrank(char ch){
    if(ch=='A')return 1;
    if(ch=='T')return 10;
    if(ch=='J')return 11;
    if(ch=='Q')return 12;
    if(ch=='K')return 13;
    return ch-'2'+2;
}
int getsuit(char ch){
    if(ch=='c')return 1;
    if(ch=='d')return 2;
    if(ch=='h')return 3;
    if(ch=='s')return 4;
}
bool can(int col,int mask)
{
    for(int i=0;i<5;++i)
        for(int j=i+1;j<5;++j)
            if(now[i]==now[j])
                return false;
    for(int i=0;i<5;++i)
        if((mask&(1<<i))==0)
        {
            if(a[i][1]!=col)return false;
        }
        else
        {
            for(int j=0;j<5;++j)
                if(a[j][0]==now[i]&&a[j][1]==col)
                    return false;
        }
    return true;
}
bool is0()
{
    for(int i=1;i<=14;++i)
        if(occ[i]==2)
            return 1;
    return 0;
}
bool is1()
{
    int ret=0;
    for(int i=1;i<=14;++i)
        if(occ[i]==2)
            ++ret;
    return ret==2;
}
bool is2()
{
    for(int i=1;i<=14;++i)
        if(occ[i]==3)
            return 1;
    return 0;
}
bool is3()
{
    if(occ[1]&&occ[10]&&occ[11]&&occ[12]&&occ[13])
        return true;
    for(int i=1;i+5-1<=13;++i)
        if(occ[i]&&occ[i+1]&&occ[i+2]&&occ[i+3]&&occ[i+4])
            return true;
    return false;
}
bool is5()
{
    for(int i=1;i<=14;++i)
        if (occ[i] == 3)
            for(int j=1;j<=14;++j)
                if(occ[j]==2)
                    return true;
    return false;
}
bool is6()
{
    for(int i=1;i<=14;++i)
        if(occ[i]==4)
            return 1;
    return 0;
}
int getscore()
{
    if(is6())return v[6];
    if(is5())return v[5];
    if(is3())return v[3];
    if(is2())return v[2];
    if(is1())return v[1];
    if(is0())return v[0];
    return 0;
}
int getsame(int *r)
{
    if(occ[1]&&occ[10]&&occ[11]&&occ[12]&&occ[13])
        return 8;
    for(int i=1;i+5-1<=13;++i)
        if(occ[i]&&occ[i+1]&&occ[i+2]&&occ[i+3]&&occ[i+4])
            return 7;
    return 4;
}
void search(int u,int cnt, int mask)
{
    if(u==5)
    {
        memset(occ,0,sizeof(occ));
        for(int i=0;i<5;++i)
            ++occ[now[i]];
        tot[mask] += cnt;
        int tmp = 0;
        for(int i=1;i<=4;++i)
            if(can(i,mask)) {
                ++ tmp;
            }
        if (is6() || is5()) tmp = 0;
        if (tmp) score[mask] += (long long)tmp * (long long)v[getsame(now)];
        score[mask]+=(long long)(cnt - tmp)*(long long)getscore();
        return;
    }
    now[u]=a[u][0];
    search(u + 1, cnt , mask);
    for(int i=1;i<=13;++i)
        if(rest[i])
        {
            --rest[i];
            now[u]=i;
            search(u+1,cnt*(rest[i]+1),mask|(1<<u));
            ++rest[i];
        }
}
int main()
{
    int _;
    for(scanf("%d",&_);_--;)
    {
        for(int i=0;i<9;++i)scanf("%d",v+i);
        scanf("%d%*c",&n);
        for (int k = 0; k < n; ++ k) {
            for(int i=1;i<=13;++i)rest[i]=4;
            for(int i=0;i<5;++i)
            {
                scanf("%s",s);
                a[i][0]=getrank(s[0]);
                --rest[a[i][0]];
                a[i][1]=getsuit(s[1]);
            }
            memset(tot, 0, sizeof(tot));
            memset(score, 0, sizeof(score));
            search(0,1,0);
            double ans = 0.;
            for (int  i = 0; i < (1<<5); ++ i)
                if (tot[i]) {
                    ans = max(ans, (double)score[i] / (double)tot[i]);
                }
            printf("%.8f\n",ans);
        }
    }
    return 0;
}
