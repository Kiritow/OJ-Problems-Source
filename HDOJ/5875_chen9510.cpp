// From http://www.cnblogs.com/chen9510/p/5862834.html
// ONLY For Test
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int A[100005];
int pos[100005];
int s[100005];

int main()
{
    int T,N,M;
    cin>>T;
    while(T--)
    {
        scanf("%d",&N);
        for(int i=1;i<=N;i++)
            scanf("%d",&A[i]);
        int num=1;
        A[N+1]=-1;
        s[1]=N+1;
        for(int i=N;i>=1;i--)///单调栈；
        {
            while(A[i]<A[s[num]]) num--;
            pos[i]=s[num];
            s[++num]=i;
        }
        scanf("%d",&M);
        while(M--)
        {
            int l,r;
            scanf("%d%d",&l,&r);
            int tmp=A[l];
            while(l<=r)
            {
                if(tmp==0) break;
                if(pos[l]>r) break;
                tmp=tmp%A[pos[l]];
                l=pos[l];
            }
            printf("%d\n",tmp);
        }
    }
    return 0;
}
