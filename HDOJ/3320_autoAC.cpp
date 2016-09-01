#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#define eps 1e-8
using namespace std;
const double PI=acos(-1.0);
const int MAXN=105;
struct point3{
    double x,y,z;
};
struct order{
    char c;
    double x,y,z,ang;
}ord[MAXN];
point3 rotate3(point3 q,double x0,double y0,double z0,double ang)
{
    double x2=x0*x0;
    double y2=y0*y0;
    double z2=z0*z0;
    double d2=x2+y2+z2;
    double d=sqrt(d2);
    double sina=sin(ang);
    double cosa=cos(ang);
    point3 ans;
    ans.x=(x2+(y2+z2)*cosa)/d2*q.x+(x0*y0*(1-cosa)/d2-z0*sina/d)*q.y+(x0*z0*(1-cosa)/d2+y0*sina/d)*q.z;
    ans.y=(y0*x0*(1-cosa)/d2+z0*sina/d)*q.x+(y2+(x2+z2)*cosa)/d2*q.y+(y0*z0*(1-cosa)/d2-x0*sina/d)*q.z;
    ans.z=(z0*x0*(1-cosa)/d2-y0*sina/d)*q.x+(z0*y0*(1-cosa)/d2+x0*sina/d)*q.y+(z2+(x2+y2)*cosa)/d2*q.z;
    return ans;
}
int main()
{
    int T;
    char str[500];
    scanf("%d",&T);
    while(T--){
        int i,j;
        double tmp;
        double tail,muti;
        double sig;
        for(i=0;;i++){
            scanf("%s",str);
            if(str[2]=='B') ord[i].c='B';
            else if(str[2]=='S'){
                ord[i].c='S';
                for(j=2;str[j]!='(';j++);
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].x=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].y=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=')';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].z=tmp*sig;
            }
            else if(str[2]=='T'){
                ord[i].c='T';
                for(j=2;str[j]!='(';j++);
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].x=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].y=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=')';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].z=tmp*sig;
            }
            else if(str[2]=='V'){
                ord[i].c='V';
                for(j=2;str[j]!='(';j++);
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].x=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].y=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=')';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].z=tmp*sig;
            }
            else if(str[2]=='E') break;
            else{
                ord[i].c='R';
                for(j=2;str[j]!='(';j++);
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].ang=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].x=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=',';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].y=tmp*sig;
                tmp=0.0;
                sig=1.0;
                for(j++;str[j]!='.';j++){
                    if(str[j]=='-'){
                        sig=-1.0;
                        continue;
                    }
                    tmp=tmp*10+str[j]-'0';
                }
                tail=0.0;
                muti=0.1;
                for(j++;str[j]!=')';j++){
                    tail+=(str[j]-'0')*muti;
                    muti/=10.0;
                }
                tmp+=tail;
                ord[i].z=tmp*sig;
            }
        }
        point3 pnt;
        i--;
        pnt.x=ord[i].x;
        pnt.y=ord[i].y;
        pnt.z=ord[i].z;
        for(i--;i>=0;i--){
            if(ord[i].c=='T'){
                pnt.x+=ord[i].x;
                pnt.y+=ord[i].y;
                pnt.z+=ord[i].z;
            }
            else if(ord[i].c=='S'){
                pnt.x*=ord[i].x;
                pnt.y*=ord[i].y;
                pnt.z*=ord[i].z;
            }
            else if(ord[i].c=='R'){
                pnt=rotate3(pnt,ord[i].x,ord[i].y,ord[i].z,ord[i].ang);
            }
        }
        printf("%.1f %.1f %.1f\n",pnt.x,pnt.y,pnt.z);
    }
    return 0;
}
