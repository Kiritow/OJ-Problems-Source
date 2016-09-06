#include <iostream>  
#include <cstdio>  
#include <cstring>  
#include <cstdlib>  
#include <algorithm>  
#include <sstream>  
#include <map>  
#include <cctype>  
using namespace std;  
struct Item {  
    int prz, typ, num;  
    int tn;  
    int us[65][2];  
}a[110];  
struct Name {  
    char name[20];  
    bool operator < (const Name &b) const {  
        return strcmp(name, b.name) == -1;  
    }  
}b;  
map <Name, int> mmap;  
map <Name, int>::iterator it;  
int id, fg;  
int n;  
char s[10000], ch, bf[1000];  
int cnt, gold, p;  
int main(void) {  
    int cas = 0;  
    while (~scanf("%d", &n)) {  
        mmap.clear();  
        cnt = gold = 0;  
        fg = 0;  
        cas++;  
        while (n--) {  
            scanf("%s", b.name);  
            it = mmap.find(b);  
            if (it == mmap.end()) {  
                mmap.insert(pair<Name, int>(b, fg++));  
                id = fg - 1;  
            } else  
                id = it->second;  
            scanf("%d", &a[id].prz);  
            a[id].typ = 0;  
            a[id].num = a[id].tn = 0;  
        }  
        scanf("%d", &n);  
        while (n--) {  
            scanf("%s", b.name);  
            it = mmap.find(b);  
            if (it == mmap.end()) {  
                mmap.insert(pair<Name, int>(b, fg++));  
                id = fg - 1;  
            } else  
                id = it->second;  
            scanf("%d", &a[id].prz);  
            a[id].typ = 1;  
            a[id].num = a[id].tn = 0;  
            getchar();  
            cin.getline(s, 10000);  
            stringstream ss(s);  
            while (ss >> b.name) {  
                it = mmap.find(b);  
                if (it == mmap.end()) {  
                    mmap.insert(pair<Name, int>(b, fg++));  
                    it = mmap.find(b);  
                }  
                a[id].us[a[id].tn][0] = it->second;  
                ss >> a[id].us[a[id].tn][1] >> bf;  
                a[id].tn++;  
            }  
        }  
        scanf("%d", &n);  
        while (n--) {  
            scanf("%s", b.name);  
            it = mmap.find(b);  
            if (it == mmap.end()) {  
                mmap.insert(pair<Name, int>(b, fg++));  
                id = fg - 1;  
            } else  
                id = it->second;  
            scanf("%d", &a[id].prz);  
            a[id].typ = 2;  
            a[id].num = a[id].tn = 0;  
        }  
        scanf("%d", &n);  
        while (n--) {  
            //cout << "Gold = " << gold << endl;  
            scanf("%s", s);  
            if (isdigit(s[1])) {  
                p = 0;  
                for (int i = 1; s[i] != 0; i++)  
                    p = p*10 + s[i] - 48;  
                if (s[0] == '+')  
                    gold += p;  
                else if (gold >= p)  
                    gold -= p;  
            } else {  
                sscanf(s+1, "%s", b.name);  
                it = mmap.find(b);  
                if (it == mmap.end())  
                    continue;  
                id = it->second;  
                if (s[0] == '+') {  
                    if (a[id].typ == 0 && cnt < 6 && gold >= a[id].prz) {  
                        a[id].num++;  
                        cnt++;  
                        gold -= a[id].prz;  
                    } else if (a[id].typ == 2 && cnt < 6 && gold >= a[id].prz) {  
                        if (a[id].num == 0) cnt++;  
                        a[id].num++;  
                        gold -= a[id].prz;  
                    } else if (a[id].typ == 1 && gold >= a[id].prz) {  
                        bool flag = 1;  
                        int grid = 1;  
                        for (int i = 0; i < a[id].tn && flag; i++) {  
                            if (a[a[id].us[i][0]].num < a[id].us[i][1])  
                                flag = 0;  
                            else  
                                grid -= a[id].us[i][1];  
                        }  
                        if (flag && cnt + grid <= 6) {  
                            gold -= a[id].prz;  
                            cnt += grid;  
                            a[id].num++;  
                            for (int i = 0; i < a[id].tn; i++)  
                                a[a[id].us[i][0]].num -= a[id].us[i][1];  
                        }  
                    }  
                } else if (a[id].num != 0) {  
                    if (a[id].typ == 0) {  
                        cnt--;  
                        a[id].num--;  
                        gold += a[id].prz;  
                    } else if (a[id].typ == 1) {  
                        cnt--;  
                        a[id].num--;  
                        int cost = a[id].prz;  
                        for (int i = 0; i < a[id].tn; i++)  
                            cost += a[id].us[i][1] * a[a[id].us[i][0]].prz;  
                        gold += cost;  
                    } else {  
                        cnt--;  
                        gold += a[id].prz * a[id].num;  
                        a[id].num = 0;  
                    }  
                }  
            }  
        }  
        printf("Case %d:\n%d\n%d\n", cas, gold, cnt);  
        for (it = mmap.begin(); it != mmap.end(); it++) {  
            for (int i = 0; i < a[it->second].num; i++) {  
                if (a[it->second].typ != 2)  
                    printf("%s: 1\n", (it->first).name);  
                else {  
                    printf("%s: %d\n", (it->first).name, a[it->second].num);  
                    break;  
                }  
            }  
        }  
        printf("\n");  
    }  
    return 0;  
}
