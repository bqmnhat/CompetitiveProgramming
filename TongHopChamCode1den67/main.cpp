#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void main1()
{
    cout << "Hello World @ Code Online";
}

void main2()
{
    long long a,b;
    cin >> a >> b;
    cout << a+b;
}

void main3()
{
    ll a,b;
    cin >> a >> b;
    cout << a + b << " " << a - b << '\n';
    cout << a*b << " " << setprecision(2) << fixed << double(double(a)/double(b));
}

void Solve4() {
    int ans = a;
    for (int i=2; i<=3; i++) {
        ans = ans*a;
        cout << ans << " ";
    }
    ans = ans*a;
    cout << ans;
}

void main4()
{
    int a;
    cin >> a;
    Solve4();
}

void main5()
{
    ll a,b;
    cin >> a >> b;
    cout << a+b;
}

ll CalP6(ll a, ll b) {
    ll ans = (a+b)*2;
    return ans;
}

ll CalA6(ll a, ll b) {
    ll ans = a*b;
    return ans;
}

void main6()
{
    ll a,b;
    cin >> a >> b;
    cout << CalP6(a,b) << " " << CalA6(a,b);
}

void main7()
{
    double r, c = 4.0/3.0, pi = 3.14;
    cin >> r;
    cout << fixed << setprecision(2) << 4*pi*(r*r) << " " << c*pi*(r*r*r);
}


void Solve8() {
    while (d.length() < 2)
        d = "0" + d;
    while (m.length() < 2)
        m = "0" + m;
    while (y.length() < 4)
        y = "0" + y;
    cout << d << "/" << m << "/" << y;
}

void main8()
{
    string d,m,y;
    cin >> d >> m >> y;
    Solve8();
}

void Solve9(long long a) {
    long long h,m,s;
    h = a/3600;
    a = a%3600;
    m = a/60;
    a = a%60;
    s = a;
    if (h < 10)
        cout << "0";
    cout << h << ":";
    if (m < 10)
        cout << "0";
    cout << m << ":";
    if (s < 10)
        cout << "0";
    cout << s;
}

void main9()
{
    long long a;
    cin >> a;
    Solve9(a);
}

void main10()
{
    ll a,b;
    cin >> a >> b;
    if (a > b)
        cout << a;
    else
        cout << b;
}

