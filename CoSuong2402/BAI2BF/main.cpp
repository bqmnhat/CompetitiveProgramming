#include <bits/stdc++.h>
#define MaxN 5000
using namespace std;
int arr[MaxN + 1], n;

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> arr[i];
}

int findNumberOfTriangles(int n)
{
	ll cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++)
				if ((arr[i] + arr[j] > arr[k]) && (arr[i] + arr[k] > arr[j]) && (arr[k] + arr[j] > arr[i]))
					cnt++;
		}
	}
	return cnt;
}

int main()
{

	ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    cin >> n;
    ReadData();
    cout << findNumberOfTriangles()
	return 0;
}
