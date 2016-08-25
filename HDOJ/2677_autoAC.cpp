#include <cstdio>
#include <map>
#include <string>
using namespace std;
map<string,int>mp,has;
map<string,string>he;
char a[10010];
int n,m,k,u;
int dfs(string s){
    if(mp.count(s))return mp[s]; 
    string l=he[s];
    int price=0;
    for(int i=0;l[i]!='\0';i++){
        if(l[i]==' '||l[i]=='+')continue;
        string g=""; 
        for(;l[i]!='\0'&&l[i]!=' ';i++)
            g+=l[i];
        if(mp.count(g))
            price+=mp[g];
        else{
            mp.insert(make_pair(g,dfs(g)));
            price+=mp[g];
        }
    }
    return price;
}
void dfs(string s,int t){
    if(!he.count(s)){
        has[s]-=t;
        return;
    }
    if(has[s]>=t){
        has[s]-=t;return;
    }
    t=t-has[s];
    has[s]=0; 
    string l=he[s]; 
    for(int i=0;l[i]!='\0';i++){
        if(l[i]==' '||l[i]=='+')continue;
        string g="";
        for(;l[i]!='\0'&&l[i]!=' ';i++)
            g+=l[i];
        dfs(g,t); 
    }
}
void make_map(){
    map<string,string>::iterator i;
    for(i=he.begin();i!=he.end();i++)
        mp.insert(make_pair(i->first,dfs(i->first)));
}
int main(void){
    int t;
    while(~scanf("%d",&n)){
        mp.clear();has.clear();he.clear(); 
        for(int i=1;i<=n;i++){
            scanf("%s %d",a,&t);
            mp.insert(make_pair(a,t)); 
        }
        scanf("%d",&m);
        for(int i=0;i<m;i++){
            scanf("%s %d",a,&t);
            has.insert(make_pair(a,t));
        }
        scanf("%d",&k);
        getchar();
        for(int j=0;j<k;j++){
            gets(a);
            string s="",g="";
            int i;
            for(i=0;a[i]!='=';i++)
                s+=a[i];
            for(i+=2;a[i]!='\0';i++)
                g+=a[i];
            he.insert(make_pair(g,s));
        }
        make_map();
        scanf("%d",&u);
        while(u--){
            scanf("%s %d",a,&t);
            dfs(a,t);
        }
        int ans=0;
        map<string,int>::iterator it;
        for(it=has.begin();it!=has.end();it++){
            if(it->second<0)
                ans+=-(it->second)*mp[it->first];
        }
        printf("%d\n",ans);
    }
    return 0;
}
