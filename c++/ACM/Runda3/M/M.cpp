#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T, R, S, B;
	int x, y, z;
	cin>>T;
	for(int t = 1; t <= T; ++t) {
		cout<<"Case #"<<t<<": ";
		cin>>R>>S>>B;
		for(int i = 0; i < B; ++i) {
			cin>>x>>y;
			v[x].push_back(y+1);
		}

		x = y = 0;

		for(int i = 0; i < R; ++i) {
			v[i].push_back(0);
			v[i].push_back(S+1);
			sort(v[i].begin(), v[i].end());

			for(int j = 1; j < v[i].size(); ++j) {
				z = v[i][j] - v[i][j-1] - 1;
				//cout<<v[i][j-1]+1<<" "<<v[i][j]-1<<" -> "<<z<<"\n";
				x += z / 2 + (z & 1);
				y += z / 3 + (z % 3 != 0);
			}

			v[i].clear();
		}

		cout<<x<<" "<<y<<"\n";
	}

	return 0;
}
