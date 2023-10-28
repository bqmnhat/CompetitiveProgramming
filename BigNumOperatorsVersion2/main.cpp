#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int BASE_DIGITS = 9;
const int BASE = 1000000000;


struct BigInt {
    int sign;
    vector<int> a;

    BigInt(ll v = 0) {
        *this = v;
    }

    bool IsZero() {
        if (a.size() > 1)
            return false;
        return (a[0] == 0);
    }

    BigInt& operator=(ll v) {
        sign = 1;
        if (v < 0) {
            sign = -1;
            v = -v;
        }
        a.clear();
        while (v > 0LL) {
            a.push_back(v%BASE);
            v /= BASE;
        }
        return *this;
    }

    void trim() {
        while ((!a.empty()) && (!a.back()))
            a.pop_back();
        if (a.empty())
            sign = 1;
    }

    void read(const string& s) {
        a.clear();
        sign = 1;
        int pos = 0;
        while ((pos < s.length()) && ((s[pos] == '-') || (s[pos] == '+'))) {
            if (s[pos] == '-')
                sign = -sign;
            pos++;
        }
        for (int i=s.length()-1; i>=pos; i -= BASE_DIGITS) {
            int x = 0;
            for (int j=max(pos, i - BASE_DIGITS + 1); j<=i; j++)
                x = x*10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }

    friend istream& operator >> (istream& stream, BigInt &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }

    friend ostream& operator << (ostream& stream, BigInt &v) {
        if ((v.sign == -1) && (!v.IsZero()))
            stream << '-';
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i=v.a.size()-2; i>=0; i--)
            stream << setw(BASE_DIGITS) << setfill('0') << v.a[i];
        return stream;
    }

    ll operator%(ll v) { // Ignore the sign
        ll ans = 0, CurBase = 1;
        for (int i=a.size()-1; i >= 0; i--) {
            ans = (ans + ((a[i]%v)*(CurBase%v))%v)%v;
            CurBase = (CurBase*BASE)%v;
        }
        return ans;
    }

    void __internal_add(const BigInt& v) {
        if (a.size() < v.a.size()) {
            a.resize(v.a.size(), 0);
        }
        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
            if (i == (int) a.size()) a.push_back(0);

            a[i] += carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = a[i] >= BASE;
            if (carry) a[i] -= BASE;
        }
    }

    void operator*=(int v) {
        if (v < 0)
            sign = -sign, v = -v;
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size())
                a.push_back(0);
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / BASE);
            a[i] = (int) (cur % BASE);
        }
        trim();
    }

    BigInt operator*(int v) const {
        BigInt res = *this;
        res *= v;
        return res;
    }
};

int main()
{
    BigInt n;
    cin >> n;
    cout << n%1000;
    return 0;
}
