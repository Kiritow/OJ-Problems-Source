/*
作者:千里冰封
题目:p1380 没有上司的舞会
*/
//
// Created by ice1000 on 2016/7/5.
//

#include <stdio.h>
#include <vector>

using namespace std;

const int size = 6005;

int n, dp[size][2], r[size], f[size];
vector<int> vec[size];

void dfs(int i);

void init();

int main(int argc, char *argv[]) {
//	init();
	int l, k, out = -1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &r[i]);
	}
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &l, &k);
		vec[k].push_back(l);
		f[l] = k;
	}
	scanf("%d %d", &l, &k);
	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			dfs(i);
			out = max(dp[i][0], dp[i][1]);
			break;
		}
	}
	printf("%d\n", out);
	return 0;
}
void dfs(int root) {
	for (int i = 0; i < vec[root].size(); i++) {
		int j = vec[root][i];
		dfs(j);
		dp[root][0] += max(dp[j][0], dp[j][1]);
		dp[root][1] += dp[j][0];
	}
	dp[root][1] += r[root];
}

