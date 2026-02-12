/*
    Room Allocation - 1164
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
    ll n;
    cin >> n;

    vector<pair<pll, ll>> customers(n);

    forn(i, n) {
        cin >> customers[i].f.f >> customers[i].f.s;
        customers[i].s = i;
    }

    sort(all(customers));

    vll ans(n);
    ll rooms_count = 0;

    priority_queue<pll, vector<pll>, greater<pll>> pq;

    forn(i, n) {
        ll arrival = customers[i].f.f;
        ll departure = customers[i].f.s;
        ll original_idx = customers[i].s;

        if (!pq.empty() && pq.top().f < arrival) {
            pll best_room = pq.top();
            pq.pop();
            
            pq.push({departure, best_room.s});
            ans[original_idx] = best_room.s;
        }
        else {
            rooms_count++;
            pq.push({departure, rooms_count});
            ans[original_idx] = rooms_count;
        }
    }

    cout << rooms_count << endl;

    forn(i, n) {
        cout << ans[i] << " ";
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
