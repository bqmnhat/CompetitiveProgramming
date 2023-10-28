#include <bits/stdc++.h>
#define fo(i,o) for(int i = 0; i < o; i++)

using namespace std;

int n,x1,ya,x2,y2,spe,ans;
vector<int>_x1;
vector<int>_x2;
vector<int>_ya;
vector<int>_y2;
vector<int>a;
vector<double>val;

int input()
{
    cin >> n;
    fo(i,n)
    {
        cin >> x1 >> ya >> x2 >> y2;
        _x1.push_back(x1);
        _ya.push_back(ya);
        _x2.push_back(x2);
        _y2.push_back(y2);
    }
}

int main()
{
    freopen("LINES.INP", "r", stdin);
    freopen("LINES.OUT", "w", stdout);
    input();
    ans = n;
    fo(i,n)
    {
        val.push_back((double)(_x2[i] - _x1[i]) / (_y2[i] - _ya[i]));
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < i; j++)
    {
        if(val[i] == val[j])
        {
            val[j] = 0;
            ans--;
        }
    }
    cout << ans;
}
