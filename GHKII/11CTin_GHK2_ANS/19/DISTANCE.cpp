#include <bits/stdc++.h>


using namespace std;

int main()
{
      /*  long long int n;
        cin >> n;
        Diem A[10000];
        double Ax, Ay;
        cin >> Ax; cin >>Ay;
        double Min = 1000000;
        for (long long int i = 0; i < n; i++)
        {
            cin >> A[i].x >> A[i].y;
        }
        for (long long int i = 0; i < n - 1; i++)
            for (long long int j=i +1; j < n; j++)
        {
            if (DistanceDT(A[i].x,A[i].y, A[j].x, A[j].y, Ax,Ay) < Min) Min = DistanceDT(A[i].x,A[i].y, A[j].x, A[j].y, Ax,Ay);
        }
        cout << Min;*/
      freopen("DISTANCE.INP","r",stdin);
        freopen("DISTANCE.OUT","w",stdout);
        long long int a,b;
        double mins = INT_MAX;
        double ans = INT_MAX;
        long long int n;
        cin >> n;
        cin >>a >>b;
        long long int abefore, bbefore;
        for (long long int i=0;i < n; i++)
        {
            long long int atemp, btemp;
            cin >> atemp >> btemp;
            if (i!=0)
            {
                long long int midA = (atemp -abefore)/2;
                long long int midB = (btemp -bbefore)/2;
                double temp;
                temp = (double)sqrt( (a-b) - (midA - midB));
                ans = min(ans , temp);
            }
            abefore = atemp;
            bbefore = btemp;
        }
        cout << fixed << setprecision(4)<<ans << "\n";
}
