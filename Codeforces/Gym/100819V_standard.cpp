#include<cstdio>
int n;
struct gear { int x, y, r; } a[1024];
int dir[1024];
int gcd(int x, int y) { while (y) { int t = x%y; x = y; y = t; } return x; }
bool fill(int i, int d)
{
	dir[i] = d;
	for (int j = 1; j <= n; j++)
	{
		if (i != j && (a[i].x - a[j].x)*(a[i].x - a[j].x)
			+ (a[i].y - a[j].y)*(a[i].y - a[j].y)
			== (a[i].r + a[j].r)*(a[i].r + a[j].r))
		{
			if (dir[i] == dir[j]) return false;
			if (dir[j]) continue;
			if (!fill(j, -d)) return false;
		}
	}
	return true;
}
int main()
{
	int i;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].r);
	if (!fill(1, 1)) printf("The input gear cannot move.\n");
	else if (!dir[n]) printf("The input gear is not connected to the output gear.\n");
	else
	{
		int g = gcd(a[1].r, a[n].r);
		printf("%d:%d\n", a[1].r*dir[n] / g, a[n].r / g);
	}
	return 0;
}
