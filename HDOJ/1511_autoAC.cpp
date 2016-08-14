#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define MAX_N 100
#define max(a,b) (a)>(b)?(a):(b)
int leftdp[MAX_N],rightdp[MAX_N];
char s[MAX_N];
bool compare(int s1,int s2,int t1,int t2){
    while(s[s1]=='0')
        s1++;
    while(s[t1]=='0')
        t1++;
    if(s2-s1!=t2-t1)
        return s2-s1<t2-t1;
    while(s1<s2){
        if(s[s1]!=s[t1])
            return s[s1]<s[t1];
        s1++,t1++;
    }
    return false;
}
void OutputPath(int len){
    int p=rightdp[0],i=0;
    while(i<len){
        while(i<p && i<len)
            cout<<s[i++];
        if(i<len)
            cout<<",";
        p=rightdp[p];
    }
        cout<<endl;
}
int main(){
    while(scanf("%s",&s)!=EOF){
        int i,j,len;
        len=strlen(s);
        if(len==1 && s[0]=='0') 
            break;
        memset(leftdp,0,sizeof(leftdp));
        memset(rightdp,0,sizeof(rightdp));
        for(i=1;i<len;i++)
            for(j=0;j<i;j++)
                if(compare(leftdp[j],j+1,j+1,i+1))
                    leftdp[i]=max(leftdp[i],j+1);
        int tlen=leftdp[len-1];
        rightdp[tlen]=rightdp[tlen+1]=len;
        i=tlen-1;
        while(s[i]=='0')
            rightdp[i--]=len;
        for(i=tlen-1;i>=0;i--)
            for(j=i;j<=tlen;j++)
                if(compare(i,j,j,rightdp[j]))
                    rightdp[i]=max(rightdp[i],j);
        OutputPath(len);
    }
    return 0;
}
