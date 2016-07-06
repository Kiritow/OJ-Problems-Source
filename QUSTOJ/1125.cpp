#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
using namespace std;
//Written by Coffee. 判断素数
bool isPrime(int num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}
	for (int i = 5; i*i <= num; i += 6)
	{
		if (num % i == 0 || num % (i+2) == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
    int n,k;
    vector<int> vec;
    scanf("%d %d",&n,&k);
    int tmp;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&tmp);
        vec.push_back(tmp);
    }
    sort(vec.begin(),vec.end());
    int m=vec.at(n-k)-vec.at(k-1);
    if(isPrime(m))
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }
    return printf("%d\n",m),0;
}
