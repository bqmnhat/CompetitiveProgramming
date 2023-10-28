#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    float sum[7];
    int n;
    for (int i = 1; i<=6; i++){
        sum[i] = 0;
    }
    long long fac = 1;
    cin >> n;
    for (int i = 1; i<=n; i++){
        sum[1] = sum[1] + sqrt(i);
        sum[2] = sum[2] + float(float(i-1)/float(i));
        if (i%2 != 0){
            fac = fac * i;
            sum[3] = sum[3] + float(1.0/fac);
        }
        else {
            fac = fac * i;
            sum[3] = sum[3] - float(1.0/fac);
        }
        if (i%2 == n%2){
            sum[5] = sum[5] + i;
        }
    }
    sum[4] = sqrt(2);
    sum[6] = n;
    for (int i = n-1; i>=1; i--){
        sum[4] = sqrt(2+sum[4]);
        sum[6] = i + float(1.0/sum[6]);
    }
    for (int i = 1; i<=4; i++){
        cout << setprecision(3) << fixed << sum[i] << endl;
    }
    cout << int(sum[5]) << endl;
    cout << setprecision(3) << fixed << sum[6] << endl;
    cout << 3/2;
    return 0;
}