ll Max311(ll a[4]) {
    ll ans = 0;
    for (int i=1; i<=3; i++) {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

void main11()
{
    ll a[4];
    cin >> a[1] >> a[2] >> a[3];
    cout << Max311(a);
}

ll Max412(ll a[5]) {
    ll ans = 0;
    for (int i=1; i<=4; i++) {
        if (a[i] > ans)
            ans = a[i];
    }
    return ans;
}

void main12()
{
    ll a[5];
    cin >> a[1] >> a[2] >> a[3] >> a[4];
    cout << Max412(a);
}

void Solve13(ll a, ll b, ll c) {
    if (a == b) {
        if (c == b)
            cout << "VSN";
        else
            cout << "VN";
        return;
    }
    double delta = (b*b) - 4*(a*c);
    if (delta < 0) {
        cout << "VN";
        return;
    }
    if (delta == 0) {
        cout << "x = 2.00";
        return;
    }
    double x1 = double(double(-b) + sqrt(delta))/double(2*double(a)), x2 = double(double(-b) - sqrt(delta))/double(2*double(a));
    cout << fixed << setprecision(2) << x1 << " " <<  x2;
}

void main13()
{
    ll a,b,c;
    cin >> a >> b >> c;
    Solve(a,b,c);
}

bool IsTri14(ll a, ll b, ll c) {
    if ((a + b > c) && (b + c > a) && (a + c > b))
        return true;
    else
        return false;
}

void Solve14(ll a, ll b, ll c) {
    if (IsTri(a,b,c)) {
        ll chuvi = a + b + c;
        double p = double(chuvi)/2.0;
        double S = sqrt(p*(p - double(a))*(p - double(b))*(p - double(c)));
        cout << fixed << setprecision(2) << double(chuvi) << " " << S;
    }
    else
        cout << "NO";
}

void main14()
{
    ll a, b, c;
    cin >> a >> b >> c;
    Solve(a,b,c);
}

void main15()
{
    ll t;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    cin >> t;
     if ((t > 12) || (t < 1))
        cout << "NOT FOUND";
     else
        cout << a[t];
}

ll CallCost16(ll a) {
    ll ans = 25000;
    ans = ans + min(a,ll(50))*600;
    a = max(a - 50, ll(0));
    ans = ans + min(a,ll(150))*400;
    a = max(a - 150, ll(0));
    ans = ans + a*200;
    return ans;
}

void main16()
{
    ll a;
    cin >> a;
    cout << "So tien = " << CallCost16(a);
}

void main17()
{
    int n;
    cin >> n;
    for (int i=1; i<=n; i++) {
        if (i == n)
            cout << i;
        else
            cout << i << " ";
    }
}

ll Sum18(int n) {
    ll ans = 0;
    for (int i=1; i<=n; i++) {
        ans += i;
    }
    return ans;
}

void main18()
{
    int n;
    cin >> n;
    cout << Sum18(n);
}

void main19()
{
    int n;
    string s;
    cin >> n;
    cin.get();
    getline(cin, s, '\n');
    for (int i=1; i<n; i++)
        cout << s << '\n';
    cout << s;
}

ll GiaiThua20(int n) {
    ll ans = 1;
    if (n == 0)
        return 0;
    for (int i=2; i<=n; i++)
        ans = ans*i;
    return ans;
}

void main20()
{
    int n;
    cin >> n;
    cout << GiaiThua20(n);
}

double SumFrac21() {
    double ans = 0;
    for (int i=1; i<=n; i++)
        ans = ans + (1.0/double(i));
    return ans;
}

void main21()
{
    int n;
    cin >> n;
    cout << fixed << setprecision(6) << SumFrac();
}

void DrawSolidRec22(int n, int m) {
    for (int i=1; i<n; i++) {
        for (int j=1; j<=m; j++)
            cout << "*";
        cout << '\n';
    }
    for (int j=1; j<=m; j++)
        cout << "*";
}

void main22()
{
    int n,m;
    cin >> n >> m;
    DrawSolidRec22(n,m);
    return 0;
}

void DrawTri23(int x) {
    for (int i=x; i>1; i--) {
        for (int j=1; j<=i; j++)
            cout << "*";
        cout << '\n';
    }
    cout << "*";
}

void main23()
{
    int x;
    cin >> x;
    DrawTri23(x);
}

void DrawHollowRec24(int n, int m) {
    for (int i=1; i<=m; i++)
        cout << "*";
    cout << '\n';
    for (int i=2; i<=n-1; i++) {
        cout << "*";
        for (int j=1; j<=m-2; j++)
            cout << " ";
        cout << "*" << '\n';
    }
    for (int i=1; i<=m; i++)
        cout << "*";
}

void main24()
{
    int n,m;
    cin >> n >> m;
    DrawHollowRec24(n,m);
}

bool IsPrime25(ll n) {
    ll m = sqrt(n);
    if (n <= 1)
        return false;
    if (n == 2)
        return true;
    for (int i=2; i<=m; i++)
        if (n % i == 0)
            return false;
    return true;
}

void main25()
{
    ll n;
    cin >> n;
    if (IsPrime25(n))
        cout << "TRUE";
    else
        cout << "FALSE";
}

bool IsSquare26(ll n) {
    return ((sqrt(n) * sqrt(n)) == n);
}

bool IsPerfect26(ll n)  {
    if (n < 0)
        return false;
    if (n == 0)
        return true;
    ll sumdiv = 1, m = sqrt(n);
    for (int i=2; i<=m; i++) {
        if (n%i == 0) {
            sumdiv = sumdiv + i + (n/i);
        }
        if (sumdiv > n)
            return false;
    }
    if (IsSquare26(n))
        sumdiv = sumdiv - sqrt(n);
    if (sumdiv == n)
        return true;
    else
        return false;
}

void main26()
{
    ll n;
    cin >> n;
    if (IsPerfect26(n))
        cout << "TRUE";
    else
        cout << "FALSE";
}

long long FibN27(long long n) {
    long long f1 = 1, f2 = 1, f3;
    if (n <= 2)
        return 1;
    for (int i=3; i<=n; i++) {
        f3 = f1 + f2;
        f1 = f2;
        f2 = f3;
    }
    return f3;
}

void main27()
{
    int n;
    cin >> n;
    cout << FibN27(n);
}

long long Reverse28(long long n) {
    long long ans = 0;
    while (n > 0) {
        ans = ans*10 + (n%10);
        n = n/10;
    }
    return ans;
}

void main28()
{
    long long n;
    cin >> n;
    cout << Reverse28(n);
}

long long MaxDig29(long long n) {
    long long ans = 0;
    while (n > 0) {
        if ((n%10) > ans)
            ans = n%10;
        n = n/10;
    }
    return ans;
}

void main29()
{
    long long n;
    cin >> n;
    cout << MaxDig29(n);
}

long long Reverse30(long long n) {
    long long ans = 0;
    while (n > 0) {
        ans = ans*10 + (n%10);
        n = n/10;
    }
    return ans;
}

long long SumReverse30(long long n) {
    long long ans = n + Reverse30(n);
    return ans;
}

void main30()
{
    long long n;
    cin >> n;
    cout << SumReverse30(n);
}

void Factorise31(ll n) {
    ll m = sqrt(n);
    int i = 2;
    bool exist = false;
    while ((i <= m) && (n > 1)) {
        while (n%i == 0) {
            if (!exist)
                cout << i;
            else
                cout << "*" << i;
            exist = true;
            n = n/i;
        }
        i++;
    }
    if (n > 1)
        if (!exist)
            cout << n;
        else
            cout << "*" << n;
}

void main31()
{
    ll n;
    cin >> n;
    Factorise(n);
}

ll GCD(ll a, ll b) {
    ll tmp;
    while (b != 0) {
        tmp = b;
        b = a%b;
        a = tmp;
    }
    return a;
}

ll LCM(ll a ,ll b) {
    ll ans = (a*b)/GCD(a,b);
    return ans;
}

int main()
{
    ll a, b;
    cin >> a >> b;
    cout << GCD(a,b) << " " << LCM(a, b);
}

Bài 33:

Đề bài: Cho một dãy số nguyên, mỗi số cách nhau bởi một dấu cách. Kết thúc dãy là số 0. Tìm số lớn nhất, nhỏ nhất trong dãy và số lượng số trong dãy (không tính số 0 cuối dãy).
Đầu vào: Một dãy các số cách nhau bởi dấu cách. Số cuối cùng là số 0. Đầu ra: Một dòng gồm 3 số cách nhau bởi dấu cách lần lượt là số lớn nhất, nhỏ nhất trong dãy và số lượng số của dãy.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll Max = 0, Min = 1e18, cnt = 0;

void ReadData(ll &Max, ll &Min, ll &cnt) {
    ll ai;
    while (cin >> ai) {
        if (ai == 0)
            break;
        if (ai > Max)
            Max = ai;
        if (ai < Min)
            Min = ai;
        cnt++;
    }
}

int main()
{
    ReadData(Max, Min, cnt);
    cout << Max << " " << Min << " " << cnt;
    return 0;
}

Bài 34:

Đề bài: Nhập vào một số nguyên k, in ra danh sách các số nguyên tố nhỏ hơn k.
Đầu vào: Một số nguyên k.
Đầu ra: Một dòng gồm các số nguyên tố nhỏ hơn k, mỗi số cách nhau bởi đấu cách. Nếu không có số nguyên tố nào nhỏ hơn k thì in ra “NOT FOUND”.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(n);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=n; j++)
                Sieve[i*j] = true;
        }
    }
}

