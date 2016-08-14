#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int n,deep;
char c[10] = "ACGT";
struct node
{
    char s[10];
    int len;
} a[10];
int pos[10];
int get_h()
{
    int ans = 0;
    for(int i = 1; i<=n; i++)
        ans = max(ans,a[i].len-pos[i]);
    return ans;
}
int dfs(int step)
{
    if(step+get_h()>deep)
        return 0;
    if(!get_h())
        return 1;
    int i,j;
    int tem[10];
    for(i = 0; i<4; i++)
    {
        int flag = 0;
        for(j = 1; j<=n; j++)
            tem[j] = pos[j];
        for(j = 1; j<=n; j++)
        {
            if(a[j].s[pos[j]] == c[i])
            {
                flag = 1;
                pos[j]++;
            }
        }
        if(flag)
        {
            if(dfs(step+1))
                return 1;
            for(j = 1; j<=n; j++)
                pos[j] = tem[j];
        }
    }
    return 0;
}
int main()
{
    int t,i,j,maxn;
    cin >> t;
    while(t--)
    {
        cin>>n;
        maxn = 0;
        for(i = 1; i<=n; i++)
        {
            cin>>a[i].s;
            a[i].len = strlen(a[i].s);
            maxn = max(maxn,a[i].len);
            pos[i] = 0;
        }
        deep = maxn;
        while(1)
        {
            if(dfs(0))break;
            deep++;
        }
        cout << deep << endl;
    }
    return 0;
}
