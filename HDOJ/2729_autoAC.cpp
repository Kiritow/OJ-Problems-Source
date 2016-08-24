#include <stdio.h>
#include <string.h>
#define oo 100000
bool dfs(int, int);
int n,m,mini;
bool finished[14];
struct CLASS {
    char name[8];
    int time,preNum;
    int prerequisites[13];
} subject[15];
bool permit(int num) {
    int i;
    for(i=0; i<subject[num].preNum && finished[subject[num].prerequisites[i]]; i++);
    if(i == subject[num].preNum) return true;
    return false;
}
bool selectAndDfs(int total, int elect, int from, int que[], int result[], int lev, int semester) {
    int i;
    if(total-from < elect) return false;
    if(from == total && elect == 0) {
        for(i=0; i<m; i++) finished[result[i]] = true;
        dfs(lev+m, semester+1);
        for(i=0; i<m; i++) finished[result[i]] = false;
        return true;
    }
    for(i=from; i<total; i++) {
        result[m-elect] = que[i];
        selectAndDfs(total, elect-1, i+1, que, result, lev, semester);
    }
    return true;
}
bool dfs(int lev, int semester) {
    if(semester-1 >= mini) return false;
    if(lev == n) {
        if(semester-1 < mini) mini = semester-1;
        return true;
    }
    int i,tn=0,que[15];
    for(i=0; i<n; i++) if(!finished[i] && permit(i) && (subject[i].time & (1<<semester%2)) != 0) que[tn++] = i;
    if(tn <= m) {
        for(i=0; i<tn; i++) finished[que[i]] = true;
        dfs(lev+tn,semester+1);
        for(i=0; i<tn; i++) finished[que[i]] = false;
    }
    else {
        int temp[15];
        selectAndDfs(tn,m,0,que,temp,lev,semester);
    }
    return false;
}
int main() {
    while(scanf("%d%d", &n, &m) == 2 && !(n == -1 && m == -1)) {
        int i,j,k,p,t;
        for(i=0; i<n; i++) {
            scanf("%s", &subject[i].name);
            subject[i].time = subject[i].preNum = 0;
        }
        for(i=0; i<n; i++) {
            char s[10];
            scanf("%s", s);
            for(j=0; j<n && strcmp(s, subject[j].name) != 0; j++);
            scanf("%s", s);
            if(s[0] == 'B') subject[j].time = 3;
            else if(s[0] == 'S') subject[j].time = 1;
            else subject[j].time = 2;
            scanf("%d", &t);
            for(k=0; k<t; k++) {
                scanf("%s", s);
                for(p=0; p<n && strcmp(s, subject[p].name) != 0; p++);
                subject[j].prerequisites[subject[j].preNum++] = p;
            }
        }
        memset(finished, 0, sizeof(finished));
        mini = oo;
        dfs(0,1);
        printf("The minimum number of semesters required to graduate is %d.\n", mini);
    }
    return 0;
}
