#include <stdio.h>
#include <math.h>

bool is_pri(int n){
	for(int i = 3; i <= sqrt(n); i++)
		if(n % i == 0) return false;
	return true;
}

int main(int argc, char** argv){
	int cnt = 1;
	int goal;
	scanf("%i", &goal);
	if(goal == 1) {
		printf("2");
		return 0;
	}
	// all is ji_shu
	for(int i = 3; ; i += 2){
		if(is_pri(i))
			cnt++;
		if(cnt == goal){
			printf("%i", i);
			return 0;
		}
	}
//    while(1);
    return 0;
}
