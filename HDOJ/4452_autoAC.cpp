#include<iostream>
using namespace std;
int f[4][2]={-1,0,0,-1,1,0,0,1};
int n;
int x_1,y_1,x_2,y_2;
int dis_1,speed_1,time_1;
int dis_2,speed_2,time_2;
inline int Get_f(char f)
{
    if(f=='N')
        return 0;
    else if(f=='W') 
        return 1;
    else if(f=='S')
        return 2;
    else
        return 3;
}
void Get_next(int &x,int &y,int speed,int &dis)
{
    int temp=2*(n-1);
    speed%=temp;
    x+=speed*f[dis][0];
    y+=speed*f[dis][1];
    if(f[dis][0])
    {
        if(x<=0)
        {
            x+=temp;
            dis=2;
            if(x>n&&x<=temp)
            {
                x=2*n-x;
            }
        }
        else if(x>temp)
        {
            x-=temp;
            dis=0;
            if(x>n&&x<=temp)
            {
                x=2*n-x;
            }
        }
        else if(x>n&&x<=temp)
        {
            x=2*n-x;
            dis=0;
        }
    }
    else
    {
        if(y<=0)
        {
            y+=temp;
            dis=3;
            if(y>n&&y<=temp)
            {
                y=2*n-y;
            }
        }
        else if(y>temp)
        {
            y-=temp;
            dis=1;
            if(y>n&&y<=temp)
            {
                y=2*n-y;
            }
        }
        else if(y>n&&y<=temp)
        {
            y=2*n-y;
            dis=1;
        }
    }
}
void run(int k)
{
    int t_1=0;
    int t_2=0;
    x_1=y_1=1;
    x_2=y_2=n;
    while(k--)
    {
        Get_next(x_1,y_1,speed_1,dis_1);
        Get_next(x_2,y_2,speed_2,dis_2);
        t_1++;
        t_2++;
        if(x_1==x_2&&y_1==y_2)
        {
            int temp=dis_1;
            dis_1=dis_2;
            dis_2=temp;
            t_1%=time_1;
            t_2%=time_2;
            continue;
        }
        if(t_1==time_1)
        {
            dis_1++;
            dis_1%=4;
        }
        if(t_2==time_2)
        {
            dis_2++;
            dis_2%=4;
        }
        t_1%=time_1;
        t_2%=time_2;
    }
}
int main()
{
    int k;
    char temp_1[2],temp_2[2];
    while(scanf("%d",&n)!=EOF&&n)
    {
        scanf("%s%d%d",&temp_1,&speed_1,&time_1);
        scanf("%s%d%d",&temp_2,&speed_2,&time_2);
        dis_1=Get_f(temp_1[0]);
        dis_2=Get_f(temp_2[0]);
        scanf("%d",&k);
        run(k);
        printf("%d %d\n",x_1,y_1);
        printf("%d %d\n",x_2,y_2);
    }
    return 0;
}
