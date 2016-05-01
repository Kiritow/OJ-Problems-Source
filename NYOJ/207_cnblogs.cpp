#include <cstdio>
#include <iostream>

using namespace std;

const int N = 50005;
int father[N];
int relation[N];//根点节到点节的关系

void init(int n)
{
    for(int i = 0; i <= n; ++i)
    {
        father[i]= i;
        relation[i] = 0;
    }
}
//更新的步调，先将当前点节与其根点节相连，然后更新其与根点节的关系
//当前节点x与根节点r的关系更新的方法：
//    (x与其父点节的关系+其父点节的关系与根点节的关系)%3
//所以在更新节点x的数据之前需要更新其父节点的数据，这是find为什么搞成递归函数的原因
//其更新的次序是从根节点开始往下，始终到当前点节x的父点节。
int find(int x)
{
    if(x != father[x])//不是根点节
    {
        int temp = father[x];
        //将当前点节的父点节设置为根点节
        father[x] = find(temp);
        //更新当前点节与根点节的关系，由x->x父和x父->父根的关系失掉x->父根的关系
        //所以在这之前必须更新其父点节与根点节的关系
        relation[x] = (relation[x] + relation[temp]) % 3;
    }
    return father[x];
}

int main()
{
    int n, m, x, y, d, fx, fy, cnt;

    while(~scanf("%d %d", &n, &m))//POJ上只要需一次入输，所以不要需while循环
    {
        cnt = 0;
        init(n);
        for(int i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &d, &x, &y);
            if(x > n || y > n)
            {
                ++cnt;
                continue;
            }
            if(d == 2 && x == y)
            {
                ++cnt;
                continue;
            }
            fx = find(x);
            fy = find(y);
            if(fx == fy)//属于同一个子集
            {
                //如果x、y是同类，那么他们相对根点节的关系应该是一样的
                if(d == 1 && relation[x] != relation[y])
                    ++cnt;
                //如果不是同类，加入x与y的关系之后，x相对根点节的关系(x根->y,y->x(即3-(d-1)=2).即x根->x)应该是不变的
                //这里d=2表示x - y = 2-1=1;而y->x=3-(x->y)=3-1=2;
                if(d == 2 && relation[x] != (relation[y] + 2)%3)
                    ++cnt;
            }
            else//合并两个连通区域
            {
                father[fy] = fx;//y根的父点节更新成x根
                //(d-1)为x与y的关系，3-relation[y]是y与y的根点节的关系，注意方向，relation[x]是其根点节与x的关系
                //x根->x,x->y,y->y根：即x根->y根
                relation[fy] = (relation[x] + (d-1) + (3-relation[y])) % 3;//注意这里只更新的是fy相对于根的关系
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
