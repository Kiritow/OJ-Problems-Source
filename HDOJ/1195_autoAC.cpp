#include<iostream>
#include<queue>
using namespace std;
struct note
{
    int num[4];
    int count;      
};
bool mark[10][10][10][10] = { false };
void bfs(note dd, note b1)
{
    queue <note> q;
    note now, next;
    now = dd;
    now.count = 0;
    q.push(now);
    while (!q.empty())
    {
        now = q.front();   
        q.pop();
        if (now.num[0] == b1.num[0] && now.num[1] == b1.num[1] && now.num[2] == b1.num[2] && now.num[3] == b1.num[3])
        {
            cout << now.count << endl;  
            return;
        }
        for (int i = 0; i<4; i++)
        {
            next = now;
            next.num[i]++;         
            if (next.num[i] == 10)
                next.num[i] = 1;
            if (mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] != true)
            {
                mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = true;
                next.count++;
                q.push(next);
            }
        }
        for (int i = 0; i<4; i++)
        {                                    
            next = now;
            next.num[i]--;
            if (next.num[i] == 0)
                next.num[i] = 9;
            if (mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] != true)
            {
                mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = true;
                next.count++;
                q.push(next);
            }
        }
        for (int i = 0; i<3; i++)
        {
            next = now;
            int temp = next.num[i];             
            next.num[i] = next.num[i + 1];
            next.num[i + 1] = temp;
            if (mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] != true)
            {
                mark[next.num[0]][next.num[1]][next.num[2]][next.num[3]] = true;
                next.count++;
                q.push(next);
            }
        }
    }
}
int main()
{
    int size;
    cin >> size;
    for (int i = 0; i<size; i++)
    {
        memset(mark, false, sizeof(mark));
        int a, b;
        cin >> a >> b;
        note a1, b1;
        for (int i = 3; i >= 0; i--)
        {
            a1.num[i] = a % 10;           
            a /= 10;
            b1.num[i] = b % 10;
            b /= 10;
        }
        bfs(a1, b1);
    }
}
