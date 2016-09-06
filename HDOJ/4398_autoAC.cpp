#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
#include<queue>
#include<map>
#include<set>
using namespace std;
const int MAXN=100010;
int Ti[MAXN];
int ne[MAXN];
map<int,int>mp;
struct Node
{
    int next_id;
    int ti;
};
struct classcomp
{
    bool operator()(const Node &a,const Node &b)const
    {
        return a.next_id<b.next_id;
    }
};
multiset<Node,classcomp>T_info;
multiset<Node>::iterator it_n;
set<int>Te;
set<int>::iterator it;
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)==2)
    {
        for(int i=1;i<=n;i++)
          scanf("%d",&Ti[i]);
        mp.clear();
        for(int i=n;i>=1;i--)
        {
            if(mp[Ti[i]])
               ne[i]=mp[Ti[i]];
            else ne[i]=n+1;
            mp[Ti[i]]=i;
        }
        Te.clear();
        T_info.clear();
        for(int i=1;i<=m;i++)
        {
            if(!mp[i])mp[i]=n+1;
            Node temp;
            temp.next_id=mp[i];
            temp.ti=i;
            T_info.insert(temp);
            Te.insert(i);
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            it=Te.find(Ti[i]);
            if(it!=Te.end())
            {
                Node temp;
                temp.next_id=i;
                temp.ti=Ti[i];
                T_info.erase(temp);
                temp.next_id=ne[i];
                T_info.insert(temp);
            }
            else
            {
                ans++;
                it_n=T_info.end();
                it_n--;
                if(ne[i]<(*it_n).next_id)
                {
                    Te.erase((*it_n).ti);
                    T_info.erase(it_n);
                    Te.insert(Ti[i]);
                    Node temp;
                    temp.next_id=ne[i];
                    temp.ti=Ti[i];
                    T_info.insert(temp);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
