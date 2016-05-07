#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <fstream>

using namespace std;


typedef pair<int,int> point;

int main()
{
	int T;
	cin>>T;
	for(int i=0;i<T;i++)
	{
		int n;
		set<point> data;
		cin>>n;
		int sum = 0;
		for(int j=0;j<n;j++)
		{
			int x,y;
			cin>>x>>y;
			sum+=x;
			data.insert(point(x*n,y));
		}
		bool flag = true;
		for(set<point>::iterator i=data.begin();i!=data.end();i++)
		{
			point p = *i;
			if(data.find(point(2*sum-p.first,p.second))==data.end())
			{
				flag = false;
				break;
			}
		}
		if(flag==true)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
