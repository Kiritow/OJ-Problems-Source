#include <stdio.h>
#include <stdlib.h>
#define  SIZE 20

/*int min(int x,int y){
	if(x > y) return y;
	else return x;
}*/
int a[SIZE],b[SIZE];
int main(int argc,char** argv){
	int x,y;
	scanf("%d %d",&x,&y);
	int i,j;
	int ans = 1;
	i = 0;
	while(x > 0){
		a[i] = x;
		x /= 2;
		i++;
	}
	j = 0;
	while(y > 0){
		b[j] = y;
		y /= 2;
		j++;
	}
	while(i >= 0 && j >= 0){
		i--;
		j--;
		if(a[i] == b[j] && a[i] > ans){
            ans = a[i];
		}
	}
	printf("%d", ans);
	return 0;
}
