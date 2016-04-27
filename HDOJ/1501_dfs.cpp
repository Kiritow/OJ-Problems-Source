#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char a[300];
char b[300];
char c[700];

int lena,lenb,lenc;
bool dfs(int pos_in_a,int pos_in_b,int pos_in_c)
{
    if(pos_in_a==lena&&pos_in_b==lenb)
    {
        return true;
    }
    if(pos_in_a<lena&&a[pos_in_a]==c[pos_in_c]&&dfs(pos_in_a+1,pos_in_b,pos_in_c+1))
    {
        return true;
    }
    if(pos_in_b<lenb&&b[pos_in_b]==c[pos_in_c]&&dfs(pos_in_a,pos_in_b+1,pos_in_c+1))
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        scanf("%s %s %s",a,b,c);
        printf("Data set %d: ",tt);
        lena=strlen(a);
        lenb=strlen(b);
        lenc=strlen(c);
        if(a[0]!=c[0]&&b[0]!=c[0])
        {
            printf("no\n");
            continue;
        }
        if(a[lena-1]!=c[lenc-1]&&b[lenb-1]!=c[lenc-1])
        {
            printf("no\n");
            continue;
        }
        bool ans=dfs(0,0,0);
        if(ans)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}
