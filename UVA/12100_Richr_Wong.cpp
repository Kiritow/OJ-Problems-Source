#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		int num, index;
		queue<int> q;
		priority_queue<int> pq;
		cin>>num>>index;
		for(int j=0;j<num;j++)
		{
			int rate;
			cin>>rate;
			pq.push(rate);
			q.push(rate);
		}
		int x = 0;
		while(true)
		{
			if(q.front()==pq.top())
			{
				if(x==index)
				{
					cout<<num-q.size()+1<<endl;
					break;
				}
				else
				{
					q.pop();
					pq.pop();
					x++;
				}
			}
			else
			{
				int temp = q.front();
				q.pop();
				q.push(temp);
				if(x==index)
				{
					x=0;
					index=q.size()-1;
				}
				else
				{
					x++;
				}
			}
		}
	}
	return 0;
}
