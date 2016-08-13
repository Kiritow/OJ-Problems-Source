#include <iostream>
using namespace std;
int main()
{
    int k,a;
    while(cin>>k)
    {
        if(k%65==0)
        {
            cout<<"no"<<endl;
            continue;
        }
        for(a=0;a<65;++a)
        {
            if((a*k)%65==47)
            {
                cout << a << endl;
                break;
            }
        }
        if(a==65) cout << "no" <<endl;
    }
    return 0;
}
