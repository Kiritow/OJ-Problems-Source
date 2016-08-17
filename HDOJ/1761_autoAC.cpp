#include <stdlib.h>
#include<stdio.h>
#include<string.h>
#include<string>
#include<iostream>
#include<map>
#include<vector>
using namespace std;
typedef map<string, int> STRING2MAP;
int main()
{
    int n, m;
    int i, j;
    int k;
    char name[25], like[25], hate[25], go[25];
    map<string, STRING2MAP> t_map;
    map<string, STRING2MAP>::iterator it_t;
    map<string, bool> t_now;
    map<string, bool>::iterator it_n;
    STRING2MAP::iterator it_f;
    STRING2MAP S2M;
    string t_add[101], t_remove[101];
    int p_add, p_remove;
    int h, l;
    int geted;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        t_map.clear();
        t_now.clear();
        for (i=0; i < n; i++)
        {
            scanf("%s", name);
            scanf("%d", &k);
            t_map[name] = S2M;
            it_t = t_map.find(name);
            for (j=0; j < k; j++)
            {
                scanf("%s", like);
                it_t->second.insert(STRING2MAP::value_type(like, 1));
            }
            scanf("%d", &k);
            for (j=0; j < k; j++)
            {
                scanf("%s", hate);
                it_t->second.insert(STRING2MAP::value_type(hate, 2));
            }
        }
        scanf("%d", &k);
        for (j=0; j < k; j++)
        {
            scanf("%s", go);
            t_now[go] = true;
        }
        for (i=0; i<m; i++)
        {
            p_add = 0;
            p_remove = 0;
            it_t=t_map.begin();
            for (; it_t != t_map.end(); it_t++)
            {
                it_n=t_now.begin();
                l=h=0;
                for (; it_n != t_now.end(); it_n++)
                {
                    it_f = it_t->second.find(it_n->first);
                    if (it_f != it_t->second.end())
                    {
                        geted = it_f->second;
                        if (geted & 1) l++;
                        if (geted & 1<<1) h++;
                        if (l>0 && h>0) break;
                    }
                }
                if (h == 0 && l > 0)
                    t_add[p_add++] = it_t->first;
                if (h > 0 && l == 0)
                    t_remove[p_remove++] = it_t->first;
            }
            if (p_remove == 0 && p_add == 0)
                break;
            for (j=0; j < p_remove; j++)
                t_now.erase(t_remove[j]);
            for (j=0; j <p_add; j++)
                t_now.insert(make_pair(t_add[j], true));
        }
        if (t_now.empty())
        {
            printf("None\n");
            continue;
        }
        it_n=t_now.begin();
        cout<< it_n->first;
        it_n++;
        for (; it_n != t_now.end(); it_n++)
            cout << " " << it_n->first;
        cout << endl;
    }
    return 0;
}
