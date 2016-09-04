#include<iostream>
#include<algorithm>
using namespace std;
#define N 200020 
struct Node {
      int x,y,lt,id ;  
}point[N]; 
int n,len,maxlp[N],by[N];
int cmp(Node a,Node b) {
      if(a.x != b.x) 
          return a.x < b.x ;
      if(a.y == b.y) 
          return a.lt > b.lt ;
      return a.y < b.y ;           
}
int find(int len,int _y) {
      int mid, left = 1, right = len  ;
      while(left <= right) {
          mid = (left+right) >> 1 ; 
          if(by[mid] >= _y)
             right = mid-1 ;
          else left = mid+1 ;
      }                   
      return  left ; 
} 
int main() {
    while(scanf("%d",&n) && n) {
       for(int i=0;i<n;i++) {
           scanf("%d%d",&point[2*i].x,&point[2*i].y);  
           point[2*i].lt = 1 ;    
           scanf("%d%d",&point[2*i+1].x,&point[2*i+1].y);  
           point[2*i+1].lt = 0 ;    
           point[2*i].id = point[2*i+1].id = i ; 
       }    
       n *= 2 ;
       sort(point,point+n,cmp) ; 
       len = 0 ;
       for(int i=0;i<n;i++) {
           if(point[i].lt == 1) maxlp[point[i].id] = find(len,point[i].y) ;        
           else {
              int tmp = maxlp[point[i].id] ;
              if(tmp > len) by[++len] = point[i].y ;
              else by[tmp] = min(by[tmp],point[i].y) ;                   
           }
       }  
       printf("%d\n",len);
    }
    return 0;        
}
