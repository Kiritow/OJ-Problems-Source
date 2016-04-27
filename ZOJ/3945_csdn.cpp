#include<bits/stdc++.h>

using namespace std;

struct Pt{
	double x, y, z;
} A,B,C,D;

const double eps = 1e-8;
const double _5 = sqrt(5.0);
const double _2 = sqrt(2.0);
double f[3];

typedef pair<Pt, Pt> PPP;

struct Pi{
	int x, y, z;
};

bool operator < (const Pi & a, const Pi & b){
	return (a.x < b.x);
}

bool operator == (const Pi & a, const Pi & b){
	return (a.x == b.x && a.y == b.y && a.z == b.z);
}

void Pit(const Pt & X){
	cout<<X.x<<' '<<X.y<<' '<<X.z<<endl;
}

bool operator == (const Pt & a, const Pt & b){
	return (fabs(a.x - b.x) < eps && fabs(a.y - b.y) < eps && fabs(a.z - b.z) < eps);
}

Pt work(Pt X, int k){
	return (Pt){X.x - 0.5 + (k & 1), X.y - 0.5 + ((k >> 1) & 1), X.z - 0.5 + ((k >> 2) & 1)};
}

/******************************/

#ifdef SPFA
	#define MAXD 60
#else
	#define MAXD 30
#endif

bool dis2_inRange(int x, int y, int z){
	return 0 <= x && x <= MAXD && 0 <= y && y <= MAXD && 0 <= z && z <= MAXD;
}

inline double dis2_getDis(int cnt){
	return cnt > 3 ? 1E100 : cnt == 3 ? _5 : cnt == 2 ? _2 : 1.0;
}

int dis2_getDis(int x, int y, int z, int ux, int uy, int uz){
	const int t = -2;
	if (((x | 1) != (ux | 1) || (y | 1) != (uy | 1) || (z | 1) != (uz | 1))
		&& ((x + (x & 1)) != (ux + (ux & 1)) || (y + (y & 1)) != (uy + (uy & 1)) || (z + (z & 1)) != (uz + (uz & 1))))
		return 4;
	return (x != ux) + (y != uy) + (z != uz);
}

void dis2_pre(Pi st, double (&dis)[MAXD + 1][MAXD + 1][MAXD + 1], int (&dt)[MAXD + 1][MAXD + 1][MAXD + 1][3]){
	static bool in[MAXD + 1][MAXD + 1][MAXD + 1];
	for (int i = 0; i <= MAXD; ++i)
		for (int j = 0; j <= MAXD; ++j)
			for (int k = 0; k <= MAXD; ++k){
				dis[i][j][k] = 1E100;
				in[i][j][k] = false;
				dt[i][j][k][0] = dt[i][j][k][1] = dt[i][j][k][2] = 0;
			}
	dis[st.x][st.y][st.z] = 0;
	queue<Pi> Q;
	Q.push(st);
	while (!Q.empty()){
		Pi u = Q.front();
		Q.pop();
//		fprintf(stderr, "start update: %d %d %d\n", u.x, u.y, u.z);
		for (int i = -1; i <= 1; ++i)
			for (int j = -1; j <= 1; ++j)
				for (int k = -1; k <= 1; ++k){
					int x = u.x + i, y = u.y + j, z = u.z + k;
					if (dis2_inRange(x, y, z)){
						int tmp = dis2_getDis(u.x, u.y, u.z, x, y, z);
						if (dis[x][y][z] > dis[u.x][u.y][u.z] + dis2_getDis(tmp)){
							dis[x][y][z] = dis[u.x][u.y][u.z] + dis2_getDis(tmp);
							dt[x][y][z][0] = dt[u.x][u.y][u.z][0];
							dt[x][y][z][1] = dt[u.x][u.y][u.z][1];
							dt[x][y][z][2] = dt[u.x][u.y][u.z][2];
							++dt[x][y][z][tmp - 1];
//							printf("%d %d %d\n", x, y, z);
							if (!in[x][y][z]){
//								puts("- =");
								in[x][y][z] = true;
								Q.push((Pi){x, y, z});
							}
						}
					}
				}
		in[u.x][u.y][u.z] = false;
	}
}

