/*
作者:千里冰封
题目:p1910 递归函数
*/

#include<stdio.h>
#include<stdlib.h>

int w[21][21][21] = {0};

int main(int argc, char* argv[]){
  int a, b, c;
  for(a = 0; a <= 20; a++){
    for(b = 0; b <= 20; b++){
      for(c = 0; c <= 20; c++){
        if(a < 1 || b < 1 || c < 1){
          w[a][b][c] = 1;
          continue;
        }
//        if(a > 20 || b > 20 || c > 20){
//          w[a][b][c] = w[20][20][20];
//          continue;
//        }
        if(a < b && b < c){
          w[a][b][c] = w[a][b][c-1] + w[a][b-1][c-1] + w[a][b-1][c];
          continue;
        }
        w[a][b][c] = w[a-1][b][c]+w[a-1][b][c-1]+w[a-1][b-1][c]-w[a-1][b-1][c-1];
      }
    }
  }
  while(1){
    scanf("%i%i%i", &a, &b, &c);
    if(a == -1 && b == -1 && c == -1) break;
    printf("w(%i, %i, %i) = %i\n", a, b, c, w[a][b][c]);
  }
  return 0;
}
/*
long w(int a, int b, int c){
  if(a < 1 || b < 1 || c < 1)
    return 1;
  if(w[a][b][c]) return w[a][b][c];
  if(a > 20 || b > 20 || c > 20) {
    return w[20][20][20] ? w[20][20][20] : w(20, 20, 20);
  }
  if(a < b && b < c) {
    w[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) + w(a, b - 1, c);
    return w[a][b][c];
  }
  w[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return w[a][b][c];
}
*/
