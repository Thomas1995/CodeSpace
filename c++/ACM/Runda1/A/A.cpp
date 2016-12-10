#include <bits/stdc++.h>
using namespace std;

vector<string> cuv;

char M[10][10];

int dx[] = {1,1,1,-1,-1,-1,0,0};
int dy[] = {1,-1,0,1,-1,0,1,-1};

bool found;

int pcts[] = {0,0,0,1,1,2,3,5,11};
int sum, nrcuv;
string word;

bool cmp(string a, string b) {
	if(a.size() != b.size()) {
		return a.size() > b.size();
	}
	return a < b;
}

void bkt(int nr, int k, int x, int y) {
	if(found)
		return;

	if(k+1 == cuv[nr].size()) {
		sum += pcts[cuv[nr].size()];
		++nrcuv;

		if(word == "")
			word = cuv[nr];

		found = true;
		return;
	}

	M[x][y] = 0;

	for(int dir=0;dir<8;++dir) {
		int x2 = x+dx[dir];
		int y2 = y+dy[dir];
		if(M[x2][y2] == cuv[nr][k+1]) {
			bkt(nr, k+1, x2, y2);
		}
	}

	M[x][y] = cuv[nr][k];
}

void solve(int x) {
	found = false;

	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			if(!found && M[i][j] == cuv[x][0])
				bkt(x, 0, i, j);
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	string tmp;

	int n;
	cin>>n;
	for(int i=1;i<=n;++i) {
		cin>>tmp;
		cuv.push_back(tmp);
	}

	sort(cuv.begin(), cuv.end(), cmp);

	int T;
	cin>>T;

	while(T--) {
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j)
				cin>>M[i][j];

		sum = 0;
		nrcuv = 0;
		word = "";

		for(int i=0;i<n;++i) {
			solve(i);
		}

		cout<<sum<<" "<<word<<" "<<nrcuv<<"\n";
	}

	return 0;
}
