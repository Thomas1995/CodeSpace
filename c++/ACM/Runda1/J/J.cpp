#include <bits/stdc++.h>
using namespace std;

int n,m,t;
double pold[105], pnew[105];

vector< pair<int, int> > v;
vector< double > w;
vector< int > vec[105];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T,a,b;
	double c;
	cin>>T;
	while(T--) {
		cin>>n>>m>>t;
		v.clear();
		w.clear();
		for(int i=1;i<=n;++i)
			vec[i].clear();

		for(int i=1;i<=n;++i) {
			cin>>pold[i];
			pnew[i] = pold[i];
		}

		for(int i=1;i<=m;++i) {
			cin>>a>>b>>c;
			v.push_back(make_pair(a+1,b+1));
			w.push_back(c);
			vec[a+1].push_back(b+1);
			vec[b+1].push_back(a+1);
		}

		while(t--) {
			for(int i=0;i<v.size();++i) {
				int from = v[i].first;
				int to = v[i].second;

				double tr = w[i] * pold[from];
				pnew[to] += tr;
				pnew[from] -= tr;
			}

			for(int i=1;i<=n;++i) {
				pold[i] = pnew[i];
				//cout<<i<<" -> "<<pold[i]<<"\n";
			}

			//cout<<"\n";
		}

		double mn = 1e9;
		for(int i=1;i<=n;++i) {
			double crt = pold[i];
			for(int j=0;j<vec[i].size();++j) {
				crt += pold[vec[i][j]];
			}
			mn = min(mn, crt);
		}

		cout<<fixed<<setprecision(9)<<mn<<"\n";
	}

	return 0;
}
