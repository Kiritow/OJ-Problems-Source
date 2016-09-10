#include<cstdio>
#include<algorithm>
using namespace std;
struct Node{
    int x,y,z,p,t;
    Node(){}
    Node(int x,int y,int z,int p,int t):x(x),y(y),z(z),p(p),t(t){}
};
#define maxn 450007
Node star[maxn];
Node star2[maxn];
Node star3[maxn];
int tree[maxn];
int lowbit(int i){
    return i&(-i);
}
void add(int i,int x){
    while(i<maxn){
        tree[i]+=x;
        i+=lowbit(i);
    }
}
int get(int i){
    int ans = 0;
    while(i>0){
        ans += tree[i];
        i -= lowbit(i);
    }
    return ans;
}
int res[maxn];
void CDQ2(int l,int r){
    if(l == r) return ;
    int mid = (l+r)/2;
    CDQ2(l,mid);
    CDQ2(mid+1,r);
    int l1 =l, r1 = mid+1;
    while(r1 <= r){
        while(l1 <= mid && star2[l1].y <= star2[r1].y){
            if(star2[l1].t == 0) add(star2[l1].z,1);
            l1++;
        }
        if(star2[r1].t != 0){
            res[star2[r1].p] += get(star2[r1].z)*star2[r1].t;
        }
        r1++;
    }
    while(l1 > l){
        --l1;
        if(star2[l1].t == 0) add(star2[l1].z,-1);
    }
    l1 = l, r1 = mid+1;
    for(int i = l;i <= r; i++){
        if((l1 <= mid && star2[l1].y <= star2[r1].y) || r1 > r )
            star3[i] = star2[l1++];
        else star3[i] = star2[r1++];
    }
    for(int i = l; i <= r; i++)
        star2[i] = star3[i];
}
void CDQ1(int l,int r){
    if(l == r) return ;
    int mid = (l+r)/2;
    CDQ1(l,mid);
    CDQ1(mid+1,r);
    int l1 = l, r1 = mid+1,n = 0;
    while(r1 <= r){
        while(star[l1].t != 0 && l1 <= mid) l1++;
        while(star[r1].t == 0 && r1 <= r) r1++;
        if(r1 > r) break;
        if((star[l1].x <= star[r1].x && l1 <= mid)|| r1 > r)
            star2[n++] = star[l1++];
        else star2[n++] = star[r1++];
    }
    if(n > 0) CDQ2(0,n-1);
    l1 = l, r1 = mid+1;
    for(int i = l;i <= r; i++){
        if((star[l1].x <= star[r1].x && l1 <= mid)|| r1 > r)
            star3[i] = star[l1++];
        else star3[i] = star[r1++];
    }
    for(int i = l;i <= r; i++)
        star[i] = star3[i];
}
int compn(Node a,Node b){
    return a.p < b.p;
}
int compz(Node a,Node b){
    return a.z < b.z;
}
int main(){
    int t,q,a,x1,y1,z1,x2,y2,z2;
    scanf("%d",&t);
    while(t--){
        int n = 0;
        scanf("%d",&q);
        while(q--){
            scanf("%d",&a);
            if(a == 1){
                scanf("%d%d%d",&x1,&y1,&z1);
                star[n++] = Node(x1,y1,z1,n,0);
            }
            else {
                scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
                star[n++] = Node(x2,y2,z2,n,1);
                star[n++] = Node(x2,y1-1,z2,n,-1);
                star[n++] = Node(x1-1,y2,z2,n,-1);
                star[n++] = Node(x2,y2,z1-1,n,-1);
                star[n++] = Node(x1-1,y1-1,z2,n,1);
                star[n++] = Node(x1-1,y2,z1-1,n,1);
                star[n++] = Node(x2,y1-1,z1-1,n,1);
                star[n++] = Node(x1-1,y1-1,z1-1,n,-1);
            }
        }
        for(int i = 0;i < n; i++)
            res[i] = 0;
        sort(star,star+n,compz);
        a = 1;
        star[n].z = -1;
        for(int i = 0;i < n; i++){
            if(star[i].z != star[i+1].z)
                star[i].z = a++;
            else star[i].z = a;
        }
        sort(star,star+n,compn);
        CDQ1(0,n-1);
        sort(star,star+n,compn);
        for(int i = 0;i < n; i++){
            if(star[i].t != 0){
                int ans = 0;
                for(int j = 0;j < 8; j++)
                    ans += res[i+j];
                printf("%d\n",ans);
                i += 7;
            }
        }
    }
    return 0;
}