double dis2(Pi st, Pi ed){
	static bool used = false;
	static double dis[8][MAXD + 1][MAXD + 1][MAXD + 1];
	static int dt[8][MAXD + 1][MAXD + 1][MAXD + 1][3];

	/* prework */
	if (!used){
		used = true;
		for (int i = 0; i < 8; ++i)
			dis2_pre((Pi){i >> 2 & 1, i >> 1 & 1, i & 1}, dis[i], dt[i]);
	}

	int dx = ed.x - st.x, dy = ed.y - st.y, dz = ed.z - st.z;

	if (dx < dy){
		swap(dx, dy);
		swap(st.x, st.y);
		swap(ed.x, ed.y);
	}
	if (dx < dz){
		swap(dx, dz);
		swap(st.x, st.z);
		swap(ed.x, ed.z);
	}
	if (dy < dz){
		swap(dy, dz);
		swap(st.y, st.z);
		swap(ed.y, ed.z);
	}

	int cnt2 = 0, cnt1 = 0;
#ifndef SPFA
	int Maki = 5;
	int tx = max(0, dx - Maki) & -4, ty = max(0, dy - Maki) & -4, tz = max(0, dz - Maki) & -4;
//	printf("%d %d %d\n", tx, ty, tz);
	dx -= tx, dy -= ty, dz -= tz;
	if (ty + tz <= tx){
		tx -= cnt2 = ty + tz;
		cnt1 += max(0, tx - dy - dz);
		dx += min(dy + dz, tx);
	}
	else
		cnt2 += tx + ty + tz >> 1;
//	printf("- %d %d %d, %d %d\n", dx, dy, dz, cnt1, cnt2);
//	printf("st: %d %d %d\n", st.x, st.y, st.z);
#endif
	ed.x = st.x + dx;
	ed.y = st.y + dy;
	ed.z = st.z + dz;
	int type = st.x << 2 | st.y << 1 | st.z;
//	printf("%d %d %d\n", cnt1 + dt[type][ed.x][ed.y][ed.z][0], cnt2 + dt[type][ed.x][ed.y][ed.z][1], dt[type][ed.x][ed.y][ed.z][2]);
	return cnt1 + cnt2 * _2 + dis[type][ed.x][ed.y][ed.z];
}

#undef MAXD

/******************************/

double _dis2(Pt P, Pt Q){
	f[0] = fabs(P.x - Q.x);
	f[1] = fabs(P.y - Q.y);
	f[2] = fabs(P.z - Q.z);
	sort(f, f + 3);
	f[2] -= f[1];
	f[1] -= f[0];
	return _5 * f[0] + _2 * f[1] + f[2];
}

Pt operator -(const Pt & a, const Pt & b){
	return (Pt){a.x - b.x, a.y - b.y, a.z - b.z};
}

Pt operator +(const Pt & a, const Pt & b){
	return (Pt){a.x + b.x, a.y + b.y, a.z + b.z};
}

Pt operator *(const Pt & a, double x){
	return (Pt){a.x * x, a.y * x, a.z * x};
}

double sqr(double x){
	return x * x;
}

inline double len(const Pt & a){
	return sqrt(sqr(a.x)+sqr(a.y)+sqr(a.z));
}

double dg(double x, double y){
	return sqrt(sqr(x) + sqr(y));
}

PPP a[100];

int like(double p, double q, double r){
	if (fabs(p - q) < eps && fabs(q - r) < eps)
		return 1;
	else
		return 0;
}

double le[100][100];

