#include<iostream>
#include<cstdio>
using namespace std;
int main(){
    int n;
    while(~scanf("%d",&n)){
        if(n<=3){puts("-1");continue;}
        if(n==4){puts("1 * 2");puts("5 + 3");puts("6 + 4");continue; }
        if(n==5){puts("2 / 3");puts("6 / 4");puts("1 - 7");puts("8 * 5");continue; }
        if(n==6){puts("1 + 2");puts("7 + 3");puts("8 + 4");puts("9 + 5");puts("10 - 6");continue; }
        if(n==7){puts("1 + 2");puts("8 + 3");puts("9 / 4");puts("10 + 5");puts("11 + 6");puts("12 + 7");continue; }
        if(n==8){puts("1 + 2");puts("9 + 3");puts("10 + 4");puts("5 + 6");puts("11 / 12");puts("13 * 7");puts("14 + 8");continue; }
        if(n==9){puts("1 + 2");puts("10 + 3");puts("4 + 5");puts("12 + 6");puts("13 / 7");
                 puts("11 - 14");puts("15 * 8");puts("16 / 9");continue;}
        if(n==10){puts("1 + 2");puts("11 / 3");puts("12 + 4");puts("5 / 6");puts("7 / 8");
                 puts("14 + 15");puts("13 * 16");puts("17 * 9");puts("18 / 10");continue;   }
        if(n==11){puts("1 / 2");puts("12 + 3");puts("4 / 5");puts("6 / 7");puts("14 + 15");puts("13 * 16");
                 puts("17 * 8");puts("18 * 9");puts("19 / 10");puts("20 / 11");continue;  }
        if(n&1){
            puts("1 + 2");printf("%d / 3\n",n+1);
            puts("4 + 5");printf("%d / 6\n",n+3);
            puts("7 + 8");printf("%d / 9\n",n+5);
            puts("10 + 11");printf("%d + 12\n",n+7);printf("%d / 13\n",n+8);
            printf("%d * %d\n",n+2,n+4);printf("%d * %d\n",n+10,n+6);
            printf("%d * %d\n",n+11,n+9);
            int x=n+12,y=14;
            for(int i=1;i<=(n-13)/2;i++){
                printf("%d * %d\n",x++,y++);
                printf("%d / %d\n",x++,y++);
            }
        }else{
            puts("1 + 2");printf("%d + 3\n",n+1);printf("%d + 4\n",n+2);printf("%d / 5\n",n+3);
            puts("6 + 7");
            for(int i=5;i<=8;i++)
                printf("%d + %d\n",n+i,i+3);
            printf("%d / 12\n",n+9);
            printf("%d * %d\n",n+4,n+10);
            int x=n+11,y=13;
            for(int i=1;i<=(n-12)/2;i++){
                printf("%d * %d\n",x++,y++);
                printf("%d / %d\n",x++,y++);
            }
        }
    }
    return 0;
}
