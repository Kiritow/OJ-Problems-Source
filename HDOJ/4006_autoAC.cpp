#include<queue>
#include<iostream>
#include<vector>
using namespace std;
struct mycmp
{
    bool operator()(const int &a,const int &b)
    {
        return a>b;
    }
};
int main()
{
    int n,k,val;
    char str[5];
    int count;
    while(scanf("%d%d",&n,&k)!=EOF)
    {
        priority_queue<int,vector<int>,mycmp> pq;
        while(n--)
        {
            scanf("%s",str);
            if(str[0]=='I')
            {
                scanf("%d",&val);
                pq.push(val);
                while(pq.size()>k)
                    pq.pop();
            }
            else 
            {
                printf("%d\n",pq.top());
            }
        }
    }
    return 0;
}
