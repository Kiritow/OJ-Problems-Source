#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=1003;
double y[2*MAXN];
struct Line
{
    double x;
    double up,down;
    int mark;
    bool operator <(const Line a)const
    {
        return x<a.x;
    }
}L[2*MAXN];
struct node
{
    double x;
    double up,down;
    int cover;
    bool isLeaf;
}T[20*MAXN];
void build(int k,int left,int right)
{
    T[k].x=-1;
    T[k].down=y[left];
    T[k].up=y[right];
    T[k].cover=0;
    if(left+1==right)
    {
        T[k].isLeaf=true;
        return;
    }
    T[k].isLeaf=false;
    int mid=(left+right)/2;
    build(2*k+1,left,mid);
    build(2*k+2,mid,right);
}
double insert(int k,double x,double down,double up,int mark)
{
    if(T[k].down>=up||T[k].up<=down)
        return 0;
    if(T[k].isLeaf)
    {
        double s=0;
        if(T[k].cover>1)
        {
            double xx=T[k].x;
            s=(x-xx)*(T[k].up-T[k].down);
        }
        T[k].x=x;
        T[k].cover+=mark;
        return s;
    }
    double s1=insert(2*k+1,x,down,up,mark);
    double s2=insert(2*k+2,x,down,up,mark);
    return s1+s2;
}
int main()
{
    int T,N;
    double area,x1,x2,y1,y2;
    scanf("%d",&T);
    while(T--)
    {
        area=0;
        scanf("%d",&N);
        for(int i=0,num=-1;i<N;++i)
        {
            scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
            L[++num].x=x1;
            L[num].down=y1;
            L[num].up=y2;
            L[num].mark=1;
            y[num]=y1;
            L[++num].x=x2;
            L[num].down=y1;
            L[num].up=y2;
            L[num].mark=-1;
            y[num]=y2;
        }
        sort(L,L+2*N);
        sort(y,y+2*N);
        build(0,0,2*N-1);
        for(int i=0;i<2*N;++i)
            area+=insert(0,L[i].x,L[i].down,L[i].up,L[i].mark);
        printf("%.2f\n",area);
    }
    return 0;
}
