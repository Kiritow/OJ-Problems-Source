#include <deque>
#include <cstdio>
#include <algorithm>
using namespace std;
unsigned int m,n;

deque <int> Q;

int main(int argc, char* argv[]) {
	int t,ans=0;
	scanf("%d %d",&m,&n);
	for(unsigned int i=0;i<n;i++) {
		scanf("%d",&t);
		if(find(Q.begin(),Q.end(),t)==Q.end()) {
			ans++;
			Q.push_back(t);
			if( Q.size() >= m)
				Q.pop_front();
		}
	}
	printf("%d\n",ans);
	return 0;
}

/*
ÑùÀý #1£º
3 7
1 2 1 5 4 4 1
ÑùÀý #2£º
2 10
8 824 11 78 11 78 11 78 8 264
*/
