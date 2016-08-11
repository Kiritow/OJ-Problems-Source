#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int sc;
  char na[100];
} stu;

int judge(const void* a, const void* b) {
  return ((stu*)a) -> sc < ((stu*)b) -> sc ? 1 : 0;
}

int main(int argc, char* argv[]) {
  int cnt, i;
  stu s[1000];
  scanf("%d", &cnt);
  for(i = 0; i < cnt; i++) {
    scanf("%s %d", s[i].na, &s[i].sc);
  }
  qsort(s, cnt, sizeof(s[0]), judge);
  for(i = 0; i < cnt; i++) {
    printf("%s %d\n", s[i].na, s[i].sc);
  }
  return 0;
}
