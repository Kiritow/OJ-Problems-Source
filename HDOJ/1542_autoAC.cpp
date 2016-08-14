#include<stdio.h>
#include<algorithm>
using namespace std;
double Y[1000];
typedef struct
{
    double x,up,down;
    int flag;
}node;
node N[1000];
typedef struct
{
    double x,up,down;
    int cover;
    int flag;
}tree;
tree T[1000];
bool cmp(node a,node b)
{
    return a.x<b.x;
}
void buit(int left,int right,int num)
{
    T[num].down=Y[left];
    T[num].up=Y[right];
    T[num].cover=0;
    T[num].flag=0;
    if(left+1==right)
    {
        T[num].flag=1;
        return ;
    }
    int mid=(left+right)/2;
    buit(left,mid,num*2);
    buit(mid,right,num*2+1);
}
double insert(double x,double down,double up,int flag,int num)
{
    if(T[num].up<=down||T[num].down>=up)
    return 0;
    if(T[num].flag)
    {
        if(T[num].cover>0)
        {
            T[num].cover+=flag;
            double xx=T[num].x;
            T[num].x=x;
            return (T[num].x-xx)*(T[num].up-T[num].down);
        }
        else
        {
            T[num].cover+=flag;
            T[num].x=x;
            return 0;
        }
    }
    double s1=insert(x,down,up,flag,2*num);
    double s2=insert(x,down,up,flag,2*num+1);
    return s1+s2;
}
int main()
{
    int i,n,k,c_ase=1;
    double x1,y1,x2,y2,area;
    while(~scanf("%d",&n),n)
    {
    k=1,area=0;    
    for(i=1;i<=n;i++)
    {
        scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
        N[k].x=x1,N[k].up=y2,N[k].down=y1,N[k].flag=1,Y[k++]=y1;
        N[k].x=x2,N[k].up=y2,N[k].down=y1,N[k].flag=-1,Y[k++]=y2;
    }
    sort(Y+1,Y+k);
    sort(N+1,N+k,cmp);
    buit(1,2*n,1);
    for(i=1;i<=2*n;i++)
    area+=insert(N[i].x,N[i].down,N[i].up,N[i].flag,1);
    printf("Test case #%d\nTotal explored area: %.2lf\n",c_ase++,area);
    printf("\n");
    }
    return 0;
}
