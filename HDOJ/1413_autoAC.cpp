#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int FILEE = 0, DIR = 1;
char createRes[2][30] = { "file already exist", "directory already exist" };
char delRes[2][30] = { "no such file", "can not delete the directory" };
struct F {
    int head, next, type, fa;
    string name;
    F() {
    }
    F(int h, int n, int t, int f, string s) :
            head(h), next(n), type(t), fa(f), name(s) {
    }
};
int tot, cur;
vector<F> V;
void cd(const char *com) {
    int i = 1;
    if (!strcmp(com, "\\")) {
        cur = 0;
    } else if (!strcmp(com, "..")) {
        cur = V[cur].fa;
    } else {
        for (i = V[cur].head; i > 0; i = V[i].next) {
            if (V[i].type == DIR && !strcmp(V[i].name.c_str(), com)) {
                cur = i;
                break;
            }
        }
    }
    puts(i ? "success" : "no such directory");
}
void create(const char *com, int type) {
    int i = 1;
    if (!strcmp(com, "\\")) {
    } else if (!strcmp(com, "..")) {
    } else {
        for (i = V[cur].head; i > 0; i = V[i].next) {
            if (V[i].type == type && !strcmp(V[i].name.c_str(), com)) {
                break;
            }
        }
        if (!i) {
            V.push_back(F(0, V[cur].head, type, cur, com));
            V[cur].head = tot++;
        }
    }
    puts(i ? createRes[type] : "success");
}
void del(const char *com, int type) {
    int i = 0;
    if (!strcmp(com, "\\")) {
    } else if (!strcmp(com, "..")) {
    } else {
        int *p = &V[cur].head;
        for (i = V[cur].head; i > 0; i = V[i].next) {
            if (V[i].type == type && !strcmp(V[i].name.c_str(), com)) {
                if (type == DIR && V[i].head)
                    continue;
                *p = V[i].next;
                break;
            }
            p = &V[i].next;
        }
    }
    puts(i ? "success" : delRes[type]);
}
int main() {
    char op[9], com[30];
    V.push_back(F(0, 0, DIR, 0, "\\"));
    ++tot;
    while (scanf("%s%s", op, com) != EOF) {
        switch (op[0]) {
        case 'C':
            if (op[1] == 'D') {
                cd(com);
            } else {
                create(com, FILEE);
            }
            break;
        case 'M':
            create(com, DIR);
            break;
        case 'D':
            del(com, FILEE);
            break;
        case 'R':
            del(com, DIR);
            break;
        }
    }
    return 0;
}
