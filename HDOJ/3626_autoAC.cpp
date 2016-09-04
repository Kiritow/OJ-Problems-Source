#include<iostream>
#include<string.h>
using namespace std;
const int maxn =1010;
struct matrix{
    int x,y;
};
matrix ma[maxn];
int flag[maxn];
int main(){
    for(int n,cases=1;cin>>n && n!=0;cases++){
        for(int i=0;i<n;i++)
            cin>>ma[i].x>>ma[i].y;
        cout<<(cases==1?"":"\n")<<"Case "<<cases<<":\n";
        for(int i=0;i<n;i++){
            int min,num=0;
            memset(flag,0,sizeof(flag));
            for(int j=0;j<n;j++){
                if(ma[j].x>ma[i].x && ma[j].y>ma[i].y){
                    flag[j]=1;
                    num++;
                    min=j;
                }
            }
            if(num==0)
                cout<<"-1 -1\n";
            else if(num==1)
                cout<<ma[min].x<<" "<<ma[min].y<<"\n";
            else{
                for(int j=0;j<n;j++){
                    if(flag[j]==1 && ma[j].x<ma[min].x){
                        min=j;
                    }
                }
                num=0;
                for(int j=0;j<n;j++){
                    if(flag[j]==1 && ma[j].x==ma[min].x){
                        num++;
                        flag[j]=2;
                    }
                }
                if(num ==1)
                    cout<<ma[min].x<<" "<<ma[min].y<<"\n";
                else{
                    for(int j=0;j<n;j++){
                        if(flag[j]==2 && ma[j].y<ma[min].y)
                            min=j;
                    }
                    cout<<ma[min].x<<" "<<ma[min].y<<"\n";
                }
            }
        }
    }
}
