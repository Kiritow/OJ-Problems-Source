#include<cstdio>
#include<vector>
using namespace std;
namespace
{
    vector<pair<pair<int, int>, pair<int, int> > > V;
    void init()
    {
        V.push_back(make_pair(make_pair(1, 5), make_pair(1, 6)));
        V.push_back(make_pair(make_pair(2, 10), make_pair(2, 11)));
        V.push_back(make_pair(make_pair(3, 16), make_pair(3, 17)));
        V.push_back(make_pair(make_pair(4, 21), make_pair(4, 22)));
        V.push_back(make_pair(make_pair(5, 27), make_pair(5, 28)));
        V.push_back(make_pair(make_pair(6, 32), make_pair(6, 33)));
        V.push_back(make_pair(make_pair(7, 38), make_pair(7, 39)));
        V.push_back(make_pair(make_pair(8, 43), make_pair(8, 44)));
        V.push_back(make_pair(make_pair(9, 48), make_pair(9, 49)));
        V.push_back(make_pair(make_pair(10, 54), make_pair(10, 55)));
    }
    bool before(int h1, int m1, int h2, int m2)
    {
        if (h1 != h2)
            return h1 < h2;
        else
            return m1 <= m2;
    }
    int pass(int bh, int bm, int eh, int em)
    {
        int total = 0;
        for (size_ i = 0; i < V.size(); i++)
        {
            pair<int, int> &begin = V[i].first;
            pair<int, int> &end = V[i].second;
            if (before(bh, bm, begin.first, begin.second)
                    && before(end.first, end.second, eh, em))
                total++;
        }
        return total;
    }
}
int main()
{
    init();
    int bh, bm, eh, em;
    puts("Program 3 by team X");
    puts("Initial time  Final time  Passes");
    while (scanf("%d%d%d%d", &bh, &bm, &eh, &em) != EOF)
    {
        bh %= 12;
        eh %= 12;
        int res;
        if (bh > eh || (bh == eh && bm > em))
            res = pass(bh, bm, 12, 0) + pass(0, 0, eh, em) + 1;
        else
            res = pass(bh, bm, eh, em);
        printf("       %02d:%02d       %02d:%02d%8d\n", bh ? bh : 12, bm,
                eh ? eh : 12, em, res);
    }
    puts("End of program 3 by team X");
    return 0;
}
