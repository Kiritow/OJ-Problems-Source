#include<iostream>
#include<set>
using namespace std;
struct node
{
    node(int a,int b):num(a),p(b){}
    int num;
    int p;
    bool operator < (const node a)const
    {
        return p<a.p;
    }
};
int main()
{
    int com,k,p;
    set<node> s;
    while(cin>>com&&com)
    {
        switch(com)
        {
            case 1:
            {
                cin>>k>>p;
                s.insert(node(k,p));
            }break;
            case 2:
            {
                if(s.empty())
                    cout<<0<<endl;
                else
                {
                    cout<<(*(--s.end())).num<<endl;
                    s.erase(--s.end());
                }
            }break;
            case 3:
            {
                if(s.empty())
                    cout<<0<<endl;
                else
                {
                    cout<<(*s.begin()).num<<endl;
                    s.erase(s.begin());
                }
            }break;
        }
    }
    return 0;
}
