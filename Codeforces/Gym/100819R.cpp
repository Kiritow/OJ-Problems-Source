/// Problem R - Class Time
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
using namespace std;
#define NAMELEN 128
#define MAXN 105
struct _student
{
    char a[NAMELEN];
    char b[NAMELEN];
};
_student stu[MAXN];

bool cmp(const _student& sta,const _student& stb)
{
    int a=strcmp(sta.b,stb.b);
    if(a==0)
    {
        int b=strcmp(sta.a,stb.a);
        return (b<0);
    }
    return (a<0);
}

int main()
{
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%s %s",stu[i].a,stu[i].b);
    }
    sort(stu,stu+n,cmp);
    for(int i=0;i<n;i++)
    {
        printf("%s %s\n",stu[i].a,stu[i].b);
    }
    return 0;
}
