#include<stdio.h>
#include<stdlib.h>
#include<string.h>
const int N = 10005;
int arr[N][2];
bool used[N];//表示第几天被占用了
int compare(const void *a, const void *b)
{
	int *p1 = (int *)a;
	int *p2 = (int *)b;
	return p2[0] - p1[0];//价格降序
}
int main()
{
	int n,i,j,sum,d;
	while(scanf("%d", &n) != EOF)
	{
		memset(used, 0, sizeof(used));
		for(i = 0; i < n; ++i)
			scanf("%d %d", &arr[i][0], &arr[i][1]);
		qsort(arr, n, 2*sizeof(int), compare);
		sum = 0;
		for(i = 0; i < n; ++i)
		{
			for(j = arr[i][1]; j > 0; --j)
			{
				if(!used[j])//在这之前，有日期可用
				{
					used[j] = true;
					sum += arr[i][0];
					break;
				}
			}
		}
		printf("%d\n", sum);
	}
	return 0;
}
