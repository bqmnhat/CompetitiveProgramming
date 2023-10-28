#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int tc, tk[27];
string s, numbers[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}, t = "ZWUXGHFOVI", ordered[10] = {"0", "2", "4", "6", "8", "3", "5", "1", "7", "9"};

void MakeTK() {
    int l = s.length();
    for (int i=0; i<=26; i++)
        tk[i] = 0;
    for (int i=0; i<l; i++)
        tk[s[i] - 'A']++;
}

void SolveTestCases() {
    string res;
    for (int i=0; i<=9; i++) {
        while (tk[t[i] - 'A']) {
            res = res + ordered[i][0];
            int num = (int)ordered[i][0] - (int)'0';
            for (int i=0; i<numbers[num].length(); i++)
                tk[numbers[num][i] - 'A']--;
        }
    }
    sort(res.begin(), res.end());
    cout << res;
}

void Solve() {
    for (int i=1; i<=tc; i++) {
        cin >> s;
        cout << "Case #" << i << ": ";
        MakeTK();
        SolveTestCases();
        cout << '\n';
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> tc;
    Solve();
    return 0;
}
