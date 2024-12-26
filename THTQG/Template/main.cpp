#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ordered_set tree <int,  null_type,  less,  rb_tree_tag,  tree_order_statistics_node_update > // Thuc chat ordered_set la mot cai CTDL dang cay => nhanh vl =))) co O(logn)
#define ll long long
#define pii pair<int, int>
#define pb push_back
#define fi first
#define se second
#define ed '\n'
#define mp make_pair
//Sang nguyen to co ban

void MakeSieve() {
    Sieve[0] = Sieve[1] = true;
    for (int x = 2; x*x <= maxN; ++x)
        if (Sieve[x] == false)
            for (int y = x; x*y <= maxN; ++y)
                Sieve[y*x] = true;
}

//Sang mo rong 1: d[n] la so uoc so cua n
int d[maxN] = {0};
void Sieve() {
    for (int x = 1; x <= sqrt(maxN); ++x) {
        ++d[x*x];
        for (int y = x+1; y <= maxN/x; ++y)
            d[x*y] += 2;
    }
} // O(n^2)

//Sang mo rong 2: d[n] la tong cac uoc so cua n
void Sieve() {
    for (int x = 1; x <= sqrt(maxN); ++x) {
        d[x*x] = d[x*x] + x;
        for (int y = x+1; y <= maxN/x; ++y)
            d[x*y] = d[x*y] + x + y;
    }
}

//Sang mo rong 3: d[n] la tong tat ca cac thua so nguyen to trong ptklt cua n
void Sieve() {
    for (int x = 2; x <= maxN; ++x) {
        if (d[x] == 0) //x là số nguyên tố
            for (int y = 1; y <= maxN/x; ++y) {
                z = y*x;
                while (z % x == 0) {
                    d[x*y] += x;
                    z = z/x;
                }
            }
    }
}

//Sang mo rong 4: d[n] la sum every different prime factors of cua n
void Sieve() {
    for (int x = 2; x <= maxN; ++x) {
        if (d[x] == 0)
            for (int y = 1; y <= maxN/x; ++y)
                d[y*x] += x;
    }
}

//Sang mo rong 5: Phan tich thua so ngto O(logN)
int d[MaxN], NumOfDiv[MaxN];
int a,b,t;
map <int, ll> mu;

void MakeD() {
    for (int i=2; i*i<= MaxN; i++)
        if (d[i] == 0)
            for (int j=i; i*j <= MaxN; j++)
                d[i*j] = i;
}

ll CntDiv(int x) {
    mu.clear();
    while (x > 1) {
        int p = d[x];
        if (p == 0)
            p = x;
        mu[p]++;
        x = x/p;
    }
    ll ans = 1;
    for (auto i=mu.begin();i!= mu.end(); i++)
        ans = ans*((*i).second + 1);
    return ans;
}

// Xu ly so nguyen lon

typedef vector<int> BigNum;
// Sum of 2 Big Numbers
BigNum operator + (BigNum a, BigNum b) {
    BigNum ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) || (j < b.size())) {
        if (i < a.size())
            r += a[i++];
        if (j < b.size())
            r += b[j++];
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;

}
// Subtraction of 2 Big Numbers
BigNum operator - (BigNum a, BigNum b) {
    BigNum ans;
    int i = 0, j = 0, r = 0;
    while ((i < a.size()) && (j < b.size())) {
        int tmp = a[i++] - r;
        if (j < b.size())
            tmp = tmp - b[j++];
        if (tmp < 0) {
            tmp += 10;
            r = 1;
        }
        else
            r = 0;
        ans.push_back(tmp);
    }
    while (ans.back() == 0)
        ans.pop_back();
    return ans;
}
// Multiplication of 2 Big Numbers
BigNum operator * (BigNum a, int b) // Multiplication of 1 Big Number and 1 integer
{
    BigNum ans;
    int r = 0;
    for (int i = 0; i < a.size(); ++i) {
        r = r + a[i]*b;
        ans.push_back(r%10);
        r = r/10;
    }
    if (r > 0)
        ans.push_back(r);
    return ans;
}
BigNum pow10(BigNum a, int n) { //ham mu 10
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
}

//Longest Increasing Subsequence length with O(nlogn)
int n, tail[MaxN], a[MaxN];
int BinSearchCeil(const int& val, int lo, int hi, const int arr[MaxN]) {
    int ans = 0;
    while (lo <= hi) {
        int m = (lo + hi)/2;
        if (arr[m] >= val) {
            ans = m;
            hi = m - 1;
        }
        else
            lo = m + 1;
    }
    return ans;
}
int LISLength() {
    int length = 2;
    tail[1] = a[1];
    for (int i = 2; i<=n; i++) {
        if (a[i] < tail[1])
            tail[1] = a[i];
        else if (a[i] > tail[length - 1])
            tail[length++] = a[i];
        else
            tail[BinSearchCeil(a[i], 1, length-1, tail)] = a[i];
    }
    return length-1;
}

// BFS va DFS

//BFS
vector<int> g[100001];
int n, m, trace[100001], s, t;
bool visited[100001];
queue<int> q;

void BFS(int s, int t) {
    q.push(s);
    visited[s] = true;
    trace[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        if (u == t)
            break;
        for (auto v: g[u]) {
            if (!visited[v]) {
                q.push(v);
                visited[v] = true;
                trace[v] = u;
            }
        }
    }
    PrintAns(t);//Ham nay tu viet khi can thiet
}


//DFS
vector<int> g[100001];
int n,m,trace[100001], s, t;
bool visited[100001];
stack<int> stk;

void DFS(int s, int t) {
    stk.push(s);
    visited[s] = true;
    trace[s] = -1;
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if (u == t)
            break;
        for (auto v: g[u]) {
            if (!visited[v]) {
                stk.push(v);
                visited[v] = true;
                trace[v] = u;
            }
        }
    }
    PrintAns(t);//Ham nay tu viet khi can thiet
}

//Cay DFS
bool visited[100001];
int n, m, discTime[100001], low[100001], tail[100001];
vector<int> g[100001];

void MakeDFSTree(int u, int& time, int parent) {
    time++;
    discTime[u] = low[u] = time;
    for (auto v: g[u]) {
        if (discTime[v] == -1) { //Ban dau khoi tao discTime[] va low[] bang -1
            MakeDFSTree(v, time, u); //Build cay con goc v
            low[u] = min(low[u], low[v]); //Cap nhat low de lien ket voi cay con goc v
        }
        else if (v != parent)
            low[u] = min(low[u], discTime[v]); //Cap nhat low va di nguoc lai theo backedge
    }
    tail[u] = time;
}

