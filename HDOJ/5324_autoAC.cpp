#include <iostream>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <algorithm>
    using namespace std;
    const int maxn = 50010;
    struct Node{
        Node *ch[2];
        int r;
        int v; 
        int len; 
        int idx; 
        int mlen; 
        int midx; 
        Node() {}
        Node(int v, int len, int idx):v(v),len(len),idx(idx),mlen(len),midx(idx) {ch[0] = ch[1] = NULL; r = rand();}
        int cmp(int x) const {
            if (x == v) return -1;
            return x < v ? 0 : 1;
        }
        void maintain(){
            mlen = len;
            midx = idx;
            if (ch[0] != NULL && (ch[0]->mlen > mlen || (ch[0]->mlen == mlen && ch[0]->midx < midx))){
                mlen = ch[0]->mlen;
                midx = ch[0]->midx;
            }
            if (ch[1] != NULL && (ch[1]->mlen > mlen || (ch[1]->mlen == mlen && ch[1]->midx < midx))){
                mlen = ch[1]->mlen;
                midx = ch[1]->midx;
            }
        }
    };
    bool findMax(Node* a, Node* b){
        if (a->mlen < b->mlen || (a->mlen == b->mlen && a->midx > b->midx)){
            *a = *b;
            return true;
        }
        return false;
    }
    namespace Treap{
        int cntnode;
        Node node[maxn*10];
        void init(){
            cntnode = 0;
        }
        Node* newNode(int v, int len, int idx){
            node[++cntnode] = Node(v, len, idx);
            return &node[cntnode];
        }
        void rotate(Node* &o, int d){
            Node* k = o->ch[d^1]; o->ch[d^1] = k->ch[d]; k->ch[d] = o;
            o->maintain(); k->maintain(); o = k;
        }
        void insert(Node* &o, int v, int len, int idx){
            if (o == NULL) o = newNode(v, len, idx);
            else {
                int d = o->cmp(v);
                if (d != -1){
                    insert(o->ch[d], v, len, idx);
                    if (o->r < o->ch[d]->r) rotate(o, d^1);
                }
                else
                {
                    if (len >= o->len){
                        o->len = len;
                        o->idx = idx;
                    }
                }
            }
            o->maintain();
        }
        Node search(Node *o, int v){
            if (o == NULL){
                return Node(-1, 0, -1);
            }
            else{
                Node re, tmp;
                if (o->v == v) {
                    re = Node(o->v, o->len, o->idx);
                    if (o->ch[1]){
                        findMax(&re, o->ch[1]);
                    }
                }
                else if (o->v > v){
                    re = Node(o->v, o->len, o->idx);
                    if (o->ch[1]){
                        findMax(&re, o->ch[1]);
                    }
                    if (o->ch[0]){
                        tmp = search(o->ch[0], v);
                        findMax(&re, &tmp);
                    }
                }
                else{
                    re = search(o->ch[1], v);
                }
                return re;
            }
        }
    }
    namespace BIT{
        Node* fwt[maxn];
        int N;
        void init(int n){
            N = n;
            memset(fwt, 0, sizeof fwt);
        }
        void add(int v1, int v2, int len, int idx){
            while(v1 < N){
                Treap::insert(fwt[v1], v2, len, idx);
                v1 += (-v1)&v1;
            }
        }
        Node query(int v1, int v2){
            Node re, tmp;
            re = Node(-1, 0, -1);
            while(v1 > 0){
                tmp = Treap::search(fwt[v1], v2);
                findMax(&re, &tmp);
                v1 -= (-v1)&v1;
            }
            return re;
        }
    }
    struct Pe{
        int L,R;
        int i;
        bool operator < (const Pe& rhs)const{
            return L < rhs.L;
        }
    };
    bool cmp(Pe a, Pe b){
        return a.i < b.i;
    }
    int solo[maxn];
    Pe pe[maxn];int pre[maxn];
    void print(Node& a){
        int id = a.midx;
        printf("%d\n", a.mlen);
        while(1){
            printf("%d", id+1);
            if (pre[id] == -1){
                break;
            }
            printf(" ");
            id = pre[id];
        }
        printf("\n");
    }
    int main(){
        int n;
        while(scanf("%d", &n) != EOF){
            for(int i=0;i<n;i++){
                pe[i].i = i;
                scanf("%d", &pe[i].L);
            }
            for(int i=0;i<n;i++){
                scanf("%d", &pe[i].R);
            }
            sort(pe, pe+n);
            int m = 0;
            solo[0] = ++m;
            for(int i=1;i<n;i++){
                if (pe[i].L != pe[i-1].L){
                    solo[i] = ++m;
                }
                else{
                    solo[i] = solo[i-1];
                }
            }
            for(int i=0;i<n;i++){
                pe[i].L = solo[i];
            }
            sort(pe, pe+n, cmp);
            BIT::init(m+1);
            Treap::init();
            Node ans = Node(-1, 0, -1), tmp;
            for(int i=n-1;i>=0;i--){
                tmp = BIT::query(pe[i].L, pe[i].R);
                pre[i] = tmp.midx;
                tmp.mlen = tmp.mlen + 1;
                tmp.midx = i;
                BIT::add(pe[i].L, pe[i].R, tmp.mlen, tmp.midx);
                findMax(&ans, &tmp);
            }
            print(ans);
        }
        return 0;
    }
