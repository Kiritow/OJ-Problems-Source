#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int a;
	vector<int> vec;
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a);
		vec.push_back(a);
	}
	sort(vec.begin(),vec.end());
	printf("%d %d %d\n",vec.at(0),vec.at(1),vec.at(2));
	return 0;
}