#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
#define inf -0x3f3f3f3f
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define mem(a, b) memset(a, b, sizeof(a))
typedef long long ll;
char s[1010];
int l[1010],r[1010];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        mem0(l);
        mem0(r);
        int len=strlen(s);
        for(int i=len-1;i>=0;i--){
            if(i==len-1)
                r[i]=(s[i]==')');
            else
                r[i]=r[i+1]+(s[i]==')');
        }
        for(int i=0;i<len;i++){
            if(i==0)
                l[i]=(s[i]=='(');     
            else
                l[i]=l[i-1]+(s[i]=='(');
        }
        int ans=INF;
        for(int i=0;i<len;i++)
            ans=min(ans,l[i]+r[i]-1);   
        printf("%d\n",ans);
    }
    return 0;
}
