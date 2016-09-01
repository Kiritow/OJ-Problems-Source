#include<iostream>
#include<map>
using namespace std;
int gx[200005],sz[200005];
char s1[200005][25],s2[200005][25];
int find(int p)
{
     if(p!=gx[p])
     {
         gx[p]=find(gx[p]);
     }
     return gx[p];
}
int unions(int p,int q)
{
    int i=find(p),j=find(q);
    if(i==j) return sz[j];
    gx[i]=j;
    sz[j]+=sz[i];
    return sz[j];
}
int main()
{
    int n,f,num,i;
    map<string,int>mymap;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&f);
            mymap.clear();
            num=0;
            for(i=1;i<=f;i++)
            {
                scanf("%s%s",s1[i],s2[i]);
                if(!mymap[s1[i]]) mymap[s1[i]]=++num;
                if(!mymap[s2[i]]) mymap[s2[i]]=++num;
            }
            for(i=1;i<=num;i++)
            {
                gx[i]=i;
                sz[i]=1;
            }
            for(i=1;i<=f;i++)
               printf("%d\n",unions(mymap[s1[i]],mymap[s2[i]]));
        }
    }
    return 0;
}
