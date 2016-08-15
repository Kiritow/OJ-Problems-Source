#include <iostream>
#include <string.h>
#include <algorithm>
#include <map>
using namespace std;
struct p{
    char s[100];
    int num;
}a[100];
bool cmp(p a,p b)
{
    return a.num>b.num;
}
int main()
{
    int n,m,i,j,z=1;
    char b[100];
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        memset(a,0,sizeof(a));
        getchar();
        map<string,int>q;
        for(i=0;i<n;i++)
        {
            scanf("%s",b);
            q[b]=1;
        }
           getchar();
        for(i=0;i<m;i++)
        {
            gets(a[i].s);
            int t=strlen(a[i].s);
            string w="";
            char x[100];
            strcpy(x,a[i].s);
            for(j=0;j<t;j++)
            {
                if(x[j]>=65&&x[j]<=90)
                    x[j]+=32;
            }
            for(j=0;j<t;j++)
            {
                if(x[j]>=97&&x[j]<=122)
                    w=w+x[j];
                else
                {
                    map<string,int>::iterator it;
                    it=q.find(w);
                    if(it!=q.end())
                        a[i].num++;
                    w="";
                }
            }
        }
        sort(a,a+m,cmp);
        int v=a[0].num;
        printf("Excuse Set #%d\n",z);
        z++;
        for(i=0;i<m;i++)
        {
            if(a[i].num==v)
                printf("%s\n",a[i].s);
            else
                break;
        }
        printf("\n");
    }
    return 0;
}
