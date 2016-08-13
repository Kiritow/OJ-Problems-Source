#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<math.h>
#include<iomanip>
#include<time.h>
#include<string.h>
#include<string>
#include<stack>
#include<vector>
using namespace std;
char map[220][220];
int main(){
    int n,m;
    while(~scanf("%d%d",&m,&n)){
        memset(map,0,sizeof(map));
        int *m1,*m2,*n1,*n2,num;
        m1=(int*)malloc(sizeof(int)*m);
        m2=(int*)malloc(sizeof(int)*m);
        n1=(int*)malloc(sizeof(int)*n);
        n2=(int*)malloc(sizeof(int)*n);
        int i,j,k;
        for(i=0;i<m;i++)
            scanf("%d",m1+i);
        for(i=0;i<m;i++)
            scanf("%d",m2+i);
        for(i=0;i<n;i++)
            scanf("%d",n1+i);
        for(i=0;i<n;i++)
            scanf("%d",n2+i);
        int d[220],h;
        for(i=0,h=1;i<n;i++){
            for(j=0;j<n2[i];j++)
                d[h++]=n1[i];
        }
        h--;
        string l="";
        for(i=0;i<m;i++){
            for(j=0;j<m1[i];j++)
                l+="1";
            for(j=0;j<m2[i];j++)
                l+="0";
        }
        for(i=0;i<l.length();i++)
            map[l.length()-1-i][0]=l[i];
        for(j=1;j<=h;j++){
            for(i=0;i<l.length();i++){
                map[i][j]=map[(i+d[j]+l.length())%l.length()][j-1];
            }
        }
        string l2="";
        for(i=0;i<l.length();i++)
            l2+=map[i][h],map[i][h]=0;
        reverse(l2.begin(),l2.end());
        if(l.compare(l2)==0){
            for(i=0;i<l.length();i++)
                puts(map[i]);
        }
        else
            printf("Can not make beautilful cloth !\n");
    }
    return 0;
}
