#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN = 100005;
struct NODE;
struct EDGE{
    NODE *a, *b;
       EDGE *next;
    int u;    
    bool bridge;  
}edge[MAXN << 1];
struct NODE{
  EDGE *head;
  NODE *par;
  int DFN, low;
  int mv;    
}node[MAXN];
int ecnt, dep, n, m;
void Tarjan(NODE *x){
    x->DFN = x->low = ++ dep;
      for(EDGE *j = x->head; j; j = j->next){
       NODE *p = j->b;
          if(p == x->par)
              continue;
     if(!p->DFN){
        p->par = x;
          Tarjan(p);
        }
      j->bridge = p->low > x->DFN;
      x->low = min(x->low, p->low);
      x->mv = max(x->mv, p->mv);
    j->u = j->b->mv;
    }
}
void addedge(NODE *a, NODE *b, int& ecnt){
 EDGE *j = &edge[ecnt ++];
  j->a = a;
  j->b = b;
   j->next = a->head;
  a->head = j;
  j->bridge = false;
}
void domain(){
  int i, u, v;
   scanf("%d%d", &n, &m);
   ecnt = 0;
 for(i = 0; i <= n; i ++){
     node[i].mv = i;
      node[i].par = nullptr;
      node[i].DFN = 0;
      node[i].head = nullptr;
    }
  for(i = 0; i < m; i ++){
      scanf("%d%d", &u, &v);
       addedge(node + u, node + v, ecnt);
      addedge(node + v, node + u, ecnt);
    }
  dep = 0;
  Tarjan(node + n);
   for(i = 0; i < ecnt; ){
     u = 0;
      if(edge[i].bridge)
         u = edge[i].u;
     i ++;
       if(edge[i].bridge)
          u = edge[i].u;
      i ++;
      printf("%d %d\n", u, u > 0 ? u + 1 : 0);
    }
}
int main(){
  int T;
  scanf("%d", &T);
   while(T --)
       domain();
  return 0;
}
