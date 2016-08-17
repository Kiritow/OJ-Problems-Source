#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
struct P
{
    int x;
    int y;
    P() {}
    P(int xx, int yy):x(xx), y(yy) {}
};
bool operator < (P p1, P p2)
{
    if (p1.x == p2.x)
    {
        return p1.y < p2.y;
    }
    return p1.x < p2.x;
}
class cmp1
{
    public:
        bool operator()(const P& left, const P& right)
        {
            if (left.y == right.y)
            {
                return left.x < right.x;
            }
            return left.y < right.y;
        }
};
class cmp2
{
    public:
        bool operator()(const P& left, const P& right)
        {
            if (left.x == right.x)
            {
                return left.y < right.y;
            }
            return left.x > right.x;
        }
};
P p1[100005];
P p2[100005];
int h, v;
void gao(P p2[], int v, vector <P> &vec)
{
        sort(p2+1, p2+1+v);
        int pt = v;
        vec.push_back(p2[v]);
        for (int i = v-1; i >= 1; i--)
        {
            if (p2[i].x < p2[pt].x && p2[i].y > p2[pt].y)
            {
                vec.push_back(p2[i]);
                pt = i;
            }
        }
}
int main()
{
 int T;
 scanf("%d", &T);
 for (int cas = 1; cas <= T; cas++)
 {
     scanf("%d%d", &h, &v);
     for (int i = 1; i <= h; i++)
     {
         scanf("%d%d", &p1[i].x, &p1[i].y);
     }
     for (int i = 1; i <= v; i++)
     {
         scanf("%d%d", &p2[i].x, &p2[i].y);
     }
     vector <P> v1;
     vector <P> v2;
        gao(p1, h, v1);
        gao(p2, v, v2);
        int cnt = 0;
        int t = 0;
        int size = (int)v1.size();
        for (int i = 0; i < (int)v2.size(); i++)
        {
            if (t == size) break;
            if (i == (int)v2.size()-1)
            {
                cnt++;
                break;
            }
            if (v1[t].x > v2[i+1].x)
            {
                cnt++;
                while (t < size && v1[t].y <= v2[i].y)
                {
                    t++;
                }
            }
        }
        printf("%d\n", cnt);
 }
 return 0;
}
