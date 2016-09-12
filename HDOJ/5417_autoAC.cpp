#include <iostream>
using namespace std;
int main()
{
    int x, y, w, n;
    while(cin>>x>>y>>w>>n)
    {
        n -= 1;
        int ans, tmp1, tmp2;
        if(w > x)
            ans = (x+y)*n;
        else
        {
            tmp1 = n % ((int)(x/w)+1);
            tmp2 = n / (x/w+1);
            ans = tmp2*(x+y)+w*tmp1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