double Get_s(Pt p, Pt q){
	for(int i = 0; i < 12; i++)
		for(int j = 0; j < 12; j++){
			if (like(a[i].first.x, a[j].first.x, 0) || like(a[i].first.x, a[j].first.x, 1))
				le[i][j] = len(a[i].first - a[j].first);
			else if (like(a[i].first.y, a[j].first.y, 0) || like(a[i].first.y, a[j].first.y, 1))
				le[i][j] = len(a[i].first - a[j].first);
			else if (like(a[i].first.z, a[j].first.z, 0) || like(a[i].first.z, a[j].first.z, 1))
				le[i][j] = len(a[i].first - a[j].first);
			else
				le[i][j] = 12345678;
		}
	for(int i = 0; i < 12; i++){
		if (like(a[i].first.x, p.x, 0) ||like(a[i].first.x, p.x, 1) ||
			like(a[i].first.y, p.y, 0) ||like(a[i].first.y, p.y, 1) ||
			like(a[i].first.z, p.z, 0) ||like(a[i].first.z, p.z, 1))
			le[i][13] = le[13][i] = len(p - a[i].first);
		else
			le[i][13] = le[13][i] = 12345678;
		if (like(a[i].first.x, q.x, 0) ||like(a[i].first.x, q.x, 1) ||
			like(a[i].first.y, q.y, 0) ||like(a[i].first.y, q.y, 1) ||
			like(a[i].first.z, q.z, 0) ||like(a[i].first.z, q.z, 1))
			le[i][12] = le[12][i] = len(q - a[i].first);
		else
			le[i][12] = le[12][i] = 12345678;
	}
	le[13][13] = le[12][12] = 0;
	if (like(p.x, q.x, 0) || like(p.y, q.y, 0) || like(p.z, q.z, 0) || like(p.x, q.x, 1) || like(p.y, q.y, 1) || like(p.z, q.z, 1))
		le[13][12] = le[12][13] = len(p - q);
	else
		le[13][12] = le[12][13] = 12345678;
	for(int k = 0; k < 14; k++)
		for(int i = 0; i < 14; i++)
			for(int j = 0; j < 14; j++)
				le[i][j] = min(le[i][j] , le[i][k] + le[k][j]);
	return le[12][13];
}

double tf(Pt p, Pt q){
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
			a[(i << 1) + j + 0] = (PPP){(Pt){i, j, rand()/(double)(RAND_MAX)}, (Pt){0, 0, 1}};
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
			a[(i << 1) + j + 4] = (PPP){(Pt){i, rand()/(double)(RAND_MAX), j}, (Pt){0, 1, 0}};
	for(int i = 0; i <= 1; i++)
		for(int j = 0; j <= 1; j++)
			a[(i << 1) + j + 8] = (PPP){(Pt){rand()/(double)(RAND_MAX), i, j}, (Pt){1, 0, 0}};
	double now = Get_s(p, q);
	double t = 0.5;
	while(t > 0.001){
		int flag = 0;
		for(int i = 0; i < 12; i++)
			if (!flag){
				a[20] = a[i];
				a[i].first = a[i].first + (a[i].second * t);
				double tmp = Get_s(p, q);
				if (tmp < now){
					flag = 1;
					while(tmp < now){
						now = tmp;
						a[20] = a[i];
						a[i].first = a[i].first + (a[i].second * t);
						tmp = Get_s(p, q);
					}
				}
				a[i] = a[20];
			}
		t *= 0.9;
	}
	return now;
}

double dis1(Pt P, Pt Q, Pt R){
//	puts("QAQ");
	P = P - R;
	Q = Q - R;
	P.x += 0.5, P.y += 0.5, P.z += 0.5;
	Q.x += 0.5, Q.y += 0.5, Q.z += 0.5;
//	Pit(P), Pit(Q);
	double ans = 10;
	for(int ts = 0; ts < 100; ts++){
//		puts("= -");
		ans = min(ans, tf(P, Q));
	}
//	cout<<"tf:\t"<<ans<<endl;
	return ans;
}

