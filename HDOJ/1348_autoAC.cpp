#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cmath>
#include<cstdlib>
const int MAX=1001;
const double PI=3.1415926;
int n;
int top;
using namespace std;
typedef struct Node
{
    double x;
    double y;
};
Node s[MAX],stack[MAX];
double Distance(Node a,Node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double  Mul(Node p2, Node p1, Node p0)
{
    return (p2.x - p0.x) * (p1.y - p0.y) - (p1.x - p0.x) * (p2.y - p0.y);
}
bool cmp(Node p2,Node p1)
{
    double m;
    m=Mul(p2,p1,s[0]);
    if(m>0||(!m&&Distance(s[0],p2)<Distance(s[0],p1)))
    return true;
    return false;
}
void convex_hull()
{
    int i;
    for(i=1;i<n;i++)
    {
        Node temp;
        if(s[i].y<s[0].y||(s[i].y==s[0].y&&s[i].x<s[0].x))
        {
            temp=s[0];
            s[0]=s[i];
            s[i]=temp;
        }
    }
    sort(s+1,s+n,cmp);
    top=1;
    stack[0]=s[0];
    stack[1]=s[1];
    for(i=2;i<n;i++)
    {
        while(top>=1&&Mul(s[i],stack[top],stack[top-1])>=0)
        top--;
        top++;
        stack[top]=s[i];
    }
}
int main()
{
    int i,p=0,t,l;
    double sum;
    while(cin>>t)
    {
        while(t--)
        {
            cin>>n>>l;
            cout.setf(ios::fixed);
            cout.precision(0);
            for(i=0;i<n;i++)
            cin>>s[i].x>>s[i].y;
            convex_hull();
            sum=0;
            for(i=0;i<top;i++)
            {
                sum+=Distance(stack[i],stack[i+1]);
            }
            sum+=Distance(stack[0],stack[top]);
            sum+=2*double(l)*PI;
            cout<<sum<<endl;
            if(t)
            cout<<endl;
        }
    }
    return 0;
}
