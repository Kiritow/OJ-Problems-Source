#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 999999999
using namespace std;
const int MAX=100000+10;
char s[MAX*2];
int ne[MAX];
void get_next(char *a,int len){
    int i=-1,j=0;
    ne[0]=-1;
    while(j<len){
        if(i == -1 || a[i] == a[j])ne[++j]=++i;
        else i=ne[i];
    }
}
void get_extend(char *a,int len){
    int k=0,i=1;
    ne[0]=len;
    while(k+1<len && a[k] == a[k+1])++k;
    ne[1]=k;
    k=1;
    while(++i<len/2){
        int maxr=k+ne[k]-1;
        ne[i]=min(ne[i-k],max(maxr-i+1,0));
        while(i+ne[i]<len && a[ne[i]] == a[i+ne[i]])++ne[i];
        if(i+ne[i]>k+ne[k])k=i;
    }
}
int main(){
    int t,num=0;
    cin>>t;
    while(t--){
        scanf("%s",s);
        int len=strlen(s);
        get_next(s,len);
        int temp=len%(len-ne[len]) == 0?len/(len-ne[len]):1; 
        for(int i=0;i<=len;++i)s[i+len]=s[i];
        get_extend(s,len+len);
        int a=0,b=0,c=0;
        for(int i=0;i<len;++i){
            if(ne[i]>=len)++b;
            else if(s[ne[i]]<s[i+ne[i]])++c;
            else ++a; 
        }
        cout<<"Case "<<++num<<": "<<a/temp<<' '<<b/temp<<' '<<c/temp<<endl;
    }
    return 0;
}
