#include <iostream>
using namespace std;
int n;
int main()
{
    while(scanf("%d",&n) != EOF)
    {
        cout<<(n*n*n + 5*n + 6)/6<<endl;
    }
    return 0;
}
