#include <iostream>
#include <set>
#include <cstdio>
using namespace std;
multiset<int>mset;
multiset<int>::iterator iter1,iter2;
int main()
{
    int n,x;
    char str[10];
    while(scanf("%d",&n)!=EOF)
    {
        mset.clear();
        while(n--)
        {
            scanf("%s %d",str,&x);
            if(str[1]=='u')
                mset.insert(x);
            else
            {
                if (x<*(mset.begin()))
                {
                    printf("No Element!\n");
                    continue;
                }
                iter1=mset.find(x);
                if(iter1!=mset.end())
                {
                    printf("%d\n",*iter1);
                    mset.erase(iter1);
                }
                else
                {
                    mset.insert(x);
                    iter1=iter2=mset.find(x);
                    iter1--;
                    printf("%d\n",*iter1);
                    mset.erase(iter1);
                    mset.erase(iter2);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
