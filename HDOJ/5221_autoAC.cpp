#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <string.h>
#include <math.h>
#include <queue>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <stdio.h>
#include <vector>
#define L(x) (x*2)
#define R(x) (x*2 + 1)
using namespace std;
const int INF = 0x3f3f3f3f ;
const int MX = 100000 + 5 ;
int n ,m ,num ,idx ,sum ;
int dep[MX] ,top[MX] ,V[MX] ,ti[MX] ,to[MX] ,head[MX] ,father[MX] ,siz[MX] ,son[MX] ;
struct Edge
{
    int v ,next ;
}E[MX*2] ;
void add_edge(int u ,int v)
{
    E[num].v = v ; E[num].next = head[u] ; head[u] = num++ ;
    E[num].v = u ; E[num].next = head[v] ; head[v] = num++ ;
}
void dfs_find(int u ,int fa)
{
    dep[u] = dep[fa] + 1 ;
    father[u] = fa ;
    siz[u] = 1 ;
    son[u] = 0 ;
    for(int i = head[u] ;i != -1 ; i = E[i].next)
    {
        int v = E[i].v ;
        if(v == fa)  continue ;
        dfs_find(v ,u) ;
        siz[u] += siz[v] ;
        if(siz[son[u]] < siz[v])   son[u] = v ;
    }
}
void dfs_time(int u ,int fa)
{
    ti[u] = idx++ ;
    top[u] = fa ;
    if(son[u])  dfs_time(son[u] ,top[u]) ;
    for(int i = head[u] ;i != -1 ;i = E[i].next)
    {
        int v = E[i].v ;
        if(v == father[u] || v == son[u])  continue ;
        dfs_time(v ,v) ;
    }
    to[u] = idx-1 ;
}
void init()
{
    sum = 0 ;
    num = 0 ;
    memset(head ,-1 ,sizeof(head)) ;
}
struct node
{
    int le ,rt ,sum ,flag ;
}T[MX*4] ;
void build(int x ,int le ,int rt)
{
    T[x].sum = 0 ;
    T[x].flag = true ;
    T[x].le = le ; T[x].rt = rt ;
    if(le == rt)
               return ;
    int Mid = (le + rt)>>1 ;
    build(L(x) ,le ,Mid) ;
    build(R(x),Mid+1 ,rt) ;
}
void push_up(int x)
{
    T[x].sum = T[L(x)].sum + T[R(x)].sum  ;
    T[x].flag = true ;
}
void push_down(int x)
{
    if(!T[x].flag)
    {
        T[L(x)].sum = T[R(x)].sum = 0 ;
        T[L(x)].flag = T[R(x)].flag = false ;
        T[x].sum = 0 ;
    }
}
bool Findpos(int x ,int pos)
{
    if(T[x].le == T[x].rt && T[x].le == pos)
    {
        if(!T[x].flag)  T[x].sum = 0 ;
        return T[x].flag ;
    }
    push_down(x) ;
    int Mid = (T[x].le + T[x].rt)>>1 ;
    if(pos <= Mid)   return Findpos(L(x) ,pos) ;
    else    return Findpos(R(x) ,pos) ;
    push_up(x) ;
}
void insert(int x ,int pos ,int w)  
{
     if(T[x].le == T[x].rt && T[x].le == pos)
     {
         T[x].sum = w ;
         T[x].flag = true ;
         return ;
     }
     push_down(x) ;
     int Mid = (T[x].le + T[x].rt)>>1 ;
     if(pos <= Mid)  insert(L(x) ,pos ,w) ;
     else    insert(R(x) ,pos ,w) ;
     push_up(x) ;
}
void update(int x ,int Le ,int Rt) 
{
    if(T[x].le == Le && T[x].rt == Rt)
    {
        T[x].flag = false ;
        T[x].sum = 0 ;
        return ;
    }
    push_down(x) ;
    int Mid = (T[x].le + T[x].rt)>>1 ;
    if(Le > Mid)   update(R(x) ,Le ,Rt) ;
    else if(Rt <= Mid)  update(L(x) ,Le ,Rt) ;
    else
    {
        update(L(x) ,Le ,Mid) ;
        update(R(x) ,Mid+1 ,Rt) ;
    }
    push_up(x) ;
}
int Query(int x ,int Le ,int Rt) 
{
   if(T[x].le == Le && T[x].rt == Rt)
    {
        if(!T[x].flag)  T[x].sum = 0 ;
        int temp = T[x].sum ;
        T[x].sum = 0 ;
        T[x].flag = false ;
        return temp ;
    }
    push_down(x) ;
    int Mid = (T[x].le + T[x].rt)>>1 ;
    if(Le > Mid)   return Query(R(x) ,Le ,Rt) ;
    else if(Rt <= Mid)  return Query(L(x) ,Le ,Rt) ;
    else
        return Query(L(x) ,Le ,Mid) + Query(R(x) ,Mid+1 ,Rt) ;
}
void LCA(int u ,int v)
{
    int temp ;
    while(top[u] != top[v])
    {
        if(dep[top[u]] < dep[top[v]])
             swap(u ,v) ;
        temp = Query(1 ,ti[top[u]] ,ti[u]) ;
        update(1 ,ti[top[u]] ,ti[u]) ;
        sum += temp ;
        u = father[top[u]] ;
    }
    if(dep[u] > dep[v])
         swap(u ,v) ;
    temp = Query(1 ,ti[u] ,ti[v]) ;
    update(1 ,ti[u] ,ti[v]) ;
    sum += temp ;
}
int main()
{
    int Tx ,u ,v ;
    scanf("%d" ,&Tx) ;
    while(Tx--)
    {
        init() ;
        scanf("%d" ,&n) ;
        for(int i = 1 ;i <= n ; ++i)
            scanf("%d" ,&V[i]) ;
        for(int i = 1 ;i < n ; ++i)
        {
            scanf("%d%d" ,&u ,&v) ;
            add_edge(u ,v) ;
        }
        dep[1] = siz[0] = 0 ;
        dfs_find(1 ,1) ;
        idx = 1 ;
        dfs_time(1 ,1) ;
        build(1 ,1 ,n) ;
        for(int i = 1 ;i <= n ; ++i)
            insert(1 ,ti[i] ,V[i]) ;
        scanf("%d" ,&m) ;
        int type ;
        for(int i = 0 ;i < m ; ++i)
        {
            scanf("%d%d" ,&type ,&u) ;
            if(type == 1)
            {
                scanf("%d" ,&v) ;
                LCA(u ,v) ;
            }
            else if(type == 2)
            {
                bool flag = Findpos(1 ,ti[u]) ;
                if(!flag)
                {
                    insert(1 ,ti[u] ,V[u]) ;
                    sum -= V[u] ;
                }
            }
            else if(type == 3)
            {
                sum += Query(1 ,ti[u] ,to[u]) ;
                update(1 ,ti[u] ,to[u]) ;
            }
            cout<<sum<<endl ;
        }
    }
    return 0 ;
}
