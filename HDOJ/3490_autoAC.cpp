#include <cstdio>
#include <cstring>
#include <string>
#include <map>
#include <algorithm>
using namespace std;
 map<string, pair<int, int> > ms;
 map<int, int> s1, s2;
 int n;
 inline int calc(map<int, int>& s) {
     map<int, int>::iterator ib = s.begin(), ie = s.end();
     return (--ie)->first - ib->first;
 }
 inline void erase(map<int, int> &s, int x) {
     if (--s[x] == 0)
         s.erase(x);
 }
 int main() {
     int test;
     scanf("%d", &test);
     for (int cas = 1; cas <= test; ++cas) {
         ms.clear(); s1.clear(); s2.clear();
         scanf("%d", &n);
         for (int i = 0; i < n; ++i) {
             int opt; char buf[100];
             scanf("%d%s", &opt, buf);
             if (opt == 1) {
                 int x, y;
                 scanf("%d%d", &x, &y);
                 ms[buf] = pair<int, int>(x, y);
                 s1[x - y]++; s2[x + y]++;
             } else {
                 map<string, pair<int, int> >::iterator it = ms.find(buf);
                 erase(s1, it->second.first - it->second.second);
                 erase(s2, it->second.first + it->second.second);
                 ms.erase(it);
             }
             if (ms.size() == 0)
                 puts("-1");
             else
                 printf("%d\n", max(calc(s1), calc(s2)));
         }
         putchar('\n');
     }
     return 0;
 }
