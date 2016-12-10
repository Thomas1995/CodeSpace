#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-4;

class Matrix33d {
public:
	double M[3][3];

	Matrix33d() {
		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				M[i][j] = 0;
	}

	double& operator () (int x, int y) {
		return M[x][y];
	}
};

double dist(double a, double b, double c, double d, double e, double f) {
	return sqrt((a-d)*(a-d)+(b-e)*(b-e)+(c-f)*(c-f));
}

double area(double a, double b, double c, double d, double e, double f, double g, double h, double i) {
	double l1 = dist(a,b,c,d,e,f);
	double l2 = dist(a,b,c,g,h,i);
	double l3 = dist(g,h,i,d,e,f);
	double s = (l1+l2+l3)/2;

	return sqrt(s*(s-l1)*(s-l2)*(s-l3));
}

int tr1[3][3], tr2[3][3];

Matrix33d inverse(Matrix33d& m) {
	// computes the inverse of a matrix m
	double det = m(0, 0) * (m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2)) -
             	m(0, 1) * (m(1, 0) * m(2, 2) - m(1, 2) * m(2, 0)) +
             	m(0, 2) * (m(1, 0) * m(2, 1) - m(1, 1) * m(2, 0));

	double invdet = 1 / det;

	Matrix33d minv; // inverse of matrix m
	minv(0, 0) = (m(1, 1) * m(2, 2) - m(2, 1) * m(1, 2)) * invdet;
	minv(0, 1) = (m(0, 2) * m(2, 1) - m(0, 1) * m(2, 2)) * invdet;
	minv(0, 2) = (m(0, 1) * m(1, 2) - m(0, 2) * m(1, 1)) * invdet;
	minv(1, 0) = (m(1, 2) * m(2, 0) - m(1, 0) * m(2, 2)) * invdet;
	minv(1, 1) = (m(0, 0) * m(2, 2) - m(0, 2) * m(2, 0)) * invdet;
	minv(1, 2) = (m(1, 0) * m(0, 2) - m(0, 0) * m(1, 2)) * invdet;
	minv(2, 0) = (m(1, 0) * m(2, 1) - m(2, 0) * m(1, 1)) * invdet;
	minv(2, 1) = (m(2, 0) * m(0, 1) - m(0, 0) * m(2, 1)) * invdet;
	minv(2, 2) = (m(0, 0) * m(1, 1) - m(1, 0) * m(0, 1)) * invdet;

	return minv;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin>>T;
	while(T--) {
		int cnt = 0;

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				cin>>tr1[i][j];

		for(int i=0;i<3;++i)
			for(int j=0;j<3;++j)
				cin>>tr2[i][j];

		int x0 = tr1[0][0], y0 = tr1[0][1], z0 = tr1[0][2];
		int x1 = tr1[1][0], y1 = tr1[1][1], z1 = tr1[1][2];
		int x2 = tr1[2][0], y2 = tr1[2][1], z2 = tr1[2][2];

		for(int i=0;i<3;++i) {
			int xa = tr2[i][0], ya = tr2[i][1], za = tr2[i][2];
			int xb = tr2[(i+1)%3][0], yb = tr2[(i+1)%3][1], zb = tr2[(i+1)%3][2];

			Matrix33d m;
			m(0,0) = xa-xb;
			m(0,1) = x1-x0;
			m(0,2) = x2-x0;
			m(1,0) = ya-yb;
			m(1,1) = y1-y0;
			m(1,2) = y2-y0;
			m(2,0) = za-zb;
			m(2,1) = z1-z0;
			m(2,2) = z2-z0;

			Matrix33d mi = inverse(m);

			double a = xa-x0, b = ya-y0, c = za-z0;

			double t2 = m(0,0) * a + m(0,1) * b + m(0,2) * c;
			double u2 = m(1,0) * a + m(1,1) * b + m(1,2) * c;
			double v2 = m(2,0) * a + m(2,1) * b + m(2,2) * c;

			t2 /= 20;

			double t, u, v;
			t = xa+(xb-xa)*t2;
			u = ya+(yb-ya)*t2;
			v = za+(zb-za)*t2;

			//cout<<t<<" "<<u<<" "<<v<<"\n";

			double dt = dist(xa, ya, za, xb, yb, zb);
			double d1 = dist(xa, ya, za, t, u, v);
			double d2 = dist(t, u, v, xb, yb, zb);

			if(abs(d1+d2-dt) <= eps) {
				double at = area(x0,y0,z0,x1,y1,z1,x2,y2,z2);
				double a1 = area(t,u,v,x1,y1,z1,x2,y2,z2);
				double a2 = area(x0,y0,z0,t,u,v,x2,y2,z2);
				double a3 = area(x0,y0,z0,x1,y1,z1,t,u,v);

				if(abs(a1+a2+a3-at) <= eps) {
					++cnt;
				}
			}
		}

		if(cnt == 1)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}

	return 0;
}
