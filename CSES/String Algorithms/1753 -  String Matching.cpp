/*
    String Matching - 1753
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// --- OTIMIZAÇÃO (Opcional - use se o limite de tempo for rígido)
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// --- DEFINIÇÕES DE TIPOS
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef __int128_t int128; // Para cálculos que extrapolam long long

// --- PBDS (Set com Rank e K-ésimo elemento)
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// --- MACROS
#define f first
#define s second
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define endl '\n'

// Loops
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)

// --- CONSTANTES ---
const int INF = 1e9 + 7;
const ll INF64 = 1e18 + 7;
const ll MOD = 1e9 + 7; // 998244353;
const double PI = acos(-1.0);
const double EPS = 1e-9;

// --- DEBUG SYSTEM
#ifdef LOCAL
#define debug(x...) cerr << "[" << #x << "] = ["; _debug_print(x)
#else
#define debug(x...)
#endif

void _debug_print() { cerr << "]\n"; }
template <typename T, typename... V> void _debug_print(T t, V... v);
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { return os << "{" << p.f << ", " << p.s << "}"; }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "["; forn(i, sz(v)) os << v[i] << (i == sz(v) - 1 ? "" : ", "); return os << "]"; }
template <typename T, typename... V> void _debug_print(T t, V... v) { cerr << t; if (sizeof...(v)) cerr << ", "; _debug_print(v...); }

// --- UTILS & MATH
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll get_rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

ll binpow(ll a, ll b, ll m = MOD) {
    a %= m; ll res = 1;
    while (b > 0) {
        if (b & 1) res = (__int128)res * a % m;
        a = (__int128)a * a % m; b >>= 1;
    }
    return res;
}

// Custom Hash para unordered_map (anti-hack)
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// --- ESTRUTURAS DE DADOS

struct DSU {
    vi parent, sz;
    DSU(int n) {
        parent.resize(n + 1); sz.assign(n + 1, 1);
        iota(all(parent), 0);
    }
    int find(int i) { return (parent[i] == i) ? i : (parent[i] = find(parent[i])); }
    bool unite(int i, int j) {
        int root_i = find(i), root_j = find(j);
        if (root_i != root_j) {
            if (sz[root_i] < sz[root_j]) swap(root_i, root_j);
            parent[root_j] = root_i; sz[root_i] += sz[root_j];
            return true;
        }
        return false;
    }
};

struct BIT {
    int n; vll tree;
    BIT(int n) : n(n), tree(n + 1, 0) {}
    void update(int i, ll delta) { for (; i <= n; i += i & -i) tree[i] += delta; }
    ll query(int i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    ll query(int l, int r) { return (l > r) ? 0 : query(r) - query(l - 1); }
};

// Segment Tree Genérica (Ponto de Atualização)
struct SegTree {
    int n; vll tree;
    ll neutral = 0; // Altere conforme a operação (0 para soma, INF para min, etc)
    
    SegTree(int n) : n(n), tree(4 * n, neutral) {}
    
    ll merge(ll a, ll b) { return a + b; } // Altere a operação aqui

    void update(int node, int start, int end, int idx, ll val) {
        if (start == end) { tree[node] = val; return; }
        int mid = (start + end) / 2;
        if (idx <= mid) update(2 * node, start, mid, idx, val);
        else update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }
    
    ll query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return neutral;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        return merge(query(2 * node, start, mid, l, r), query(2 * node + 1, mid + 1, end, l, r));
    }
    // Helpers para facilitar a chamada
    void update(int idx, ll val) { update(1, 0, n - 1, idx, val); }
    ll query(int l, int r) { return query(1, 0, n - 1, l, r); }
};

void solve(){
    string s, p;
    cin >> s >> p;
    string combined = p + "#" + s;

    int n = sz(combined);
    int m = sz(p);
    vi pi(n, 0);
    int occurrences = 0;

    for(int i = 1; i < n; i++){
        int j = pi[i - 1];

        while(j > 0 && combined[i] != combined[j]) 
            j = pi[j - 1];

        if(combined[i] == combined[j]) 
            j++;
        
        pi[i] = j;

        if(pi[i] == m) 
            occurrences++;
    }
    cout << occurrences << endl;
}

int main() {
    // Performance de I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t; // Descomente se houver múltiplos casos de teste
    while (t--) {
        solve();
    }

    return 0;
}