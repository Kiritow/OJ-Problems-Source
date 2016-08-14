#include <iostream>
#include <cstring>
#include <string>
#include <vector>
using namespace std;
vector<int> card[100];
int n;
bool vis[100];
int link[100];
int num_pre(char a)
{
    static string pre = "23456789TJQKA";
    for(int i = 0;i < pre.size();i ++)
    {
        if(a == pre.at(i))
            return i;
    }
    return pre.size();
}
int num_suf(char a)
{
    static string suf = "CDSH";
    for(int i = 0;i < suf.size();i ++)
    {
        if(a == suf.at(i))
            return i;
    }
    return suf.size();
}
bool is_big(const string& a,const string& b)
{
    int aa = num_pre(a.at(0));
    int bb = num_pre(b.at(0));
    if(aa == bb)
        return num_suf(a.at(1)) > num_suf(b.at(1));
    return aa > bb;
}
bool can(int x)
{
    int len = card[x].size();
    for(int i = 0;i < len;i ++)
    {
        int t = card[x].at(i);
        if(!vis[t])
        {
            vis[t] = true;
            if(link[t] == -1 || can(link[t]))
            {
                link[t] = x;
                return true;
            }
        }
    }
    return false;
}
int maxmatch()
{
    int num = 0;
    for(int i = 0;i < n;i ++)
    {
        memset(vis,false,sizeof(vis));
        if(can(i))
            num ++;
    }
    return num;
}
int main()
{
    int cas;
    cin >> cas;
    while(cas --)
    {
        cin >> n;
        memset(link,-1,sizeof(link));
        for(int i = 0;i < n;i ++)
        {
            card[i].clear();
        }
        string ss[100];
        for(int i = 0;i < n;i ++)
        {
            cin >> ss[i];
        }
        string ee;
        for(int i = 0;i < n;i ++)
        {
            cin >> ee;
            for(int j = 0;j < n;j ++)
            {
                if(is_big(ee,ss[j]))
                    card[j].push_back(i);
            }
        }
        printf("%d\n",maxmatch());
    }
    return 0;
}
