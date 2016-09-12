#include<iostream>
#include<set>
#include<cstdio>
#include<cstring>
#include<cstdio>
using namespace std;
multiset<int> haha;
multiset<int>::iterator it;
int main(){
    int n;
    while(scanf("%d",&n)!=EOF){
        int p,u;
        haha.clear();
        int ans ;
        while(n--){
            scanf("%d",&p);
            if(p == 1) {
                scanf("%d",&u);
                haha.insert(u);
            }
            else if(p == 2){
                if(haha.size() > 0){
                    haha.erase(haha.begin());
                }
            }
            else if(p==3){
                ans = 0;
                if(haha.size() > 0){
                    it = haha.end();
                    it--;
                    ans = *it;
                }
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
