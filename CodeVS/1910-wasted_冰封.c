/*
作者:千里冰封
题目:p1910 递归函数
*/

#include<stdio.h>
#include<stdlib.h>

long save[21][21][21] = {0};
long w(int a, int b, int c){
  if(a < 1 || b < 1 || c < 1)
    return 1;
  if(save[a][b][c]) return save[a][b][c];
  if(a > 20 || b > 20 || c > 20) {
    return save[20][20][20] ? save[20][20][20] : w(20, 20, 20);
  }
  if(a < b && b < c) {
    save[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) + w(a, b - 1, c);
    return save[a][b][c];
  }
  save[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
  return save[a][b][c];
}

int main(int argc, char* argv[]){
  int a, b, c;
  while(1){
    scanf("%i%i%i", &a, &b, &c);
    if(a == -1 && b == -1 && c == -1) break;
    printf("w(%i, %i, %i) = %li\n", a, b, c, w(a, b, c));
  }
  return 0;
}
