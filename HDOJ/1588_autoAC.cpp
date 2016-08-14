#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int k,b,n,m;
struct Matrix {
    __int64 map[2][2];
};
Matrix matrix,matk,matb,smat;
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
Matrix Pow(int k,Matrix &temp){
    if(k==1)return temp;
    else if(k&1){
        return Mul(temp,Pow(k-1,temp));
    }else {
        Matrix tmp=Pow(k>>1,temp);
        return Mul(tmp,tmp);
    }
}
Matrix Sum(Matrix &a,Matrix &b){
    Matrix c;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            c.map[i][j]=a.map[i][j]+b.map[i][j];
            c.map[i][j]%=m;
        }
    }
    return c;
}
Matrix Binary_Sum(int k){
    if(k==1)return matk;
    else if(k&1){
        return Sum(Binary_Sum(k-1),Pow(k,matk));
    }else {
        Matrix tmp1=Binary_Sum(k>>1);
        Matrix tmp2=Mul(Pow(k>>1,matk),tmp1);
        return Sum(tmp1,tmp2);
    }
}
int main(){
    matrix.map[0][0]=1,matrix.map[0][1]=1;
    matrix.map[1][0]=1,matrix.map[1][1]=0;
    while(scanf("%d%d%d%d",&k,&b,&n,&m)!=EOF){
        matk=Pow(k,matrix);
        smat=Binary_Sum(n-1);
        if(b){
            matb=Pow(b,matrix);
            smat=Mul(matb,smat);
            smat=Sum(matb,smat);
        }
        printf("%I64d\n",smat.map[1][0]);
    }
    return 0;
}
