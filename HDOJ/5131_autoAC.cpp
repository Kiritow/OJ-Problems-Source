#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <cmath>
#include <iomanip>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cctype>
using namespace std;
#define ll long long
const int maxn=202;
struct P
{
    string name;
    int k;
}p[maxn];
bool cmp(P a,P b)
{
    if(a.k>b.k)
        return true;
    else if(a.k==b.k)
    {
        if(a.name<b.name)
            return true;
        return false;
    }
    return false;
}
int n;
map<string,int>mp;
void find(string str)
{
    int major=1;
    int minor=1;
    for(int i=1;i<=n;i++)
    {
        if(p[i].name==str)
        {
            break;
        }
        if(p[i].k>mp[str])
            major++;
        if(p[i].k==mp[str])
            minor++;
    }
    cout<<major;
    if(minor!=1)
        cout<<" "<<minor<<endl;
    else
        cout<<endl;
}
int main()
{
    while(cin>>n&&n)
    {
        mp.clear();
        for(int i=1;i<=n;i++)
            cin>>p[i].name>>p[i].k;
        sort(p+1,p+1+n,cmp);
        for(int i=1;i<=n;i++)
        {
            cout<<p[i].name<<" "<<p[i].k<<endl;
            mp[p[i].name]=p[i].k;
        }
        int q;
        string str;
        cin>>q;
        while(q--)
        {
            cin>>str;
            find(str);
        }
    }
    return 0;
}
