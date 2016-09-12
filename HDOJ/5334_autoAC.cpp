#include<stdio.h>
#include<string.h>
int a[1000000],ans[1000000];
int cnt;
int f(int x){
    int l=1,r=cnt;
    int mid;
    while(l<r){
        mid=(l+r)/2;
        if(x>a[mid]) l=mid+1;
        else r=mid;
    }
    return r;
}
int main(){
    int k,l,r;
    cnt=1;
    a[0]=0;
    for(cnt=1;;cnt++){
        if(cnt+a[cnt-1]>1000000000) {a[cnt]=cnt+a[cnt-1]; break;}
        else a[cnt]=cnt+a[cnt-1];
    }
    while(scanf("%d",&k)!=EOF){
        if(k<=100000){
            printf("%d\n",k);
            for(int i=1;i<k;i++)
            printf("1 ");
            printf("1\n");
        }
        else {
            int tmp=f(k);
            while(k>a[tmp]) tmp++;
            if(k==a[tmp]){
                printf("%d\n",tmp);
                for(int i=1;i<tmp;i++){
                    printf("%d ",i);
                }
                printf("%d\n",tmp);
            }
            else {
                l=tmp-1;
                r=tmp;
                int x=a[tmp]-k,c=1,d;
                while(x){
                    d=f(x);
                    if(x==a[d]){
                        ans[c++]=d+1;
                        break;
                    }
                    else {
                        ans[c++]=d;
                        x-=a[d-1];
                    }
                }
                int t=1,sum=0;
                printf("%d\n",tmp);
                for(int i=1;i<c;i++){
                    sum+=ans[i];
                    for(int j=1;j<=ans[i];j++)
                    {
                    printf("%d",t);
                    if(sum!=tmp) printf(" ");
                    else {
                        if(j==ans[i]) printf("\n");
                        else printf(" ");
                    }
                    }
                    t++;
                }
                if(sum<tmp)
                {for(int i=sum+1;i<tmp;i++){
                    printf("%d ",t);t++;
                }
                printf("%d\n",t);}
            }
        }
    }
    return 0;
}