//Canh cau va khop
void DFS(int u, int p) {
  	counter++;
    num[u] = low[u] = counter;
    int numChild = 0;
    for (int v: g[u]) {
        if (v == p)
            continue;
        if (num[v])
            low[u] = min(low[u], num[v]);
        else {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            numChild++;
            if (low[v] > num[u])
                Bridges.push_back(pii(u, v));
            if ((low[v] >= num[u]) && (p != -1))
                IsCut[u] = true;
        }
    }
    if ((p == -1) && (numChild > 1))
        IsCut[u] = true;
}

//Strongly connected component

// Tarjan
int discTime[10001], low[10001], n, m, SCC = 0;
bool visited[10001];
vector<int> g[10001];
stack<int> st; //stack uses for storing nodes of the SCCs
//Tarjan algo for COUNTING SCC

void DFSSCC(int u, int &time) {
    time++;
    discTime[u] = low[u] = time;
    st.push(u);
    visited[u] = true;
    for (auto v: g[u]) {
        if (discTime[v] == -1) {
            DFSSCC(v, time);
            low[u] = min(low[u], low[v]);
        }
        else if (visited[v])
            low[u] = min(low[u], discTime[v]);
    }
    if (low[u] == discTime[u]) { //If found SCC then count Number of SCC by 1
        SCC++;
        int x = 0;
        while (st.top() != u) { //erase all the node of the SCC from stack
            x = st.top();
            visited[x] = false;
            st.pop();
        }
        visited[u] = false;
        st.pop();
    }
}

void Solve() {
    int time = 0;
    for (int i=1; i<=n; i++) {
        discTime[i] = -1;
        low[i] = -1;
    }
    for (int u=1; u<=n; u++)
        if (discTime[u] == -1)
            DFSSCC(u,time);
    cout << SCC;
}

// Dijkstra
int n, m, s, t, dist[100001], INF = 1e9;
vector<pair<int,int>> g[100001];
set<pair<int,int>> setds;

void Init() {
    for (int i=0; i<=n; i++)
        dist[i] = INF;
}

void Dijkstra(int s/*, int t */) {
    setds.insert(make_pair(0, s));
    dist[s] = 0;
    while (!setds.empty()) {
        pair<int, int> top = *(setds.begin());
        setds.erase(setds.begin());
        int u = top.second;
        for (auto e: g[u]) {
            int v = e.first, wei = e.second;
            if (dist[v] > dist[u] + wei) {
                if (dist[v] != INF)
                    setds.erase(setds.find(make_pair(dist[v],v)));
                dist[v] = dist[u] + wei;
                setds.insert(make_pair(dist[v], v));
            }
        }
    }
    for (int i=0; i<n; i++)
        if (dist[i] != INF)
            cout << i << " " << dist[i] << '\n';
    //cout << dist[t];
    //Bo dau comment cho truong hop chi in ra duong di ngan nhat tu 1 diem
}

//Segment Tree
const int MaxN = 1e6;
int n, t[4*MaxN], a[MaxN];

void ReadData() {
    for (int i=1; i<=n; i++)
        cin >> a[i];
}

