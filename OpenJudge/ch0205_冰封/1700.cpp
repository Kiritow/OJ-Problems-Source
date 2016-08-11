#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
using namespace std;

typedef struct Board {
  public:
  short a[8];
  int idx;
  Board(){idx = 0; for(int k = 0; k < 8; k++) a[k] = -10;}
} Board;

char* res[8] = {
  "1 0 0 0 0 0 0 0\n",
  "0 1 0 0 0 0 0 0\n",
  "0 0 1 0 0 0 0 0\n",
  "0 0 0 1 0 0 0 0\n",
  "0 0 0 0 1 0 0 0\n",
  "0 0 0 0 0 1 0 0\n",
  "0 0 0 0 0 0 1 0\n",
  "0 0 0 0 0 0 0 1\n",
};

int cnt = 0;

bool canGo(Board b, int now){
  for(int i = 0; i < 8; i++){
    if(b.a[i] == now) return false;
    if(!(abs(b.a[i] - now) - abs(i - b.idx))) return false;
  }
  return true;
}

void run(){
//  queue<Board> q;
//  while(!q.empty()) q.pop();
  Board b;
  b.idx = 0;
//  q.push(b);
  int i[8];
  for(i[0] = 0; i[0] < 8; i[0]++){
    b.a[0] = i[0];
    b.idx = 1;
    for(i[1] = 0; i[1] < 8; i[1]++){
      b.idx = 2;
      if(canGo(b, i[0])){
        b.a[1] = i[1];
        for(i[2] = 0; i[2] < 8; i[2]++){
          b.idx = 3;
          if(canGo(b, i[2])){
            b.a[2] = i[2];
            for(i[3] = 0; i[3] < 8; i[3]++){
              b.idx = 4;
              if(canGo(b, i[3])){
                b.a[3] = i[3];
                for(i[4] = 0; i[4] < 8; i[4]++){
                  b.idx = 5;
                  if(canGo(b, i[4])){
                    b.a[4] = i[4];
                    for(i[5] = 0; i[5] < 8; i[5]++){
                      b.idx = 6;
                      if(canGo(b, i[5])){
                        b.a[5] = i[5];
                        for(i[6] = 0; i[6] < 8; i[6]++){
                          b.idx = 7;
                          if(canGo(b, i[6])){
                            b.a[6] = i[6];
                            for(i[7] = 0; i[7] < 8; i[7]++){
                              b.idx = 8;
                              if(canGo(b, i[7])){
                                b.a[7] = i[7];
                                cnt++;
                                printf("No. %i\n", cnt);
                                  for(int i = 0; i < 8; i++)
                                printf(res[b.a[i]]);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

void test(){
  Board b;
  b.idx = 2;
  b.a[0] = 0;
  b.a[1] = 3;
  printf("%s\n", canGo(b, 6) ? "can" : "cannot");
}

int main(int argc,char** argv){
  run();
  system("PAUSE");
  return 0;
}
  //while(!q.empty()) {
//    b = q.front();
//    q.pop();
//    Board bb;
//    bb.idx = b.idx + 1;
//    for(int i = 0; i < 8; i++) {
//      if(canGo(b, i)) {
//        bb.a[b.idx] = i;
//        if(bb.idx >= 8) {
//          cnt++;
//          printf("No. %i\n", cnt);
//            for(int i = 0; i < 8; i++)
//          printf(res[b.a[i]]);
//          continue;
//        }
//        q.push(bb);
//      }
//    }
//  }
