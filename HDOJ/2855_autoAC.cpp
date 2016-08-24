#include<iostream>
using namespace std;
int n,m;
struct Matrix{
    int map[2][2];
};
Matrix mat,unit;
void Initiate(){
    mat.map[0][0]=2;
    mat.map[0][1]=1;
    mat.map[1][0]=1;
    mat.map[1][1]=1;
    unit.map[0][0]=unit.map[1][1]=1;
    unit.map[0][1]=unit.map[1][0]=0;
}
Matrix Mul(Matrix &a,Matrix &b){
    Matrix c;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c.map[i][j]=0;
            for(int k=0;k<2;k++){
                c.map[i][j]+=a.map[i][k]*b.map[k][j];
                c.map[i][j]%=m;
            }
        }
    }
    return c;
}
Matrix Pow(int n){
    Matrix p=unit,q=mat;
    while(n){
        if(n&1)
            p=Mul(p,q);
        n>>=1;
        q=Mul(q,q);
    }
    return p;
}
int main(){
    int _case;
    scanf("%d",&_case);
    Initiate();
    while(_case--){
        scanf("%d%d",&n,&m);
        Matrix remat=Pow(n);
        printf("%d\n",remat.map[0][1]);
    }
    return 0;
}
