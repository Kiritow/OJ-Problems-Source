#include <stdio.h>
#include <string.h>
#define MAX 40
#define MOD 10007
char dir[MAX];
int hash[256],n,m,total;
struct node {
    int flag,in;
    node *fail,*next[4];
}*qu[MAX*MAX],arr[MAX*MAX],*root;
node *CreateNode() {
    node *p = &arr[total];
    p->in = total++;
    p->flag = 0;
    p->fail = NULL;
    for (int i = 0; i < 4; ++i)
        p->next[i] = NULL;
    return p;
}
void Insert(char *str) {
    int i = 0,k;
    node *p = root;
    while (str[i]) {
        k = hash[str[i++]];
        if (p->next[k] == NULL)
            p->next[k] = CreateNode();
        p = p->next[k];
    }
    p->flag = 1;
}
void Build_AC() {
    int head,tail,i;
    head = tail = 0;
    root->fail = root;
    qu[++head] = root;
    while (tail < head) {
        node *p = qu[++tail];
        for (i = 0; i < 4; ++i) {
            if (p->next[i] != NULL) {
                if (p == root) p->next[i]->fail = root;
                else p->next[i]->fail = p->fail->next[i];
                qu[++head] = p->next[i];
                p->next[i]->flag |= p->fail->next[i]->flag;
            }
            else {
                if (p == root) p->next[i] = root;
                else p->next[i] = p->fail->next[i];
            }//else
        }//for
    }//while
}//void
struct Mat{
    int mat[MAX*2][MAX*2],size;
    Mat(int n) {size = n,memset(mat,0,sizeof(mat));}
    Mat(int arr[][MAX*2],int n) { size = n,memcpy(mat,arr,sizeof(arr));}
    friend Mat operator *(Mat a,Mat b);
    friend Mat operator +(Mat a,Mat b);
    friend Mat operator ^(Mat a,int k);
    friend Mat Sum(Mat a,int k);
}A(MAX*2),E(MAX*2);
Mat operator *(Mat a,Mat b) {
    Mat c(total*2);
    for (int i = 0; i < c.size; ++i)
        for (int j = 0; j < c.size; ++j)
            for (int k = 0; k < c.size; ++k)
                if (a.mat[i][k] && b.mat[k][j]) {
                    c.mat[i][j] += a.mat[i][k] * b.mat[k][j];
                    c.mat[i][j] %= MOD;
                }
    return c;
}
Mat operator +(Mat a,Mat b) {
    Mat c(total*2);
    for (int i = 0; i < c.size; ++i)
        for (int j = 0; j < c.size; ++j)
            c.mat[i][j] = (a.mat[i][j] + b.mat[i][j]) % MOD;
    return c;
}
Mat operator ^(Mat a,int k) {
    Mat c = E;
    while (k) {
        if (k & 1) c = c * a;
        a = a * a,k >>= 1;
    }
    return c;
}
Mat Sum(Mat A,int k) {
    if (k == 1) return A;
    else if (k & 1) return (A^k) * Sum(A,k-1);
    else return Sum(A,k/2) * ((A^(k/2)) + E);
}
void GetMat() {
    int i,j,k;
    Mat c(total*2);
    for (i = 0; i < total; ++i) {
        for (k = 0; k < 4; ++k) {
            j = arr[i].next[k]->in;    
            if (arr[i].next[k]->flag)
                c.mat[i][j+total]++;
            else c.mat[i][j]++,c.mat[i+total][j+total]++;
        }
    }
    E = A = c;
    memset(E.mat,0,sizeof(E.mat));
    for (i = 0; i < E.size; ++i)
        E.mat[i][i] = 1;
}
int Solve_1A() {
    int i,j,k,ans,sum;
    ans = 1,k = n,sum = 4;
    while (k) {
        if (k & 1) ans = (ans * sum) % MOD;
        sum = (sum * sum) % MOD,k >>= 1;
    }
    A = A^n;
    for (i = 0; i < 2 * total; ++i)
        ans = (ans - A.mat[0][i] + MOD) % MOD;
    return ans;
}
int main()
{
    int i,j,k,ans;
    hash['A'] = 0,hash['T'] = 1;
    hash['C'] = 2,hash['G'] = 3;
    while (scanf("%d%d",&m,&n) != EOF) {
        total = 0;
        root = CreateNode();
        for (i = 0; i < m; ++i)
            scanf("%s",dir),Insert(dir);
        Build_AC();
        GetMat();
        ans = Solve_1A();
        printf("%d\n",ans % MOD);
    }
}
