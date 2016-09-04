#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
int ans[10000][53];
int main(){
    int T, op, left, right;
    scanf("%d", &T);
    for(int t=1; t<=T; t++){
       for(int i=1; i<=52; i++)
           scanf("%d", &ans[0][i]);
       scanf("%d %d %d", &op, &left, &right);
       int len = 1;
       while(1){
           int tag = 1;
           for(int i=left; i<=right; i++)
              ans[len][tag++] = ans[len-1][i];
           for(int i=1; i<left; i++)
              ans[len][tag++] = ans[len-1][i];
           for(int i=right+1; i<=52; i++)
              ans[len][tag++] = ans[len-1][i];
           bool flag = true;
           for(int i=1; i<=52; i++)
              if(ans[0][i] != ans[len][i]){
                  flag = false;
                  break;
              }
           if(flag){
              tag = op%len;
              printf("Case #%d:", t);
              for(int i=1; i<=52; i++)
                  printf(" %d", ans[tag][i]);
              printf("\n");
              break;
           }
           len++;
       }
    }
    return 0;
}
