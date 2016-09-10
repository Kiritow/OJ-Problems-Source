#include<iostream>
#include<stdio.h> 
#include<algorithm>
using namespace std;
#include<list>
typedef  pair<long long ,long long > candy;
list<candy> s;
int main()
{
    int n;
    while( scanf("%d",&n) && n ){
        s.clear();
         while(n--){
        long long x,y,z;
        scanf("%I64d%I64d%I64d",&z,&x,&y);
        candy aa ; aa.first=x; aa.second=y;
        if(z==1 ) { s.push_front(aa); }
        else if(z==-1) {
                for(list<candy>::iterator i=s.begin();i!=s.end();i++)
                if((*i).first==x&&(*i).second==y) { s.erase(i); break;  }
        }
        else if(z==0) {
                long long sum=-0x7f7f7f7f;
            for(list<candy>::iterator i=s.begin();i!=s.end();i++) {
                    sum = max(sum, (*i).first*x+(*i).second*y);
            }
            cout<<sum<<endl;
        }
    }
    }
    return 0;
}
