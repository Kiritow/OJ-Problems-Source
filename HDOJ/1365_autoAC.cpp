#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
struct node{
   int right,child;
   char ch;
   bool end;
}tree[350010];
int index = 1,cnt = 0,mat[100],tl[100];
char answer[128],key[125],list[100][30];
bool used[128],findans,matched[100];
void insert(int p,char *word){
   if (tree[p].ch){
       if (tree[p].ch == *word){
           if (!*(word + 1)) tree[p].end = 1;
           else{
               if(!tree[p].child) tree[p].child = ++index;
               insert(tree[p].child,word + 1);
           }
       }
       else{
           if (tree[p].right) insert(tree[p].right,word);
           else {
               tree[p].right = ++ index;
               insert(tree[p].right,word);
           }
       }
   }
   else{
       tree[p].ch = *word;
       if (!*(word + 1)) tree[p].end = 1;
       else{
           tree[p].child = ++ index;
           insert(tree[p].child,word + 1);
       }
   }
}
int findwordmat(){
   for (int i = 0;i < cnt;i ++){
       mat[i] = 0;
       for (int j = 0;j < tl[i];j ++)
           if (key[list[i][j]])
               ++ mat[i];
   }
}
int subsearch(int cur,int wi,int num,int tnum);
int search(int cur){
   if (cur == cnt){
       if (findans) return 2;
       findans = 1;
       for (int i = 'A';i <= 'Z';i ++) answer[key[i]] = i;
       return 1;
   }
   findwordmat();
   int m = -1,wi;
   for (int i = 0;i < cnt;i ++)
       if (!matched[i] && mat[i] > m){
           m = mat[i];
           wi = i;
       }
   return subsearch(cur,wi,0,1);
}
int subsearch(int cur,int wi,int num,int tnum){
   if (num == tl[wi]){
       matched[wi] = true;
       int tmp = search(cur + 1);
       matched[wi] = false;
       return tmp;
   }
   if (!tnum) return 0;
   char cc = list[wi][num];
   if (key[cc]){
       for (;tnum;tnum = tree[tnum].right)
           if (tree[tnum].ch == key[cc]){
               if (num + 1 == tl[wi] && !tree[tnum].end) return 0;
               return subsearch(cur,wi,num + 1,tree[tnum].child);
           }
       return 0;
   }else{
       int find = 0;
       for (;tnum;tnum = tree[tnum].right)
           if (!used[tree[tnum].ch]){
               if (num + 1 == tl[wi] && !tree[tnum].end) continue;
               used[tree[tnum].ch] = true;
               key[cc] = tree[tnum].ch;
               int tmp = subsearch(cur,wi,num + 1,tree[tnum].child);
               key[cc] = 0;
               used[tree[tnum].ch] = false;
               if (tmp == 2) return tmp;
               if (tmp == 1) find = tmp;
           }
       return find;
   }
}
int main(){
   char word[130];
   int w,t,tmp,pd,T;
   scanf("%d",&w);
   for (int i = 1;i <= w;i ++){
       scanf("%s",word);
       insert(1,word);
   }
   scanf("%d",&T);
   while (T --){
       memset(list,0,sizeof list);
       cnt = 0,tmp = 0,pd = 0;
       findans = 0;
       memset(key,0,sizeof key);
       memset(answer,0,sizeof answer);
       char c;
       while (c = getchar(),c < 'A' || c > 'z');
       for (;;){
           if (c >= 'A' && c <= 'Z'){
               pd = false; list[cnt][tmp ++] = c;
           }
           else if (c == ' '){
               pd = false;
               if (tmp){
                   tl[cnt] = tmp;list[cnt ++][tmp] = 0;
                   tmp = 0;
               }
           }
           else if (c == '\n'){
               if (tmp){
                   tl[cnt] = tmp;list[cnt ++][tmp] = 0;
                   tmp = 0;
               }
               if (pd) break;
               pd = 1;
           }
           if (scanf("%c",&c) == EOF){
               if (tmp){
                   tl[cnt] = tmp;list[cnt ++][tmp] = 0;
                   tmp = 0;break;
               }
           }
       }
       int tmp = search(0);
       if (tmp == 0) puts("#No solution#");
       else if (tmp == 1){
           for (int i = 'A';i <= 'Z';i ++){
               if (answer[i]) printf("%c",answer[i]);
               else printf("*");
           }
           printf("\n");
       }else{
           puts("#More than one solution#");
       }        
   }
   return 0;
}
