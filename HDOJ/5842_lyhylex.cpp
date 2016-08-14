///好厉害~！来自lyhylex (CSDN)
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100000 + 9];
int main()
{
	int ca = 1, t;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%s", s);
		int n = strlen(s);
		sort(s, s + n);
		printf("Case #%d: %d\n", ca++, unique(s, s + n) - s);
	}
	return 0;
}
