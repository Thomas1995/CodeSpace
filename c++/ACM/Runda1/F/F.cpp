#include <bits/stdc++.h>
using namespace std;

int M[20][20];
pair<int, int> dame[9];
bool elim[9];
int n;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,1,-1};

int mx;

int cnt;

void bkt(int k) {
	mx = max(mx, k-1);

	for(int i=1;i<=n;++i) {
		if(elim[i])
			continue;

		for(int j=0;j<4;++j) {
			int x0 = dame[i].first;
			int y0 = dame[i].second;
			int x = x0 + dx[j];
			int y = y0 + dy[j];
			int x2 = x + dx[j];
			int y2 = y + dy[j];

			if(M[x][y] >= 1 && M[x2][y2] == 0) {
				int e = M[x][y];

				M[x0][y0] = 0;
				M[x][y] = 0;
				M[x2][y2] = i;

				//if(++cnt <= 300) cout<<k<<") Piesa "<<i<<" a sarit pe pozitia "<<x2<<" "<<y2<<" peste piesa "<<e<<endl;

				dame[i].first = x2;
				dame[i].second = y2;

				elim[e] = true;

				bkt(k+1);

				elim[e] = false;

				dame[i].first = x0;
				dame[i].second = y0;
				M[x2][y2] = 0;
				M[x][y] = e;
				M[x0][y0] = i;
			}
		}
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
	#endif // ONLINE_JUDGE
	cin.sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin>>T;

	string tmp;

	for(int i=0;i<=10;++i)
		M[0][i] = M[6][i] = -1;

	for(int i=0;i<=6;++i)
		M[i][0] = M[i][10] = -1;

	while(T--) {
		n = 0;

		for(int i=1;i<=5;++i) {
			cin>>tmp;

			for(int j=0;j<tmp.size();++j) {
				if(tmp[j] == '.')
					M[i][j+1] = 0;
				else
					if(tmp[j] == 'o') {
						dame[++n] = make_pair(i,j+1);
						M[i][j+1] = n;
					}
					else
						M[i][j+1] = -1;
			}
		}

		/*for(int i=0;i<=6;++i) {
			for(int j=0;j<=10;++j) {
				cout<<M[i][j]<<"\t";
			}
			cout<<"\n";
		}*/

		mx = 0;

		bkt(1);

		cout<<n-mx<<" "<<mx<<"\n";
	}

	return 0;
}
