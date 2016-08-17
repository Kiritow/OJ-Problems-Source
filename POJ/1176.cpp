#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define MAXN 128
int N,C;
int a[MAXN];

void proca()
{
    for(int i=1;i<=N;i++)
        a[i]=!a[i];
}
void procb()
{
    for(int i=1;i<=N;i+=2)
        a[i]=!a[i];
}
void procc()
{
    for(int i=2;i<=N;i+=2)
        a[i]=!a[i];
}
void procd()
{
    for(int i=1;i<=N;i+=3)
        a[i]=!a[i];
}
int isopen[MAXN];
int isclose[MAXN];
bool check()

{
    /// check
    for(int i=1;i<=N;i++)
    {
        if(isopen[i]&&a[i]!=1) return false;
        if(isclose[i]&&a[i]!=0) return false;
    }
    return true;
}
vector<string> ans;
void DFS(int step)
{
    if(step==C)
    {
        if(check())
        {
            string s;
            for(int i=1;i<=N;i++)
            {
                s.push_back(a[i]+'0');
            }
            ans.push_back(s);
        }
        return;
    }
    proca();
    DFS(step+1);
    proca();

    procb();
    DFS(step+1);
    procb();

    procc();
    DFS(step+1);
    procc();

    procd();
    DFS(step+1);
    procd();
}
int main()
{
    /// Input Start
    scanf("%d",&N);
    scanf("%d",&C);
    if(C>4) C=4-C%2;
    int tmp;
    while(scanf("%d",&tmp)==1&&tmp!=-1) isopen[tmp]=1;
    while(scanf("%d",&tmp)==1&&tmp!=-1) isclose[tmp]=1;
    for(int i=1;i<=N;i++) /// 1 ON , 0 OFF
    {
        a[i]=1;
    }
    DFS(0);
    sort(ans.begin(),ans.end());
    printf("%s\n",ans.at(0).c_str());
    int last=0;
    for(size_t i=1;i<ans.size();i++)
    {
        if(ans.at(i)!=ans.at(last))
        {
            printf("%s\n",ans.at(i).c_str());
            last=i;
        }
    }
    return 0;
}
