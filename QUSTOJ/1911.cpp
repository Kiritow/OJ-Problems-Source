#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> dvec;
int vs[100];
vector<int> vec[100];
bool cmp(const int& a,const int& b)
{
    return a<b;
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++)
    {
        int temp;
        scanf("%d",&temp);
        vs[temp]=i;
        dvec.push_back(temp);
    }
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vec[vs[a]].push_back(vs[b]);
        vec[vs[b]].push_back(vs[a]);
    }
    for(int i=0;i<n;i++)
    {
        printf("%d",dvec.at(i));
        sort(vec[i].begin(),vec[i].end(),cmp);
        int sz=vec[i].size();
        for(int j=0;j<sz;j++)
        {
            printf(" -> %d",dvec.at(vec[i].at(j)));
        }
        printf(" -> NULL\n");
    }
    return 0;
}
