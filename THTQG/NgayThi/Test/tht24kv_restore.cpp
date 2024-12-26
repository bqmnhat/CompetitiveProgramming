#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MaxN 100
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <int,  null_type,  less,  rb_tree_tag,  tree_order_statistics_node_update > // Thuc chat ordered_set la mot cai CTDL dang cay => nhanh vl =))) co O(logn)
#define ll long long
#define pll pair<long long, long long>
#define pb push_back
#define fi first
#define se second
#define ed '\n'
#define mp make_pair
int m, n, a[MaxN+5], b[MaxN+5], Mat[MaxN+5][MaxN+5], posx[MaxN+5], posy[MaxN+5], cnt = 0, cntCol[MaxN+5], cntRow[MaxN+5];
//
void read_data()
{
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> Mat[i][j];
            if (Mat[i][j] == -1) {
                cnt++;
                posx[cnt-1] = i;
                posy[cnt-1] = j;
            }
        }
    }
    for (int i=1; i<=n; i++)
        cin >> a[i];
    for (int j=1; j<=m; j++)
        cin >> b[j];
}

bool Check() {
    memset(cntCol, 0, sizeof(cntCol));
    memset(cntRow, 0, sizeof(cntRow));
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cntCol[j] += Mat[i][j];
            cntRow[i] += Mat[i][j];
        }
    }
    for (int i=1; i<=n; i++)
        if (cntRow[i] != a[i])
            return false;
    for (int j=1; j<=m; j++)
        if (cntCol[j] != b[j])
            return false;
    return true;
}
//
void sol()
{
    for (int mask = 0; mask < (1 << (cnt)); mask++) {
        int CurMask = mask;
        int cnt = -1;
        while (CurMask > 0) {
            cnt++;
            int bit = (CurMask & 1);
            Mat[posx[cnt]][posy[cnt]] = bit;
            CurMask >>= 1;
        }
        if (Check()) {
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=m; j++) {
                    cout << Mat[i][j] << " ";
                }
                cout << ed;
            }
            return;
        }
    }
}
//
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    read_data();
    sol();
    return 0;
}
