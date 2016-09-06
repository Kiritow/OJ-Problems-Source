#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
struct node
{
    int sum;
    int m;
    int v;
}ne,cur;
vector<node>a,b;
int main()
{
    int num,j,n;
    char k;
    while(scanf("%d",&num)!=EOF)
    {
        a.clear();
        b.clear();
        while(num--)
        {
            getchar();
            scanf("%c",&k);
            if(k=='I')
            {
                scanf("%d",&n);
                ne.m=n;
                ne.v=n;
                ne.sum=n;
                if(a.size()==0)
                    a.push_back(ne);
                else
                {
                    int sz=a.size();
                    cur=a[sz-1];
                    ne.sum = cur.sum + ne.v;
                    ne.m = max(ne.sum,cur.m);
                    a.push_back(ne);
                }
            }
            else if(k=='L')
            {
                int sz = a.size() ;
                if(sz)
                {    
                    cur = a[sz-1] ;
                    a.pop_back();
                    b.push_back(cur);
                }
            }
            else if(k=='R')
            {
                j = b.size();
                if(j)
                {                
                    ne=b[j-1];
                    b.pop_back();
                    ne.sum=ne.v;
                    ne.m=ne.v;
                    int sz = a.size();
                    if(sz==0)
                    {
                        ne.sum=ne.v;
                        ne.m=ne.v;
                        a.push_back(ne);
                    }
                    else
                    {
                        cur = a[sz-1];
                        ne.sum = cur.sum + ne.v;
                        ne.m = max(ne.sum,cur.m);
                        a.push_back(ne);
                    }
                }
            }
            else if(k=='D')
            {
                if(a.size())
                a.pop_back();
            }
            else if(k=='Q')
            {
                scanf("%d",&n);
                printf("%d\n",a[n-1].m);
            }
        }
    }
    return 0;
}