void Solve() {
    bool exist = false;
    for (int i=2; i<n; i++) {
        if (!Sieve[i]) {
            if (!exist) {
                cout << i;
                exist = true;
            }
            else
                cout << " " << i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}

Bài 35:

Đề bài: Nhập vào một số nguyên k, Tính và in ra trung bình cộng của các số nguyên tố nhỏ hơn hoặc bằng k.
Đầu vào: Một số nguyên k.
Đầu ra: Một số duy nhất là trung bình cộng các số nguyên tố nhỏ hơn hoặc bằng k. Kết quả làm tròn tới 3 chữ số thập phân.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(n);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=n; j++)
                Sieve[i*j] = true;
        }
    }
}

double Solution() {
    double ans = 0;
    int cnt = 0;
    for (long long i=2; i<=n; i++) {
        if (!Sieve[i]) {
            ans = ans + i;
            cnt++;
        }
    }
    ans = ans/double(cnt);
    return ans;
}

int main()
{
    cin >> n;
    MakeSieve();
    cout << setprecision(3) << fixed << Solution();
    return 0;
}

Bài 36:

Đề bài: Nhập vào một số dương nguyên k, in ra danh sách k số nguyên tố đầu tiên.
Đầu vào: Một số nguyên dương k.
Đầu ra: Một dòng gồm k số nguyên tố đầu tiên. Các số cách nhau bởi dấu cách.

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int n;
bool Sieve[5000001];

void MakeSieve() {
    int m = sqrt(5000001);
    Sieve[1] = Sieve[0] = true;
    for (int i=2; i<=m; i++) {
        if (!Sieve[i]) {
            for (int j=i; i*j<=5000001; j++)
                Sieve[i*j] = true;
        }
    }
}

void Solve() {
    int cnt = 0, i = 0;
    bool exist = false;
    while (cnt < n) {
        i++;
        if (!Sieve[i]) {
            cnt++;
            if (!exist) {
                cout << i;
                exist = true;
            }
            else
                cout << " " << i;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    MakeSieve();
    Solve();
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
