 #include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <algorithm>
    #include <map>
    using namespace std;
    const int maxn = 100010;
    typedef long long LL;
    int a[maxn], vidx[maxn];
    int vis[maxn], flg[maxn];
    namespace SegmentTree{
        int maxv[maxn<<2]; int setv[maxn<<2];
        #define Lson o<<1
        #define Rson o<<1|1
        void pushup(int o){
            maxv[o] = max(maxv[Lson], maxv[Rson]);
        }
        void build(int o, int l, int r){
            int m = (l+r)>>1;
            if(l == r){
                maxv[o] = a[l];
                setv[o] = -1;
            }
            else {
                build(Lson, l, m);
                build(Rson, m+1, r);
                setv[o] = -1;
                pushup(o);
            }
        }
        void pushdown(int o){
            if (setv[o] >= 0){
                setv[Lson] = setv[Rson] = setv[o];
                maxv[Lson] = maxv[Rson] = setv[o];
                setv[o] = -1;
            }
        }
        int v, ul, ur;
        void update(int o, int l, int r){
            if(l > r) return ;
            if (ul <= l && r <= ur){
                setv[o] = v;
                maxv[o] = v;
            }
            else{
                pushdown(o);
                int m = (l+r)>>1;
                if (ul <= m) update(Lson, l, m);
                if (ur > m) update(Rson, m+1, r);
                pushup(o);
            }
        }
        int _max, ql, qr;
        void query(int o, int l, int r){
            if(l>r) return ;
            if (setv[o] >= 0){
                _max = max(_max, setv[o]);
            }
            else if (ql <= l && r <= qr){
                _max = max(_max, maxv[o]);
            }
            else {
                int m = (l+r)>>1;
                pushdown(o);
                if(ql <= m) query(Lson, l, m);
                if(qr > m) query(Rson, m+1, r);
            }
        }
    }
    namespace BS{
        typedef pair<int,int> seg;
        #define l first
        #define r second
        #define MP make_pair
        int n;
        map<int,int> mp;
        void init(){
            mp.clear();
        }
        void add(int l, int r){
            seg line = MP(l, r);
            mp.insert(line);
        }
        int search(int v){
            map<int,int>::iterator it = mp.upper_bound(v);
            if (it == mp.begin()){
                return 0;
            }
            else{
                --it;
                return it->r;
            }
        }
    }
    int ans[maxn];
    void link(int l, int r){
        for(int i=l; i<r; i++){
            ans[a[i]] = a[i+1];
        }
        ans[a[r]] = a[l];
    }
    int main(){
        int T, n;
        scanf("%d",&T);
        while(T--){
            scanf("%d", &n);
            for(int i=1;i<=n;i++){
                scanf("%d",&a[i]);
                vidx[a[i]] = i;
            }
            memset(vis, 0, sizeof vis);
            memset(flg, 0, sizeof flg);
            SegmentTree::build(1,1,n);
            BS::init();
            for(int _i=1;_i<=n;_i++){
                int i = vidx[_i];
                if (vis[i]) continue;
                int id = i, mx=0;
                if(!flg[_i]) mx = _i;
                SegmentTree::ql = BS::search(i) + 1;
                SegmentTree::qr = id-1;
                SegmentTree::_max = 0;
                SegmentTree::query(1,1,n);
                mx = max(mx, SegmentTree::_max);
                if (!vis[i+1] && i < n){
                    mx = max(mx, a[i+1]);
                    if (mx == a[i+1]){
                        ans[_i] = a[i+1];
                        flg[a[i+1]] = 1;
                        SegmentTree::ul = i+1;
                        SegmentTree::ur = i+1;
                        SegmentTree::v = 0;
                        SegmentTree::update(1,1,n);
                        continue;
                    }
                }
                int l = min(vidx[mx], i),r = max(vidx[mx], i);
                link(l, r);
                for(int j = l; j <= r; j++){
                    vis[j] = 1;
                    flg[a[j]] = 1;
                }
                BS::add(l, r);
                SegmentTree::ul = l;
                SegmentTree::ur = r;
                SegmentTree::v = 0;
                SegmentTree::update(1,1,n);
            }
            for(int i=1; i <= n; i++){
                printf("%d%c", ans[i], i<n?' ':'\n');
            }
        }
        return 0;
    }
