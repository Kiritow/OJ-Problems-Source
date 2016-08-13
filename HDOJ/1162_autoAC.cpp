#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int father[10005], Enums, Count;
double MinL;
struct Point{
    int begin;
    int end;
    double Dis;
}P[10005];
int Find(int k){
    return father[k]==k?k:father[k]=Find(father[k]);
}
int Cmp(Point a, Point b){
    return a.Dis<b.Dis;
}
double Kruskal(){
    for(int i=0; i<Count; i++){
        father[i] = i;
    }
    for(int i=0; i<Count; i++){
        int a = Find(P[i].begin);
        int b = Find(P[i].end);
        if(a!=b){
            father[b] = a;
            MinL += P[i].Dis;
        }
    }
    return MinL;
}
void Init(){
    int N;
    double x[100], y[100];
    while(cin>>N){
        for(int i=0; i<N; i++){
            cin>>x[i]>>y[i];
        }
        MinL = 0.0;
        Count=0;
        for(int i=0; i<N; i++){
            for(int j=i+1; j<N; j++){
                P[Count].begin = i;
                P[Count].end = j;
                P[Count].Dis = sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
                Count++;
            }
        }
        sort(P, P+Count, Cmp);
        printf("%.2lf\n", Kruskal());
    }
}
int main(){
    Init();
}
