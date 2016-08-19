#include<cstdio>
#include<algorithm>
using namespace std;
int a[44000];
int main()
{
    int t;
    int m;
    int i;
    int position;
    int n;
    int top;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        scanf("%d",&a[0]);
        top=0;
        for(i=1;i<n;i++)
        {
            scanf("%d",&m);
            if(m>a[top])
            {
                top++;
                a[top]=m;
            }
            else
            {
                position=lower_bound(a,a+top,m)-a;
                a[position]=m;
            }
        }
        printf("%d\n",top+1);
    }
    return 0;
}
