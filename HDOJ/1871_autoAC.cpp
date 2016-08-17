#include<stdio.h>
#include<algorithm>
using namespace std;
struct man
{
    int a,b,c;
};
man x[1001];
int n,t,i,m,a;
bool cmp(man x,man y)
{
    if(x.c>y.c)
        return false;
    return true;
}
void print(int a)
{
    int j;
    for(j=0;j<n;j++)
    {
        if(a<=x[j].b)
        {
            printf("%d\n",x[j].a);
            x[j].b-=a;
            return;
        }
    }
    printf("sorry\n");
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d%d%d",&x[i].a,&x[i].b,&x[i].c);
        sort(x,x+n,cmp);
        scanf("%d",&m);
        for(i=0;i<m;i++)
        {
            scanf("%d",&a);
            print(a);
        }                
    }
    return 0;
}
