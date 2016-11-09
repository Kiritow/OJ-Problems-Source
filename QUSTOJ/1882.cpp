#include <iostream>
#include <stack>
using namespace std;
int ans[1024];
int main()
{
    int n,m;
    cin>>n>>m;
    while(n--)
    {
        stack<int> s;
        int nextTrain=1;
        for(int i=0;i<m;i++)
        {
            cin>>ans[i];
        }
        int flag=1;
        for(int i=0;i<m;i++)
        {
            int target=ans[i];
            if(s.empty())
            {
                if(nextTrain<m+1)
                {
                    s.push(nextTrain);
                    ++nextTrain;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
            while(s.top()!=target)
            {
                if(nextTrain<m+1)
                {
                    s.push(nextTrain);
                    ++nextTrain;
                }
                else
                {
                    flag=0;
                    break;
                }
            }
            if(!flag) break;
            s.pop();
        }
        cout<<(flag?"Yes":"No")<<endl;
    }
    return 0;
}
