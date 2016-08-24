#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;
const int MAX=30+10;
int hash1[200],hash2[10];
char a[MAX],b[MAX];
void Map(){
    hash2[0]=63,hash1[63]=0;
    hash2[1]=10,hash1[10]=1;
    hash2[2]=93,hash1[93]=2;
    hash2[3]=79,hash1[79]=3;
    hash2[4]=106,hash1[106]=4;
    hash2[5]=103,hash1[103]=5;
    hash2[6]=119,hash1[119]=6;
    hash2[7]=11,hash1[11]=7;
    hash2[8]=127,hash1[127]=8;
    hash2[9]=107,hash1[107]=9;
}
int main(){
    Map();
    int lena,lenb,sum=0,i,j,p,temp=1;
    while(~scanf("%s",a),strcmp(a,"BYE")){
        i=j=sum=0,temp=1;
        while(a[i++] != '+');
        lena=i-1;
        while(a[i] != '=')b[j++]=a[i++];
        lenb=j;
        for(i=lena-3,j=lenb-3;i>=0 && j>=0;i-=3,j-=3){
            p=(a[i]-'0')*100+(a[i+1]-'0')*10+a[i+2]-'0';
            sum+=hash1[p]*temp;
            p=(b[j]-'0')*100+(b[j+1]-'0')*10+b[j+2]-'0';
            sum+=hash1[p]*temp;
            temp*=10;
        }
        while(i>=0){
            p=(a[i]-'0')*100+(a[i+1]-'0')*10+a[i+2]-'0';
            sum+=hash1[p]*temp;
            temp*=10;
            i-=3;
        }
        while(j>=0){
            p=(b[j]-'0')*100+(b[j+1]-'0')*10+b[j+2]-'0';
            sum+=hash1[p]*temp;
            temp*=10;
            j-=3;
        }
        printf("%s",a);
        while(temp>sum)temp/=10;
        while(temp){
            printf("%03d",hash2[sum/temp]);
            sum=sum%temp;
            temp=temp/10;
        }
        cout<<endl;
    }
    return 0;
}
