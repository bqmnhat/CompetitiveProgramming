#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n, res, a[200005];
double x, y, u, v;
double t;
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> y >> u >> v;
		a[i] = (v - y) / (u - x);
		//cout << t <<" ";
		//cout << dd[t];
	}
	sort (a+1,a+n+1);
	for (int i = 1; i <= n; i++)
		if (a[i] != a[i+1]) res++;
	cout << res;
}
