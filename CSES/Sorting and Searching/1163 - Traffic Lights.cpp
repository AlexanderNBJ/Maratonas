/*
    Traffic Lights - 1163
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

void solve() {
    int x, n;
    cin >> x >> n;

    set<int> positions;
    positions.insert(0);
    positions.insert(x);

    multiset<int> gaps;
    gaps.insert(x);

    forn(i, n) {
        int p;
        cin >> p;

        auto it_right = positions.upper_bound(p);
        auto it_left = prev(it_right);

        gaps.erase(gaps.find(*it_right - *it_left));
        gaps.insert(p - *it_left);
        gaps.insert(*it_right - p);
        positions.insert(p);

        cout << *gaps.rbegin() << (i == n - 1 ? "" : " ");
    }
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
