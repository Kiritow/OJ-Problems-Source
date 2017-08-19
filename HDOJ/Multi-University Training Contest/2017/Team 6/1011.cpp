#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int maxtotal=-1;
        for(int i=0;i<n;i++)
        {
            int a,b,c,ab,bc,ac,abc;
            scanf("%d %d %d %d %d %d %d",&a,&b,&c,&ab,&bc,&ac,&abc);
            int A,B,C,AB,BC,AC,ABC;
            ABC=abc;
            AB=ab-abc;
            BC=bc-abc;
            AC=ac-abc;
            A=a-AB-AC-ABC;
            B=b-AB-BC-ABC;
            C=c-AC-BC-ABC;
            if(A<0||B<0||C<0||AB<0||AC<0||BC<0||AC<0||ABC<0)
            {
                continue;
            }
            int total=A+B+C+AB+AC+BC+ABC;
            maxtotal=max(total,maxtotal);
        }
        printf("%d\n",maxtotal);
    }
    return 0;
}