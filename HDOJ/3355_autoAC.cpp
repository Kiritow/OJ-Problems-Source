#include<iostream>
#include<map>
#include<string>
#include<queue>
using namespace std;
bool is(string s)
{
        int i,k=0,flag=0,t=0;
    int n=s.size();
    for(i=0;i<n;++i) {
        if(s[i]=='W'&&flag==1) k++;
        if(s[i]=='B') {
            flag=1;
            if(k!=0) {
                t=1;
                break;
            }
        }
    }
    if(t) return false;
    else return true;
}
int BFS(string s)
{
        queue<string> Qu;
        int len=s.size(),f;
        string u,v;
        map<string,int> step;
        step[s]=0;
        Qu.push(s);
        while(!Qu.empty()) {
                u=Qu.front();
                Qu.pop();
                if(step[u]>=10) return -1;
                f=u.find('F');
                v=u;
                if(f+1<len) {
                        v[f]=v[f+1];
                        v[f+1]='F';
                        if(step.find(v)==step.end()) {
                                step[v]=step[u]+1;
                                if(is(v)) return step[v];
                                Qu.push(v);
                        }
                }
                v=u;
                if(f-1>=0) {
                        v[f]=v[f-1];
                        v[f-1]='F';
                        if(step.find(v)==step.end()) {
                                step[v]=step[u]+1;
                                if(is(v)) return step[v];
                                Qu.push(v);
                        }
                }
                v=u;
                if(f+2<len) {
                        if(v[f+2]=='B')
                                v[f]='W';
                        if(v[f+2]=='W')
                                v[f]='B';
                        v[f+2]='F';
                        if(step.find(v)==step.end()) {
                                step[v]=step[u]+1;
                                if(is(v)) return step[v];
                                Qu.push(v);
                        }
                }
                v=u;
                if(f-2>=0) {
                        if(v[f-2]=='B')
                                v[f]='W';
                        if(v[f-2]=='W')
                                v[f]='B';
                        v[f-2]='F';
                        if(step.find(v)==step.end()) {
                                step[v]=step[u]+1;
                                if(is(v)) return step[v];
                                Qu.push(v);
                        }
                }
        }
        return -1;
}
int main()
{
        string state;
        int count=1,r;
        while(cin>>state)
        {
                if(state[0]=='-') break;
                if(is(state)) cout<<count++<<". 0"<<endl;
                else {
                        r=BFS(state);
                        r==-1?cout<<count++<<". -1"<<endl:cout<<count++<<". "<<r<<endl;
                }
        }
        return 0;
}
