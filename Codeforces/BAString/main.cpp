#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n,k;
ll x;
string s;

void SolveTestCase() {
    ll cnta = 0, StartofB[2001], NumofB[2001], l = s.length(), lb = 0, AiD[2001], SumOfB[2001];
    for (int i=0; i<l; i++) {
        SumOfB[i] = 0;
        if(s[i] == 'a') {
            cnta++;
            AiD[cnta] = i;
        }
        else {
            if ((s[i-1] != '*') || (i == 0)) {
                lb++;
                StartofB[lb] = i;
                NumofB[lb] = 1;
            }
            else
                NumofB[lb]++;
            SumOfB[i] = 1;
        }
        if (i > 0)
            SumOfB[i] += SumOfB[i-1];
    }
    if (x <= cnta) {
        for (int i=1; i<=x; i++) {
            cout << 'a';
            cnta--;
        }
        cout << '\n';
        return;
    }
    x--;
    int cnt = 0;
    for (int i=0; i<l; i++) {
        if (s[i] == 'a')
            break;
        bool BreakOut = false;
        for (int j=1; j<=k; j++) {
            if (x - (cnt+1)*(1 + (SumOfB[l-1] - SumOfB[AiD[1]])*k) >= 0) {
                cout << 'b';
                cnt++;
                x = x - (cnt)*(1 + (SumOfB[l-1] - SumOfB[AiD[1]])*k);
            }
            else {
                BreakOut = true;
                break;
            }
        }
        if (BreakOut)
            break;
    }
    ll t = lb;
    bool Flag = false;
    while ((x-(k*NumofB[t]) > 0)&&(t >= 1)) {
        x = x-(k*NumofB[t]);
        t--;
        Flag = true;
    }
    int i=1;
    while ((AiD[i] < StartofB[t]) && (cnta > 0)) {
        cout << 'a';
        cnta--;
        i++;
    }
    if (x > 0)
        for (int j=1; j<=x; j++)
            cout << 'b';
    x = 0;
    if (Flag) {
        for (int j=t; j<=lb; j++) {
            if (cnta > 0) {
                cout << 'a';
                cnta--;
            }
            for (int d=1; d<=NumofB[j]; d++) {
                for (int r = 1; r<=k; r++)
                    cout << 'b';
            }
        }
    }
    while (cnta > 0) {
        cout << 'a';
        cnta--;
    }
    cout << '\n';
}

void Solve() {
    for (int i=1; i<=t; i++) {
        cin >> n >> k >> x >> s;
        SolveTestCase();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    Solve();
    return 0;
}
