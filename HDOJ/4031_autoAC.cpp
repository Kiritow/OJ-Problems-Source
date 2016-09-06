#include <iostream>
#include <string.h>
using namespace std;
const int MAX = 20000 + 100;
int C[MAX];
int N;
struct Node
{
    int l;
    int r;
};
int LowBit(int x)
{
    return x & (-x);
}
void Update(int num,int key)
{
    while(num <= N)
    {
        C[num] += key;
        num += LowBit(num);
    }
}
int CalSum(int num)
{
    int sum = 0;
    while(num > 0)
    {
        sum += C[num];
        num -= LowBit(num);
    }
    return sum;
}
int main()
{
    int T;
    cin>>T;
    int Case = 0;
    while(T--)
    {
        int Q;
        int CD;
        int time = 0;
        int used_time[MAX] = {0};
        int porected[MAX] = {0};
        Node attack[MAX] = {0};
        memset(C,0,sizeof(C));
        Case++;
        cout<<"Case "<<Case<<":"<<endl;
        scanf("%d%d%d",&N,&Q,&CD);
        int i;
        for(i=0;i<Q;i++)
        {
            char str[20];
            scanf("%s",str);
            if(str[0] == 'A')
            {
                scanf("%d%d",&attack[time].l,&attack[time].r);
                Update(attack[time].l,1);
                Update(attack[time].r+1,-1);
                time++;
            }
            else
            {
                int num;
                scanf("%d",&num);
                int i;
                for(i = used_time[num] ; i< time ;i++)
                {
                    if(attack[i].l <=num    && num <= attack[i].r )
                    {
                        porected[num]++;
                        used_time[num] = i + CD;
                        i = i + CD - 1;
                    }
                }
                printf("%d\n",CalSum(num)-porected[num]);
            }
        }
    }
    return 0;
}
