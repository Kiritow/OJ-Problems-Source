#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<set>
#include<map>
using namespace std;
struct course
{
    int cap;
    set<int> times;
}tempc;
struct student
{
    set<string> cou;
    set<int> times;
}temps;
map<string,student> maps;
map<string,course> mapc;
map<string,int> ct;
struct request
{
    string s,c;
    int idx;
}re[500];
bool check(int x)
{
    map<string,student>::iterator its=maps.find(re[x].s);
    map<string,course>::iterator itc=mapc.find(re[x].c);
    if(itc->second.cap<=0) return false;
    if(its->second.cou.count(re[x].c)!=0) return false;
    for(set<int>::iterator it=itc->second.times.begin();it!=itc->second.times.end();++it)
    {
        if(its->second.times.count(*it)!=0) return false;
    }
    for(set<int>::iterator it=itc->second.times.begin();it!=itc->second.times.end();++it)
    {
        its->second.times.insert(*it);
    }
    (its->second.cou.insert(re[x].c));
    (itc->second.cap)--;
    return true;
}
bool cmp(const request &a,const request &b)
{
    if(ct[a.c]<ct[b.c]) return true;
    else if(ct[a.c]>ct[b.c]) return false;
    else return a.idx<b.idx;
}
int main()
{
    int n,m,r,t,x;
    char s[150],c[150];
    for(int cas=1;~scanf("%d%d%d",&n,&m,&r);++cas)
    {
        mapc.clear();
        maps.clear();
        ct.clear();
        temps.cou.clear();
        temps.times.clear();
        for(int i=0;i<n;++i)
        {
            scanf("%s",s);
            maps.insert(make_pair(string(s),temps));
        }
        for(int i=0;i<m;++i)
        {
            tempc.times.clear();
            scanf("%s",s);
            scanf("%d",&tempc.cap);
            scanf("%d",&t);
            for(;t--;)
            {
                scanf("%d",&x);
                tempc.times.insert(x);
            }
            mapc.insert(make_pair(string(s),tempc));
            ct.insert(make_pair(string(s),i));
        }
        for(int i=0;i<r;++i)
        {
            scanf("%s%s",s,c);
            re[i].s=string(s);
            re[i].c=string(c);
            re[i].idx=i;
        }
        sort(re,re+r,cmp);
        int ans=0;
        for(int i=0;i<r;++i)
            if(check(i))
               ans++;
        printf("Case %d: %d\n",cas,ans);
    }
    return 0;
}
