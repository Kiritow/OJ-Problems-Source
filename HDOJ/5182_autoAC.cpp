#include<iostream>
#include<algorithm>
#define maxn 100+5
using namespace std;
struct stu
{
    int id,a,b,c;
};
stu mapp[maxn];
bool cmp(stu x,stu y)
{
    if(x.c==y.c)
    {
        if(x.b==y.b) return x.id<y.id;
        return x.b<y.b;
    }
    return x.c>y.c;
}
int main()
{
    int n;
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            cin>>mapp[i].a>>mapp[i].b;
            mapp[i].c=mapp[i].a-mapp[i].b;
            mapp[i].id=i;
        }
        sort(mapp,mapp+n,cmp);
        cout<<mapp[0].id;
        for(int i=1;i<n;i++) cout<<" "<<mapp[i].id;
        cout<<endl;
    }
    return 0;
}