void build(int a[], int v, int tl, int tr) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(a, v*2, tl, tm);
        build(a, v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

void update(int v, int tl, int tr, int pos, int new_val) { //Initially v = 1, tl = 1, tr = n
    if (tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update(v*2, tl, tm, pos, new_val);
        else
            update(v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int sum(int v, int tl, int tr, int l, int r) { //Initially v = 1, tl = 1, tr = n
    if (l > r)
        return 0;
    if (l == tl && r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v*2, tl, tm, l, min(r, tm)) + sum(v*2+1, tm+1, tr, max(l, tm+1), r);
}

// Persistent segment tree (With example of D. MEDIAN ICPC Central VN 2022)
struct Vertex {
    Vertex *l, *r;
    int sum;
    Vertex(int val) : l(nullptr), r(nullptr), sum(val){}
    Vertex(Vertex *l, Vertex *r) : l(l), r(r), sum(0) {
        if (l) sum += l->sum;
        if (r) sum += r->sum;
    }
};
int n, q, a[MaxN+1];
vector<Vertex*> root;

Vertex* BuildSt(int tl, int tr) {
    if (tl == tr)
        return new Vertex(0);
    int tm = ((tl + tr) >> 1);
    return new Vertex(BuildSt(tl, tm), BuildSt(tm+1, tr));
}

Vertex* UpdateSt(Vertex* v, int tl, int tr, int pos) {
    if (tl == tr)
        return new Vertex(v->sum+1);
    int tm = ((tl + tr) >> 1);
    if (pos <= tm)
        return new Vertex(UpdateSt(v->l, tl, tm, pos), v->r);
    else
        return new Vertex(v->l, UpdateSt(v->r, tm+1, tr, pos));
}

int FindKth(Vertex* vl, Vertex *vr, int tl, int tr, int k) {
    if (tl == tr)
        return tl;
    int tm = ((tl + tr) >> 1);
    int left_count = (vr->l->sum) - (vl->l->sum);
    if (left_count >= k)
        return FindKth(vl->l, vr->l, tl, tm, k);
    return FindKth(vl->r, vr->r, tm+1, tr, k-left_count);
}
void Solve() {
    root.push_back(BuildSt(0, MaxN+1));
    for (int i=0; i<n; i++)
        root.push_back(UpdateSt(root.back(), 0, MaxN+1, a[i]));
    for (int i=1; i<=q; i++) {
        int a, b;
        cin >> a >> b;
        int kth = ((b - a + 2) >> 1);
        int ans = FindKth(root[a-1], root[b], 0, MaxN+1, kth);
        cout << ans << '\n';
    }
}

// MST (Cay khung nho nhat) Kruskal's algorithm
vector<vector<int>> kruskal(int V, vector<vector<int>> E) {
    vector<vector<int>> mstEdges;
    DSU dsu(V);
    sort(E.begin(), E.end());
    for (i=0; i<E.size() && mstEdges.size()<V-1; i++) {
        int w = E[i][0], u = E[i][1], v = E[i][2];
        if (dsu.find(u) != dsu.find(v)) {
            mstEdges.push_back({w, u, v});
            dsu.combine(u, v);
        }
    }
    return mstEdges;
}

// Geometry
struct Point {
    Point(double _x=0, double _y=0) { x = _x; y = _y; }
    double x; double y;
    bool operator<(const Point b) const { return make_pair(x, y) < make_pair(b.x, b.y); }
    bool operator==(const Point b) const { return x == b.x && y == b.y; }
    Point operator+(const Point b) { return Point(x + b.x, y + b.y); }
    Point operator-(const Point b) { return Point(x - b.x, y - b.y); }
    Point operator*(const double val) { return Point(x * val, y * val); }
    Point operator/(const double val) { return Point(x / val, y / val); }
    double cross(const Point b) { return x * b.y - b.x * y; }
    double dot(const Point b) {return x * b.x + y * b.y;}
};

// Counterclockwise sort

double Pi = atan(1) * 4;
void sortCounterClockwisePoints(vector<Point>& points) {
    Point center(0,0);
    for (Point p : points)
        center = center + p;
    center = center / points.size();
    auto cmp = [&](Point p1, Point p2) {
        double A1 = atan2(p1.y - center.y, p1.x - center.x);
        double A2 = atan2(p2.y - center.y, p2.x - center.x);
        if (A1 <= 0) A1 += 2*Pi;
        if (A2 <= 0) A2 += 2*Pi;
        if (A1 != A2) return A1 > A2;
        double d1 = pow(p1.x - center.x,2) + pow(p1.y - center.y,2);
        double d2 = pow(p2.x - center.x,2) + pow(p2.y - center.x,2);
        return d1 > d2;
    };
    sort(points.begin(), points.end(), cmp);
}

// Dinh ly Pick's
// Gia su co da giac voi cac dinh toa do so nguyen
// B = so dinh, S = dien tich da giac, I = so diem co toa do nguyen trong da giac
// Ta co: S = I + (B/2) - 1

//Kiem tra diem L nam trong tam giac ABC
bool pointInTriangle(Point A, Point B, Point C, Point L) {
    // EPS deals with precision error
    double EPS = -1e9;
    double S = area({ A,B,C });
    double s1 = area({ A,B,L });
    double s2 = area({ A,C,L });
    double s3 = area({ B,C,L });
    return S - (s1 + s2 + s3) <= EPS;
}

// Dien tich Simple Polygon (cac dinh dc sort counterclockwise)
double area(vector<Point> inp) {
    int N = inp.size();
    inp.push_back(inp[0]);
    double sumPart = 0;
    for (int i = 0; i < N; i++) {
        sumPart += inp[i].x * inp[i+1].y - inp[i+1].x * inp[i].y;
    }
    return abs(sumPart)/ 2;
}

//Check xem dinh K co nam trong da giac loi O(logN)
bool pointInConvexPoly(vector<Point> poly, Point K) {
    int L = 1, R = poly.size() - 1;
    while (R - L >= 10) {
        int mid = (L + R) / 2;
        if ((poly[mid] - poly[0]).cross(K - poly[0]) < 0) R = mid - 1;
        else L = mid;
    }
    // brute force when R-L is small
    for (; 0 < L && L <= R+3; L++) {
        if ((poly[L] - poly[0]).cross(K - poly[0]) < 0) {
            L = L - 1;
            break;
        }
    }
    if (L <= 0 || L >= poly.size() - 1) return false;
    return pointInTriangle(poly[L], poly[L+1], poly[0], K);
}

//Tim cap diem gan nhau nhat trong cac diem da cho
typedef tuple<double, Point, Point> dPP;
dPP BruteForce(int L, int R, vector<Point>& A) {
    dPP ans(dist(A[0], A[1]), A[0], A[1]);
    for (int i = L; i <= R; i++)
        for (int j = i + 1; j <= R; j++)
            if (dist(A[i], A[j]) < get<0>(ans))
                ans = make_tuple(dist(A[i], A[j]), A[i], A[j]);
    return ans;
}

dPP recur(int L, int R, vector<Point>& A, vector<Point>& sortedByY) {
    if (R - L <= 10) return BruteForce(L, R, A);
    int mid = (L + R) / 2;
    dPP resLeft = recur(L, mid, A, sortedByY);
    dPP resRight = recur(mid, R, A, sortedByY);
    dPP ans = min(resLeft, resRight);
    vector<Point> stripe;
    for (Point p : sortedByY)
        if (A[mid].x - get<0>(ans) <= p.x && p.x <= A[mid].x + get<0>(ans))
            stripe.push_back(p);
    for (int i = 0; i < stripe.size(); i++) {
        for (int j = i + 1; j < i + 20 && j < stripe.size(); j++) {
            double d = dist(stripe[i], stripe[j]);
            if (d < get<0>(ans)) {
                ans = make_tuple(d, stripe[i], stripe[j]);
            }
        }
    }
    return ans;
}

dPP closestPair(vector<Point>& points) {
    vector<Point> sortedByY = points;
    sort(sortedByY.begin(), sortedByY.end(), [](Point A, Point B) {
        return A.y < B.y;
    });
    return recur(0, points.size()-1, points, sortedByY);
}

//Lay cac diem thuoc Convex Hull (ko theo thu tu nhat dinh)
vector<Point> convexHull(vector<Point> points) {
    vector<Point> uH;
    vector<Point> bH;
    auto cmp = [](Point p1, Point p2) {
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y;
    };
    sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < points.size(); i++) {
        uH.push_back(points[i]);
        int64_t N = uH.size();
        while (uH.size() > 2 && isTurnLeft(uH[N-3], uH[N-2], uH[N-1])) {
            uH.erase(uH.begin() + N - 2);
            N = uH.size();
        }
    }
    for (int i = 0; i < points.size(); i++) {
        bH.push_back(points[i]);
        int64_t N = bH.size();
        while (bH.size() > 2 && isTurnRight(bH[N-3], bH[N-2], bH[N-1])) {
            bH.erase(bH.begin() + N - 2);
            N = bH.size();
        }
    }
    set<Point> cH(bH.begin(), bH.end());
    cH.insert(uH.begin(), uH.end());
    return vector<Point>(cH.begin(), cH.end());
}

// does vec{AB} turn right to look at C?
bool isTurnRight(Point A, Point B, Point C) {
    return (B - A).cross(C - A) < 0;
}

// does vec{AB} turn left to look at C?
bool isTurnLeft(Point A, Point B, Point C) {
    return (B - A).cross(C - A) > 0;
}

// Ktra 2 doan thang giao nhau (AB, CD)

bool OnSegment(Point A,Point B,Point C) {
    if(C.x<=max(A.x,B.x)&&C.x>=min(A.x,B.x)&&C.y<=max(A.y,B.y)&&C.y>=min(A.y,B.y)) return true;
    return false;
    }
//Xét orientation của các bộ 3 điểm A,B,C; A,B,D; C,D,A; C,D,B :
int Orient(Point A,Point B,Point C) {
    int val=(B.y-A.y)*(C.x-B.x)-(B.x-A.x)*(C.y-B.y);
    if (val==0) return 0; //A,B,C thẳng hàng
    return (val>0)? 1: 2; //clockwise hoặc counterclockwise
}
bool CheckInter(Point A,Point B,Point C,Point D){
    if ((Orient(A,B,C)!=Orient(A,B,D))&&(Orient(C,D,A)!=Orient(C,D,B))) return true;
    if (Orient(A,B,C)==0&&OnSegment(A,B,C)) return true;
    if (Orient(A,B,D)==0&&OnSegment(A,B,D)) return true;
    if (Orient(C,D,A)==0&&OnSegment(C,D,A)) return true;
    if (Orient(C,D,B)==0&&OnSegment(C,D,B)) return true;
    return false;
}

// Tinh dien tich tam gia, cong thuc Heron
double heron(double a, double b, double c){
    double p = (a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

// Tim giao diem cua 2 duong thang
int CheckInter(int A1,int B1,int C1,int A2,int B2,int C2){
    if(A1*B2-A2*B1==0)
        if((A1*C2-A2*C1==0)&&(B1*C2-B2*C1==0)) return 2; //trùng nhau
        else return 0; //không giao
    return 1; //giao
}

//Sau khi check thi toa do giao diem la
/*
x = -1.0*(C1*B2-C2*B1)/(A1*B2-A2*B1);
y = -1.0*(A1*C2-A2*C1)/(A1*B2-A2*B1);
*/

//Chuyen gia tri a tu he 10 sang he n (2 -> 36)

string Convert(int a, int n){
    string s;
    static char hTab[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    if(a>=n)s=s+Convert(a/n,n);
    return s+hTab[a%n];
}

//Rolling hash
string s;
//Base (# of vals), Mod (usually prime), k
ll B,M,k;
ll curHash = 0;
for (int i = 0; i < k; i++)
    curHash = (curHash*B + val[s[i]]) % M;
//curHash now holds the hash of s[0..k]
for (int i = 1; i < s.size() - k + 1; i++) {
    curHash = curHash - (val[s[i-1]]*pow(B, k-1)) % M;
    while (curHash < 0) curHash += M;
    curHash = (curHash*B + val[s[i+k-1]]) % M;
    //curHash now holds the hash of s[i..k+i]
}

// Rollback DSU
struct Data {
    int time, u, par, Comp;
};
struct DSU { // Rollback DSU
    int Comp;
    vector<int> par;
    vector<Data> changes;
    DSU(int n): par(n+5, -1) {}
    int FindSet(int u) {
        while (par[u] >= 0)
            u = par[u];
        return u;
    }

    bool UnionSet(int u, int v, int t) {
        u = FindSet(u);
        v = FindSet(v);
        if (u == v)
            return false;
        if (par[u] < par[v])
            swap(u, v);
        changes.push_back({t, v, par[v], Comp});
        par[v] += par[u];
        changes.push_back({t, u, par[u], Comp});
        par[u] = v;
        Comp--;
        return true;
    }

    void Rollback(int t) {
        while ((!changes.empty()) && (changes.back().time > t)) {
            par[changes.back().u] = changes.back().par;
            Comp = changes.back().Comp;
            changes.pop_back();
        }
    }
};

//Sparse table
ll n, a[MaxN+5], SparseTableMax[MaxN+5][23], SparseTableMin[MaxN+5][23];
ll log_2[MaxN+5];

void MakeLog2() {
    for (int i=2; i<=n; i++)
        log_2[i] = log_2[i/2] + 1;
}

void MakeSparse() {
    for (int i=1; i<=n; i++)
        SparseTableMax[i][0] = SparseTableMin[i][0] = a[i];
    for (int j=1; (1<<j) <= n; j++) {
        int step = 1 << (j-1);
        for (int i=1; i+2*step <= n+1; i++) {
            SparseTableMax[i][j] = max(SparseTableMax[i][j-1], SparseTableMax[i+step][j-1]);
            SparseTableMin[i][j] = min(SparseTableMin[i][j-1], SparseTableMin[i+step][j-1]);
        }
    }
}

ll MinQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (min(SparseTableMin[l][k], SparseTableMin[r - (1 << k) + 1][k]));
}

ll MaxQuery(int l, int r) {
    int k = log_2[r-l+1];
    return (max(SparseTableMax[l][k], SparseTableMax[r - (1 << k) + 1][k]));
}

// Finding mext/pre Smaller value and next/pre larger value using stack
ll n, a[MaxN+5];
ll PreSmaller[MaxN+5], PreLarger[MaxN+5];
void FindPreSmaller() {
    stack<int> st;
    for (int i=n; i>=1; i--) {
        while ((!st.empty()) && (a[i] < a[st.top()])) {
            PreSmaller[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

void FindPreLarger() {
    stack<int> st;
    for (int i=n; i>=1; i--) {
        while ((!st.empty()) && (a[i] > a[st.top()])) {
            PreLarger[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
}

// Kahn
int indeg[100001];
vector<int> graph[200001], res;

void ReadGraph() {
    int a, b;
    for (int i=1; i<=m; i++) {
        cin >> a >> b;
        graph[a].push_back(b);
        indeg[b]++;
    }
}

bool Kahn() {
    queue<int> q;
    for (int i=1; i<=n; i++)
        if (indeg[i] == 0)
            q.push(i);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        res.push_back(u);
        for (int v : graph[u]) {
            indeg[v]--;
            if (indeg[v] == 0)
                q.push(v);
        }
    }
    return (res.size() == n); //return if the graph has a cycle. If the graph has a cycle, it cannot be sorted topologically
}

void Toposort() {
    if (Kahn()) {
        for (auto i: res)
            cout << i << ' ';
    }
    else
        cout << "IMPOSSIBLE";
}

// Euler Cycle
int T, n, DegIn[27], DegOut[27], Edge[27][27];
vector<int> graph[27], path;
bool vis[27];

void ReadData() {
    string tmp;
    for (int i=1; i<=n; i++) {
        cin >> tmp;
        int v = int(tmp[tmp.length()-1] - 'a'), u = int(tmp[0] - 'a');
        vis[v] = vis[u] = true;
        DegIn[v]++;
        DegOut[u]++;
        Edge[u][v] = 1;
        Edge[v][u] = 1;
        graph[u].push_back(v);
    }
}

void Init() {
    path.clear();
    for (int i=0; i<26 ; i++) {
        graph[i].clear();
        DegIn[i] = DegOut[i] = 0;
        vis[i] = true;
    }
    for (int i=0; i<26; i++)
        for (int j=0; j<26; j++)
            Edge[i][j] = 0;
}

void DFS(int u) {
    vis[u] = true;
    for (int v = 0; v < 26; v++)
        if (((Edge[u][v] > 1) || (Edge[v][u] > 1)) && (!vis[v]))
            DFS(v);
}

bool ExistEuler() {
    int u = -1, v = -1, cc = 0;
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            DFS(i);
            cc++;
        }
    }
    if (cc > 1)
        return false;
    for (int i=0; i<26; i++) {
        if (DegIn[i] != DegOut[i]) {
            if (u == -1)
                u = i;
            else if (v == -1)
                v = i;
            else
                return false;
        }
    }
    if (u == -1)
        return true;
    if (((DegIn[u] - DegOut[u] == 1) && (DegOut[v] - DegIn[v] == 1)) || ((DegOut[u] - DegIn[u] == 1) && (DegIn[v] - DegOut[v] == 1)))
        return true;
    return false;
}

// Find Euler Path
int T, n = 0, m, Edge[1001][1001];
vector<int> path;

void ReadGraph() {
    for (int i=1; i<=T; i++) {
        int u, v;
        cin >> m >> u;
        n = max(n, u);
        for (int j=1; j<=m; j++) {
            cin >> v;
            Edge[u][v]++;
            n = max(n, v);
            u = v;
        }
    }
}

void FindEulerPath(int u) {
    for (int v = 1; v<=n; v++) {
        if (Edge[u][v] > 0) {
            Edge[u][v]--;
            FindEulerPath(v);
        }
    }
    path.push_back(u);
}

// Hamilton Cycle

int T, n, m, MaxDist[11];
vector<int> graph[11];
bool vis[11];

void ReadData() {
    for (int i=1; i<=m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}

void Init() {
    for (int i=1; i<=10; i++) {
        vis[i] = false;
        graph[i].clear();
        MaxDist[i] = 0;
    }
}

void Hamilton(int u, int dist) {
    MaxDist[u] = max(MaxDist[u], dist);
    for (auto v: graph[u]) {
        if (!vis[v]) {
            vis[v] = true;
            Hamilton(v, dist+1);
            vis[v] = false;
        }
    }
}

void Solve() {
    for (int i=1; i<=T; i++) {
        cin >> n >> m;
        Init();
        ReadData();
        for (int st=1; st<=n; st++) {
            vis[st] = true;
            Hamilton(st,0);
            vis[st] = false;
        }
        for (int i=1; i<=n; i++)
            cout << MaxDist[i] << ' ';
        cout << '\n';
    }
}

// FastPow
typedef long long ll;
const ll Mod = 998244353;
int t;
ll n, m, k;
ll Fact[MaxN+5], InvFact[MaxN+5];

ll FastPow(ll base, ll e, const ll& Mod) {
    ll ans = 1;
    while (e > 0) {
        if (e&1LL)
            ans = (ans*base)%Mod;
        base = (base*base)%Mod;
        e >>= 1LL;
    }
    return ans;
}

// Inverse Modulo with Mod is a prime

ll InverseMod(ll x, const ll& Mod) {
    return FastPow(x, Mod-2, Mod);
}

// Factorial with Inverse Modulo and Mod is a prine

void MakeFac() {
    Fact[0] = 1;
    for (ll i = 1; i <= MaxN; i++) {
        Fact[i] = (Fact[i-1]*i)%Mod;
        InvFact[i] = InverseMod(Fact[i], Mod);
    }
}

// nCk

ll nCk(ll n, ll k) {
    if (n < k)
        return 0;
    if ((k == 0) || (k == n))
        return 1;
    ll ans = ((Fact[n] * InvFact[k])%Mod * InvFact[n-k])%Mod;
    return ans;
}

//Z Function
vector<int> MakeZFunction(string s) {
    int n = s.length(), l = 0, r = 0;
    vector<int> z(n);
    z[0] = n;
    for (int i=1; i<n; i++) {
        if (i <= r)
            z[i] = min(z[i-l], r-i+1);
        while ((i + z[i] < n) && (s[i + z[i]] == s[z[i]]))
            z[i]++;
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    return z;
}

// Fenwick Tree
ll ft[MaxN+5];

void UpdateFt(ll ft[], int v, ll val) {
    while (v <= n) {
        ft[v] += val;
        v += (v & -v);
    }
}

ll GetSum(ll ft[], int v) {
    ll sum = 0;
    while (v > 0) {
        sum += ft[v];
        v -= (v & -v);
    }
    return sum;
}

void UpdateRange(int l, int r, ll val) {
    UpdateFt(ft, l, val);
    UpdateFt(ft, r+1, -val);
}

//LCA
int n, l, counter, par[MaxN+1][21], tin[MaxN+1], tout[MaxN+1];
vector<int> g[MaxN+1];

void ReadGraph() {
    int u, v;
    for (int i=1; i<=n;i++)
        g[i].clear();
    for (int i=1; i<n; i++) {
        cin >> u >> v;
        g[v].push_back(u);
        g[u].push_back(v);
    }
}

void DFS(int u, int p) {
    counter++;
    tin[u] = counter;
    par[u][0] = p;
    for (auto v: g[u])
        if (p != v)
            DFS(v, u);
    counter++;
    tout[u] = counter;
}

void PreProcess() {
    counter = 0;
    l = ceil(log2(n));
    DFS(1, 1);
    for (int k=1; k<=l; k++) {
        for (int i=1; i<=n; i++)
            par[i][k] = par[par[i][k-1]][k-1];
    }
}

bool IsAncestor(int Anc, int v) {
    return ((tin[Anc] <= tin[v]) && (tin[v] <= tout[Anc]));
}

int LCA(int u, int v) {
    if (IsAncestor(u, v)) return u;
    if (IsAncestor(v, u)) return v;
    for (int k=l; k>=0; k--)
        if (!IsAncestor(par[u][k], v))
            u = par[u][k];
    return par[u][0];
}

// Trie

struct Node {
    Node* child[2];
    int cnt;
    Node() {
        cnt = 0;
        fill(child, child + MaxC, nullptr);
    }
};
Node* root = new Node();

void Add(Node* root, const vector<int>& bit) {
    Node* cur = root;
    for (int x: bit) {
        if (cur->child[x] == nullptr)
            cur->child[x] = new Node();
        cur = cur->child[x];
    }
    cur->cnt++;
}

bool IsEmpty(Node* cur) {
    Node* tmp = cur;
    for (int i=0; i<MaxC; i++)
        if (tmp->child[i] != nullptr)
            return false;
    return true;
}

bool Remove(Node* root, const vector<int>& bit, int depth = 0) {
    if (!root)
        return false;
    if (depth == bit.size()) {
        if (root->cnt > 0) {
            root->cnt--;
            return true;
        }
        return false;
    }
    int x = bit[depth];
    if (!root->child[x])
        return false;
    bool IsRemoved = Remove(root->child[x], bit, depth+1);
    Node* tmp = root->child[x];
    if ((IsRemoved) && (tmp->cnt == 0) && (IsEmpty(tmp))) {
        delete root->child[x];
        root->child[x] = nullptr;
    }
    return IsRemoved;
}

int Search(Node* root, const vector<int>& bit) {
    vector<int> res;
    Node* cur = root;
    for (int x: bit) {
        int tmp = 1-x;
        if (cur->child[tmp] == nullptr) {
            tmp = 1-tmp;
            if (cur->child[tmp] == nullptr)
                break;
        }
        res.push_back(tmp);
        cur = cur->child[tmp];
    }
    return GetNum(res);
}



// Nhan ma tran
const ll Mod = 1e9 + 9;
struct Matrix {
    vector<vector<ll>> a;
    int n, m;

    Matrix(int n = 0, int m = 0): n(n), m(m) {
        a.assign(n, vector<ll>(m, 0));
    }
};

Matrix operator* (const Matrix& a, const Matrix& b) {
    Matrix c(a.n, b.m);
    for (int i=0; i<a.n; i++)
        for (int j=0; j<b.m; j++)
            for (int k=0; k<a.m; k++)
                c.a[i][j] = ((a.a[i][k]*b.a[k][j])%Mod + c.a[i][j])%Mod;
    return c;
}

Matrix Identity(int n) {
    Matrix ans(n, n);
    for (int i=0; i<n; i++)
        ans.a[i][i] = 1;
    return ans;
}

Matrix FastPow(Matrix& base, ll e)  {
    Matrix ans = Identity(base.n);
    while (e > 0) {
        if (e&1)
            ans = ans * base;
        base = base * base;
        e >>= 1LL;
    }
    return ans;
}

void SolveTestCase() { // Vd mau ve nhan ma tran
    Matrix mat(3, 3), unit(3, 1), tmp;
    mat.a[0][1] = mat.a[1][2] = mat.a[2][0] = mat.a[2][1] = mat.a[2][2] = 1;
    unit.a[0][0] = 0;
    unit.a[1][0] = 1;
    unit.a[2][0] = 2;
    tmp = FastPow(mat, n-1);
    tmp = tmp*unit;
    cout << tmp.a[0][0] << '\n';
}

// LIS N log N Binary search approach
int lengthOfLIS(vector<int>& nums)
{
    int n = nums.size();
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < n; i++) {
        if (nums[i] > ans.back())
            ans.push_back(nums[i]);
        else {
            int low = lower_bound(ans.begin(), ans.end(),nums[i]) - ans.begin();
            ans[low] = nums[i];
        }
    }
    return ans.size();
}

// Longest Bitonic sequence
int ceilIndex(int arr[], int l, int r, int x)
{
    if (l > r)
        return -1;

    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
        return mid;

    if (x < arr[mid])
        return ceilIndex(arr, l, mid - 1, x);

    return ceilIndex(arr, mid + 1, r, x);

}

// function to reverse an array
void revereseArr(int arr[], int n)
{
    int i = 0;
    int j = n - 1;
    while (i < j)
       swap(arr[i++], arr[j--]);
}

// Returns length of longest Bitonic
// subsequence in O(n Log n) time.
int getLBSLengthLogn(int arr[], int n)
{
    if (n == 0)
        return 0;
    int increasing[n];
    int tail1[n];  // To store lengths of IS
    int decreasing[n];
    int tail2[n]; // To store lengths of DS
    increasing[0] = arr[0];
    int in = 1;
    tail1[0] = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < increasing[0])
        {
            increasing[0] = arr[i];
            tail1[i] = 0;
        }
        else if (arr[i] > increasing[in - 1])
        {
            increasing[in++] = arr[i];
            tail1[i] = in - 1;
        }
        else
        {
            increasing[ceilIndex(increasing, -1,
                        in - 1, arr[i])] = arr[i];
            tail1[i] = ceilIndex(increasing, -1,
                                   in - 1, arr[i]);
        }
    }
    in = 1;
    revereseArr(arr, n);
    decreasing[0] = arr[0];
    tail2[0] = 0;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] < decreasing[0])
        {
            decreasing[0] = arr[i];
            tail2[i] = 0;
        }
        else if (arr[i] > decreasing[in - 1])
        {
            decreasing[in++] = arr[i];
            tail2[i] = in - 1;
        }
        else
        {
            decreasing[ceilIndex(decreasing, -1,
                      in - 1, arr[i])] = arr[i];
            tail2[i] = ceilIndex(decreasing, -1,
                                 in - 1, arr[i]);
        }
    }
    revereseArr(arr, n);
    revereseArr(tail2, n);
    int ans = 0;
    for (int i = 0; i < n; i++)
        if (ans < (tail1[i] + tail2[i] + 1))
            ans = (tail1[i] + tail2[i] + 1);


    return ans;
}

// Coin change problems with unlimited coins for each type
using namespace std;
typedef long long ll;
int n, m, c[51];
ll dp[251];

void ReadData() {
    for (int i=1; i<=m; i++)
        cin >> c[i];
}

ll Solution() {
    dp[0] = 1;
    for (int i=1; i<=m; i++)
        for (int j=1; j<=n; j++)
            if (j - c[i] >= 0)
                dp[j] += dp[j-c[i]];
    return dp[n];
}

//Calculate number of ways a price can be paid with cash range from $1 to $300
ll dp[301][1001];

void InitDp() {
    for (int i = 0; i<=300; i++)
        for (int j=0; j<=1000; j++)
            dp[i][j] = 0;
    dp[0][0] = 1;
}

void CalDp() {
    for (int i=1; i<=300; i++)
        for (int j=i; j<=300; j++)
            for (int k=1; k<=300; k++)
                dp[j][k] += dp[j-i][k-1];
}

//Divide the candies into 2 parts with the least difference
// dp[i] == whether it is possible to form a sum of i (dp[i] > 0 == true)
int n, c[101], k[101], dp[10000001], Prev[10000001];
ll MaxSum = 0;

void ReadData() {
    for (int i=1; i<=n; i++) {
        cin >> k[i] >> c[i];
        MaxSum += (k[i] * c[i]);
    }
}

int Solution() {
    Prev[0] = 1;
    for (int i=1; i<=n; i++) {
        int a = k[i] * c[i];
        for (int j=0; 2*j <= MaxSum; j++) {
            if (Prev[j] > 0)
                dp[j] = 1;
            else
                dp[j] = 0;
            if (j - c[i] >= 0) {
                dp[j] += dp[j-c[i]];
                if ((j - a - c[i] >= 0) && (Prev[j-a-c[i]] > 0))
                    dp[j]--;
            }
        }
        for (int i=0; 2*i <= MaxSum; i++)
            Prev[i] = dp[i];
    }
    for (int i=MaxSum/2; i>=0; i--)
        if (dp[i])
            return (MaxSum - 2*i);
}

// Modulo - fermat nho
/*
(a+b)%c = (a%c + b%c) % c
(a*b)%c = ((a%c) * (b%c)) % c
(a-b)%c = (a%c – b%c + c) % c
// a % c = (a+x) % c (a < 0, x > a && x % c == 0)
(a^n) % c = (a%c)^n % c
a % b = c => (k*a) % (k*b) = k*c
(a/b) % c = [(a%c)*(b^(-1) % c)] % c
// b^(-1) la nghich đao modulo theo co so c cua b
*/

// Dinh ly Fermat nho
/*
Neu m la snt, a % m != 0
Thi a^(m-1) % m = 1
a*a^(m-2) % m = 1
a*a^(m-2) la nghich dao modulo cua a khi mod m
a^(-1) % m = a^(m-2) % m
*/

//Ep kieu du lieu
int t;
string s;
stringstream ss;
ss << t;
ss >> s;

// Lam tron
cout << fixed << setprecision(2) << a/b;

// If rut gon
cout << s (l%5 != 0 ? 1 : 0);

//

// Dp Optimization: Knuth - Yao

//FORMULA
// Sum of digits of numbers from 1 to n: D(10q+r)=45q+10D(q−1)+r(r+1)/2+(r+1)d(q)  (n = 10q + r)
// Tong binh phuong tu 1 den n: n(n+1)(2n+1)/6
// So uoc: (mi+1)
// Tong cac uoc: (pi^(mi + 1) - 1)/(pi - 1)

//6k+-1
volid Divide(ll& n, ll k, ll& cal) {
    ll cnt = 0;
    while (n%k == 0) {
        cnt++;
        n/=k;
    }
    cal *= (Pow(k, cnt+1) - 1)/(k-1);
}

ll prime(ll m) {
    ll ans = 1;
    Divide(m, 2, ans);
    Divide(m, 3, ans);
    for (int k=5; k*k <= m; k+=6) {
        Divide(m, k, ans);
        Divide(m, k+2, ans);
    }
    if (m != 1 && trunc(sqrt(m))*trunc(sqrt(m)) == m)
        Divide(m, trunc(sqrt(m)), ans);
    if (m != 1)
        Divide(m, m, ans);
    return ans;
}

// ordered set
ordered_set os;
*(os.find_by_order(k)); // int: tra ve phan tu thu k
os.order_of_key(val; // int: tra ve so phan tu (strictly) nho hon gia tri val trong os
os.erase(os.find(val)); // xoa phan tu val neu co ton tai

// Two pointer
/*
- Cung chieu
- Nguoc chieu
- Tren 2 mang
*/

// Bitset, bitmask
/*
__builtin_clz(x): so chu so 0 o dau (dang bit)
__builtin_ctz(x): so chu so 0 o cuoi
__builtin_popcount(x): so chu so 1
__builtin_parity(x): dem su chan le cua so bit 1 trong bieu dien nhi phan cua x. Neu so bit 1 la le return 1. Nguoc lai neu so bit 1 la chan return 0

Bit set la mang co gia tri moi phan tu la 0 va 1
bitset<10> s;
s[1] = 1;
s[3] = 1;
s[4] = 1;
s[7] = 1;
cout << s[4] << '\n'; // 1
cout << s[5] << '\n'; // 0

Ham count tra ve so chu so 1 trong bit
cout << s.count() << '\n'; // 4

bitset ap dung dc cac phep toan bit nhu mot dang day nhi phan dai
*/

// Segment tree co lazy: bai toan tong doan lon nhat
long long n, a[1000001], q;
struct STNode {
    long long val = 0, lazy = 0;
}st[4000001];

void down(int id) {
    long long tmp = st[id].lazy;
    st[id*2].val += tmp;
    st[id*2].lazy += tmp;
    st[id*2+1].val += tmp;
    st[id*2+1].lazy += tmp;
    st[id].lazy = 0;
}

void update(int id, int l, int r, int u, int v, long long val) {
    if ((l > v) || (r < u))
        return;
    if ((u <= l) && (r <= v)) {
        st[id].val += val;
        st[id].lazy += val;
        return;
    }
    down(id);
    int mid = (l + r)/2;
    update(id*2, l, mid, u, v, val);
    update(id*2+1, mid+1, r, u, v, val);
    st[id].val = max(st[id*2].val, st[id*2+1].val);
}

int getMax(int id, int l, int r, int u, int v) {
    if ((l > v) || (r < u))
        return -1e9;
    if ((u <= l) && (r <= v))
        return st[id].val;
    down(id);
    int mid = (l + r)/2;
    return max(getMax(id*2, l, mid, u, v), getMax(id*2+1, mid+1, r, u, v));
}

// Dp Digit
void Transform(ll n, vector<int>& digit)
{
    while (n > 0)
    {
        digit.pb(n%10);
        n/=10;
    }
    if (digit.size() == 0) digit.pb(0);
    reverse(digit.begin(), digit.end());
}
//
ll sol(vector<int> digit)
{
    // id - prev - tight - zero
    int n = digit.size();
    ll f[n][10][2][2];
    memset(f,0,sizeof(f));
    for (int i = 0; i <= digit[0]; i++)
    {
        f[0][i][i == digit[0]][i == 0] = 1;
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int prev = 0; prev < 10; prev++)
        {
            for (int tight = 0; tight < 2; tight++)
            {
                for (int zero = 0; zero < 2; zero++)
                {
                    //f[i][prev][tight][zero]
                    for (int next = 0; next < 10; next++)
                    {
                        if (tight == 1 && next > digit[i+1]) continue;
                        if (next == prev && zero == 0) continue;
                        int New_tight = tight && next == digit[i+1];
                        int New_zero = zero && next == 0;
                        f[i+1][next][New_tight][New_zero] +=
                            f[i][prev][tight][zero];
                    }
                }
            }
        }
    }
    ll res = 0;
    for (int prev = 0; prev < 10; prev++)
    {
        for (int tight = 0; tight < 2; tight++)
        {
            for (int zero = 0; zero < 2; zero++)
            {
                res += f[n-1][prev][tight][zero];
            }
        }
    }
    return res;
}
//
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    /*ll a;
    cin >> a;
    vector<int> digit;
    digit.clear();
    Transform(a,digit);
    cout << sol(digit);*/
    ll a,b,res;
    cin >> a >> b;
    vector<int> digit;
    digit.clear();
    Transform(b, digit);
    res = sol(digit);
    if (a > 0)
    {
        a--;
        digit.clear();
        Transform(a,digit);
        res -= sol(digit);
    }
    cout << res;
    return 0;
}

// DP Knapsack: Matrix
ll n,w,ans,m[101],v[101],dp[101][100005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //freopen("knapsack1.inp","r",stdin);
    //freopen("knapsack1.out","w",stdout);
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
        cin >> m[i] >> v[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (j - m[i] < 0) dp[i][j] = dp[i-1][j];
            else
            {
                dp[i][j] = max(dp[i-1][j], v[i] + dp[i-1][j-m[i]]);
            }
        }
    }
    for (int i = 1; i <= w; i++)
        ans = max(ans, dp[n][i]);
    cout << ans;
}

// Dp  Knapsack: One-dimensional array
const ll MOD = 1e9+7;
ll n, a[101], x, dp[1000006];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = x; j >= 1; j--)
        {
            if (j - a[i] >= 0)
                dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
        }
    }
    cout << dp[x];
    return 0;
}

