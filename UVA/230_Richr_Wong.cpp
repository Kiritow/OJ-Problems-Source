#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#include<map>
using namespace std;
const int maxx=1010;
typedef struct Node
{
    string book,name;
    bool operator<(const struct Node &x)const
    {
        if(name!=x.name) return name<x.name;
        return book<x.book;
    }
}node;
int main()
{
    set<node> st;
    map<string,string> mp;
    string s;
    node tnode;
    int p;
    while(getline(cin,s))
    {
        if(s[0]=='E') break;
        p=s.find('"',1);
        tnode.book=s.substr(0,p+1);
        tnode.name=s.substr(p+5);
        mp.insert(make_pair(tnode.book,tnode.name));
        st.insert(tnode);
    }
    set<node> st1;
    while(getline(cin,s))
    {
        if(s[0]=='E') break;
        if(s[0]=='S')
        {
            set<node>::iterator it,it1;
            for(it=st1.begin();it!=st1.end();it++)
            {
                cout<<"Put "<<it->book<<" ";
                it1=st.lower_bound(*it);
                if(st.empty()||it==st.begin()) cout<<"first"<<endl;
                else cout<<"after "<<(--it1)->book<<endl;
                st.insert(*it);
            }
            st1.clear();
            cout<<"END"<<endl;
        }
        else
        {
            p=s.find('"');
            string book=s.substr(p);
            tnode.book=book;
            tnode.name=mp[book];
            if(s[0]=='B') st.erase(tnode);
            else st1.insert(tnode);
        }
    }
}
