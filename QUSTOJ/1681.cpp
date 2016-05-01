#include <iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    int m,n;
    int start;
    for(int i=0;i<t;i++)
    {
        cin>>start>>m>>n;
        int a=n%(m+1);
        if(a!=0)
        {
            if(start==1)
            {
                cout<<"Richard"<<endl;
            }
            else
            {
                cout<<"Dick"<<endl;
            }
        }
        else
        {
            if(start==1)
            {
                cout<<"Dick"<<endl;
            }
            else
            {
                cout<<"Richard"<<endl;
            }
        }
    }
    return 0;
}
