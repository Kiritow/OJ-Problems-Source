#include<iostream>
using namespace std;
int main()
{
    int h,u,d,f;
    while(cin>>h>>u>>d>>f&&h!=0)
    {
        int i=1;
        double sum=0;
        while(i)
        {
            sum+=u-u*(i-1)*double(f)/100;
            if(sum>h)
            {
                cout<<"success on day "<<i<<endl;
                break;
            }
            sum-=d;
            if(sum<0)
            {
                cout<<"failure on day "<<i<<endl;
                break;
            }
            i++;
        }
    }
    return 0;
}
