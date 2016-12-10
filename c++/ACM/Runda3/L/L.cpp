#include <bits/stdc++.h>
using namespace std;
const int N=1111;
int a[N][N];
int  read(){
    int x=0;
    char c=' ';
    while(!((c>='0'&&c<='9') || c=='?')) c = getchar();
    if (c=='?') return  0;
    while(c>='0'&&c<='9'){
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin>>T;
    for(int t=1;t<=T;t++)
    {
        cout<<"Case #"<<t<<": ";
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                a[i][j] = read();

        int i1,j1,i2,j2, f1=0,f2=0;
        int i,j;
        int cnt=0;
        for(i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j])
        {
            cnt++;
            if (cnt==1) i1=i,j1=j;
            if (cnt==2) i2=i,j2=j;
        }
        if (cnt == 0)
        {
            cout<<"Yes\n";
        }
        if (cnt==1)
        {
            int f=0;
            int x =a[i1][j1];
            for(int i=i1;i<=1e5 && !f;i++) {
                if (x % i == 0) f = i;
            }
            if (x / f >= j1) cout << "Yes\n";
            else cout << "No\n";
        }
        double si=0;
        if (cnt>1)
        {
            int p=j2-j1;
            int q=i2-i1;
            int i=i1;
            long long x = a[i1][j1], y=a[i2][j2];

            long long A = p, B = x - y + 1LL*p*q, C = 1LL*q * x;

            if(p == 0) {
                double sj = 1.0*(y - x) / q;
                si = x / sj;
            } else if (q == 0){
                si = 1.0* (y - x) / p;
            } else
            if (B == 0) {
                if(p!=0) si = sqrt(1.0*C/A);
            } else if (p==0){
                si = 1.0*C/B;
            }else if (q==0){
                si = 1.0*B/A;
            }else {
                double dis = B*B - 4*A*C;
                if (dis >= 0){
                    dis = sqrt(dis);
                    dis = (-B + dis)/(2.0*A);
                    if(dis > 0) si = dis;
                }
            }

            if (si == 0) {
                cout << "No\n";
                continue;
            }
            int soli = round(si);
            int solj = x / soli;
         //  cout << "xxx " << soli << " " << solj << endl;
            int ok = 1;
            if(i1 > soli || j1 > solj) ok = 0;
            if (ok)
            {
                for(int i=soli-i1+1,ci=1;ci<=n;i++,ci++)
                    for(int j=solj-j1+1,cj=1;cj<=m;cj++<j++)
                        if (a[ci][cj] && a[ci][cj]!=1LL*i*j) ok = 0;
            }
            int ok1=1;
            swap(soli,solj);
            if(i1 > soli || j1 > solj) ok1 = 0;
            if (ok1)
            {
                for(int i=soli-i1+1,ci=1;ci<=n;i++,ci++)
                    for(int j=solj-j1+1,cj=1;cj<=m;cj++<j++)
                        if (a[ci][cj] && a[ci][cj]!=1LL*i*j) ok1 = 0;
            }
            ok |= ok1;
            if (ok) cout << "Yes\n";
            else cout << "No\n";

        }
    }
}
