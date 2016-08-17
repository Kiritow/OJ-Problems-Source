# include <iostream>
# include <algorithm>
# include <string>
# include <vector>
using namespace std;
bool cmp(string a,string b)
{
    int x=0,y=0,i,j;
    for(i=0;i<a.size();i++)
    {
        for(j=i+1;j<a.size();j++)
        {
            if(a[i]>a[j])
                x++;
        }
    }
    for(i=0;i<b.size();i++)
    {
        for(j=i+1;j<b.size();j++)
        {
            if(b[i]>b[j])
                y++;
        }
    }
    return x!=y?x<y:1;
}
int main()
{
    int T,n,m,i;
    string s;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        vector<string>w;
        for(i=0;i<m;i++)
        {
            cin>>s;
            w.push_back(s);
        }
        sort(w.begin(),w.end(),cmp);
        for(i=0;i<m;i++)
            cout<<w[i]<<endl;
    }
    return 0;
}
