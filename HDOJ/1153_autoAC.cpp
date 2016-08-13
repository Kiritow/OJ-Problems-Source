#include <iostream>
using namespace std;
long long p;
int a[100010];
int main()
{
    while(cin >> p)
    {
        if(p==0)break;
        if(p==2)cout << "Impossible" << endl;
        else
        {
            for(int i=1;i<p;i++)a[i]=1;
            for(long long i=1;i<p;i++)a[i*i%p]=0;
            for(int i=1;i<p;i++)cout << a[i];
            cout << endl;
        }
    }
    return 0;
}