// Tim chu trinh am
bool findNegativeCycle(int n, vector<long long> &D, vector<int> &trace, vector<int> &negCycle) {
    // mảng D và trace đã được chạy qua thuật toán Bellman-Ford
    int negStart = -1; // đỉnh bắt đầu
    for (auto E : e) {
        int u = E.u;
        int v = E.v;
        long long w = E.w;
        if (D[u] != INF && D[v] > D[u] + w) {
            D[v] = -INF;
            trace[v] = u;
            negStart = v; // đã tìm thấy -INF
        }
    }

    if (negStart == -1) return false; // không có chu trình âm

    int u = negStart;
    for (int i = 0; i < n; i++) {
        u = trace[u]; // đưa u về chu trình âm
    }

    negCycle = vector<int>(1, u);
    for (int v = trace[u]; v != u; v = trace[u]) {
        negCycle.push_back(v); // truy vết một vòng
    }
    reverse(negCycle.begin(), negCycle.end());

    return true;
}

// Maxflow
struct Edge {
    int v, cap, flow;
};

int n, m;
vector<Edge> edges;
vector<int> g[501];
int lv[501];

//
bool bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    memset(lv, -1, sizeof(lv));
    lv[s] = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < g[u].size(); i++)
        {
            int id = g[u][i];
            int v = edges[id].v;
            int cap = edges[id].cap;
            int flow = edges[id].flow;
            if (lv[v] != -1) continue;
            if (cap <= flow) continue;
            lv[v] = lv[u] + 1;
            q.push(v);
        }
    }
    return lv[t] != -1;
}

