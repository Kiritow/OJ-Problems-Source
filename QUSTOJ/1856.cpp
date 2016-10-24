#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
int main()
{
    int t;
    scanf("%d",&t);
    int tmp;
    for(int i=0;i<t;i++)
    {
        scanf("%d",&tmp);
        a.push_back(tmp);
    }
    int id;
    int val;
    scanf("%d %d",&id,&val);
    if(id<1||id>(int)a.size()+1)
    {
        printf("对不起，插入位置错误！\n");
        return 0;
    }
    a.insert(a.begin()+id-1,val);
    for(int i=0;i<(int)a.size()-1;i++)
    {
        printf("%d ",a.at(i));
    }
    printf("%d\n",a.at(a.size()-1));
    return 0;
}
/*
5
2 4 6 8 10
7 2

8
1 2 3 4 5 6 7 8
7 9

*/
