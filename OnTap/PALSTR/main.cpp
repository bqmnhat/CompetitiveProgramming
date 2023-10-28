#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int tk[26], ans[1000001], l1 = 0, l2;

void ThongKe() {
    for (int i=0; i<s.length(); i++) {
        tk[s[i]-'A']++;
    }
}

void PrintAns() {
    for (int i=1; i<=s.length(); i++) {
        cout << char(ans[i]+'A');
    }
}

void Solve() {
    int oddid = -1;
    for (int i=0; i<=25; i++) {
        int x = tk[i];
        if (x%2 == 0) {
            while (x > 0) {
                l1++;
                l2--;
                ans[l1] = i;
                ans[l2] = i;
                x = x-2;
            }
        }
        else if (oddid == -1) {
            oddid = i;
        }
        else {
            cout << "NO SOLUTION";
            return;
        }
    }
    int x = tk[oddid];
    if (oddid != -1) {
        while (x > 1) {
            l1++;
            l2--;
            ans[l1] = oddid;
            ans[l2] = oddid;
            x = x-2;
        }
        l1++;
        ans[l1] = oddid;
    }
    PrintAns();
}

int main()
{
    freopen("PALSTR.INP", "r", stdin);
    freopen("PALSTR.OUT", "w", stdout);
    cin >> s;
    l2 = s.length()+1;
    ThongKe();
    Solve();
    return 0;
}
