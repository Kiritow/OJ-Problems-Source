#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	int i, cnt = 0;
	for(i = 0; i < 256; i++) {
		char k;
		k = getchar();
		if(k == '\n') break;
		if(k >= '0' && k <= '9') cnt++;
	}
    printf("%i", cnt);
	return 0;
}
