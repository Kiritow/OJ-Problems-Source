#include<iostream>
using namespace std;
int main()
{
    int len;
    double x1,y1,x2,y2;
    while(cin>>len)
    {
        if(len==0)
            break;
        cin>>x1>>y1>>x2>>y2;
        if(x2>len||y2>len||(-x2)>len||(-y2)>len)
            cout<<"Out Of Range"<<endl;
        else
        {
        int flag=0;    
        if(x1==x2)
        {
            if(y1-y2>1.0||y2-y1>1.0)
                flag=1;
            else
            {
                flag=0;
            }
        }
        else if(y1==y2)
        {
            if(x1-x2>1.0||x2-x1>1.0)
                flag=1;
            else
            {
                flag=0;
            }
        }
        else
        {
              double k=(y2-y1)*1.0/(x2*1.0-x1*1.0);
                  double b=y1*1.0-k*x1;
          double minx=x1>x2?x2:x1;
        double maxx=x1>x2?x1:x2;
        for(double i=minx+1;i<maxx;i++)
        {
        double    temp = (1.0*i - x1)*(y2 - y1) / (x2 - x1) + y1;
            if (temp == (double)(int)temp)
            {
                flag=1;
                break;
            }
        }
        }
        if(flag)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
