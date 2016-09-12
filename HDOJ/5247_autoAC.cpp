#include<cstdio>
#include<set>
#include<algorithm>
using namespace std;
typedef long long LL;
const int maxn = 10005;
set<LL>s;
set<LL>::iterator it1,it2;
int n,m;
int num[maxn] = {0};
LL arr[maxn];
int main(){
    scanf("%d%d",&n,&m);
    for(int i = 0; i < n; i++)
        scanf("%I64d",&arr[i]);
    for(int i = 0; i < n; i++){
        s.clear();
        s.insert(arr[i]);
        num[1] ++;
        for(int j = i + 1; j < n; j++){
            if(!s.count(arr[j]))
                s.insert(arr[j]);
            else
                break;
            it1 = s.begin();
            it2 = s.end();
            it2 --;
            LL e1 = *it1,e2 = *it2;
            if(e2 - e1 == s.size() - 1){
                num[s.size()] ++;
            }
        }
    }
    printf("Case #1:\n");
    while(m--){
        int k;
        scanf("%d",&k);
        printf("%d\n",num[k]);
    }
    return 0;
}
