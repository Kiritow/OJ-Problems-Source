#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *jjfly(char *s) {
	char *h, *t;
	char c;
	h = s;
	t = s + strlen(s) - 1;
	while (h < t) {
		c = *h;
		*(h++) = *t;
		*(t--) = c;
	}
	return s;
}

int main(int argc, char* argv[]) {
	char *a,*b,*c;
	int i,j,max,min;
	int ifis = 0;
	a = (char*)malloc(sizeof(char)*300);
	b = (char*)malloc(sizeof(char)*300);
	c = (char*)malloc(sizeof(char)*300);

	scanf("%s",a);
	scanf("%s",b);

	jjfly(a);
	jjfly(b);

	if(strlen(a)>strlen(b)) {
		max = strlen(b);
		min = strlen(a);
		strcpy(c,a);
	} else {
		max = strlen(a);
		min = strlen(b);
		strcpy(c,b);
	}

	for(i = 0; i < max; i++) {
		j = (a[i]-'0' + b[i]-'0');
		j += ifis;
		ifis = 0;
		if(j>9) {
			j-=10;
			ifis++;
		}
		c[i] = j+'0';
		j = 0;
	}

	for(i = max; i < min; i++) {
		j = c[i] - '0';
		j += ifis;
		ifis = 0;
		if(j>9) {
			j-=10;
			ifis++;
		}
		c[i] = j+'0';
	}
	jjfly(c);
	if(ifis != 0)
		printf("%d",ifis);
	for(i = 0; c[i] == '0'; i++);
	if(i >= strlen(c))
		puts("0");
	else
		puts(c+i);
	return 0;
}