double _dis1(Pt P, Pt Q, Pt R){
//	puts("#############################");
/*	Pit(P);
	Pit(Q);
	Pit(R);
*/	P = P - R;
	Q = Q - R;
/*	Pit(P);
	Pit(Q);
*/	if (fabs(fabs(P.x) - 0.5) > eps){
		if (fabs(fabs(P.y) - 0.5) <= eps){
			swap(P.y, P.x);
			swap(Q.y, Q.x);
		}
		else{
			swap(P.z, P.x);
			swap(Q.z, Q.x);
		}
	}
	if (fabs(P.x + 0.5) < eps){
		P.x = -P.x, Q.x = -Q.x;
	}
	if (fabs(Q.x - 0.5) < eps){//On the same face
	//	cout<<"tl:\t"<<sqrt(sqr(P.y - Q.y) + sqr(P.z - Q.z))<<endl;
		return sqrt(sqr(P.y - Q.y) + sqr(P.z - Q.z));
	}
	if (fabs(fabs(Q.y) - 0.5) < eps || fabs(fabs(Q.z) - 0.5) < eps){//have a common edge
		if (fabs(fabs(Q.y) - 0.5) > eps){
			swap(Q.y, Q.z);
			swap(P.y, P.z);
		}
		if (fabs(Q.y + 0.5) < eps){
			Q.y = -Q.y, P.y = -P.y;
		}
	//	cout<<"tl:\t"<<min(dg(1-P.y-Q.x, P.z-Q.z), min(dg(1-P.y-Q.z, 1-P.z-Q.x), dg(1+P.z-Q.x,1+Q.z-P.y)))<<endl;
		return min(dg(1-P.y-Q.x, P.z-Q.z), min(dg(1-P.y-Q.z, 1-P.z-Q.x), dg(1+P.z-Q.x,1+Q.z-P.y)));
	}
	//On the opposite face
	double sum = 12345678;
	//passing another face
	sum = min(sum , dg(2 - P.z - Q.z, P.y - Q.y));
	sum = min(sum , dg(2 + P.z + Q.z, P.y - Q.y));
	sum = min(sum , dg(2 + P.y + Q.y, P.z - Q.z));
	sum = min(sum , dg(2 - P.y - Q.y, P.z - Q.z));
	//passing two other faces
	sum = min(sum, dg(2 - P.y - Q.z, 1 - P.z - Q.y));
	sum = min(sum, dg(2 - P.y + Q.z, 1 + P.z - Q.y));
	sum = min(sum, dg(2 + P.y - Q.z, 1 - P.z + Q.y));
	sum = min(sum, dg(2 + P.y + Q.z, 1 + P.z + Q.y));
	sum = min(sum, dg(2 + P.z + Q.y, 1 + P.y + Q.z));
	sum = min(sum, dg(2 + P.z - Q.y, 1 - P.y + Q.z));
	sum = min(sum, dg(2 - P.z + Q.y, 1 + P.y - Q.z));
	sum = min(sum, dg(2 - P.z - Q.y, 1 - P.y - Q.z));
//	cout<<"tl:\t"<<sum<<endl;
	return sum;
}

Pt getcenter(Pt X){
	int x, y, z;
	x = (int)(round(X.x));
	y = (int)(round(X.y));
	z = (int)(round(X.z));
	if (fabs(fabs(fmod(X.x, 1)) - 0.5) > eps){
		if ((y & 1) != (x & 1)){
			y = (int)(round(X.y * 2 - y));
		}
		if ((z & 1) != (x & 1)){
			z = (int)(round(X.z * 2 - z));
		}
	}
	else{
		if (fabs(fabs(fmod(X.y, 1)) - 0.5) > eps){
			if ((y & 1) != (x & 1)){
				x = (int)(round(X.x * 2 - x));
			}
			if ((z & 1) != (y & 1)){
				z = (int)(round(X.z * 2 - z));
			}
		}
		else{
			if ((z & 1) != (x & 1)){
				x = (int)(round(X.x * 2 - x));
			}
			if ((z & 1) != (y & 1)){
				y = (int)(round(X.y * 2 - y));
			}
		}
	}
	return (Pt){(double)x, (double)y, (double)z};
}