//
int dfs(int s, int t, int pushed)
{
    if (pushed == 0) return 0;
    if (s == t) return pushed;
    for (int i = 0; i < g[s].size(); i++)
    {
        int id = g[s][i];
        int v = edges[id].v, cap = edges[id].cap, flow = edges[id].flow;
        if (lv[v] != lv[s] + 1) continue;
        if (cap <= flow) continue;
        int f = min(pushed, cap - flow);
        f = dfs(v, t, f);
        if (f == 0) continue;
        edges[g[s][i]].flow += f;
        edges[g[s][i]^1].flow -= f;
        return f;
    }
    return 0;
}

//
int dinic(int s, int t)
{
    int sumFlow = 0, newFlow;
    while (bfs(s, t))
    {
        while (newFlow = dfs(s, t, 1e18))
        {
            sumFlow += newFlow;
        }
    }
    return sumFlow;
}

//
void read_data()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].pb(edges.size());
        edges.pb({v, w, 0});
        g[v].pb(edges.size());
        edges.pb({u, 0, 0});
    }
    cout << dinic(1, n);
}

//
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    read_data();
    return 0;
}

// Sweep line
//
struct Event {
    int x, y, type;

    bool operator < (const Event& other)
    {
        if (x != other.x) return x < other.x;
        return type > other.type;
    }
};

//
vector<Event> events;

//
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        events.pb({x1, y1, 0});
        events.pb({x2, y2, 1});
    }
    sort(events.begin(), events.end());
    int x = 0; ll res = 0;
    multiset<int, greater<int>> T;
    T.clear();
    T.insert(0);
    for (int i = 0; i < events.size(); i++)
    {
        Event e = events[i];
        ll Max_y, tmp;
        if (e.type == 0)
        {
            Max_y = *T.begin();
            tmp = Max_y * (e.x - x);
            res += tmp;
            T.insert(e.y);
            x = e.x;
        }
        else
        {
            Max_y = *T.begin();
            tmp = Max_y * (e.x - x);
            res += tmp;
            T.erase(T.lower_bound(e.y));
            x = e.x;
        }
    }
    cout << res;
    return 0;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
