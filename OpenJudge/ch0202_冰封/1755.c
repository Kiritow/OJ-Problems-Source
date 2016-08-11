#include <stdio.h>

int save[10000];
int get(int cnt) {
  if(save[cnt]) return save[cnt];
  else {
    save[cnt] = get(cnt - 1) + get(cnt - 2);
    return save[cnt];
  }
}

int main(int argc, char** argv) {
  int cnt;
  save[0] = 1;
  save[1] = 1;
//  save[2] = 1;
  scanf("%d", &cnt);
  while(cnt--) {
    int k;
    scanf("%d", &k);
    printf("%d\n", get(--k));
  }
  return 0;
}
