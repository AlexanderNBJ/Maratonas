/*
    Nested Ranges Count - 2169
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;

// Definições de Tipos
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// Macros para Agilidade
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

// Loops
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

// Constantes
const int INF = 1e9;
const ll INF64 = 1e18;
const ll MOD = 1e9 + 7;
const double PI = acos(-1.0);

// Debugging
// Para usar: compile com a flag -DLOCAL ou descomente a linha abaixo
// #define LOCAL
#ifdef LOCAL
#define debug(x) cerr << #x << " = " << x << endl
#else
#define debug(x)
#endif

struct Range {
    int x, y, id;
    int contains = 0;
    int contained = 0;
};

const int MAXN = 200005;
int bit[MAXN];

void update(int idx, int val, int m) {
    for (; idx <= m; idx += idx & -idx)
        bit[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx)
        sum += bit[idx];
    return sum;
}

void solve() {
    ll n;
    cin >> n;

    vector<Range> ranges(n);
    vi coordsY;

    forn(i, n) {
        cin >> ranges[i].x >> ranges[i].y;
        ranges[i].id = i;
        coordsY.pb(ranges[i].y);
    }

    sort(all(coordsY));
    coordsY.erase(unique(all(coordsY)), coordsY.end());

    ll m = sz(coordsY);

    auto get_rank = [&](int y) {
        return lower_bound(all(coordsY), y) - coordsY.begin() + 1;
    };

    sort(all(ranges), [](const Range& a, const Range& b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y > b.y;
    });

    ford(i, n) {
        int y_rank = get_rank(ranges[i].y);
        ranges[i].contains = query(y_rank);
        update(y_rank, 1, m);
    }

    for1(i, m)
        bit[i] = 0;

    forn(i, n) {
        int y_rank = get_rank(ranges[i].y);
        ranges[i].contained = query(m) - query(y_rank - 1);
        update(y_rank, 1, m);
    }

    sort(all(ranges), [](const Range& a, const Range& b) {
        return a.id < b.id;
    });

    forn(i, n) 
        cout << ranges[i].contains << " ";
    cout << endl;

    forn(i, n) 
        cout << ranges[i].contained << " ";
    cout << endl;
}

int main() {
    // Otimização de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Se o problema tiver múltiplos casos de teste, descomente:
    // int t; cin >> t; while (t--)
    solve();

    return 0;
}