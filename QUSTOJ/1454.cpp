#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
using namespace std;
int a[16][100];
int main()
{
    a[1][1]=1;
    for(int i=2;i<=10;i++)
    {
        a[i][1]=1;
        for(int j=2;j<i;j++)
        {
            a[i][j]=a[i-1][j-1]+a[i-1][j];
        }
        a[i][i]=1;
    }


    int n;
    vector<int> vec;
    while(scanf("%d",&n)==1) vec.push_back(n);
    for(int ci=0;ci<(int)vec.size();ci++)
    {
        n=vec.at(ci);
        for(int line=n;line>=1;line--)
        {
            if(vec.size()>2)
            {
                printf("  ");
            }
            if(vec.size()>2)
            {
                for(int k=0;k<(n-line)*3;k++)
                {
                    printf(" ");
                }
            }
            else
            {
                for(int k=0;k<n-line;k++)
                {
                    printf(" ");
                }
            }
            for(int i=1;i<line;i++)
            {
                printf("%d",a[line][i]);
                if(vec.size()>2)
                {
                    printf("     ");
                }
                else
                {
                    printf(" ");
                }
            }
            printf("%d\n",a[line][line]);
        }
        printf("\n");
    }
    return 0;
}
