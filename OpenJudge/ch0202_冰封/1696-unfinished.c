#include <stdio.h>
#include <string.h>
#include <math.h>

float plus(float a, float b) {return a + b;}
float mino(float a, float b) {return a - b;}
float time(float a, float b) {return a * b;}
float devi(float a, float b) {return a / b;}

int main(int argc, char* argv[]) {
	char s[1000];
	int i, end = 0;
	int temp[1000], tidx = 0;
	float num[1000]; int nidx = 0;
	memset(temp, 0, sizeof(temp[0]));
	gets(s);
	float (*cal[])(float, float) = {
		plus, mino, time, devi
	};
	for(i = 0; i < strlen(s); i++) {
		if(s[i] == ' ') {
			end = 1;
		}
		else {
			int isNum = 0;
			end = 0;
			switch(s[i]) {
				case '+':
					temp[tidx++] = 0;
					break;
				case '-':
					temp[tidx++] = 1;
					break;
				case '*':
					temp[tidx++] = 2;
					break;
				case '/':
					temp[tidx++] = 3;
					break;
				default:
					isNum++;
					break;
			}
			if(isNum) {
				int idx = 0;
				char t[10];
				memset(t, 0, sizeof(t[0]));
				while(s[i + idx] != ' ') {
					t[idx] = s[i + idx];
					idx++;
				}
				i += idx;
				num[nidx++] = atof(t);
			}
			else {
				i++;
			}
		}
	}
	// for(i = 0; i < nidx; i++) {
	// 	printf("%f\n", num[i]);
	// }
	// for(i = 0; i < tidx; i++) {
	// 	printf("%d\n", temp[i]);
	// }
	return 0;
}
