#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
int sta[5010];
int cnt;
int top;
int index;
map<int,long long>mp;
void gao1(int u){
    for(int i = 1;i <= cnt;i++)
        if(sta[i] == u){
            printf("Operation #%d: same priority.\n",index);
            return;
        }
    printf("Operation #%d: success.\n",index);
    sta[++cnt] = u;
    mp[u] = 0;
}
void gao2(int u){
    for(int i = 1;i <= cnt;i++)
        if(sta[i] == u){
            if(top != -1){
                if(top == u){
                    top = -1;
                }
            }
            for(int j = i;j < cnt;j++)sta[j] = sta[j+1];
            cnt--;
            printf("Operation #%d: close %d with %I64d.\n",index,u,mp[u]);
            return;
        }
    printf("Operation #%d: invalid priority.\n",index);
}
void gao3(int w){
    if(cnt == 0){
        printf("Operation #%d: empty.\n",index);
        return;
    }
    if(top != -1)mp[top] += w;
    else mp[sta[1]] += w;
    printf("Operation #%d: success.\n",index);
}
void gao4(int x){
    if(x < 1 || x > cnt){
        printf("Operation #%d: out of range.\n",index);
        return;
    }
    int tmp = sta[x];
    for(int i = x;i > 1;i--)sta[i] = sta[i-1];
    sta[1] = tmp;
    printf("Operation #%d: success.\n",index);
}
void gao5(){
    if(cnt == 0){
        printf("Operation #%d: empty.\n",index);
        return;
    }
    int id = 1;
    for(int i = 1;i <= cnt;i++)
        if(sta[i] > sta[id])
            id = i;
    gao4(id);
}
void gao6(int u){
    for(int i = 1;i <= cnt;i++)
        if(sta[i] == u){
            gao4(i);
            return;
        }
    printf("Operation #%d: invalid priority.\n",index);
}
void gao7(int u){
    for(int i = 1;i <= cnt;i++)
        if(sta[i] == u){
            top = u;
            printf("Operation #%d: success.\n",index);
            return;
        }
    printf("Operation #%d: invalid priority.\n",index);
}
void gao8(){
    if(top != -1){
        top = -1;
        printf("Operation #%d: success.\n",index);
    }
    else printf("Operation #%d: no such person.\n",index);
}
int main()
{
    int T;
    int n;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        cnt = 0;
        top = -1;
        mp.clear();
        char op[20];
        int u;
        for(index = 1;index <= n;index++){
            scanf("%s",op);
            if(strcmp(op,"Add") == 0){
                scanf("%d",&u);
                gao1(u);
            }
            else if(strcmp(op,"Close") == 0){
                scanf("%d",&u);
                gao2(u);
            }
            else if(strcmp(op,"Chat") == 0){
                scanf("%d",&u);
                gao3(u);
            }
            else if(strcmp(op,"Rotate") == 0){
                scanf("%d",&u);
                gao4(u);
            }
            else if(strcmp(op,"Prior") == 0){
                gao5();
            }
            else if(strcmp(op,"Choose") == 0){
                scanf("%d",&u);
                gao6(u);
            }
            else if(strcmp(op,"Top") == 0){
                scanf("%d",&u);
                gao7(u);
            }
            else gao8();
        }
        if(top != -1 && mp[top])
            printf("Bye %d: %I64d\n",top,mp[top]);
        for(int i = 1;i <= cnt;i++)
            if(sta[i] != top && mp[sta[i]])
                printf("Bye %d: %I64d\n",sta[i],mp[sta[i]]);
    }
    return 0;
}
