#include<cstdio>
#include<cstring>
#include<map>
#include<queue>
#include<cstdlib>
using namespace std;
int cvr[6][12]={
    {4,12,13,5,3,2,11,19,20,21,14,6},
    {12,13,5,4,11,19,20,21,14,6,3,2},
    {7,6,14,15,1,3,5,13,21,23,16,8},
    {6,14,15,7,5,13,21,23,16,8,1,3},
    {1,0,2,3,8,9,10,11,4,5,6,7},
    {0,2,3,1,10,11,4,5,6,7,8,9}};
int block[8][3]={
    {3,5,6},{1,7,8},{0,9,10},{2,4,11},
    {12,19,20},{13,14,21},{15,16,23},{17,18,22}};
struct S{
    char s[30];
    friend bool operator< (const S& a,const S& b){
        return strcmp(a.s,b.s)<0;
    }
    void change(){
        map<char,char> col;
        map<char,bool> flag;
        col[s[17]]='B'; flag[s[17]]=true;
        col[s[18]]='W'; flag[s[18]]=true;
        col[s[22]]='Y'; flag[s[22]]=true;
        for(int i=0;i<7;i++){
            int cnt=0,sum=0,has=3;
            if(flag[s[block[i][0]]]){cnt++;sum+=col[s[block[i][0]]];has-=0;}
            if(flag[s[block[i][1]]]){cnt++;sum+=col[s[block[i][1]]];has-=1;}
            if(flag[s[block[i][2]]]){cnt++;sum+=col[s[block[i][2]]];has-=2;}
            if(cnt!=2) continue;
            if(sum=='B'+'W') col[s[block[i][has]]]='O';
            if(sum=='B'+'Y') col[s[block[i][has]]]='G';
            if(sum=='Y'+'W') col[s[block[i][has]]]='R';
        }
        for(int i=0;i<24;i++){
            s[i]=col[s[i]];
        }
    }
}s;
map<S,int> step;
void in(char &c){
     c=getchar();
     while(c<=32) c=getchar();
}
void bfs0(){
    strcpy(s.s,"OOOORRGGBBWWRRGGBBWWYYYY");
    step.clear();
    step[s]=-1;
    queue<pair<S,int> > que;
    que.push(make_pair(s,0));
    while(!que.empty()){
        S u=que.front().first;
        int d=que.front().second;
        que.pop();
        for(int i=0;i<6;i++){
            S v=u;
            for(int j=0;j<12;j++){
                v.s[cvr[i][j]]=u.s[cvr[i^1][j]];
            }
            if(step[v]) continue;
            step[v]=d+1;
            if(d<6){
                que.push(make_pair(v,d+1));
            }
        }
    }
}
map<S,bool> vis;
int bfs1(){
    s.change();
    if(step[s]){
        if(step[s]==-1) return 0;
        else return step[s];
    }
    vis.clear();
    vis[s]=true;
    queue<pair<S,int> > que;
    que.push(make_pair(s,0));
    while(!que.empty()){
        S u=que.front().first;
        int d=que.front().second;
        que.pop();
        for(int i=0;i<6;i++){
            S v=u;
            for(int j=0;j<12;j++){
                v.s[cvr[i][j]]=u.s[cvr[i^1][j]];
            }
            if(vis[v]) continue;
            vis[v]=true;
            if(step[v]){
                if(step[v]==-1) return d+1;
                else return step[v]+d+1;
            }
            que.push(make_pair(v,d+1));
        }
    }
    return -1;
}
int main(){
    bfs0();
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<24;i++){
            in(s.s[i]);
        }
        int ans=bfs1();
        printf("%d\n",ans);
    }
}
