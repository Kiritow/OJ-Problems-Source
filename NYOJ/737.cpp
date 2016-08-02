/**石子合并*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;

#define dprintf(format,args...)

const int INF = 0x3f3f3f3f;
const int NINF = -INF -1;

#define MAXN 10000

/**
inline void show(vector<int>& s)
{
    printf("Stone: ");
    for(auto& i:s)
    {
        printf("%d ",i);
    }
    printf("\n");
}
//*/

#define show(s)

void solve(int n)
{
    vector<int> stone;
    stone.push_back(INF);
    for(int i=0;i<n;i++)
    {
        int tmp;
        scanf("%d",&tmp);
        stone.push_back(tmp);
    }
    stone.push_back(INF);

    dprintf("Init:\n");show(stone);

    int sum=0;
    while(stone.size()>3)
    {
        int k;
        for(k=1;k<stone.size()-1;k++)
        {
            if(stone[k-1]<=stone[k+1])
            {
                break;
            }
        }

        dprintf("Before deletion :\n");show(stone);

        int tmp=stone[k-1]+stone[k];
        sum+=tmp;
        k--;
        stone.erase(stone.begin()+k);
        stone.erase(stone.begin()+k);

        dprintf("After deletion: \n");show(stone);

        for(int i=k-1;i>=0;i--)
        {
            if(stone[i]>=tmp)
            {
                stone.insert(stone.begin()+i+1,tmp);
                dprintf("After Insertion :\n");show(stone);
                break;
            }
        }
    }
    printf("%d\n",sum);
}

int main()
{
    int n;
    while(scanf("%d",&n)==1&&n!=0) solve(n);
    return 0;
}
