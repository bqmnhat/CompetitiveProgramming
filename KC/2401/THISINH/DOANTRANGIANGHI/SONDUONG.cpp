#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    freopen("SONDUONG.INP","r",stdin);
    freopen("SONDUONG.OUT","w", stdout);
    long int N, L, R;
    cin >> N >> L >> R;
    int ans = 0;
    int sizes = L + R;
    vector <int> ar(sizes, 0);
    for(int i = 0; i < N; i++)
    {
        int x, y;
        cin >> x >> y;
        for(int j = x - 1; j < y - 1; j++)
            ar[j]++;
    }
    for(int h = 0; h < L + R; h++)
    {
        if(ar[h] == 2)
        {
            ans++;
        }
    }
    cout << ans;

    return 0;

}
