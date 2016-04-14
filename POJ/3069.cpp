#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int R,N,cnt;
vector<int> X;

int find_target(int StartPoint,int range)
{
    if(StartPoint==N-1)
    {
        return N-1;
    }
    for(;StartPoint<N;StartPoint++)
    {
        if(X[StartPoint]<=range)
        {
            continue;
        }
        else
        {
            return StartPoint-1;
        }
    }
    /// StartPoint==N
    return N-1;
}

int find_next(int StartPoint,int Range)
{
    if(StartPoint==N-1)
    {
        return N;
    }
    for(;StartPoint<N;StartPoint++)
    {
        if(X[StartPoint]<=Range)
        {
            continue;
        }
        else
        {
            return StartPoint;
        }
    }
    return N;

}

int main()
{
    while(scanf("%d %d",&R,&N)==2&&(N!=-1&&R!=-1))
    {
        X.clear();
        for(int i=0; i<N; i++)
        {
            int tmp;
            scanf("%d",&tmp);
            X.push_back(tmp);
        }
        sort(X.begin(),X.end());
        cnt=0;

        int point=0;
        while(point<N)
        {
            int range=X[point]+R;
            int ans=find_target(point,range);
            if(ans==point)
            {
                /// light this point : point
                cnt++;
                point=find_next(point,X[point]+R);
                continue;
            }
            else if(ans==-1)
            {
                break;
            }
            else
            {
                /// light target point : ans
                cnt++;
                point=ans;
            }
            range=X[point]+R;
            point=find_next(point,range);
        }

        printf("%d\n",cnt);
    }
    return 0;
}