double Nico(Pt P, Pt Q){
	Pi p = (Pi){(int)(round(P.x + 0.5)), (int)(round(P.y + 0.5)), (int)(round(P.z + 0.5))};
	Pi q = (Pi){(int)(round(Q.x + 0.5)), (int)(round(Q.y + 0.5)), (int)(round(Q.z + 0.5))};
	q.x -= (p.x / 2) * 2, p.x -= (p.x / 2) * 2;
	if (p.x == -1){q.x += 2, p.x += 2;}
	q.y -= (p.y / 2) * 2, p.y -= (p.y / 2) * 2;
	if (p.y == -1){q.y += 2, p.y += 2;}
	q.z -= (p.z / 2) * 2, p.z -= (p.z / 2) * 2;
	if (p.z == -1){q.z += 2, p.z += 2;}
	if (q.x <= 0){
		q.x = 1 - q.x;
		p.x = 1 - p.x;
	}
	if (q.y <= 0){
		q.y = 1 - q.y;
		p.y = 1 - p.y;
	}
	if (q.z <= 0){
		q.z = 1 - q.z;
		p.z = 1 - p.z;
	}
	return dis2(p, q);
}

void ck(double x){
	assert(x >= -9999  && x <= 9999);
}

int main(){
//	freopen("J.in", "r", stdin);
//	freopen("J.out", "w", stdout);
//

	srand(time(NULL));
	int T;
	scanf("%d",&T);

/*
	for(int i = 0; i < 100;  i++){
		scanf("%lf%lf%lf", &A.x, &A.y, &A.z);
		scanf("%lf%lf%lf", &B.x, &B.y, &B.z);
		dis1(A, B, (Pt){0, 0, 0});
		_dis1(A, B, (Pt){0, 0, 0});
	}
	return 0;
*/
	while(T--){
		scanf("%lf%lf%lf", &A.x, &A.y, &A.z);
		scanf("%lf%lf%lf", &B.x, &B.y, &B.z);
		ck(A.x); ck(A.y); ck(A.z);
		ck(B.x); ck(B.y); ck(B.z);
		C = getcenter(A);
		assert((A.x - C.x - eps) <= 0.5 && (A.x - C.x + eps) >= -0.5);
		assert((A.y - C.y - eps) <= 0.5 && (A.y - C.y + eps) >= -0.5);
		assert((A.z - C.z - eps) <= 0.5 && (A.z - C.z + eps) >= -0.5);
		assert(((int)round(C.x - C.y)) % 2 == 0);
		assert(((int)round(C.x - C.z)) % 2 == 0);
		D = getcenter(B);
		assert((B.x - D.x - eps) <= 0.5 && (B.x - D.x + eps) >= -0.5);
		assert((B.y - D.y - eps) <= 0.5 && (B.y - D.y + eps) >= -0.5);
		assert((B.z - D.z - eps) <= 0.5 && (B.z - D.z + eps) >= -0.5);
		assert(((int)round(D.x - D.y)) % 2 == 0);
		assert(((int)round(D.x - D.z)) % 2 == 0);
		double ans = 1234567;
		if (C == D){
			ans = _dis1(A, B, C);
		}
		else{
			
			for(int i = 0; i < 8; i++)
				for(int j = 0; j < 8; j++){
				//	ans = min(ans,dis2(work(C, i), work(D, j)));
				//	dis1(A, work(C, i), C);
				//	_dis1(A, work(C, i), C);
				//	dis1(B, work(D, j), D);
				//	_dis1(B, work(D, j), D);
					ans = min(ans, _dis1(A, work(C, i), C) + _dis1(B, work(D, j), D) + Nico(work(C, i), work(D, j)));
				//	ans = min(ans, dis1(A, work(C, i), C) + dis1(B, work(D, j), D) + dis2(work(C, i), work(D, j)));
				}
		}
		printf("%.16f\n", ans);
	}
	return 0;
}
 

/*
0.733017 0.493771 1
0.429134 0 0.88777
tf:	0.678462
tl:	0.677924
0.25458 0 1
0.165501 1 0.459615
tf:	1.4132
tl:	1.4108
0.561626 0 0
1 0.0775424 0.207269
tf:	0.556202
tl:	0.555994
0 0.98381 1
1 0.962809 0.831134
tf:	1.06045
tl:	1.05357
*/
