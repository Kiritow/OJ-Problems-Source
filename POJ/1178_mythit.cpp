#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 100000;
char str[150];
int k[64],king[64][64],knight[64][64];
int move1[8][2]={-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1};
int move2[8][2]={-1,-2,-2,-1,-2,1,-1,2,1,2,2,1,2,-1,1,-2};

void init(){
    int i,j,x,y,tx,ty;
    for(i=0;i<64;i++)
        for(j=0;j<64;j++)
            if(i==j) king[i][j]=knight[i][j]=0;
            else king[i][j]=knight[i][j]=inf;
    for(i=0;i<64;i++){
        x=i/8,y=i%8;
        for(j=0;j<8;j++){
            tx=x+move1[j][0],ty=y+move1[j][1];
            if(tx>=0 && ty>=0 && tx<8 && ty<8)
                king[i][8*tx+ty]=1;
        }
    }
    for(i=0;i<64;i++){
        x=i/8,y=i%8;
        for(j=0;j<8;j++){
            tx=x+move2[j][0],ty=y+move2[j][1];
            if(tx>=0 && ty>=0 && tx<8 && ty<8)
                knight[i][8*tx+ty]=1;
        }
    }
}
void floyd1(){
    int i,j,k;
    for(k=0;k<64;k++)
        for(i=0;i<64;i++)
            for(j=0;j<64;j++)
                if(king[i][k]+king[k][j]<king[i][j])
                    king[i][j]=king[i][k]+king[k][j];
}
void floyd2(){
    int i,j,k;
    for(k=0;k<64;k++)
        for(i=0;i<64;i++)
            for(j=0;j<64;j++)
                if(knight[i][k]+knight[k][j]<knight[i][j])
                    knight[i][j]=knight[i][k]+knight[k][j];
}
int main(){
    int i,j,l,cnt,pos,sum,ans,len,t1,t2;
    init();
    floyd1();
    floyd2();
    while(scanf("%s",str)!=EOF){
        len=strlen(str);
        pos=(str[0]-'A')+(str[1]-'1')*8;
        cnt=(len-2)/2;
        if(cnt==0){
            printf("0\n");
            continue;
        }
        for(i=0,j=2;i<cnt;i++,j+=2)
            k[i]=(str[j]-'A')+(str[j+1]-'1')*8;
        for(ans=inf,i=0;i<64;i++){
            for(sum=l=0;l<cnt;l++)
                sum+=knight[k[l]][i];
            for(j=0;j<64;j++){
                t1=king[pos][j];
                for(t2=inf,l=0;l<cnt;l++)
                    t2=min(t2,knight[k[l]][j]+knight[j][i]-knight[k[l]][i]);
                ans=min(ans,sum+t1+t2);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
