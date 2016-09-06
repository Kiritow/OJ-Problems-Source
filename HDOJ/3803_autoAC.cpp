#include<stdio.h>
#include<iostream>
 using namespace std;
#define sign(a) ((a)>0?1:(((a)<0?-1:0)))
struct point{__int64 x,y;};
__int64 pp1,pp2,qq1,qq2;
__int64 xmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.y-p0.y)-(p2.x-p0.x)*(p1.y-p0.y);
}
__int64 xmult(__int64 x1,__int64 y1,__int64 x2,__int64 y2,__int64 x0,__int64 y0){
    return (x1-x0)*(y2-y0)-(x2-x0)*(y1-y0);
}
__int64 dmult(point p1,point p2,point p0){
    return (p1.x-p0.x)*(p2.x-p0.x)+(p1.y-p0.y)*(p2.y-p0.y);
}
__int64 dmult(__int64 x1,__int64 y1,__int64 x2,__int64 y2,__int64 x0,__int64 y0){
    return (x1-x0)*(x2-x0)+(y1-y0)*(y2-y0);
}
__int64 dots_inline(point p1,point p2,point p3){
    return !xmult(p1,p2,p3);
}
__int64 dots_inline(__int64 x1,__int64 y1,__int64 x2,__int64 y2,__int64 x3,__int64 y3){
    return !xmult(x1,y1,x2,y2,x3,y3);
}
__int64 dot_online_in(point p,point l1,point l2){
    return !xmult(p,l1,l2)&&(l1.x-p.x)*(l2.x-p.x)<=0&&(l1.y-p.y)*(l2.y-p.y)<=0;
}
__int64 dot_online_in(__int64 x,__int64 y,__int64 x1,__int64 y1,__int64 x2,__int64 y2){
    return !xmult(x,y,x1,y1,x2,y2)&&(x1-x)*(x2-x)<=0&&(y1-y)*(y2-y)<=0;
}
__int64 dot_online_ex(point p,point l1,point l2){
    return dot_online_in(p,l1,l2)&&(p.x!=l1.x||p.y!=l1.y)&&(p.x!=l2.x||p.y!=l2.y);
}
__int64 dot_online_ex(__int64 x,__int64 y,__int64 x1,__int64 y1,__int64 x2,__int64 y2){
    return dot_online_in(x,y,x1,y1,x2,y2)&&(x!=x1||y!=y1)&&(x!=x2||y!=y2);
}
__int64 same_side(point p1,point p2,point l1,point l2){
    return sign(xmult(l1,p1,l2))*xmult(l1,p2,l2)>0;
}
__int64 opposite_side(point p1,point p2,point l1,point l2){
    return sign(xmult(l1,p1,l2))*xmult(l1,p2,l2)<0;
}
__int64 parallel(point u1,point u2,point v1,point v2){
    return (u1.x-u2.x)*(v1.y-v2.y)==(v1.x-v2.x)*(u1.y-u2.y);
}
__int64 __int64ersect_in(point u1,point u2,point v1,point v2){
    if (!dots_inline(u1,u2,v1)||!dots_inline(u1,u2,v2))
        return !same_side(u1,u2,v1,v2)&&!same_side(v1,v2,u1,u2);
    return dot_online_in(u1,v1,v2)||dot_online_in(u2,v1,v2)||dot_online_in(v1,u1,u2)||dot_online_in(v2,u1,u2);
}
__int64 __int64ersect_ex(point u1,point u2,point v1,point v2){
    return opposite_side(u1,u2,v1,v2)&&opposite_side(v1,v2,u1,u2);
}
void __int64ersection(point u1,point u2,point v1,point v2){
    point ret=u1;
    pp2=qq2=(__int64)(u1.x-u2.x)*(__int64)(v1.y-v2.y)-(__int64)(u1.y-u2.y)*(__int64)(v1.x-v2.x);
    pp1=u1.x;
    qq1=u1.y;
    pp1*=pp2;
    qq1*=qq2;
    pp1+=((__int64)(u1.x-v1.x)*(__int64)(v1.y-v2.y)-(__int64)(u1.y-v1.y)*(__int64)(v1.x-v2.x))*(__int64)(u2.x-u1.x);
    qq1+=((__int64)(u1.x-v1.x)*(__int64)(v1.y-v2.y)-(__int64)(u1.y-v1.y)*(__int64)(v1.x-v2.x))*(__int64)(u2.y-u1.y);
}
point m1,m2,n1,n2;
__int64 ansx[2],ansy[2];
__int64 fab(__int64 k)
{
    return k>0?k:-k;
}
__int64 gcd(__int64 m,__int64 n) 
{
    while (1)
    {
    m=m%n;
    if (m==0) return n;
    n=n%m;
    if (n==0) return m;
    }
}
void dod(__int64 kk1,__int64 kk2,__int64 kk)
{
    __int64 t1,t2,t3,t4;
    __int64 sign1=1;
    if(kk2==0) while(1);
    if(kk1==0) 
    {
        ansx[kk]=kk1;
        ansy[kk]=1;
        return ;
    }
    if(kk2==1 || kk1==1 )
    {
        ansx[kk]=kk1;
        ansy[kk]=kk2;
        return ;
    }
    if((kk1<0 && kk2>0) || (kk1>0 && kk2<0))
    {
        sign1=-1;
    }
    t1=fab(kk1);
    t2=fab(kk2);
    if(t1>t2)
    {
        t3=gcd(t1,t2);
        t1/=t3;
        t2/=t3;
        ansx[kk]=sign1*t1;ansy[kk]=t2;
    }
    else if(t1<t2)
    {
        t3=gcd(t2,t1);
        t1/=t3;
        t2/=t3;
        ansx[kk]=sign1*t1;ansy[kk]=t2;
    }
    else {ansx[kk]=sign1*1;ansy[kk]=1;}
}
__int64 check(point aa,point bb)
{
    if(aa.x==bb.x && aa.y==bb.y) return 1;
    return 0;
}
int main()
{
    int t;
    int ans=0;
    point res;
    scanf("%d",&t);
    while(t--)
    {
        ans=0;
        cin>>m1.x>>m1.y>>m2.x>>m2.y>>n1.x>>n1.y>>n2.x>>n2.y;
        if(__int64ersect_in(m1,m2,n1,n2)) 
        {
            if(__int64ersect_ex(m1,m2,n1,n2)) 
            {
                ans=1;
                __int64ersection(m1,m2,n1,n2);
                dod(pp1,pp2,0);
                dod(qq1,qq2,1);
            }
            else if(parallel(m1,m2,n1,n2)) 
            {
                if( check(m1,m2) && check(n1,n2))  
                {
                    res=m1;
                    cout<<'1'<<endl<<res.x<<' '<<res.y<<endl;
                    continue;
                }
                else if( check(m1,m2) || check(n1,n2))
                {
                    if(check(m1,m2)) {ans=1; res=m1;}    
                    else {ans=1; res=n1;}    
                    if(ans==1) {cout<<'1'<<endl<<res.x<<' '<<res.y<<endl;continue;}
                }
                else if( 1== check(m1,n1) + check(m1,n2) + check(m2,n1) + check(m2,n2))
                {
                    ans=-1;
                    if(check(m1,n1)) 
                    {
                        if(dmult(m2,n2,m1)<0) {ans=1;res=m1;}
                    }
                    else if(check(m1,n2))
                    {
                        if(dmult(m2,n1,m1)<0) {ans=1;res=m1;}
                    }
                    else if(check(m2,n1))
                    {
                        if(dmult(m1,n2,m2)<0) {ans=1;res=m2;}
                    }
                    else if(check(m2,n2))
                    {
                        if(dmult(m1,n1,m2)<0) {ans=1;res=m2;}
                    }
                    if(ans==1) {cout<<'1'<<endl<<res.x<<' '<<res.y<<endl;continue;}
                }
                else ans=-1; 
            }
            else
            {
                if(check(m1,n1) || check(m1,n2))  
                {
                    res=m1;ans=1;
                }
                if(check(m2,n1) || check(m2,n2))
                {
                    res=m2;ans=1;
                }
                if(ans==1) {cout<<'1'<<endl<<res.x<<' '<<res.y<<endl;continue;}
                ans=1;
                __int64ersection(m1,m2,n1,n2);
                dod(pp1,pp2,0);
                dod(qq1,qq2,1);
            }
        }
        if(ans==-1) puts("INF");
        else
        {
            printf("%d\n",ans);
            if(ans==1)
            {
                if(ansy[0]==1) cout<<ansx[0]<<" ";
                else cout<<ansx[0]<<'/'<<ansy[0]<<" ";
                if(ansy[1]==1) cout<<ansx[1]<<endl;
                else cout<<ansx[1]<<'/'<<ansy[1]<<endl;
            }
        }    
    }
    return 0;
}
