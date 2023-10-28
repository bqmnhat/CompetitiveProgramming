#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string s;
int f[8];

int Solution() {
    for (int i=1; i <=7; i++) {
        f[i] = f[i-1];
        if (i < 2) continue;
        if (s[i] == s[i-1])
            f[i] = max(f[i], f[i-2] + 2);
        if (i < 3) continue;
        if ((s[i] == s[i-1]) && (s[i-1] == s[i-2]))
            f[i] = max(f[i], max(f[i-2], f[i-3] + 3));
        else if ((s[i] == s[i-2]) || (s[i-1] == s[i-2]) || (s[i] == s[i-1]))
            f[i] = max(f[i], max(f[i-2], f[i-3] + 2));
        if (i < 4) continue;
        if ((s[i] == s[i-1]) && (s[i-1] == s[i-2]) && (s[i-2] == s[i-3]))
            f[i] = max(f[i], max(f[i-2], max(f[i-3], f[i-4] + 5)));
        else if ((s[i] == s[i-3]) && (s[i-1] == s[i-2]))
            f[i] = max(f[i], max(f[i-2], max(f[i-3], f[i-4] + 4)));
        else if (((s[i] == s[i-1]) && (s[i-2] == s[i-3])) || ((s[i] == s[i-2]) && (s[i-1] == s[i-3])))
            f[i] = max(f[i], max(f[i-2], max(f[i-3], f[i-4] + 3)));
        else if (((s[i] == s[i-1]) && (s[i-1] == s[i-2])) || ((s[i] == s[i-1]) && (s[i-1] == s[i-3])) || ((s[i] == s[i-2]) && (s[i-2] == s[i-3])) || ((s[i-1] == s[i-2]) && (s[i-2] == s[i-3])))
            f[i] = max(f[i], max(f[i-2], max(f[i-3], f[i-4] + 3)));
        else if (((s[i] == s[i-2]) && (s[i-1] != s[i-3])) || ((s[i] != s[i-2]) && (s[i-1] == s[i-3])))
            f[i] = max(f[i], max(f[i-2], max(f[i-3], f[i-4] + 2)));
    }
    return f[7];
}

int main()
{
    cin >> s;
    s = " " + s;
    cout << Solution();
    return 0;
}
