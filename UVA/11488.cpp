#include <cstdio>
#include <cstring>
#include <cstdlib>

#include <algorithm>
using namespace std;
#define MAXN 200100
/// MAXN nodes, 2 status.
/// tree[i][j]:= next node when tree is at [i] with status j.
int tree[MAXN][2];
int val[MAXN];
int nextnode=2;
char buffer[1024];
int ans=-1;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(val,0,sizeof(val));
        memset(tree,0,sizeof(tree));
        nextnode=2;
        ans=-1;

        int n;
        scanf("%d%*c",&n);
        while(n--)
        {
            gets(buffer);
            char* p=buffer;
            int pos=1;
            int L=0;
            while((*p)-'0'>=0)
            {
                if(tree[pos][*p-'0']==0)
                {
                    tree[pos][*p-'0']=nextnode++;
                }
                pos=tree[pos][*p-'0'];
                p++;
                val[pos]++;
                ans=max(ans,(L+1)*val[pos]);
                //printf("L+1 * val[pos]=%d*%d=%d (pos=%d)\n",L+1,val[pos],(L+1)*val[pos],pos);
                L++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
/*
1
4
0000
0001
10101
010
*/
