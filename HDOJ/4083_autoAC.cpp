#include<cstdio>
 #include<cstring>
 #include<algorithm>
 #include<cstdlib>
 using namespace std;
 int ratk[12][2]={
         {-1,0},{0,-1},{0,1},{1,0},
         {-1,-1},{-1,1},{1,-1},{1,1},
         {-2,0},{0,-2},{0,2},{2,0}
 };
 int natk[3]={8,12,4};
 double fatk[3][3]={{1,2,0.5},{0.5,1,2},{2,0.5,1}};
 int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
 struct Soldier{
     int flag, type;
     Soldier(){}
     Soldier(int f, int t):flag(f), type(t){}
 }sld[8];
 struct Next{
     int id, mx, my, aid, sc;
     Next(){}
     Next(int _id, int _mx, int _my, int _aid, int _sc):
         id(_id), mx(_mx), my(_my), aid(_aid), sc(_sc){}
     friend bool operator< (const Next& a, const Next& b){
         return a.sc > b.sc;
     }
 }nexts[12][150];
 int nsz[12];
 struct State{
     int x, y, sc; 
     State(){}
     State(int _x, int _y, int _sc):
         x(_x), y(_y), sc(_sc){} 
 }sta[12][8]; 
 short smaze[12][8][8]; 
 int lx, ly, lk;
 int n, s[3];
 short maze[8][8];
 int skm, szy;
 inline bool myturn(int k, int id){ 
     if(sld[id].flag!=(k&1)) return false;
     if(sta[k][id].sc==0) return false;
     return true;
 }
 inline bool moveillegal(int k, int id, int x, int y){  
     if(x<0||x>=lx) return true;
     if(y<0||y>=ly) return true;
     if(maze[x][y]==2) return true;
     if(sld[id].type==2&&maze[x][y]==1) return true; 
     if(smaze[k][x][y]!=-1&&sld[smaze[k][x][y]].flag!=sld[id].flag) return true;
     return false; 
 } 
 inline bool attackillegal(int k, int id, int x, int y){  
     if(x<0||x>=lx) return true;
     if(y<0||y>=ly) return true;
     if(smaze[k][x][y]==-1) return true;
     if(sld[smaze[k][x][y]].flag==sld[id].flag) return true;
     if(sta[k][smaze[k][x][y]].sc==0) return true;
     return false;
 }
 inline void donext(int k, Next& p){ 
     if(p.id==-1) return; 
     swap(smaze[k][sta[k][p.id].x][sta[k][p.id].y],smaze[k][p.mx][p.my]); 
     sta[k][p.id].x = p.mx;
     sta[k][p.id].y = p.my;
     if(p.aid==-1) return;
     sta[k][p.aid].sc-=p.sc; 
     sld[p.aid].flag?szy-=p.sc:skm-=p.sc;
     if(sta[k][p.aid].sc==0){
         smaze[k][sta[k][p.aid].x][sta[k][p.aid].y]=-1;
     } 
 } 
 inline void undonext(int k, Next& p){ 
     if(p.id==-1) return; 
     sta[k][p.id].x = sta[k-1][p.id].x; 
     sta[k][p.id].y = sta[k-1][p.id].y;
     swap(smaze[k][sta[k][p.id].x][sta[k][p.id].y],smaze[k][p.mx][p.my]);
     if(p.aid==-1) return;
     sta[k][p.aid].sc+=p.sc; 
     sld[p.aid].flag?szy+=p.sc:skm+=p.sc;
     smaze[k][sta[k][p.aid].x][sta[k][p.aid].y]=p.aid; 
 } 
 inline int attack(int k, int sid, int tid){ 
     return min(sta[k][tid].sc,
             int(sta[k][sid].sc*fatk[sld[sid].type][sld[tid].type]));
 }
 inline void getattack(int k, int id, int x, int y){ 
     for(int d=0;d<natk[sld[id].type];d++){
         int tx = x + ratk[d][0];
         int ty = y + ratk[d][1];
         if(!attackillegal(k, id, tx, ty)){
             int atkid = smaze[k][tx][ty]; 
             int atksc = attack(k, id, atkid); 
             nexts[k][nsz[k]++] = Next(id, x, y, atkid, atksc); 
         }
     } 
 } 
 bool reach[8][8];
 inline void stepbystep(int dep, int k, int id, int x, int y){ 
     reach[x][y] = true;
     if(dep==0) return;
     for(int d=0;d<4;d++){
         int tx = x+dir[d][0];
         int ty = y+dir[d][1];
         if(!moveillegal(k, id, tx, ty)){
             stepbystep(dep-1, k, id, tx, ty);
         }
     }
 }
 inline void getmove(int k, int id){ 
     memset(reach, false, sizeof(reach));
     stepbystep(s[sld[id].type], k, id, sta[k][id].x, sta[k][id].y);
     for(int i=0;i<lx;i++){
         for(int j=0;j<ly;j++){
             if(reach[i][j]&&smaze[k][i][j]==-1){
                 getattack(k, id, i, j);  
                 nexts[k][nsz[k]++] = Next(id, i, j, -1, 0); 
             }
         }
     }
     getattack(k, id, sta[k][id].x, sta[k][id].y); 
 }
 inline void getnext(int k){ 
     nsz[k]=0;
     for(int i=0;i<n;i++){
         if(myturn(k,i)) getmove(k, i); 
     }
     nexts[k][nsz[k]++] = Next(-1, -1, -1, -1, 0); 
     sort(nexts[k], nexts[k]+nsz[k]); 
 }
 int dfs(int k, int sc, int maxcut, int mincut){ 
     if(k==lk) return sc; 
     if(szy==0||skm==0) return sc; 
     getnext(k); 
     memcpy(sta[k+1],sta[k],sizeof(sta[k]));
     memcpy(smaze[k+1],smaze[k],sizeof(smaze[k])); 
     int maxval = sc-szy, minval = sc+skm;
     for(int i=0;i<nsz[k];i++){
         Next &u = nexts[k][i];
         donext(k+1, u);  
         int val = dfs(k+1,(k&1)?(sc-u.sc):(sc+u.sc), maxval, minval);
         undonext(k+1, u); 
         if(maxval<val) maxval = val;
         if(minval>val) minval = val;
         if(((k&1)==0)&&val>=mincut) return val; 
         if(((k&1)==0)&&(val-sc>=szy)) return val; 
         if(((k&1)==1)&&val<=maxcut) return val; 
         if(((k&1)==1)&&(val-sc<=-skm)) return val; 
     }
     return (k&1)?minval:maxval; 
 }
 int main(){
     while(scanf("%d%d%d", &lx, &ly, &lk),lx||ly){
         memset(maze, 0, sizeof(maze));
         memset(smaze, -1, sizeof(smaze));
         for(int i=0;i<lx;i++){
             for(int j=0;j<ly;j++){
                 scanf("%d", &maze[i][j]);
             }
         }
         scanf("%d%d%d%d", &n, &s[0], &s[2], &s[1]);
         szy=skm=0;
         for(int i=0;i<n;i++){
             int x, y, a, b, c; 
             scanf("%d%d%d%d%d", &x, &y, &a, &b, &c);
             if(c==1) c=2; else if(c==2) c=1; 
             x--; y--;
             sld[i] = Soldier(a, c);
             smaze[0][x][y] = i;
             sta[0][i] = State(x, y, b);
             a?szy+=b:skm+=b;
         }
         int ans = dfs(0, skm-szy, -szy, skm);
         printf("%d\n", ans);
     }
 }
