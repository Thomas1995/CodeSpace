#include <bits/stdc++.h>
using namespace std;

vector< pair<int, string> > v;
vector<string> sol;

int solve1(int hX, int hY, int X, int Y) {
	int d = abs(hX - X);
	if(Y / 10 == hY / 10) {
		if(X != hX)
			d += min(hY % 10 + Y % 10, 20 - hY % 10 - Y % 10);
		else
			d += abs(hY - Y);
	}
	else {
		d += abs(hY - Y);
	}

	return d;
}

int solve2(int hX, int hY, int X, int Y) {
	int d = abs(hY - Y) + abs(hX - X);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int hX, hY, T, n;
	cin>>hX>>hY>>T>>n;

	int X, Y;
	string s;

	int d;

	while(n--) {
		cin>>s>>X>>Y;

		d = 0;

		if(hX % 10 == 0 && X % 10 == 0) {
			d = solve1(hX, hY, X, Y);
		}
		else {
			if(hX % 10 == 0 || X % 10 == 0) {
				d = solve2(hX, hY, X, Y);
			}
			else {
				d = solve1(hY, hX, Y, X);
			}
		}

		v.push_back(make_pair(d, s));
	}

	sort(v.begin(), v.end());

	for(auto it : v) {
		int t = it.first * 2;
		if(T >= t) {
			T -= t;
			sol.push_back(it.second);
		}
		else break;
	}

	sort(sol.begin(), sol.end());

	cout<<sol.size();
	for(auto it : sol) {
		cout<<" "<<it;
	}

	return 0;
}
