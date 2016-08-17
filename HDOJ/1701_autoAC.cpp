#include<iostream>
using namespace std;
int main()
{   double j,k;int n,i;
    cin>>n;
    while(n--)
    {
        cin>>j>>k;
        i=2;
        while(i>1)
        {
            if(int(k*i*0.01)-int(j*i*0.01)==1)
                break;
            i++;
        }
        cout<<i<<endl;
    }
    return 0;
}
