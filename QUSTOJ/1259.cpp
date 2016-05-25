#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
 
int org[4];
int code[4];
int inc[4];
 
int main()
{
    scanf("%d%*c%d%*c%d%*c%d",org,org+1,org+2,org+3);
    scanf("%d%*c%d%*c%d%*c%d",code,code+1,code+2,code+3);
    for(int i=0;i<4;i++)
    {
        org[i]=org[i]&code[i];
    }
    int n;
    scanf("%d",&n);
    int i;
    for(;n>0;n--)
    {
        scanf("%d%*c%d%*c%d%*c%d",inc,inc+1,inc+2,inc+3);
        for(i=0;i<4;i++)
        {
            if(org[i]!=(inc[i]&code[i]))
            {
                break;
            }
        }
        if(i==4)
        {
            printf("INNER\n");
        }
        else
        {
            printf("OUTER\n");
        }
    }
    return 0;
}
