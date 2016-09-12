#include <iostream>
#include <cstdio>
using namespace std;

const int N = 1000005;

struct Elem
{
	int val;
	int pos;
};

Elem maxque[N];
Elem minque[N];
int maxhead, minhead, maxtail, mintail;
int maxans[N];
int minans[N];
int cur;

int main()
{
	int n, w, num;
	scanf("%d%d", &n, &w);
	minhead = mintail = 0;
	maxhead = maxtail = 0;
	cur = 0;
	for (int i = 0; i < w; ++i)
	{
		scanf("%d", &num);
		
		while (minhead < mintail && minque[mintail - 1].val >= num) --mintail;
		minque[mintail].val = num;
		minque[mintail].pos = i;
		++mintail;

		while (maxhead < maxtail && maxque[maxtail - 1].val <= num) --maxtail;
		maxque[maxtail].val = num;
		maxque[maxtail].pos = i;
		++maxtail;
	}
	for (int i = w; i < n; ++i)
	{
		minans[cur] = minque[minhead].val;
		maxans[cur] = maxque[maxhead].val;
		++cur;

		scanf("%d", &num);

		while (minhead < mintail && i - minque[minhead].pos >= w) ++minhead;
		while (minhead < mintail && minque[mintail - 1].val >= num) --mintail;
		minque[mintail].val = num;
		minque[mintail].pos = i;
		++mintail;
		
		while (maxhead < maxtail && i - maxque[maxhead].pos >= w) ++maxhead;
		while (maxhead < maxtail && maxque[maxtail - 1].val <= num) --maxtail;
		maxque[maxtail].val = num;
		maxque[maxtail].pos = i;
		++maxtail;
	}
	minans[cur] = minque[minhead].val;
	maxans[cur] = maxque[maxhead].val;
	++cur;
	
	for (int i = 0; i < cur; ++i)
	{
		if (i > 0) putchar(' ');
		printf("%d", minans[i]);
	}
	printf("\n");
	for (int i = 0; i < cur; ++i)
	{
		if (i > 0) putchar(' ');
		printf("%d", maxans[i]);
	}
	printf("\n");

	return 0;
}
