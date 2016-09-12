#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char str[20010];
int bits[32];
int save[32][20010];
int tmp[32];
int findindex(int i,int key){
    int l=1,r=save[i][0];
    int m,ans=0;
    while(l<=r){
        int m=(l+r)/2;
        if(save[i][m]<=key){
            ans=m;
            l=m+1;
        }      
        else r=m-1;
    }
    return ans;
}
int main(){
    int kase,now,T,K;
    scanf("%d",&kase);
    for(int i=1;i<32;i++) bits[i]=(1<<i);
    while(kase--){
        scanf("%s",str);
        int len=strlen(str);
        for(int i=0;i<31;i++) save[i][0]=0;
        for(int i=0;i<len;i++){
            now=0;
            for(int j=i;j<=min(i+29,len-1);j++){
                now=(now<<1)+(str[j]-'A');
                save[j-i+1][++save[j-i+1][0]]=now;
            }
        }
        for(int i=1;i<=30;i++) sort(save[i]+1,save[i]+save[i][0]+1);
        for(int i=1;i<=30;i++) {
            save[i][0]=unique(save[i]+1,save[i]+save[i][0]+1)-(save[i]+1);
        }
        scanf("%d",&T); int ans,ansbit;
        while(T--){
            scanf("%d",&K);
            ans=-1;
            for(int i=1;i<=30;i++){
                if(K>bits[i]-save[i][0]){
                    K-=(bits[i]-save[i][0]);
                    continue;
                }
                int l=0,r=bits[i]-1;
                while(l<=r){
                    int m=(l+r)>>1;
                    int pos=findindex(i,m);
                    if(K>m+1-pos) l=m+1;
                    else if(K<m+1-pos) r=m-1;
                    else{
                        ans=m;
                        while(ans==save[i][pos]&&pos!=0){
                            ans--; pos--;
                        }
                        break;
                    }
                }
                if(ans!=-1){
                    ansbit=i;
                    break;
                }
            }
            int cnt=0;
            while(ansbit--){
                tmp[cnt++]=ans%2;
                ans/=2;
            }
            while(cnt--)
                printf("%c",tmp[cnt]+'A');
            puts("");
        }
    }
    return 0;
}
