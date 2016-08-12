#include <stdio.h>
int main(){
    int yy,mm,dd;
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d%d%d",&yy,&mm,&dd);
        if( ((mm + dd) & 1) ==0 )
            puts("YES");
        else if(dd==30 && ( mm == 9 || mm == 11))
            puts("YES");
        else puts("NO");
    }
    return 0;
}
