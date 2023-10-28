#include <bits/stdc++.h>
using namespace std;
int n, ans = 0, Min = 10001, Max = -10000, pos[100000];
bool flag = true;
pair<int, int> bug[10001];
int main(){
    freopen("BUG.INP", "r", stdin);
    freopen("BUG.OUT", "w", stdout);
    cin >> n;
    memset(pos, sizeof(pos), 0);
    for(int i = 1; i <= n; ++i){
        cin >> bug[i].first >> bug[i].second;
        bug[i].first += 10000; bug[i].second += 10000;
        if(bug[i].first < Min)
            Min = bug[i].first;
        if(bug[i].first > Max)
            Max = bug[i].first;
        pos[bug[i].first]++;
    }
    int sum = 0;
    for(int i = 1;i <= n; ++i)
        sum += bug[i].second;
    if(sum % n != 0)
        flag = false;
    for(int i = 1; i <= n; ++i)
        if(flag)
            ans += abs(sum/n - bug[i].second);
        else
            ans += abs(sum/n + 1 - bug[i].second);
    for(int i = 1; i <= n; ++i)
    if(pos[bug[i].first] > 1){
        if(Max == Min)
            ans += i - 1;
        else if(bug[i].first - Min > Max) ans += abs(Max - bug[i].first);
        else ans += abs(Min - bug[i].first);
    }
    cout << ans;
    return 0;
}
