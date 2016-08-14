#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cstdio>
#include<math.h>
#include <algorithm>
using namespace std;
#define MAX 100010
#define INF 0x6fffff
typedef struct Node{
    int start;
    int end;
    int l_space;
    int r_space;
    int m_space;
}Node;
Node arr[MAX*2];
int top = -1;
int stack[MAX];
int fa[MAX];
void build(int k, int s, int e){
    arr[k].start = s;
    arr[k].end = e;
    arr[k].l_space = arr[k].r_space = arr[k].m_space = e - s + 1;
    if(s == e){
        fa[s] = k;
        return;
    }
    int mid = (s + e) >> 1;
    build(k << 1, s, mid);
    build((k << 1) + 1, mid + 1, e);
}
void update(int k){
    if(k == 1)
        return;
    int fa_i = k >> 1;
    int b_l = fa_i << 1;
    int b_r = b_l | 1;
    arr[fa_i].m_space = max(max(arr[b_l].m_space, arr[b_r].m_space), arr[b_l].r_space + arr[b_r].l_space);
    if(arr[b_l].l_space == arr[b_l].end - arr[b_l].start + 1)
        arr[fa_i].l_space = arr[b_l].l_space + arr[b_r].l_space;
    else
        arr[fa_i].l_space = arr[b_l].l_space;
    if(arr[b_r].r_space == arr[b_r].end - arr[b_r].start + 1){
        arr[fa_i].r_space = arr[b_l].r_space + arr[b_r].r_space;
    }
    else
        arr[fa_i].r_space = arr[b_r].r_space;
    update(fa_i);
}
int sum;
void query(int i, int x){
    if(arr[i].start == arr[i].end || arr[i].end - arr[i].start + 1 == arr[i].m_space || arr[i].m_space == 0){
        sum += arr[i].m_space;
        return;
    }
    int mid = (arr[i].start + arr[i].end) >> 1;
    if(x <= mid){
        if(x >= arr[i << 1].end - arr[i << 1].r_space + 1)
                   query((i << 1) + 1, mid + 1);
        query(i << 1, x);
    } else {
        if(x <= arr[(i << 1) + 1].start + arr[(i << 1) + 1].l_space - 1)
            query(i << 1, mid);
        query((i << 1) + 1, x);
    }
}
void dbg_show(){
    int max = 15;
    for(int i = 1; i < max; ++i)
        cout<<arr[i].start<<" "<<arr[i].end<<" "<<arr[i].l_space<<" "<<arr[i].r_space<<" "<<arr[i].m_space<<endl;
}
int main(){
    char ch;
    int m, n, dt;
    int flag = 0;
    while(cin>>m>>n){
        build(1, 1, m);
        //dbg_show();
        while(n--){
            cin>>ch;
            switch(ch){
                case 'D':
                    cin>>dt;
                    arr[fa[dt]].l_space = arr[fa[dt]].r_space = arr[fa[dt]].m_space = 0;
                    update(fa[dt]);
                    stack[++top] = dt;
                    //dbg_show();
                    break;
                case 'R':
                    dt = stack[top--];
                    arr[fa[dt]].l_space = arr[fa[dt]].r_space = arr[fa[dt]].m_space = 1;
                    update(fa[dt]);
                    break;
                case 'Q':
                    cin>>dt;
                    sum = 0;
                    query(1, dt);
                    cout<<sum<<endl;
                    break;
            }
        }
    }
    return 0;
}
