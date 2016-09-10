#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
using namespace std;
const double eps = 1e-8;
inline double sqr(double x){return x*x;}
struct Point{
    double x,y,z;
    void input(){
        scanf("%lf%lf%lf",&x,&y,&z);
        assert(fabs(x) <= 10000);
        assert(fabs(y) <= 10000);
        assert(fabs(z) <= 10000);
    }
};
struct Line{
    Point s,e;
    void input(){
        s.input();
        e.input();
    }
    double len(){
        return sqrt((s.x-e.x)*(s.x-e.x)+(s.y-e.y)*(s.y-e.y)+(s.z-e.z)*(s.z-e.z));
    }
};
struct Ellipsoid{
    double x,y,z,a,b,c;
    char color[5];
    void input(){
        scanf("%lf%lf%lf%lf%lf%lf%s",&x,&y,&z,&a,&b,&c,color);
        assert(fabs(x) <= 10000);
        assert(fabs(y) <= 10000);
        assert(fabs(z) <= 10000);
        assert(a >= 1 && a <= 10000);
        assert(b >= 1 && b <= 10000);
        assert(c >= 1 && c <= 10000);
        assert(color[0] == 'R' || color[0] == 'G' || color[0] == 'B');
    }
    void output(){
        printf("%lf %lf %lf %lf %lf %lf %s\n",x,y,z,a,b,c,color);
    }
};
double calc(vector<Line>line,vector<Ellipsoid>el){
    double ans = 0;
    int sz1 = line.size();
    for(int i = 0;i < sz1;i++){
        vector<pair<double,int> >vec;
        vec.push_back(make_pair(0.0,0));
        vec.push_back(make_pair(1.0,0));
        double len = line[i].len();
        if(fabs(len) < eps)continue;
        double x1 = line[i].s.x;
        double y1 = line[i].s.y;
        double z1 = line[i].s.z;
        double dx = line[i].e.x - line[i].s.x;
        double dy = line[i].e.y - line[i].s.y;
        double dz = line[i].e.z - line[i].s.z;
        int sz = el.size();
        for(int j = 0;j < sz;j++){
            double a = sqr(dx)/sqr(el[j].a) + sqr(dy)/sqr(el[j].b) + sqr(dz)/sqr(el[j].c);
            double b = 2*dx*(x1-el[j].x)/sqr(el[j].a) + 
                2*dy*(y1-el[j].y)/sqr(el[j].b) + 2*dz*(z1-el[j].z)/sqr(el[j].c);
            double c = sqr(x1-el[j].x)/sqr(el[j].a) + sqr(y1-el[j].y)/sqr(el[j].b)
                + sqr(z1-el[j].z)/sqr(el[j].c) - 1;
            double delta = b*b - 4*a*c;
            if(delta < eps)continue;
            double k1 = (-b+sqrt(delta))/(2*a);
            double k2 = (-b-sqrt(delta))/(2*a);
            if(k1 > k2)swap(k1,k2);
            k1 = max(0.0,k1);
            k2 = min(1.0,k2);
            if(k1 >= k2)continue;
            vec.push_back(make_pair(k1,1));
            vec.push_back(make_pair(k2,-1));
        }
        int cnt = 0;
        sort(vec.begin(),vec.end());
        int sz2 = vec.size();
        double pre = 0;
        for(int j = 0;j < sz2;j++){
            if(cnt > 0)
                ans += (vec[j].first - pre)*len;
            pre = vec[j].first;
            cnt += vec[j].second;
        }
    }
    return ans;
}
Line line[110];
Ellipsoid el[110];
vector<Line>vec1;
vector<Ellipsoid>vec2;
int main()
{
    int T;
    scanf("%d",&T);
    assert(T >= 1 && T  <= 100);
    int iCase = 0;
    int n,m;
    while(T--){
        iCase++;
        scanf("%d%d",&n,&m);
        for(int i = 0;i < n;i++)line[i].input();
        for(int i = 0;i < m;i++){
            el[i].input();
        }
        vec1.clear();
        for(int i = 0;i < n;i++)vec1.push_back(line[i]);
        double tot = 0;
        for(int i = 0;i < n;i++)tot += line[i].len();
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'R')
                vec2.push_back(el[i]);
        double R = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'G')
                vec2.push_back(el[i]);
        double G = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'B')
                vec2.push_back(el[i]);
        double B = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'R' || el[i].color[0] == 'G')
                vec2.push_back(el[i]);
        double RG = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'R' || el[i].color[0] == 'B')
                vec2.push_back(el[i]);
        double RB = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'G' || el[i].color[0] == 'B')
                vec2.push_back(el[i]);
        double GB = calc(vec1,vec2);
        vec2.clear();
        for(int i = 0;i < m;i++)
            if(el[i].color[0] == 'R' || el[i].color[0] == 'G' || el[i].color[0] == 'B')
                vec2.push_back(el[i]);
        double RGB = calc(vec1,vec2);
        double ans1 = RGB - GB;
        double ans2 = RGB - RB;
        double ans3 = RGB - RG;
        double ans4 = RGB - B - ans1 - ans2;
        double ans5 = RGB - G - ans1 - ans3;
        double ans6 = RGB - R - ans2 - ans3;
        double ans7 = R + G - RG - ans4;
        double aa = tot-RGB;
        if(fabs(aa) < eps)aa = 0;
        if(fabs(ans1) < eps)ans1 = 0;
        if(fabs(ans2) < eps)ans2 = 0;
        if(fabs(ans3) < eps)ans3 = 0;
        if(fabs(ans4) < eps)ans4 = 0;
        if(fabs(ans5) < eps)ans5 = 0;
        if(fabs(ans6) < eps)ans6 = 0;
        if(fabs(ans7) < eps)ans7 = 0;
        printf("%.10lf\n",aa);
        printf("%.10lf\n",ans1);
        printf("%.10lf\n",ans2);
        printf("%.10lf\n",ans3);
        printf("%.10lf\n",ans4);
        printf("%.10lf\n",ans5);
        printf("%.10lf\n",ans6);
        printf("%.10lf\n",ans7);
    }
    return 0;
}
