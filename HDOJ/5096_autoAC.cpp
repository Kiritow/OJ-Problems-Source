#include<cstdio>
#include<cstring>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int N = 100100;
const int M = 5000;
int n, m, sol_num, tot;
int arr[11][M];
int cnt[N][11];
int sum[11];
bool solve[N][10];
char s1[20], s2[20];
int solved[N];
int pen[N];
int last[N];
struct Team{
    int id, ac;
    Team(){}
    Team(int id, int ac):id(id),ac(ac){}
    bool operator < (const Team &A)const{
        return ac<A.ac;
    }
};
int lowbit(int x){
    return x&(-x);
}
void add(int sol, int x, int v){
    if(x==0){
        arr[sol][x]+=v;
        return;
    }
    for(; x<M; x+=lowbit(x))    arr[sol][x]+=v;
}
int cal(int sol, int x){
    if(x<0)    return 0;
    int res = arr[sol][0];
    for(; x>0; x-=lowbit(x))    res += arr[sol][x];
    return res;
}
Team t[N];
map<int, set<Team> > MP[11];
set<int> ST;
void init(){
    for(int i=1; i<=m; i++){
        MP[i].clear();
    }
    ST.clear();
    for(int i=0; i<n; i++){
        ST.insert(i);
        t[i] = Team(i,-10);
        last[i] = -10;
    }
    tot = 0;
    sol_num = 0;
    memset(solved, 0, sizeof(solved));
    memset(pen, 0, sizeof(pen));
    memset(arr, 0, sizeof(arr));
    memset(solve, 0, sizeof(solve));
    memset(cnt, 0, sizeof(cnt));
    memset(sum, 0, sizeof(sum));
}
inline void in(int &x){
    char c=getchar();
    x = 0;
    while(c<48 || c>57)    c=getchar();
    while(c>=48 && c<=57){
        x = x*10+c-48;
        c = getchar();
    }
}
inline void read(int &x){
    char c=getchar();
    x = c-'A';
}
void submit(){
    int min, id, flag, pro;
    in(min);
    in(id);
    read(pro);
    in(flag);
    if(min - last[id] < 5 || solve[id][pro])    return;
    last[id] = min;
    if(flag){
        printf("[%d][%c]\n", id, pro+'A');
        int sol = solved[id];
        int penlty = pen[id];
        if(sol){
            MP[sol][penlty].erase(t[id]);
            add(sol, penlty, -1);
            sum[sol]--;
        }
        else{
            sol_num++;
            ST.erase(id);
        }
        sol++;
        penlty += min + cnt[id][pro]*20;
        solved[id]++;
        pen[id] = penlty;
        t[id].ac = ++tot;
        MP[sol][penlty].insert(t[id]);
        add(sol, penlty, 1);
        solve[id][pro]=1;
        sum[sol]++;
    }
    else{
        cnt[id][pro]++;
    }
}
int R(){
    int id, res;
    in(id);
    if(solved[id]==0)    return sol_num+1;
    res = cal(solved[id], pen[id]-1)+1;
    for(int i=solved[id]+1; i<=m; i++)    res+=sum[i];
    return res;
}
int find(int sol, int rank){
    int low=0, top=M, mid;
    int ans = M;
    while(low<=top){
        mid = (low+top)>>1;
        int res = cal(sol, mid);
        if(res >= rank){
            ans = min(ans, mid);
            top = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    int tmp = cal(sol, ans-1);
    if(tmp + 1 != rank)    return -1;
    return MP[sol][ans].begin()->id;
}
int T(){
    int rank;
    in(rank);
    if(rank > n)    return -1;
    if(rank == sol_num+1)    return *ST.begin();
    if(rank > sol_num)    return -1;
    int i, res = 0;
    for(i=m; i>=0; i--){
        res += sum[i];
        if(res >= rank)    break;
    }
    res -= sum[i];
    return find(i, rank - res);
}
int main(){
    while(~scanf("%d %d", &n, &m)){
        init();
        while(~scanf("%s", s1) && s1[0]!='C'){
            if(s1[0]=='S')    submit();
            else if(s1[0]=='T')    printf("%d\n", T());
            else    printf("%d\n", R());
        }
        scanf("%s", s1);
        puts("");
    }
    return 0;
}
