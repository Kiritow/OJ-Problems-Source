/*
作者:千里冰封
题目:p4511 信息传递 NOIP2015 day1 T2
*/

#include <stdio.h>

const int size = 0xfff;

typedef struct {
    int known[size];
    int kcnt;
    int to;
} Line ;

int main(int argc, char* argv[]) {
    int a, i;
    Line l[size];
    scanf("%i", &a);
    for(i = 0; i < a; i++){
        int x,y;
        scanf("%i", &l[i].to);
        l[i].kcnt = 1;
        l[i].known[0] = i;
    }
    for(i = 0; ; i++){
        int j, k;
        for(j = 0; j < a; j++){
            for(k = 0; k < l[l[j].to].kcnt; k++){
                if(l[l[j].to].known[k] == )
            }
        }
    }
    return 0;
}
