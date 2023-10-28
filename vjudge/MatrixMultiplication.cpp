#include <bits/stdc++.h>
#define fo(i,m,n) for(int i = m; i <= n; i++)
#define fod(i,m,n) for(int i = m; i >= n; i--)
#define fov(i,x) for(auto &i : x)
using namespace std;
using i64 = int64_t;
using _ii = pair<int,int>;
vector <vector<i64>> Mul(vector<vector<i64>> a, vector<vector<i64>> b, i64 m)
{
	vector <vector<i64>> ans(2);
	ans[0].resize(2);
	ans[1].resize(2);
	for(int i = 0; i < 2; ++i)
	{
		for(int j = 0; j < 2; ++j)
		{
			for(int k = 0; k < 2; ++k)
			{
				ans[i][j] = ans[i][j] + a[i][k]*b[k][j];
				ans[i][j] %= m;
			}
		}
	}
	return ans;
}
vector <vector<i64>> Power(vector <vector<i64>> a, i64 n, i64 m)
{
	if(n == 0)
	{
		vector <vector<i64>> b(2);
		b[0].resize(2);
		b[1].resize(2);
		b[0][0] = b[1][1] = 1;
		return b;
	}
	if(n == 1) return a;
	vector <vector<i64>> b = Power(a,n/2,m);
	b = Mul(b,b,m);
	if(n&1) b = Mul(b,a,m);
	return b;
}
i64 Fibo(i64 n, i64 m)
{
	if(n == 0) return 0 % m;
	if(n == 1) return 1 % m;
	vector <vector <i64>> a(2);
	a[0].resize(2);
	a[1].resize(2);
	a[0][0] = a[0][1] = a[1][0] = 1;
	a = Power(a,n-1,m);
	return a[0][0];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	i64 n,m;
	while(cin >> n >> m)
	{
		m = 1 << m;
		cout << Fibo(n,m) << '\n';
	}
}