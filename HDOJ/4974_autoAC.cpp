#include<cstdio>
#include<algorithm>
using namespace std;
int t,c=1,m,a,i,s,n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n),s=0,m=0;
        while(n--)
            scanf("%d",&a),s+=a,m=max(m,a);
        printf("Case #%d: %d\n",c++,max(m,(int)(s/2.0+0.5)));
    }
}
