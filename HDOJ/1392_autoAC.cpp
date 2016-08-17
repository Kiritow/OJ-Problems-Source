#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
struct node
{
    int x,y;
}a[110],stack1[110];
double distan(node a,node b)
{
    return (double)sqrt((a.x-b.x)*(a.x-b.x)*1.0+(a.y-b.y)*(a.y-b.y)*1.0);
}
double across(node a,node n1,node n2)
{
    return (n1.x-a.x)*(n2.y-a.y) - (n1.y-a.y)*(n2.x-a.x);
}
bool cmp(node a1,node b1)
{
    double k=across(a[0],a1,b1);
    if(k>0) return true;
    else if (k==0&&distan(a[0],a1)<distan(a[0],b1))
    {
        return true;
    }
    else return false;
}
void anglesort(int n)
{
    int i,k=0;
    node temp;
    for(i=1;i<n;i++)
    {
        if(a[i].y<a[k].y||(a[i].y==a[k].y&&a[i].x<a[k].x))
            k=i;
    }
    temp=a[0];
    a[0]=a[k];
    a[k]=temp;
    sort(a+1,a+n,cmp);
}
void Graham(int n)
{
    anglesort(n);
    int i,head;
    double sum=0;
    a[n]=a[0];
    stack1[0]=a[0];
    stack1[1]=a[1];
    stack1[2]=a[2];
    head=2;
    for(i=3;i<=n;i++)
    {
       while(head>=2  && (across(stack1[head-1],stack1[head],a[i])<=0)) head--;
       stack1[++head]=a[i];
    }
    for(i=0;i<head;i++)
    {
        sum+=distan(stack1[i],stack1[i+1]);
    }
    printf("%.2lf\n",sum);
}
int main()
{
    int i,n;
    while(scanf("%d",&n),n)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&a[i].x,&a[i].y);
        }
        if(n==1)
        {
            printf("0.00\n");
            continue;
        }
        if(n==2)
        {
            printf("%.2lf\n",distan(a[0],a[1]));
            continue;
        }
        Graham(n);
    }
    return 0;
}
