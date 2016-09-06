#include<stdio.h> 
int a[110];
int main(){
    int t;
    scanf("%d",&t);
    int ca = 1;
    while(t--){
        int n;
        scanf("%d",&n);
        int i,j;
        for(i=1;i<=n;i++)scanf("%d",&a[i]);
        int win = 0;
        i = 1,j = n;
        while(1){
            if(j-i+1==2){
                if(a[1]>a[2])win = 1;
                else win = 2;
                break;
            }
            int ii = i,jj = j;
            while(ii<=jj){
                a[ii++] += a[jj--];
            }
            i = 1,j = (j+1)/2;
        }
        printf("Case #%d: ",ca++);
        if(win==1)puts("Alice");
        else if(win==2)puts("Bob");
    }
    return 0;
}
