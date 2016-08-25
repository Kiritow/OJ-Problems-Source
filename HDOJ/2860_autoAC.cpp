#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=100111;
int n,m,q;
int pre[N],val[N];
void build()
{
    int i;
    int a,b;
    memset(val,-1,sizeof(val));
    for(i=0;i<n;i++)    pre[i]=i;
    while(m--)
    {
        scanf("%d%d",&a,&b);
        if(val[b]==-1 || a<val[b])    val[b]=a;
    }
}
int find(int k)
{
    if(pre[k]==k)    return k;
    pre[k]=find(pre[k]);
    return pre[k];
}
int main()
{
    int a,b;
    char str[11];
    while(scanf("%d%d%d",&n,&m,&q)!=-1)
    {
        build();
        while(q--)
        {
            scanf("%s",str);
            if(str[0]=='A')
            {
                scanf("%d%d",&a,&b);
                if(pre[b]!=b)    printf("Reject\n");
                else
                {
                    printf("Accept\n");
                    if(val[b]==-1 || a<val[b])    val[b]=a;
                }
            }
            else if(str[0]=='M')
            {
                scanf("%d%d",&a,&b);
                if(pre[a]!=a || pre[b]!=b || a==b)    printf("Reject\n");
                else
                {
                    printf("Accept\n");
                    pre[b]=a;
                    if(val[b]!=-1 && (val[a]==-1 || val[b]<val[a]))    val[a]=val[b];
                }
            }
            else
            {
                scanf("%d",&a);
                if(pre[a]==a && val[a]!=-1)        printf("Lowest rate: %d.\n",val[a]);
                else if(pre[a]==a && val[a]==-1)printf("Company %d is empty.\n",a);
                else if(pre[a]!=a)                printf("Company %d is a part of company %d.\n",a,find(a));
            }
        }
        cout<<endl;
    }
    return 0;
}
