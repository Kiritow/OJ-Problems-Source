#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

const int maxn = 100 + 10;
int n;

struct Point {
    int x, y;
    Point(int x=0, int y=0):x(x),y(y) {}
}P[maxn];

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Vector A, Vector B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, int p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, int p) { return Vector(A.x/p, A.y/p); }

bool operator < (const Vector& a, const Vector& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

int Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
int Length(Vector A) { return sqrt(Dot(A, A)); }
int Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
int Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
int Area2(Point A, Point B, Point C) { return Cross(B-A, C-A); }

int PolygonArea() {
    int area = 0;
    for(int i = 1; i < n-1; i++) 
        area += Cross(P[i]-P[0], P[i+1]-P[0]);
    return area/2;
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) 
        scanf("%d%d", &P[i].x, &P[i].y);

    printf("%d\n", PolygonArea());
    return 0;
}
