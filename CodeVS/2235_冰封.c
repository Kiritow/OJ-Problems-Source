/*
作者:千里冰封
题目:p2235 机票打折
*/

#include <stdio.h>
int main(int argc, char* argv[]) {
    int a;
	float b;
    scanf("%i%f", &a, &b);
    b /= 10.0;
	a *= b;
	if(a % 10 < 5)
		a -= a % 10;
	else {
		a -= a % 10;
		a += 10;
	}
    printf("%i", a);
    return 0;
}
