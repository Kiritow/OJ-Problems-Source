#include<iostream>
using namespace std;
int cnt=1;
struct jsj
{
    int x1,y1;
    int x2,y2;
}a[101];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            int c,d;
            scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&c,&d);
            a[i].x2=a[i].x1+d-1;
            a[i].y2=a[i].y1+c-1;
        }
        int m;
        scanf("%d",&m);
        printf("Desktop %d:\n",cnt++);
        for(int i=0;i<m;i++)
        {
            bool f=false;
            int q1,q2;
            scanf("%d%d",&q1,&q2);
            for(int j=n-1;j>=0;j--)
            {
                if(q1>=a[j].x1 && q1<=a[j].x2 && q2>=a[j].y1 && q2<=a[j].y2)
                {
                    f=true;
                    printf("window %d\n",j+1);
                    break;
                }
            }
            if(!f) printf("background\n");
        }
    }
    return 0;
}
