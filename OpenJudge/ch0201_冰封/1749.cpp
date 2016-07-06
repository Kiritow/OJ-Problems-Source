#include<stdio.h>
#include<stdlib.h>
  long stupid[50000];
int main(void){
  int total;
  scanf("%d",&total);
  for(long fuck = 0; fuck < total; fuck++){
    long n;
    scanf("%d",&n);
    if( n == 0 ){
      stupid[fuck] = 0;
      continue;
    }
    bool jjfly = true,dick = true;
    long a,b,c;
    for( b = n; b > 0 && dick; b--){
      for( a = n; a > 0 && jjfly; a--){
	if ((a + b) % 2 == 0){
	  for( c = n; c > 0; c--){
	    if(((b + c) %3 == 0) &&
	       ((a + b + c) % 5 == 0)){
	      stupid[fuck] = a + b + c;
	      // printf("a = %d, b = %d, c = %d\n",a,b,c);
	      jjfly = false;
	      dick = false;
	      break;
	    }
	  }
	}
      }
    }
    for(long i = 0; i < total; i++){
      printf("%d\n",stupid[i]);
    }
    // system("pause");
    return 0;
  }
}
