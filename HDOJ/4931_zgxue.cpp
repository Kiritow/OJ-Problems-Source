#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int t, a[6];

int main() {
    scanf("%d", &t);
    while (t--) {
	for (int i = 0; i < 6; i++)
	    scanf("%d", &a[i]);
	sort(a, a + 6);
	int aa = a[5] + a[4];
	int bb = a[3] + a[2] + a[1];
	if (aa > bb) printf("Grandpa Shawn is the Winner!\n");
	else printf("What a sad story!\n");
    }
    return 0;
}
