#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct stone{int pos , dis;};
struct compare
{
    bool operator() (const stone & s1 , const stone & s2)
    {
        if(s1.pos != s2.pos){return s1.pos > s2.pos;}
        return s1.dis > s2.dis;
    }
};
int main()
{
    int t;
    cin >> t;
    while(t --)
    {
        int n;
        cin >> n;
        priority_queue<stone , vector<stone> , compare> record;
        for(int i = 1; i <= n; ++i)
        {
            stone s;
            cin >> s.pos >> s.dis;
            record.push(s);
        }
        int cnt = 1;
        while(!record.empty())
        {
            stone t = record.top();
            record.pop();
            if(cnt % 2)
            {
                t.pos += t.dis;
                record.push(t);
            }
            if(record.empty()){cout << t.pos << endl;}
            ++cnt;
        }
    }
    return 0;
}
