#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
#define MAXN 4010
#define N 210
int n;
int nex[MAXN];
char words[MAXN][N];
/*qsort*/
int cmp(const void *str1 , const void *str2){
   return strlen((char *)str1)-strlen((char *)str2);
}
/*姹next*/
void getNext(char *str){
   int len = strlen(str);
   nex[0] = nex[1] = 0;
   for(int i = 1 ; i < len ; i++){
      int j = nex[i];
      while(j && str[i] != str[j])
          j = nex[j]; 
      nex[i+1] = str[i] == str[j] ? j+1 : 0;
   }
}
/*归芥*/
bool find(char *text , char *str){
    int n = strlen(text);
    int m = strlen(str);
    int j = 0;
    for(int i = 0 ; i < n ; i++){
       while(j && text[i] != str[j])
           j = nex[j];
       if(str[j] == text[i])
           j++;
       if(j == m)
           return true;
    }
    return false;
}
int main(){
   int max;
   char ans[MAXN];
   while(scanf("%d%*c" , &n) && n){
      for(int i = 0 ; i < n ; i++)
         scanf("%s" , words[i]);
      qsort(words , n , sizeof(words[0]) , cmp);
      int pos;
      char tmp[N];
      int len = strlen(words[0]);
      max = 0;
      for(int i = 0 ; i < len ; i++){
         memset(tmp , '\0' , sizeof(tmp));
         pos = 0;
         for(int j = i ; j < len ; j++){
            tmp[pos++] = words[0][j];
            getNext(tmp);
            int vis = 1;
            for(int k = 1 ; k < n ; k++){
               if(!find(words[k] , tmp)){
                  vis = 0;
                  break;
               }
            }
            if(vis && max < pos){
               max = pos;
               memcpy(ans , tmp , sizeof(tmp));
            }  
            else if(vis && max == pos && strcmp(ans , tmp) > 0)
               memcpy(ans , tmp , sizeof(tmp));
         }      
      }
      if(max)
        printf("%s\n" , ans);
      else
        printf("IDENTITY LOST\n");
   }
   return 0;
}
