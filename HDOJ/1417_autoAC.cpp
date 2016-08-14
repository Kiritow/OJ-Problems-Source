#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data
{
    int x1,y1,z1;
    int x2,y2,z2;
    data(){}
    data(int _x,int _y,int _z,int _d)
    {
        x1=_x;y1=_y;z1=_z;
        x2=_x+_d;y2=_y+_d;z2=_z+_d;
    }
    data(int _x1,int _y1,int _z1,int _x2,int _y2,int _z2)
    {
        x1=_x1;y1=_y1;z1=_z1;
        x2=_x2;y2=_y2;z2=_z2;
    }
    bool ok()
    {
        return x1<x2&&y1<y2&&z1<z2;
    }
    int volume()
    {
        if(ok())
            return (x2-x1)*(y2-y1)*(z2-z1);
        else
            return 0;
    }
};
data inter(data a,data b)
{
    if(a.ok())
        return data(max(a.x1,b.x1),max(a.y1,b.y1),max(a.z1,b.z1),min(a.x2,b.x2),min(a.y2,b.y2),min(a.z2,b.z2));
    else
        return data(0,0,0,-1);
}
int main()
{
    int n,x,y,z,d;
    while(scanf("%d",&n),n)
    {
        scanf("%d%d%d%d",&x,&y,&z,&d);
        data ans(x,y,z,d);
        for(int i=1;i<n;i++)
        {
            scanf("%d%d%d%d",&x,&y,&z,&d);
            ans=inter(ans,data(x,y,z,d));
        }
        printf("%d\n",ans.volume());
    }
    return 0;
}
