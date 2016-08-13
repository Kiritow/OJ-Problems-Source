#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct node
{
    string friut,place;
    int num;
}f[109];
bool cmp(node p,node q)
{
    if(p.place!=q.place)
    return p.place<q.place;
    return p.friut<q.friut;
}
int main()
{
    int T,n,j,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        cin>>f[i].friut>>f[i].place>>f[i].num;
        f[n+1].place="zzzzzzzzzzzz";
        sort(f+1,f+1+n,cmp);        
        int last=1;
        for(i=1;i<=n;i++)
        {    
            if(f[i].place!=f[i+1].place)
            {
                cout<<f[i].place<<endl;;
                int sum=f[last].num;
                for(j=last+1;j<=i;j++)
                {
                    if(f[j].friut!=f[j-1].friut)
                    {
                        cout<<"   |----"<<f[j-1].friut<<"("<<sum<<")"<<endl;
                        sum=f[j].num;
                    }
                    else
                    sum+=f[j].num;
                }
                cout<<"   |----"<<f[i].friut<<"("<<sum<<")"<<endl;
                last=i+1;
            }
        }
        if(T)puts("");
    }
    return 0;
}
