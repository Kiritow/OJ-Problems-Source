#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <set>
#include <queue>
using namespace std;
typedef struct abcd
{
    int p,last;
} abcd;
abcd a[110000];
int flag[110000];
int main()
{
    int c,n,b,i,j,now,ans;
    while(~scanf("%d%d%d",&c,&n,&b))
    {
        for(i=0; i<n; i++)flag[i]=110000;
        for(i=0; i<b; i++)
            scanf("%d",&a[i].p);
        for(i=b-1; i>=0; i--)
        {
            a[i].last=flag[a[i].p];
            flag[a[i].p]=i;
        }
        ans=now=0;
        memset(flag,0,sizeof(flag));
        priority_queue<pair<int,int> > q;
        while(!q.empty())q.pop();
        for(i=0; i<b; i++)
        {
            if(now<c)
            {
                if(flag[a[i].p])
                {
                    q.push(make_pair(a[i].last,a[i].p));
                }
                else
                {
                    flag[a[i].p]=1;
                    now++;
                    ans++;
                    q.push(make_pair(a[i].last,a[i].p));
                }
            }
            else
            {
                if(flag[a[i].p])
                {
                    q.push(make_pair(a[i].last,a[i].p));
                }
                else
                {
                    ans++;
                    while(flag[q.top().second]==0)q.pop();
                    pair<int,int >t=q.top();
                    q.pop();
                    flag[a[i].p]=1;
                    flag[t.second]=0;
                    q.push(make_pair(a[i].last,a[i].p));
                }
            }
        }
        cout<<ans<<endl;
    }
}
