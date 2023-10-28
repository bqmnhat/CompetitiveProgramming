#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string a,b,s1,s2;
    cout << "Nhap so lon I: " << endl;
    cin >> a;
    cout << "Nhap so lon II: " << endl;
    cin >> b;
    long long r[a.length() + b.length() + 1] = {};
    long long x,y;
    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            s1 = a.substr(i-1,1);
            s2 = b.substr(j-1,1);
            istringstream(s1) >> x;
            istringstream(s2) >> y;
            r[i+j] = r[i+j] + (x*y);
        }
    }
    for (int i = a.length() + b.length(); i>=2; i--) {
        r[i-1] = r[i-1] + (r[i]/10);
        r[i] = r[i]%10;
    }
    for (int i = 2; i<=a.length() + b.length(); i++) {
        cout << r[i];
    }
    return 0;
}
