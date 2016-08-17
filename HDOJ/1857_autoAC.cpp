#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int KIND = 26;
const int MAXN = 1000000;
int cnt_node;
int R,C;
char map[505][505];
char word[10005][22];
struct node{
    bool isword;
    int r,c;
    node* next[KIND];
    void init(){
        r=c=-1;
        isword=false;
        memset(next, 0, sizeof(next));
    }
}Heap[MAXN];
inline node* new_node(){
    Heap[cnt_node].init();
    return &Heap[cnt_node++];
}
void insert(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'A';
        if(root->next[ch]==NULL)
            root->next[ch] = new_node();
        root=root->next[ch];
    } 
    root->isword=true;
}
void search(node* root, char *str, int row, int col){
    for(char *p=str; *p; ++p){
        int ch=*p-'A';
        if(root->next[ch]==NULL)
            return ;
        root=root->next[ch];
        if(root->isword && root->r==-1 && root->c==-1){
            root->r=row, root->c=col; 
        }
    }
    if(root->isword && root->r==-1 && root->c==-1){
        root->r=row, root->c=col;
    }
}
void output(node* root, char *str){
    for(char *p=str; *p; ++p){
        int ch=*p-'A';
        if(root->next[ch]==NULL) 
            return;
        root=root->next[ch];
    }
    if(root->isword)
        printf("%d %d\n", root->r, root->c);
}
int main(){
    cnt_node=0;
    node* root=new_node();
    scanf("%d%d%*c",&R,&C);
    for(int i=0; i<R; ++i){
        gets(map[i]);
    }
    gets(word[0]); 
    int pos=0;
    while(gets(word[pos])){
        if(word[pos][0]=='-') break;
        insert(root, word[pos++]);
    }
    char str[30];
    for(int i=0; i<R; ++i){
        for(int j=0; j<C; ++j){
            int end_r,end_c=j;
            if(i+20<R)
                end_r=i+20;
            else 
                end_r=R;
            memset(str, 0, sizeof(str));
            for(int k=i,p=0; k<end_r; ++k)
                str[p++]=map[k][j];
            search(root, str, i, j);
            if(j+20<C) 
                end_c=j+20;
            else
                end_c=C;
            memset(str, 0, sizeof(str));
            for(int k=j,p=0; k<end_c; ++k)
                str[p++]=map[i][k];
            search(root, str, i, j);
            int r=i, c=j,p=0;
            memset(str, 0, sizeof(str));
            while(r<end_r && c<end_c){
                str[p++]=map[r][c];
                ++r, ++c;
            }
            search(root,str,i,j);
        }
    }
    for(int i=0; i<pos; ++i){
        output(root, word[i]);
    }
    return 0;
}
