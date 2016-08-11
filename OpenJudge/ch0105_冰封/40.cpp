#include <stdio.h>
int main(){
	int n,i,j;
	scanf("%d", &n);
	int ans = 0, count=0;
	i=1;
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			ans+=i;
			count++;
			if(count==n){
				printf("%d", ans);
				return 0;
			}
		}
	}
	return 0;
}