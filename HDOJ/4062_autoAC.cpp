#include<cstdio>
#include<cstring>
#include<set>
#include<algorithm>
#include<iostream>
using namespace std;
struct point{
    int h,l;
    friend bool operator <(point p1,point p2){return p1.h<p2.h||(p1.h==p2.h&&p1.l<p2.l);}
};
int h[]={1,1,1,1,1,2,3,4,5,6,7,8,9,9,9,9,9,8,7,6,5,4,3,2};
int l[]={5,7,9,11,13,14,15,16,17,16,15,14,13,11,9,7,5,4,3,2,1,2,3,4};
int hMove[]={0,-1,-1,0,1,1},lMove[]={-2,-1,1,2,1,-1};
int cas,bnum,wnum;char map[19][19];set<point> s,whs;bool hasmove;
int judge(char ch1,char ch2){
    int i,j,cnt1,cnt2;
    for(i=0;i<24;i++){
        if(map[h[i]][l[i]]==ch1){
            for(j=0;j<6;j++){
                cnt1=1;cnt2=0;
                if(map[h[i]+hMove[j]][l[i]+lMove[j]]==0||map[h[i]+hMove[j]][l[i]+lMove[j]]=='.')    
                    continue;
                while(map[h[i]+cnt1*hMove[j]][l[i]+cnt1*lMove[j]]==ch1)    
                    cnt1++;
                if(cnt1>=3)    continue;
                while(map[h[i]+(cnt1+cnt2)*hMove[j]][l[i]+(cnt1+cnt2)*lMove[j]]==ch2)    
                    cnt2++;
                if(cnt2>cnt1){
                    if(map[h[i]-hMove[j]][l[i]-lMove[j]]==0){
                        if(ch1=='B'&&bnum-cnt1<9)   return 2;
                        if(ch1=='W'&&wnum-cnt1<9)   return 0;
                    }
                }
            }
        }
    }
    return 1;
}
int wmove1(int h,int l){
    int j,flag;bool idx;
    for(j=0;j<6;j++){
        idx=false;
        if(map[h+hMove[j]][l+lMove[j]]=='.'){
            swap(map[h][l],map[h+hMove[j]][l+lMove[j]]);
            idx=true;hasmove=true;
        }
        if(idx){
            flag=judge('W','B');
            swap(map[h][l],map[h+hMove[j]][l+lMove[j]]);
            if(flag==1)    return flag;
        }
    }
    return 0;
}
int wmove2(int h1,int l1,int h2,int l2){
    int j,flag;int idx;
    for(j=0;j<6;j++){
        idx=0;
        if(map[h1+hMove[j]][l1+lMove[j]]=='.'&&map[h2+hMove[j]][l2+lMove[j]]=='.'){
            swap(map[h1][l1],map[h1+hMove[j]][l1+lMove[j]]);
            swap(map[h2][l2],map[h2+hMove[j]][l2+lMove[j]]);
            idx=1;
        }
        if(h2-h1==hMove[j]&&l2-l1==lMove[j]){
            if(map[h2+hMove[j]][l2+lMove[j]]=='.'){
                swap(map[h1][l1],map[h2+hMove[j]][l2+lMove[j]]);
                idx=2;
            }
            if(map[h2+hMove[j]][l2+lMove[j]]=='B'&&map[h2+2*hMove[j]][l2+2*lMove[j]]=='.'){
                swap(map[h2+hMove[j]][l2+lMove[j]],map[h2+2*hMove[j]][l2+2*lMove[j]]);
                swap(map[h1][l1],map[h2+hMove[j]][l2+lMove[j]]);
                idx=3;
            }
            if(map[h2+hMove[j]][l2+lMove[j]]=='B'&&map[h2+2*hMove[j]][l2+2*lMove[j]]==0){
                map[h2+hMove[j]][l2+lMove[j]]='W';
                map[h1][l1]='.';
                idx=4;            
            }
        }
        if(idx) hasmove=true;
        if(idx==1){
            flag=judge('W','B');
            swap(map[h1][l1],map[h1+hMove[j]][l1+lMove[j]]);
            swap(map[h2][l2],map[h2+hMove[j]][l2+lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==2){
            flag=judge('W','B');
            swap(map[h1][l1],map[h2+hMove[j]][l2+lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==3){
            flag=judge('W','B');
            swap(map[h1][l1],map[h2+hMove[j]][l2+lMove[j]]);
            swap(map[h2+hMove[j]][l2+lMove[j]],map[h2+2*hMove[j]][l2+2*lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==4){
            flag=judge('W','B');
            map[h2+hMove[j]][l2+lMove[j]]='B';
            map[h1][l1]='W';
            if(flag==1)    return flag;
        }    
    }
    return 0;
}
int wmove3(int h1,int l1,int h2,int l2,int h3,int l3)
{
    int j,flag;int idx;
    for(j=0;j<6;j++){
        idx=0;
        if(map[h1+hMove[j]][l1+lMove[j]]=='.'&&map[h2+hMove[j]][l2+lMove[j]]=='.'
            &&map[h3+hMove[j]][l3+lMove[j]]=='.'){
            swap(map[h1][l1],map[h1+hMove[j]][l1+lMove[j]]);
            swap(map[h2][l2],map[h2+hMove[j]][l2+lMove[j]]);
            swap(map[h3][l3],map[h3+hMove[j]][l3+lMove[j]]);
            idx=1;
        }
        if(h2-h1==hMove[j]&&l2-l1==lMove[j]){
            if(map[h3+hMove[j]][l3+lMove[j]]=='.'){
                swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
                idx=2;
            }
            if(map[h3+hMove[j]][l3+lMove[j]]=='B'&&map[h3+2*hMove[j]][l3+2*lMove[j]]=='.'){
                swap(map[h3+hMove[j]][l3+lMove[j]],map[h3+2*hMove[j]][l3+2*lMove[j]]);
                swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
                idx=3;
            }
            if(map[h3+hMove[j]][l3+lMove[j]]=='B'&&map[h3+2*hMove[j]][l3+2*lMove[j]]==0){
                map[h1][l1]='.';
                map[h3+hMove[j]][l3+lMove[j]]='W';
                idx=4;
            }
            if(map[h3+hMove[j]][l3+lMove[j]]=='B'&&map[h3+2*hMove[j]][l3+2*lMove[j]]=='B'
                &&map[h3+3*hMove[j]][l3+3*lMove[j]]=='.'){
                    swap(map[h3+hMove[j]][l3+lMove[j]],map[h3+3*hMove[j]][l3+3*lMove[j]]);
                    swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
                    idx=5;
            }
            if(map[h3+hMove[j]][l3+lMove[j]]=='B'&&map[h3+2*hMove[j]][l3+2*lMove[j]]=='B'
                &&map[h3+3*hMove[j]][l3+3*lMove[j]]==0){
                    map[h1][l1]='.';
                    map[h2][l2]='.';
                    map[h3+hMove[j]][l3+lMove[j]]='W';
                    map[h3+2*hMove[j]][l3+2*lMove[j]]='W';
                    idx=6;
            }
        }
        if(idx) hasmove=true;
        if(idx==1){
            flag=judge('W','B');
            swap(map[h1][l1],map[h1+hMove[j]][l1+lMove[j]]);
            swap(map[h2][l2],map[h2+hMove[j]][l2+lMove[j]]);
            swap(map[h3][l3],map[h3+hMove[j]][l3+lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==2){
            flag=judge('W','B');
            swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==3){
            flag=judge('W','B');
            swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
            swap(map[h3+hMove[j]][l3+lMove[j]],map[h3+2*hMove[j]][l3+2*lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==4){
            flag=judge('W','B');
            map[h3+hMove[j]][l3+lMove[j]]='B';
            map[h1][l1]='W';
            if(flag==1)    return flag;
        }
        if(idx==5){
            flag=judge('W','B');
            swap(map[h1][l1],map[h3+hMove[j]][l3+lMove[j]]);
            swap(map[h3+hMove[j]][l3+lMove[j]],map[h3+3*hMove[j]][l3+3*lMove[j]]);
            if(flag==1)    return flag;
        }
        if(idx==6){
            flag=judge('W','B');
            map[h1][l1]='W';
            map[h2][l2]='W';
            map[h3+hMove[j]][l3+lMove[j]]='B';
            map[h3+2*hMove[j]][l3+2*lMove[j]]='B';
            if(flag==1)    return flag;
        }
    }
    return 0;
}
void mycin(){
    int i;
    for(i=5;i<=13;i+=2) cin>>map[1][i];
    for(i=4;i<=14;i+=2) cin>>map[2][i];
    for(i=3;i<=15;i+=2) cin>>map[3][i];
    for(i=2;i<=16;i+=2) cin>>map[4][i];
    for(i=1;i<=17;i+=2) cin>>map[5][i];
    for(i=2;i<=16;i+=2) cin>>map[6][i];
    for(i=3;i<=15;i+=2) cin>>map[7][i];
    for(i=4;i<=14;i+=2) cin>>map[8][i];
    for(i=5;i<=13;i+=2) cin>>map[9][i];
}
int main()
{
    int i,j,k=1,flag;point p;
    set<point>::iterator iter;
    scanf("%d",&cas);
    while(cas--){
        s.clear();whs.clear();hasmove=false;
        memset(map,0,sizeof(map));
        mycin();
        for(i=1,wnum=bnum=0;i<=9;i++){
            for(j=1;j<=17;j++){
                if(map[i][j]=='W'){wnum++;p.h=i;p.l=j;whs.insert(p);}
                if(map[i][j]=='B')    bnum++;
            }
        }
        flag=judge('B','W');
        for(iter=whs.begin();iter!=whs.end()&&flag!=2;iter++){
            int h1=iter->h,l1=iter->l;
            flag=wmove1(h1,l1);
            if(flag==1)    break;
        }
        for(iter=whs.begin();iter!=whs.end()&&flag!=1&&flag!=2;iter++){
            for(j=0;j<6&&flag!=1;j++){
                if(map[iter->h+hMove[j]][iter->l+lMove[j]]=='W'){
                    int h1=iter->h,l1=iter->l,h2=h1+hMove[j],l2=l1+lMove[j];
                    flag=wmove2(h1,l1,h2,l2);
                    if(flag==1)    break;
                }
            }
        }
        for(iter=whs.begin();iter!=whs.end()&&flag!=1&&flag!=2;iter++){
            for(j=0;j<6&&flag!=1;j++){
                if(map[iter->h+hMove[j]][iter->l+lMove[j]]=='W'&&map[iter->h+2*hMove[j]][iter->l+2*lMove[j]]=='W'){
                    int h1=iter->h,l1=iter->l,h2=h1+hMove[j],l2=l1+lMove[j],h3=h1+2*hMove[j],l3=l1+2*lMove[j];
                    flag=wmove3(h1,l1,h2,l2,h3,l3);
                    if(flag==1)    break;
                }
            }
        }
        if(hasmove==false&&flag!=2)
            flag=judge('W','B');
        printf("Case %d: ",k++);
        if(flag==0)    printf("Black\n");
        if(flag==1) printf("Draw\n");
        if(flag==2)    printf("White\n");
    }
    return 0;
}
