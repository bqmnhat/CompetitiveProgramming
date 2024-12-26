#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll intMax = (1LL << 31);

bool checkIfDigit(char x) {
    return (('0' <= x) && (x <= '9'));
}

bool checkWithinIntRange(ll current, ll addingDigit, ll sign) {
    if (sign < 0)
        return (current*10 + addingDigit <= intMax);
    else
        return (current*10 + addingDigit <= intMax - 1LL);
}

int myAtoi(string s) {
    ll ans = 0, sign;
    int i = 0, l = s.length();
    while ((i < l) && (s[i] == ' '))
        i++;
    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        sign = 1;
        i++;
    } else
        sign = 1;
    while ((i < l) && (s[i] == '0'))
        i++;

    for (;i < l; i++) {
        if (checkIfDigit(s[i]))  {
            ll dig = s[i] - '0';
            if (checkWithinIntRange(ans, dig, sign))
                ans = ans*10 + dig;
            else {
                if (sign < 0)
                    return (-1LL)*intMax;
                else
                    return intMax-1LL;
            }
        } else
            return ans*sign;
    }
    return ans*sign;
    //2147483648
}

int main()
{
    cout << myAtoi("-91283472332");
    return 0;
}
