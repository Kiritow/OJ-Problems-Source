#include<stdio.h>
#define SIZE 10000
int a[SIZE][16];
int b[SIZE];
int main(void){
  int count;
  for(count = 0; count < SIZE; count++){
    scanf("%d",&a[count][0]);
    if(a[count][0] == -1) break;
    int sss;
    for(sss = 1; sss < 16; sss++){
      scanf("%d",&a[count][sss]);
      if(a[count][sss] == 0) break;
    }
    b[count] = sss;
  }
  for(int j = 0; j < count; j++){
    int cnt = 0;
    for(int i = 0; i < b[j]; i++){
      for(int ji = 0; ji < b[j]; ji++){
	    if(a[j][ji] == 2*a[j][i]){
	      cnt++;
	      break;
        }
      }
    }
    printf("%d\n",cnt);
  }
 // getchar();getchar();getchar();getchar();getchar();
  return 0;
}
/*
1 4 3 2 9 7 18 22 0
2 4 8 10 0
7 5 11 13 1 3 0
-1
*/
