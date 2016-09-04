#include "iostream"
using namespace std;
struct node 
{
    int num,pre;
    double weight;
}no[1009];  
double rule[1009],dev;
int e,res;
double w[110],up,down;
bool place(int s)
{
    int i,j,k = e;
    double t;
    for (i = 0; i < k;i++)
    {
        t = no[i].weight + w[s];
        if (rule[(int)(t/dev)] == -1 && t <= up)
        {
            rule[(int)(t/dev)] = t;
            no[e].num = s;
            no[e].pre = i;
            no[e++].weight = t;
            if (t >= down)
            {
                res = e-1;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    int i,j,k,n;
    double sum;
    no[0].num = -1;
    no[0].weight = 0;
    rule[0] = 0;
    while (scanf("%d",&n) && n)
    {
        e = 1;
        sum = 0;
        for (i = 1;i <= n;i++)
        {
            scanf("%lf",&w[i]);
            sum += w[i];
        }
        down = sum /2.01;
        up = sum /1.985; 
        dev = sum/1000;
        for (i = 1;i <= 1000;i++)
        {
            rule[i] = -1;
        }
        for (i = 1;i <= n;i++)
        {
            if(place(i)){
                printf("%d",no[res].num);
                i = no[res].pre;
                while(i > 0)
                {
                    printf(" %d",no[i].num);
                    i = no[i].pre;
                }
                printf("\n");
                break;
            }
        }
    }
    return 0;
}
