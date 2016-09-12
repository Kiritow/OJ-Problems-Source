#include <iostream>
#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
            int T,n;
            double a,b;
            double ap,gp;
            int sumap,sumgp,ans;
            scanf("%d",&T);
            while(T--){
                        scanf("%d",&n);
                        sumap = 2,sumgp = 2,ans = 2;
                        scanf("%lf",&a);
                        if(n==1)    {
                                    printf("1\n");
                                    continue;
                        }
                        scanf("%lf",&b);
                        ap = b-a;
                        gp = b/a;
                        a = b;
                        double tmap,tmgp;
                        for(int i=2;i<n;i++){
                                    scanf("%lf",&b);
                                    tmap = b-a;
                                    tmgp = b/a;
                                    if(ap == tmap)          sumap++;
                                    else{
                                                ans = max(ans,sumap);
                                                sumap = 2;
                                                ap = tmap;
                                    }
                                    if(gp == tmgp)          sumgp++;
                                    else{
                                                ans = max(ans,sumgp);
                                                sumgp = 2;
                                                gp = tmgp;
                                    }
                                    a = b;
                        }
                        ans = max(ans,sumap);
                        ans = max(ans,sumgp);
                        printf("%d\n",ans);
            }
            return 0;
}
