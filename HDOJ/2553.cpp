#include <cstdio>
using namespace std;
int main()
{
    int n;
    int ans;
    while(scanf("%d",&n)==1&&n!=0)
    {
        switch(n)
        {
            case 1:ans=1;break;
            case 2:case 3:ans=0;break;
            case 4:ans=2;break;
            case 5:ans=10;break;
            case 6:ans=4;break;
            case 7:ans=40;break;
            case 8:ans=92;break;
            case 9:ans=352;break;
            case 10:ans=724;break;
        }
        printf("%d\n",ans);
    }
    return 0;
}
