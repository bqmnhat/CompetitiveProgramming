#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MaxN 100
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <ll,  null_type,  less,  rb_tree_tag,  tree_order_statistics_node_update > // Thuc chat ordered_set la mot cai CTDL dang cay => nhanh vl =))) co O(logn)
#define ll long long
#define pll pair<long long, long long>
#define pb push_back
#define fi first
#define se second
#define ed '\n'
#define mp make_pair
ll t, x, k, posOne[MaxN+5], curBitOne, cntBit, cntBitOne;
ll Cycle[MaxN+5];
vector<ll> a;
//

void MakeCycle(ll curBitOne) {
    for (ll i=1; i<=MaxN; i++)
        Cycle[i] = (i - curBitOne)*(curBitOne-1LL) + 1LL;
}

ll CntBit(ll x) {
    ll cnt = 0, cntOne = 0;
    while (x > 0) {
        ll bit = (x&1LL);
        if (bit == 1) {
            posOne[cntOne] = cnt;
            cntOne++;
        }
        a.push_back(bit);
        cnt++;
        x >>= 1LL;
    }
    return cnt;
}

bool CheckMove(ll id) {
    return ((id+1 <= (a.size()-1LL)) && (a[id+1] == 0));
}

void sol()
{
    cntBit = CntBit(x);
    cntBitOne = __builtin_popcount(x);
    MakeCycle(cntBitOne);
    ll id = 0;
    int cnt = 0;
    while ((k > 0) && (posOne[0] != (cntBit - cntBitOne))) {
        if (CheckMove(posOne[id])) {
            a[posOne[id]] = 0;
            posOne[id]++;
            a[posOne[id]] = 1;
            k--;
//            cout << id << ' ' << posOne[id] << '\n';
        }
        else {
            id++;
            if (id >= a.size())
                id = 0;
        }
        if (cnt > 10000000)
            break;
        //cout << cntBit - cntBitOne << '\n';
    }
    if (k <= 0) {
        ll ans = 0;
        for (ll i=0; i<a.size(); i++)
            ans = ans + (1LL << (i))*a[i];
        if (ans > 1e15)
            cout << "-1";
        else
            cout << ans;
        return;
    }
    while (((1LL << (cntBit+1LL)) <= 1e15) && (k-Cycle[cntBit+1] > 0)) {
        cntBit++;
        k -= Cycle[cntBit];
    }
    if (k == 0) {
        a.clear();
        for (ll i=0; i<cntBit; i++)
            a.push_back(0);
        for (ll i=a.size()-1; i>=a.size()-cntBitOne; i++)
            a[i] = 1;
        ll ans = 0;
        for (ll i=0; i<a.size(); i++)
            ans = (ans + ((1LL) << (i))*a[i]);
        if (ans > 1e15)
            cout << "-1";
        else
            cout << ans;
        return;
    }
    if ((1LL << (cntBit+1LL)) > 1e15) {
        cout << "-1";
        return;
    }
    cntBit++;
//    cout << "cntBit: " << cntBit << '\n';
    k--;
    id = 0;
    a.clear();
    for (ll i=0; i<cntBit; i++)
        a.push_back(0);
    a[cntBit-1] = 1;
    posOne[cntBitOne-1] = cntBit-1;
    for (ll i=0; i<cntBitOne-1; i++) {
        a[i] = 1;
        posOne[i] = i;
    }
    while (k > 0) {
        if (CheckMove(posOne[id])) {
            a[posOne[id]] = 0;
            posOne[id]++;
            a[posOne[id]] = 1;
            k--;
        }
        id++;
    }
    ll ans = 0;
    for (ll i=0; i<a.size(); i++)
        ans = ans + (1LL << (i))*a[i];
    if (ans > 1e15)
        cout << "-1";
    else
        cout << ans;
}
//
signed main()
{
    //ios_base::sync_with_stdio(0);
    //cin.tie(0); cout.tie(0);
    cin >> t;
    while (t--) {
        cin >> x >> k;
        sol();
        cout << ed;
    }
    return 0;
}
