#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <vector>
#include <algorithm>
using namespace std;

struct cash
{
    int value;
    int amount;
};

bool cmp(const cash& a,const cash& b)
{
    return a.value<b.value;
}

int need[64];
int makedayfrom(vector<cash>& vec,int C)
{
    memset(need,0,sizeof(int)*64);
    int N=vec.size();
    int left=C;
    for(int i=N-1;i>=0;i--)
    {//
        if(vec.at(i).amount>0&&left>0)
        {
            int x=left/vec.at(i).value;
            x=min(x,vec.at(i).amount);
            need[i]=x;
            left-=x*vec.at(i).value;
        }
    }
    if(left>0)
    {
        for(int i=0;i<N;i++)
        {
            if(vec.at(i).amount>need[i]&&left>0)
            {
                int x=left/vec.at(i).value;
                if(x==0)
                {
                    /// try to make x = 1
                    need[i]++;
                    left=0;
                    break;
                }
            }
        }
    }
    if(left>0)
    {
        return -1;
    }
    int canpayday=2<<29;
    for(int i=0;i<64;i++)
    {
        if(need[i]>0)
        {
            canpayday=min(canpayday,vec.at(i).amount/need[i]);
        }
    }
    if(canpayday<=0) return -1;
    for(int i=0;i<N;i++)
    {
        if(need[i]>0)
        {
            vec.at(i).amount-=canpayday*need[i];
        }
    }
    return canpayday;

}
int main()
{
    int N,C;
    scanf("%d %d",&N,&C);
    vector<cash> vec;
    int ans=0;
    for(int i=0;i<N;i++)
    {
        cash s;
        scanf("%d %d",&s.value,&s.amount);
        vec.push_back(s);
    }
    sort(vec.begin(),vec.end(),cmp);
    for(int i=N-1;i>=0;i--)
    {
        if(vec.at(i).value>=C)
        {
            ans+=vec.at(i).amount;
            vec.pop_back();
        }
        else break;
    }
    int tmp;
    while((tmp=makedayfrom(vec,C))>0)
    {
        ans+=tmp;
    }
    printf("%d\n",ans);
    return 0;
}
