#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n,t;
bool dd[200001];
string s1,s2;

void Init() {
    for (int i=1; i<=n; i++) {
        dd[i] = false;
    }
}

int Solution() {
    int ans = 0;
    for (int i=1; i<=n; i++) {
        if (s1[i] == '1') {
            if ((s2[i] == '0') && (!dd[i])) {
                dd[i] = true;
                ans++;
            }
            else if ((s2[i-1] == '1') && (!dd[i-1])) {
                dd[i-1] = true;
                ans++;
            }
            else if ((s2[i+1] == '1') && (!dd[i+1])) {
                dd[i+1] = true;
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    cin >> t;
    for (int i=1; i<=t; i++) {
        cin >> n >> s2 >> s1;
        s2 = "0" + s2;
        s2 = s2 + "0";
        s1 = "0" + s1;
        s1 = s1 + "0";
        Init();
        cout << Solution() << '\n';
    }
    return 0;
}
