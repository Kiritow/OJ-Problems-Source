#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char str[2000100];
char t[100100];
pair<int,int>s[100100];
int index[100100];
int n;
int ne[100100];
void get_next(char* str,int len){
    ne[0]=0;
    for(int i=1;i<len;i++){
        int j=ne[i-1];
        while(j&&str[i]!=str[j])j=ne[j-1];
        if(str[i]==str[j])j++;
        ne[i]=j;
    }
}
bool match(char *s,int len){
    int k=0;
    for(int i=0;i<n;i++){
        while(k&&str[k]!=s[i])k=ne[k-1];
        if(str[k]==s[i])k++;
        if(k==len)return true;
    }
    return false;
}
int main(){
    while(~scanf("%s",str)){
        n=strlen(str);
        for(int i=0;i<n;i++){
            s[i].first=str[i];
            s[i].second=i;
        }
        stable_sort(s,s+n);
        for(int i=0;i<n;i++)index[i]=s[i].second;
        int now=index[0];
        n--;
        for(int i=0;i<n;i++){
            t[i]=s[now].first;
            now=index[now];
        }
        t[n]='\0';
        int q;
        scanf("%d",&q);
        while(q--){
            scanf("%s",str);
            int len=strlen(str);
            get_next(str,len);
            if(match(t,len))printf("YES\n");
            else printf("NO\n");
        }
    }
}
