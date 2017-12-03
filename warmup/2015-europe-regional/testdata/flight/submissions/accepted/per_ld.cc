#include <bits/stdc++.h>
using namespace std;
typedef long double ldouble;
const ldouble RADIUS = 6370;
const ldouble pi = 2.0L*acos(0.0L);
const ldouble EPS = 1e-6;

struct point {
	ldouble x, y, z;
	point(ldouble x=0, ldouble y=0, ldouble z=0): x(x), y(y), z(z) {}
	point operator-() { return point(-x, -y, -z); }
	ldouble dist() { return sqrt(x*x+y*y+z*z); }
	point normalize() {
		ldouble d = dist();
		return point(x/d, y/d, z/d);
	}
	point cross(point p) {
		return point(y*p.z-z*p.y, z*p.x-x*p.z, x*p.y-y*p.x);
	}
	ldouble angle(point p) {
		return acos(x*p.x+y*p.y+z*p.z);
	}
};

typedef vector<point> vp;

vector<vp> islands;

void readvp(vp &R) {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i) {
		ldouble lat, lng;
		scanf("%Lf%Lf", &lat, &lng);
		lng *= pi/180;
		lat *= pi/180;
		R.push_back(point(cos(lng)*cos(lat), sin(lng)*cos(lat), sin(lat)));
	}
}

bool between(point A, point B, point C) {
	return fabs(A.angle(B) + B.angle(C) - A.angle(C)) < EPS;
}

int main(void) {
	int N;
	scanf("%d", &N);
	islands.resize(N);
	for (auto &I: islands) readvp(I), I.push_back(I.front());
	vp P;
	readvp(P);
	bool inside = true;
	ldouble tot = 0.0, water = 0.0;
	for (int i = 1; i < P.size(); ++i) {
		vector<ldouble> s({0.0, P[i].angle(P[i-1])});
		for (auto &I: islands)
			for (int j = 1; j < I.size(); ++j) {
				point isect = P[i].cross(P[i-1]).cross(I[j].cross(I[j-1])).normalize();
				if (between(P[i-1], isect, P[i]) && between(I[j-1], isect, I[j]))
					s.push_back(P[i-1].angle(isect));
				else if(between(P[i-1], -isect, P[i]) && between(I[j-1], -isect, I[j]))
					s.push_back(P[i-1].angle(-isect));
			}
		sort(s.begin(), s.end());
		tot += s.back();
		for (int j = 1; j < s.size(); ++j, inside = !inside)
			if (!inside) water += s[j]-s[j-1];
		inside = !inside;
	}
	printf("%.9Lf %.9Lf\n", RADIUS*tot, 100.0*water/tot);
}