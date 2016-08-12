#include<iostream>
#include<string>
using namespace std;
string add(string s1,string s2){ 
       if(s1.length()<s2.length()){
            string temp=s1;
            s1=s2;
            s2=temp;
       }
       for(int i=s1.length()-1,j=s2.length ()-1;i>=0;i--,j--){
            s1[i]=char(s1[i]+( j>=0 ? s2[j]-'0' : 0));
            if(s1[i]-'0'>=10) {
                s1[i]=char( (s1[i]-'0')%10+'0' );
                if(i) s1[i-1]++;
                else  s1="1"+s1;
            }
       }
       return s1;
}
string f[1005];
int main(){
    int n;
    f[1]="0"; f[2]="1"; f[3]="1"; f[4]="3"; f[5]="5"; f[6]="11";
    for(int i=7;i<=1004;i++)
        f[i]=add( f[i-1], add(f[i-2],f[i-2]) );
    while(scanf("%d",&n)==1)
          cout<<f[n]<<endl;
    return 0;
}
