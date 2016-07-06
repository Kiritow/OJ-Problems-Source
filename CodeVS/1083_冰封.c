/*
作者:千里冰封
题目:p1083 Cantor表
*/

long long a, m, n;
#include <stdio.h>
void f(long long *m, long long *n, int i){
	*n = i;
	*m = 1;
	*n += a;
	*m -= a;
}
int main(int argc, char* argv[]){
    scanf("%lld", &a);
    int i;
    for(i = 0; (a -= i) > 0; i++);
    if(i % 2) f(&m, &n, i);
    else f(&n, &m, i);
    printf("%lld/%lld", m, n);
    return 0;
}
