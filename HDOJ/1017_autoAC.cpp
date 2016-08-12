#include <iostream>
using namespace std;
int main()
{
    int N;
    int n,m;
    cin>>N;
    int p = 1;
    while(p <= N)
    {
        if(p != 1)
            cout<<endl;
        int cnt = 1;
        while(cin>>n>>m && n||m)
        {
            int count = 0;
            for(int a = 1;a <= n-2;++a)
                for(int b = a+1;b <= n-1;++b)
                    if((a*a + b*b + m)%(a*b) == 0)
                        ++count;
            cout<<"Case "<<cnt<<":"<<" "<<count<<endl;
            ++cnt;
        }
        ++p;
    }
    return 0;
}
