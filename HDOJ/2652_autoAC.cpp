#include<iostream>
#include<algorithm>
using namespace std;
struct Node{
 int a,b,c;
};
bool com(Node &a,Node &b){
 return a.a<b.a;
}
Node nodes[100010];
int kan[100010];
int no[100010];
int main(){
 int number;
 while(scanf("%d",&number)!=EOF){
  int i;
  for(i=1;i<=number;i++){
   scanf("%d%d%d",&nodes[i].a,&nodes[i].b,&nodes[i].c);
  }
  sort(&nodes[1],&nodes[number+1],com);
  kan[number+1]=no[number+1]=0;
  for(i=number;i>=1;i--){
   kan[i]=no[i]=0;
   int begin=i;
   int end=number;
   while(begin<end){
    int mid=(begin+end)/2;
    if(nodes[mid].a>nodes[i].b){
     end=mid;
    }else{
     begin=mid+1;
    }
   }
   if(nodes[end].a>nodes[i].b){
    kan[i]=nodes[i].c+(kan[end]>no[end]?kan[end]:no[end]);
   }else{
    kan[i]=nodes[i].c;
   }
   no[i]=(kan[i+1]>no[i+1]?kan[i+1]:no[i+1]);
  }
  printf("%d\n",kan[1]>no[1]?kan[1]:no[1]);
 }
}
