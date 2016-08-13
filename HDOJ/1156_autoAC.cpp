#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<string.h>
#include<map>
using namespace std;
struct node{
    int l, r, num;
};
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    else
        return p1.second < p2.second;
}
node nodes[2][500000];
vector<pair<int, int>> posp;
vector<int> posy;
map<int,int> pysum;
vector<int> posx[200010];
int ress;
vector<int> reso;
void init(int i,int l,int r)
{
    for (int j = 0; j < 2; j++)
    {
        nodes[j][i].l = l;
        nodes[j][i].r = r;
        nodes[j][i].num = 0;
    }
    if (l == r)
        return;
    else
    {
        int mid = (l + r) / 2;
        init(i * 2, l, mid);
        init(i * 2 + 1, mid+1, r);
    }
}
void update(int t,int i, int y,int k)//k:0-add,1-nim
{
    if (k == 0)
        nodes[t][i].num++;
    else
        nodes[t][i].num--;
    if (nodes[t][i].l == nodes[t][i].r)
        return;
    else
    {
        int mid = (nodes[t][i].l + nodes[t][i].r) / 2;
        if (posy[mid-1] >= y)
            update(t, i * 2, y,k);
        else
            update(t, i * 2 + 1, y,k);
    }
}
int query_down(int i, int y)
{
    if (posy[nodes[0][i].r-1] < y)
        return nodes[0][i].num;
    else if (nodes[0][i].l==nodes[0][i].r)
        return 0;
    else
    {
        int mid = (nodes[0][i].l + nodes[0][i].r) / 2;
        int res = query_down(i*2,y);
        if (y > posy[mid-1])
            res += query_down(i * 2 + 1, y);
        return res;
    }
}
int query_up(int i, int y)
{
    if (y < posy[nodes[1][i].l-1])
        return nodes[1][i].num;
    else if (nodes[1][i].l == nodes[1][i].r)
        return 0;
    else
    {
        int mid = (nodes[1][i].l + nodes[1][i].r) / 2;
        int res = query_up(i * 2 + 1, y);
        if (y <= posy[mid-1])
            res += query_up(i * 2, y);
        return res;
    }
}
int main()
{
    int n;
    while (cin >> n&&n)
    {
        posp.clear();
        posy.clear();
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            posp.push_back(make_pair(x,y));
            posy.push_back(y);
        }
        sort(posp.begin(), posp.end(),cmp);
        sort(posy.begin(), posy.end());
        int cx = posp[0].first;
        int mx = 0;
        for (int i = 0; i < n; i++)
            posx[i].clear();
        pysum.clear();
        for (int i = 0; i < n; i++)
        {
            if (posp[i].first != cx)
            {
                mx++;
                cx = posp[i].first;
            }
            posx[mx].push_back(posp[i].second);
            pysum[posp[i].second]++;
        }
        vector<int>::iterator i=unique(posy.begin(), posy.end());
        posy.erase(i, posy.end());
        init(1, 1, posy.size());
        for (int i = 0; i < n; i++)
            update(1, 1, posp[i].second, 0);
        ress = -1;
        reso.clear();
        for (int i = 0; i <= mx; i++)
        {
            int tress = 999999, treso = -1;
            for (int j = 0; j < posx[i].size(); j++)
                update(1, 1, posx[i][j], 1);
            for (int j = 0; j < posx[i].size(); j++)
            {
                int ld = query_down(1, posx[i][j]);
                int ru = query_up(1, posx[i][j]);
                if (tress > ld + ru)
                    tress = ld + ru;
                treso=max(treso,int(n - tress - pysum[posx[i][j]] - posx[i].size() + 1));
            }
            for (int j = 0; j < posx[i].size(); j++)
                update(0, 1, posx[i][j], 0);
            if (tress > ress)
            {
                ress = tress;
                reso.clear();
                reso.push_back(treso);
            }
            else if (tress == ress)
            {
                reso.push_back(treso);
            }
        }
        cout << "Stan: " << ress << "; Ollie:";
        sort(reso.begin(), reso.end());
        vector<int>::iterator j=unique(reso.begin(), reso.end());
        reso.erase(j, reso.end());
        for (int i = 0; i < reso.size(); i++)
        {
            cout <<" "<<reso[i];
        }
        cout << ";" << endl;
    }
    return 0;
}
