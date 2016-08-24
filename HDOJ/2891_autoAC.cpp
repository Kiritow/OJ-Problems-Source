#include<cstdio>
#include<algorithm>
using namespace std;
int h[10004];
struct add{
    int t;
    int a;
    int minn;
}ad[10004];
bool cmp(add a, add b){
    if(a.a == b.a)
        return a.t > b.t;
    else
        return a.a < b.a;
}
bool comp(add a, int sum){
    return a.a < sum;
}
int main(){
    int n, m, hp;
    while(~scanf("%d%d%d", &n, &m, &hp)){
        h[0] = 0;
        for(int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        for(int i = 0; i < m; i++)
        {
            scanf("%d%d", &ad[i].t, &ad[i].a);
            ad[i].minn = n;
        }
        sort(ad, ad+m, cmp);
        int sum = 0, ans = 0;
        for(int i = n; i > 0; i--){
            sum += h[i];
            if(sum > ans)
                ans = sum;
            int n = lower_bound(ad, ad+m, sum, comp) - ad;
            bool boo = false;
            for(int j = n; j < m; j++){
                if(i <= ad[j].minn){
                    boo = true;
                    ad[j].minn -= ad[j].t;
                    sum = 0;
                    break;
                }
            }
            if(!boo)
                for(int j = n-1; j >= 0; j--){
                    if(i <= ad[j].minn){
                        ad[j].minn -= ad[j].t;
                        sum -= ad[j].a;
                        if(sum < 0){
                            sum = 0;
                            break;
                        }
                    }
                }
        }
        if(hp-ans <= 0)
            puts("Die");
        else
            printf("%d\n", hp-ans); 
    }
}
