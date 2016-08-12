#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
bool used[1510];
int con[1510];
vector<int> edges[1510];
bool find(int x)
{
    for (int i = 0; i < edges[x].size(); i++)
    {
        if (!used[edges[x][i]])
        {
            used[edges[x][i]] = true;
            if (con[edges[x][i]] == -1 || find(con[edges[x][i]]))
            {
                con[edges[x][i]] = x;
                return true;
            }
        }
    }
    return false;
}
int match(int n)
{
    int res = 0;
    memset(con, -1, sizeof(con));
    for (int i = 0; i < n; i++)
    {
        memset(used, false, sizeof(used));
        if (find(i))
            res++;
    }
    return res;
}
int main()
{
    int n;
    while (cin >> n)
    {
        memset(used, false, sizeof(used));
        for (int i = 0; i < n; i++)
            edges[i].clear();
        for (int i = 0; i < n; i++)
        {
            int no;
            cin >> no;
            char c;
            cin >> c >> c;
            int en;
            cin >> en >> c;
            for (int j = 0; j < en; j++)
            {
                int p;
                cin >> p;
                edges[no].push_back(p);
                edges[p].push_back(no);
            }
        }
        cout << (match(n)/2) << endl;
    }
    return 0;
}
