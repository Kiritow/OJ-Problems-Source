#include<iostream>
using namespace std;
struct node
{
   int d;
   int p;
};
typedef int Case;
node nod[10];
const double PI=3.1415926;
int main()
{
    int n;
    Case cas=1;
    while(cin>>n,n)
    {
        double min=1000000,area,sq;
        int rem;
        for(int i=0;i<n;i++)
        {
            cin>>nod[i].d>>nod[i].p;
            area=PI*(nod[i].d/2.0)*(nod[i].d/2.0);
            sq=nod[i].p/area;
            if(min>sq)
            {
                min=sq;
                rem=nod[i].d;
            } 
        }
        cout<<"Menu "<<cas++<<": "<<rem<<endl;
    }
    return 0;
}
