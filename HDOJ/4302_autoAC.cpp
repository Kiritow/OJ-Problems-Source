#include <queue>
#include <iostream>
#define LL __int64
using namespace std;
struct cmp
{
    bool operator()(LL a, LL b)
    {
        return a > b;
    }
};
int main()
{
    int t,l,n,f1,f2;
    LL sum,a,b,x,y;
    int i,j;
    scanf("%d", &t);
    for(j = 0; j < t; j++)
    {    
        priority_queue<LL> asc;
        priority_queue<LL, vector<LL>, cmp> desc;
        scanf("%d%d", &l, &n);
        y = 0;
        sum = 0;
        for(i = 0; i < n; i++)
        {
            scanf("%d", &f2);
            if(!f2)
            {
                scanf("%I64d", &x);
                if(x > y) desc.push(x);
                else asc.push(x);
            }
            else
            {
                a = b = -1;
                if(!asc.empty()) b = asc.top();
                if(!desc.empty()) a = desc.top();
                if(b == y)
                {
                    asc.pop();
                    continue;
                }
                if(a+1 && b+1)
                {
                    if(a-y > y-b)
                    {
                        sum += y-b;
                        y = b;
                        asc.pop();
                        f1 = 0;
                    }
                    else if(a-y == y-b)
                    {
                        sum += a-y;
                        if(f1) {y = a; desc.pop();}
                        else {y = b; asc.pop();}
                    }
                    else
                    {
                        sum += a-y;
                        y = a;
                        desc.pop();
                        f1 = 1;
                    }
                }
                else if(a+1)
                {
                    sum += a-y;
                    y = a;
                    desc.pop();
                    f1 = 1;
                }
                else if(b+1)
                {
                    sum += y-b;;
                    y = b;
                    asc.pop();
                    f1 = 0;
                }
            }
        }
        printf("Case %d: %I64d\n", j+1, sum);
    }
    return 0;
}
