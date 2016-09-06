#include<iostream>
#include<list>
#include<cstdio>
#include<algorithm>
using namespace std;
struct node
{
    string name;
    int grade;
    int time;
    node(string s,int a,int b):name(s),grade(a),time(b){}
    friend bool operator<(const node& a,const node& b)
    {
        if(a.grade!=b.grade)
        return a.grade<b.grade;
        else return a.time<b.time;
    }
    friend bool operator==(const node& a,const node& b)
    {
        return a.grade>=b.grade;
    }
};
int main()
{
    int cas,n,num;
    cin>>cas;
    string op,name;
    int time;
    for(int c=1;c<=cas;c++)
    {
        cin>>n;printf("Case #%d:\n",c);
        list<node>li;
        time=1;
        for(int i=0;i<n;i++)
        {
            cin>>op;
            if(op[0]=='A')
            {
                cin>>name>>num;
                li.push_back(node(name,num,i));
                li.sort();
                cout<<li.size()<<endl;
            }
            else
            {
                cin>>num;
                list<node>::iterator iter=find(li.begin(),li.end(),node("",num,0));
                if(iter!=li.end())
                {
                    cout<<iter->name<<endl;
                    li.erase(iter);
                }
                else
                {
                    cout<<"WAIT..."<<endl;
                }
            }
        }
    }
}
