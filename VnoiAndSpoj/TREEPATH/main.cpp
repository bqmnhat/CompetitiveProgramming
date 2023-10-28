#include <iostream>
#include <bits/stdc++.h>
#define MaxN 2000
using namespace std;
typedef long long ll;
typedef vector<int> BigNum;
const ll base = 1e9;
string s;
BigNum SumOfNodes = {1}, Ans = {0}, Branches = {1}, pow4[MaxN+5];
int BranchBreaks[MaxN+5];

BigNum operator + (BigNum a, BigNum b) {
	BigNum c;
	int v = 0;
	for (int i=0; i<max(a.size(), b.size()); i++) {
		if (i < a.size()) v += a[i];
		if (i < b.size()) v += b[i];
		c.push_back(v%base);
		v/=base;
	}
	if (v) c.push_back(v);
	return c;
}

BigNum operator * (BigNum a, int b) {
	BigNum c;
	ll v = 0;
	for (int i=0; i<a.size(); i++) {
		v += a[i] * (ll) b;
		c.push_back(v%base);
		v/=base;
	}
	if (v) c.push_back(v);
	return c;
}

/*BigNum pow10(BigNum a, int n) { //ham mu 10
    BigNum ans(a.size()+n, 0);
    for (int i = 0, j = n; i < a.size(); ++i, ++j)
        ans[j] = a[i];
    return ans;
}

BigNum operator * (BigNum a, BigNum b) // Multiplication of 2 BigNums
{
    BigNum ans;
    for (int i = 0; i < b.size(); ++i) {
        BigNum tmp = a*b[i]; // Use Multiplication operator of 1 BigNum and 1 integer
        tmp = pow10(tmp, i);
        ans = ans + tmp;
    }
    return ans;
}*/

void Set(BigNum &a) {
	while (a.size() > 1 && a.back() == 0) a.pop_back();
}

BigNum operator * (BigNum a, BigNum b) {
	BigNum c(a.size() + b.size(), 0);
	for (int i=0; i<a.size(); i++) {
		ll v = 0;
		for (int j = 0; j < b.size(); j++) {
			v += (ll) c[i+j] + (ll) a[i] * b[j];
			c[i+j] = v % base;
			v /= base;
		}
		if (v) c[i+b.size()] = v;
	}
	Set(c);
	return c;
}

void FindBranchBreaks() {
    int l = s.length();
    for (int i=l-1; i>=0; i--)
        BranchBreaks[i] = BranchBreaks[i+1] + (s[i] == '*');
}

void FindPow4() {
    pow4[0] = {1};
    for (int i=1; i<=BranchBreaks[0]; i++)
        pow4[i] = pow4[i-1]*4;
}

void PrintBigNum(BigNum a) {
    printf("%d", a.back());
    for (int i=a.size()-2; i>=0; i--)
        printf("%09d", a[i]);
}

void Solve() {
    FindBranchBreaks();
    FindPow4();
    int l = s.length();
    for (int i=0; i<l; i++) {
        if (s[i] == '*') {
            BigNum tmp = (SumOfNodes*9)+(Branches*3);
            Ans = Ans + (tmp*pow4[BranchBreaks[i] - 1]);
            SumOfNodes = SumOfNodes + tmp;
            Branches = Branches*4;
        }
        else {
            if (s[i] == 'L')
                SumOfNodes = SumOfNodes*3;
            else if (s[i] == 'C')
                SumOfNodes = SumOfNodes*3 + Branches;
            else if (s[i] == 'R')
                SumOfNodes = SumOfNodes*3 + Branches*2;
            if (s[i] != 'S')
                Ans = Ans + (SumOfNodes*pow4[BranchBreaks[i]]);
        }
    }
    Ans = Ans + Branches;
    PrintBigNum(Ans);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> s;
    Solve();
    return 0;
}

