#include <stdio.h>

int main(int argc, char* argv[]) {
	int a[1000], b[1000], n, na, nb, i, ret = 0;
	scanf("%i %i %i", &n, &na, &nb);
	for(i = 0; i < na; i++)
		scanf("%i", &a[i]);
	for(i = 0; i < nb; i++)
		scanf("%i", &b[i]);
	for(i = 0; i < n; i++) {
		if(		a[i%na] == 0 && b[i%nb] == 2 ||
				a[i%na] == 2 && b[i%nb] == 5 ||
				a[i%na] == 5 && b[i%nb] == 0   ) {
			ret++;
		} else if(a[i%na] != b[i%nb]) {
			ret--;
		}
	}
	printf("%s", ret ? ret > 0 ? "A" : "B" : "draw");
	return 0;
}
