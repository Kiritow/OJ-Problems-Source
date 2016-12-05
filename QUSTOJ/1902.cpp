#include <iostream>
#include <algorithm>
using namespace std;

inline void test()
{
    int n,m;
    cin>>n>>m;
    int** a=new int*[n];
    for(int i=0;i<n;i++)
    {
        a[i]=new int[m];
        for(int j=0;j<m;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int j=0;j<m;j++)
    {
        for(int i=0;i<n-1;i++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<a[n-1][j]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        delete[] a[i];
    }
    delete[] a;
}

int main()
{
    int n;
    cin>>n;
    while(n--) test();
    return 0;
}
