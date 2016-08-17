#include<iostream>
using namespace std;
struct Pair
{
    int from,conflict;
};
Pair *record;
int find(int x)
{
    if(x==record[x].from)
    return x;
    return record[x].from=find(record[x].from);
}
void link(int a,int b)
{
    int fa=find(a);
    int fb=find(b);
    if(fa!=fb)
    record[fb].from=fa;
}
int main()
{
    int t;
    int cnt=1;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        bool flag=false;
        scanf("%d %d",&n,&m);
        record=new Pair[n+1];
        for(int i=1;i<=n;i++)
        {
            record[i].from=i;
            record[i].conflict=0;
        }
        int a,b;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            int fa=find(a);
            int fb=find(b);
            if(fa==fb)flag=true;
            if(record[a].conflict!=0)
            {
                link(b,record[a].conflict);
            }
            if(record[b].conflict!=0)
            {
                link(a,record[b].conflict);
            }
            record[a].conflict=b;
            record[b].conflict=a;
        }
        cout<<"Scenario #"<<cnt<<":\n";
        if(flag)cout<<"Suspicious bugs found!\n";
        else cout<<"No suspicious bugs found!\n";
        cout<<endl;
        cnt++;
    }
    return 0;
}
