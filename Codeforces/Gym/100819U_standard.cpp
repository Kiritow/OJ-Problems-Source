#include<cstdio>
#include<set>
using namespace std;
int n, m, b;
int a[2][128][128];
set<int> s;
int dx[9]={-1,-1,-1,0,0,0,1,1,1};
int dy[9]={-1,0,1,-1,0,1,-1,0,1};
int main()
{
	scanf("%d%d%d", &m, &n, &b);
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		scanf("%d", &a[0][i][j]);
	for(int k=1;k<=b;k++) for(int i=0;i<n;i++) for(int j=0;j<m;j++)
	{
		a[k&1][i][j] = 0;
		for(int dir=0;dir<=8;dir++)
			a[k&1][i][j] += a[!(k&1)][(i+dx[dir]+n)%n][(j+dy[dir]+m)%m];
	}
	for(int i=0;i<n;i++) for(int j=0;j<m;j++)
		s.insert(a[b&1][i][j]);
	printf("%d\n", (int)s.size());
	return 0;
}
