#include <cstdio>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef vector<int> vi;
map<string, int> pos;
map<int, int> line;
const char *resetTime = "[0000/00/00 00:00:00]";
int ttEvent, ttLine;
struct Line{
    char timeMark[30];
    int line;
    int id;
}lineInform[50001];
struct Author{
    char name[35];
    int pri;
    char syncTime[30];
    vi modify;
}author[10001];
struct Event{
    char timeMark[30];
    int op;
    int id;
}event[50001];
bool cmpEvent(const Event a, const Event b){
    return strcmp(a.timeMark, b.timeMark) < 0;
}
bool cmpLine(const Line a, const Line b){
    return a.line < b.line;
}
void pre(int n){
    int k;
    char tm1[30], tm2[15], op[10];
    ttEvent = ttLine = 0;
    pos.clear();
    line.clear();
    for (int i = 0; i < n; i++){
        scanf("%s%d%d", author[i].name, &author[i].pri, &k);
        pos[author[i].name] = i;
        author[i].modify.clear();
        while (k--){
            scanf("%s%s%s", tm1, tm2, op);
            strcat(tm1, " ");
            strcat(tm1, tm2);
            strcpy(event[ttEvent].timeMark, tm1);
            if (!strcmp(op, "SYNC")){
                event[ttEvent].op = -1;
            }
            else if (!strcmp(op, "SUBMIT")){
                event[ttEvent].op = -2;
            }
            else{
                assert(!strcmp(op, "MODIFY"));
                scanf("%d", &event[ttEvent].op);
                if (!line.count(event[ttEvent].op)){
                    line[event[ttEvent].op] = ttLine;
                    strcpy(lineInform[ttLine].timeMark, resetTime);
                    lineInform[ttLine++].line = event[ttEvent].op;
                }
            }
            event[ttEvent++].id = i;
        }
    }
    sort(event, event + ttEvent, cmpEvent);
}
void run(){
    for (int i = 0; i < ttEvent; i++){
        switch (event[i].op){
            case -2:
                {
                    int id = event[i].id;
                    int pri = author[id].pri;
                    for (vi::iterator ii = author[id].modify.begin(); ii != author[id].modify.end(); ii++){
                        int linePos = line[*ii];
                        int lineID = lineInform[linePos].id;
                        //printf("cmp %s %s\n", lineInform[linePos].timeMark, author[id].syncTime);
                        if (strcmp(lineInform[linePos].timeMark, author[id].syncTime) < 0){
                            strcpy(lineInform[linePos].timeMark, event[i].timeMark);
                            lineInform[linePos].id = id;
                        }
                        else if (author[lineID].pri < pri){
                            strcpy(lineInform[linePos].timeMark, event[i].timeMark);
                            lineInform[linePos].id = id;
                        }
                    }
                    strcpy(author[id].syncTime, event[i].timeMark);
                    author[id].modify.clear();
                }
                break;
            case -1:
                {
                    strcpy(author[event[i].id].syncTime, event[i].timeMark);
                    author[event[i].id].modify.clear();
                }break;
            default:
                {
                    author[event[i].id].modify.push_back(event[i].op);
                }
        }
    }
    sort(lineInform, lineInform + ttLine, cmpLine);
}
void print(){
    for (int i = 0; i < ttLine; i++){
        if (strcmp(lineInform[i].timeMark, resetTime)) printf("%d %s BY %s\n", lineInform[i].line, lineInform[i].timeMark, author[lineInform[i].id].name);
    }
    puts("END");
}
int main(){
    int n;
    while (~scanf("%d", &n) && n){
        pre(n);
        run();
        print();
    }
    return 0;
}
