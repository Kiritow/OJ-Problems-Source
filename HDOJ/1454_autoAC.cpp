#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
const double precision=1e-3;
const double inf=99999.0;   
typedef class Node  
{
public:
    double x;
    double y;
}point;
int max(int a,int b)
{
    return a>b?a:b;
}
int dblcmp(double p)
{
    if(fabs(p)<precision)    
        return 0;       
    return p>0?1:-1;
}
double det(double x1,double y1,double x2,double y2)
{
    return x1*y2-x2*y1;
}
double cross(point A,point B,point P)
{
    return det(B.x-A.x , B.y-A.y , P.x-A.x , P.y-A.y);
}
bool check(point A,point B,point C,point D)
{
    return (dblcmp(cross(A,B,C)) * dblcmp(cross(A,B,D)) <= 0);
}
double intersection(point A,point B,point C,point D)
{
    double area1=cross(A,B,C);
    double area2=cross(A,B,D);
    int c=dblcmp(area1);
    int d=dblcmp(area2);
    if(c*d<0) 
        return (area2*C.x - area1*D.x)/(area2-area1);  
    if(c*d==0)   
        if(c==0)
            return C.x;
        else
            return D.x;
    return -inf; 
}
int main(int i,int j,int k)
{
    int n;    
    while(cin>>n)
    {
        if(!n)
            break;
        point* up=new point[n+1];         
        point* down=new point[n+1];       
        double max_x=-inf;  
        for(i=1;i<=n;i++)
        {
            cin>>up[i].x>>up[i].y;
            down[i].x=up[i].x;
            down[i].y=up[i].y-1;
        }
        bool flag=false;  
        for(i=1;i<=n;i++) 
        {
            for(j=1;j<=n;j++)
                if(i!=j)
                {
                    for(k=1;k<=n;k++)     
                        if(!check(up[i],down[j],up[k],down[k]))   
                            break;
                    if(k>n)
                    {
                        flag=true;
                        break;
                    }
                    else if(k>max(i,j))                    {                   
                        double temp=intersection(up[i],down[j],up[k],up[k-1]);
                        if(max_x < temp)  
                            max_x=temp;
                        temp=intersection(up[i],down[j],down[k],down[k-1]);
                        if(max_x < temp)  
                            max_x=temp;
                    }
                }
            if(flag)
                break;
        }
        if(flag)
            cout<<"Through all the pipe."<<endl;
        else
            cout<<fixed<<setprecision(2)<<max_x<<endl;
        delete up,down;
    }
    return 0;
}
