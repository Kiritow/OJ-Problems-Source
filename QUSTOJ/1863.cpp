#include <iostream>
using namespace std;
//Written by Kiritow. 求最大公约数
long gcd(long a,long b)
{
	if(a==0||b==0)
	{
		if(a+b==0)
		{
			return 0;
		}
		return (a==0)?b:a;
	}

	while(a!=b)
	{
		if(a>b)
		{
			a=a-b;
		}
		else
		{
			b=b-a;
		}
	}
	return a;
}
int main()
{
    int a,b;
    cin>>a>>b;
    int c=gcd(a,b);
    cout<<c<<" "<<a*b/c<<endl;
    return 0;
}
