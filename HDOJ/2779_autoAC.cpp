#include<iostream>
#include<algorithm>
#include<functional>
#include<queue>
using namespace std;
bool flag[50];
struct time
{
    int start;
    int end;
    bool operator <(const time a)const
    {
        if(a.end==end)
            return a.start<start;
        return a.end<end;
    }
}now,temp;
int main()
{
    priority_queue<time>Q;
    int i,n,j=0,t;
    while(++j)
    {
        memset(flag,false,sizeof(flag));
        scanf("%d",&n);
        if(!n)
            return 0;
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&now.start,&now.end);
            now.start*=2,now.end*=2;
            Q.push(now);
        }
        now.start=now.end=8*2;
        int count=0;
        while(!Q.empty())
        {
            temp=Q.top();
            Q.pop();
            for(t=temp.start;t<=temp.end-1;t++)
                if(flag[t]==false)
                {
                    now.start=max(t,now.start+1);
                    flag[t]=true;
                    count++;
                    break;
                }
        }
        printf("On day %d Emma can attend as many as %d parties.\n",j,count);
    }
}
