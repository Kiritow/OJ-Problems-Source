#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <cmath>
#include <string.h>
using namespace std;
int N;
long long T;
long long a[100005];

int calc(int k)
{
    queue<long long>q;
    int pos=0;
    long long sum=0;
    if((N-1)%(k-1)!=0&&N>k) ///如果不能k个k个合并到底，则先合并筹不足k个的；
    {
        pos=(N-1)%(k-1)+1;
        for(int i=0;i<pos;i++)  sum+=a[i];
        q.push(sum);
    }
    while(1)
    {
        long long sum2=0;
        for(int i=0; i<k; i++)
        {
            if(!q.empty())
            {
                if(pos<N&&q.front()>a[pos])
                {
                    sum2+=a[pos];
                    sum+=a[pos];
                    pos++;
                }
                else
                {
                    sum2+=q.front();
                    sum+=q.front();
                    q.pop();
                }
            }
            else if(pos<N)
            {
                sum2+=a[pos];
                sum+=a[pos];
                pos++;
            }
            else goto endw;
        }
        if(sum>T) return 0;
        if(pos<N||!q.empty())
        q.push(sum2);
    }
    endw:;
    if(sum<=T) return 1;
    else    return 0;
}

int main()
{
    int to;
    scanf("%d",&to);
    while(to--)
    {
        scanf("%d%lld",&N,&T);
        for(int i=0; i<N; i++)
            scanf("%lld",&a[i]);
        sort(a,a+N);
        int l=2,r=N,mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            int f=calc(mid);
            if(f==0) l=mid+1;
            else     r=mid-1;
        }
        printf("%d\n",l);
    }
    return 0;
}
