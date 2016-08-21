#include <cstdio>
#define max(a , b) ((a) > (b) ? (a) : (b))
int LIS[55];
int LDS[55];
long long minlis[55];
long long data[55];
int binary(int l, int r , int x){
     int mid; 
     while(l <= r){
          mid = (l + r) >> 1;
          if(minlis[mid] < x)  l = mid + 1; 
          else  r = mid -1;
     }    
     return l;
}
int main(){
     int n, maxn, len;
     while(~scanf("%d", &n) && n != 0){
          for(int i = 1; i <= n; i++)    scanf("%lld", data + i);  
          minlis[1] = data[1]; LIS[1] = 1; len = 1;
          for(int i = 2; i <= n; i++){
                LIS[i] = binary(1, len, data[i]); 
                minlis[LIS[i]] = data[i]; 
                if(LIS[i] > len)  len++;
          }
          minlis[1] = data[n];  LDS[n] = 1; len = 1;
          for(int i = n-1; i > 0; i--){
                LDS[i] = binary(1, len, data[i]);   
                minlis[LDS[i]] = data[i];    
                if(LDS[i] > len)   len++;
          }
          maxn = 0;
          for(int i = 1; i <= n; i++)
               maxn = max(maxn , LIS[i] + LDS[i] - 1);                   
          printf("%d\n", n - maxn);
     }
     return 0;
}
