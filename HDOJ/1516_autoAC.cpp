#include<stdio.h>
#include<string.h>
#define SIZE 80
#define MAX 100000
int Min(int x,int y,int z){
    int min= x<y ? x : y;
    return min<z ? min : z;
}
int main(){
    char s1[SIZE];
    char s2[SIZE];
    int count[SIZE+1][SIZE+1];
    int flag[SIZE][SIZE];
    while(scanf("%s%s",s1,s2)!=EOF){
        //濮flag[][] 
        for(int i=0;i<SIZE;++i)
            for(int j=0;j<SIZE;++j)
                flag[i][j]= s1[i]==s2[j] ? 0 : 1 ;    
        for(int i=0;i<=SIZE;++i)
            count[0][i]=count[i][0]=i;
        for(int i=1;i<=strlen(s1);++i)
            for(int j=1;j<=strlen(s2);++j)
                count[i][j]=Min(count[i-1][j]+1,count[i][j-1]+1,count[i-1][j-1]+flag[i-1][j-1]);
        printf("%d\n",count[strlen(s1)][strlen(s2)]);
        for(int is1=strlen(s1),is2=strlen(s2),k=1;k<=count[strlen(s1)][strlen(s2)];){
            int t;
            if(is1==0&&is2!=0) t=1;
            else if(is1!=0&&is2==0) t=3;
            else if(is1!=0&&is2!=0){
                if(count[is1][is2-1]==Min(count[is1-1][is2],count[is1-1][is2-1],count[is1][is2-1])) t=1;
                if(count[is1-1][is2]==Min(count[is1-1][is2],count[is1-1][is2-1],count[is1][is2-1])) t=3;
                if(count[is1-1][is2-1]==Min(count[is1-1][is2],count[is1-1][is2-1],count[is1][is2-1])) t= count[is1-1][is2-1]==count[is1][is2] ? 0:2;
            }
            switch(t){
                case 0 : --is1;--is2;break;
                case 1 : printf("%d Insert %d,%c\n",k++,is1+1,s2[--is2]);break;
                case 2 : printf("%d Replace %d,%c\n",k++,is1--,s2[--is2]);break;
                case 3 : printf("%d Delete %d\n",k++,is1--);break;
            }
        } 
    }
    return 0;
}
