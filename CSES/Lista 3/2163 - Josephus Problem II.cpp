/*
    Josephus Problem II - 2163
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

const ll MAXN = 200005;
ll bit[MAXN];
ll n;
ll k;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

int find_kth(int target) {
    int idx = 0;
    int current_sum = 0;

    for (int i = 1 << 18; i > 0; i >>= 1) {
        if (idx + i <= n && current_sum + bit[idx + i] < target) {
            idx += i;
            current_sum += bit[idx];
        }
    }
    return idx + 1;
}

void solve() {
    cin >> n >> k;

    fore(i, 1, n){
        update(i, 1);
    }

    ll currentPos = 0;

    ford(i, n){
        ll currentSize = i+1;
        currentPos = (currentPos+k) % currentSize;

        ll child_idx = find_kth(currentPos + 1);

        cout << child_idx << " ";
        update(child_idx, -1);
    }

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
