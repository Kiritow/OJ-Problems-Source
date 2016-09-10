#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;
const int MOD = 20140927;
struct Matrix{
    int mat[2][2];
    void init(){
        memset(mat,0,sizeof(mat));
    }
    Matrix operator *(const Matrix &b)const{
        Matrix ret;
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++){
                ret.mat[i][j] = 0;
                for(int k = 0;k < 2;k++){
                    ret.mat[i][j] += (long long)mat[i][k]*b.mat[k][j]%MOD;
                    if(ret.mat[i][j] >= MOD)
                        ret.mat[i][j] -= MOD;
                }
            }
        return ret;
    }
    void output(){
        printf("%d %d\n%d %d\n",mat[0][0],mat[0][1],mat[1][0],mat[1][1]);
    }
};
Matrix pow_M(Matrix A,int n){
    Matrix ret;
    ret.mat[0][0] = ret.mat[1][1] = 1;
    ret.mat[0][1] = ret.mat[1][0] = 0;
    Matrix tmp = A;
    while(n){
        if(n&1)ret = ret*tmp;
        tmp = tmp*tmp;
        n >>= 1;
    }
    return ret;
}
Matrix A[11*11*11 + 100];
vector<int>vec;
Matrix B;
Matrix C;
struct Matrix2{
    int mat[2][2];
    void init(){
        memset(mat,0,sizeof(mat));
    }
    Matrix2 operator *(const Matrix2 &b)const{
        Matrix2 ret;
        for(int i = 0;i < 2;i++)
            for(int j = 0;j < 2;j++){
                ret.mat[i][j] = 0;
                for(int k = 0;k < 2;k++)
                    if(mat[i][k] && b.mat[k][j])
                        ret.mat[i][j] = 1;
            }
        return ret;
    }
};
Matrix2 pow_M(Matrix2 A,int n){
    Matrix2 ret;
    ret.mat[0][0] = ret.mat[1][1] = 1;
    ret.mat[0][1] = ret.mat[1][0] = 0;
    Matrix2 tmp = A;
    while(n){
        if(n&1)ret = ret*tmp;
        tmp = tmp*tmp;
        n >>= 1;
    }
    return ret;
}
Matrix2 A2[11*11*11 + 100];
Matrix2 B2;
Matrix2 C2;
void Add(int &a,int b){
    if(a || b)a = 1;
}
int main()
{
    for(int i = 0;i < 11*11*11;i++)A[i].init();
    for(int i = 0;i < 11*11*11;i++)A2[i].init();
    for(int x = 0;x < 11;x++)
        for(int y = 0;y < 11;y++)
            for(int z = 0; z < 11;z++){
                int id = x*11*11 + y*11 + z;
                for(int i = 0;i < 10;i++){
                    if(x != 10 && x != i)continue;
                    for(int j = 0;j < 10;j++){
                        if(y != 10 && y != j)continue;
                        for(int k = 0;k < 10;k++){
                            if(z != 10 && z != k)continue;
                            if(i + j == k)A[id].mat[0][0]++;
                            if(i + j == 10 + k)A[id].mat[0][1]++;
                            if(i + j + 1 == k)A[id].mat[1][0]++;
                            if(i + j + 1 == 10 + k)A[id].mat[1][1]++;
                            if(i + j == k)Add(A2[id].mat[0][0],1);
                            if(i + j == 10 + k)Add(A2[id].mat[0][1],1);
                            if(i + j + 1 == k)Add(A2[id].mat[1][0],1);
                            if(i + j + 1 == 10 + k)Add(A2[id].mat[1][1],1);
                        }
                    }
                }
            }
    int T;
    int iCase = 0;
    int n1,m1,n2,m2,n3,m3;
    scanf("%d",&T);
    while(T--){
        iCase++;
        scanf("%d%d",&n1,&m1);
        assert(n1 >= 1 && n1 <= 10000000);
        assert(m1 >= 0 && m1 <= n1);
        map<int,int>mp1;
        map<int,int>mp2;
        map<int,int>mp3;
        bool flag = true;
        vec.clear();
        int id,x;
        while(m1--){
            scanf("%d%d",&id,&x);
            id = n1 - 1 - id;
            vec.push_back(id);
            if(mp1.find(id) != mp1.end()){
                if(mp1[id] != x)flag = false;
            }
            else mp1[id] = x;
        }
        scanf("%d%d",&n2,&m2);
        assert(n2 >= 1 && n2 <= 10000000);
        assert(m2 >= 0 && m2 <= n2);
        while(m2--){
            scanf("%d%d",&id,&x);
            id = n2 - 1 - id;
            vec.push_back(id);
            if(mp2.find(id) != mp2.end()){
                if(mp2[id] != x)flag = false;
            }
            else mp2[id] = x;
        }
        scanf("%d%d",&n3,&m3);
        assert(n3 >= 1 && n3 <= 10000000);
        assert(m3 >= 0 && m3 <= n3);
        while(m3--){
            scanf("%d%d",&id,&x);
            id = n3 - 1 - id;
            vec.push_back(id);
            if(mp3.find(id) != mp3.end()){
                if(mp3[id] != x)flag = false;
            }
            else mp3[id] = x;
        }
        if((!flag) || (n1 < max(n2,n3)) || (n1 > max(n2,n3)+1)){
            printf("Case #%d: IMPOSSIBLE\n",iCase);
            continue;
        }
        vec.push_back(n2-1);
        vec.push_back(n3-1);
        sort(vec.begin(),vec.end());
        vec.erase(unique(vec.begin(),vec.end()),vec.end());
        int mn = max(n2,n3);
        B.init();
        B.mat[0][0] = B.mat[1][1] = 1;
        B2.init();
        B2.mat[0][0] = B2.mat[1][1] = 1;
        if(vec[0] > 0)B = B * pow_M(A[10*11*11+10*11+10],vec[0]);
        if(vec[0] > 0)B2 = B2 * pow_M(A2[10*11*11+10*11+10],vec[0]);
        int sz = vec.size();
        for(int i = 0;i < sz;i++){
            if(i > 0){
                B = B * pow_M(A[10*11*11+10*11+10],vec[i]-vec[i-1]-1);
            }
            int x,y,z;
            if(mp2.find(vec[i]) == mp2.end())x = 10;
            else x = mp2[vec[i]];
            if(vec[i] >= n2)x = 0;
            if(mp3.find(vec[i]) == mp3.end())y = 10;
            else y = mp3[vec[i]];
            if(vec[i] >= n3)y = 0;
            if(mp1.find(vec[i]) == mp1.end())z = 10;
            else z = mp1[vec[i]];
            if(vec[i] >= n1)z = 0;
            if(vec[i] != n2-1 && vec[i] != n3-1){
                B = B * A[x*11*11+y*11+z];
                B2 = B2 * A2[x*11*11+y*11+z];
            }
            else {
                C.init();
                C2.init();
                for(int p = 0;p < 10;p++)
                    for(int q = 0;q < 10;q++)
                        for(int r = 0;r < 10;r++){
                            if(x != 10 && p != x)continue;
                            if(y != 10 && q != y)continue;
                            if(z != 10 && r != z)continue;
                            if(n2 != 1 && vec[i] == n2-1 && p == 0)continue;
                            if(n3 != 1 && vec[i] == n3-1 && q == 0)continue;
                            if(vec[i] >= n2 && p != 0)continue;
                            if(vec[i] >= n3 && q != 0)continue;
                            if(p+q == r)C.mat[0][0]++;
                            if(p+q == r+10)C.mat[0][1]++;
                            if(p+q+1 == r)C.mat[1][0]++;
                            if(p+q+1 == r + 10)C.mat[1][1]++;
                            if(p+q == r)Add(C2.mat[0][0],1);
                            if(p+q == r+10)Add(C2.mat[0][1],1);
                            if(p+q+1 == r)Add(C2.mat[1][0],1);
                            if(p+q+1 == r + 10)Add(C2.mat[1][1],1);
                        }
                B = B*C;
                B2 = B2*C2;
            }
        }
        int ans = 0;
        int ans2 = 0;
        if(n1 == max(n2,n3)){
            ans = B.mat[0][0];
            ans2 = B2.mat[0][0];
        }
        else{
            if(mp1.find(n1-1) != mp1.end() && mp1[n1-1] != 1){
                printf("Case #%d: IMPOSSIBLE\n",iCase);
                continue;
            }
            ans = B.mat[0][1];
            ans2 = B2.mat[0][1];
        }
        if(ans2 == 0)printf("Case #%d: IMPOSSIBLE\n",iCase);
        else printf("Case #%d: %d\n",iCase,ans);
    }
    return 0;
}
