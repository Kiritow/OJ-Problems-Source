//Memory   Time 
//240K      0MS 

#include<iostream>
#include<math.h>
#include<string>
#include<iomanip>
using namespace std;
int main(void)
{
	char alpha;
	double t,d,h;
	int i;
	for(;;)
	{
		t=d=h=200;    //三个参数的范围默认都是在-100 ~ 100
		for(i=0;i<2;i++)
		{
			cin>>alpha;
			if(alpha=='E')
				return 0;
			else if(alpha=='T')
			    cin>>t;
			else if(alpha=='D')
				cin>>d;
			else if(alpha=='H')
				cin>>h;
		}
		if(h==200)
			h=t+0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
		else if(t==200)
			t=h-0.5555*(6.11*exp(5417.7530*(1/273.16-1/(d+273.16)))-10);
		else if(d==200)
			d=1/((1/273.16)-((log((((h-t)/0.5555)+10.0)/6.11))/5417.7530))-273.16;
		cout<<setprecision(1)<<fixed<<"T "<<t<<" D "<<d<<" H "<<h<<endl;
	}
	return 0;
}
