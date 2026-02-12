/*
    Nested Ranges Check - 2168
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

// Definições de Tipos
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

// --- PBDS Typedefs ---
// Funciona como um std::set, mas com duas funções extra em O(log N):
// 1. find_by_order(k): Retorna um iterador para o k-ésimo menor elemento (0-indexed).
// 2. order_of_key(k): Retorna a quantidade de elementos estritamente menores que k.
template <typename T> 
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

// ==============================================================================
// ALGORITMOS E ESTRUTURAS DE DADOS ÚTEIS (COPIE/APAGUE CONFORME A NECESSIDADE)
// ==============================================================================

// --- RNG (Random Number Generator) ---
// Melhor que rand(), seguro contra hacks em competições
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
inline ll get_rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rng); }

// --- CUSTOM HASH PARA UNORDERED_MAP ---
// Evita TLE contra casos de teste maliciosos (colisão de hash)
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
// Uso: unordered_map<ll, ll, custom_hash> mapa_seguro;

// --- MATH UTILS ---
// Exponenciação Rápida Modular: Calcula (base^exp) % mod em O(log exp)
ll binpow(ll base, ll exp, ll mod = MOD) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

// Inverso Modular: Retorna x tal que (a * x) % mod == 1 em O(log mod)
ll modInverse(ll n, ll mod = MOD) {
    return binpow(n, mod - 2, mod); // Funciona se mod for primo (Pequeno Teorema de Fermat)
}

// --- DSU (Disjoint Set Union / Union-Find) ---
// O(alpha(N)) para verificar conectividade de grafos ou Kruskal
struct DSU {
    vll parent, size;
    DSU(ll n) {
        parent.resize(n + 1);
        size.assign(n + 1, 1);
        for1(i, n) parent[i] = i;
    }
    ll find(ll v) {
        if (v == parent[v]) return v;
        return parent[v] = find(parent[v]); // Path compression
    }
    bool unite(ll a, ll b) {
        a = find(a);
        b = find(b);
        if (a != b) {
            if (size[a] < size[b]) swap(a, b); // Union by size
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }
};

// --- FENWICK TREE (Binary Indexed Tree - BIT) ---
// O(log N) para Ponto de Atualização e Soma de Intervalo
struct BIT {
    ll n;
    vll tree;
    BIT(ll n) : n(n), tree(n + 1, 0) {}
    void update(ll i, ll delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }
    ll query(ll i) {
        ll sum = 0;
        for (; i > 0; i -= i & -i) sum += tree[i];
        return sum;
    }
    ll query(ll l, ll r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

// --- SEGMENT TREE (Ponto de Atualização, Range Query) ---
// O(log N) - Mude a função 'combine' para MIN, MAX, GCD, etc.
struct SegTree {
    ll n;
    vll tree;
    SegTree(ll n) : n(n), tree(4 * n, 0) {}
    
    ll combine(ll a, ll b) { return a + b; } // Altere aqui a operação (ex: min(a,b))

    void build(const vll& a, ll node, ll start, ll end) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            ll mid = (start + end) / 2;
            build(a, 2 * node, start, mid);
            build(a, 2 * node + 1, mid + 1, end);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }
    void update(ll node, ll start, ll end, ll idx, ll val) {
        if (start == end) {
            tree[node] = val; // Substituição. Se for adição, mude para +=
        } else {
            ll mid = (start + end) / 2;
            if (start <= idx && idx <= mid)
                update(2 * node, start, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, end, idx, val);
            tree[node] = combine(tree[2 * node], tree[2 * node + 1]);
        }
    }
    ll query(ll node, ll start, ll end, ll l, ll r) {
        if (r < start || end < l) return 0; // Elemento neutro (0 pra soma, INF pra min)
        if (l <= start && end <= r) return tree[node];
        ll mid = (start + end) / 2;
        ll p1 = query(2 * node, start, mid, l, r);
        ll p2 = query(2 * node + 1, mid + 1, end, l, r);
        return combine(p1, p2);
    }
};

bool ordena(tuple<int,int,int>& a, tuple<int,int,int>& b){
    if(get<0>(a)==get<0>(b)){
        return get<1>(a) > get<1>(b);
    }
    else{
        return get<0>(a) < get<0>(b);
    }
}

void solve() {
    int n;
    cin >> n;
 
    vector<tuple<int,int,int>> range(n);
 
    for(int i=0; i<n; i++){
        int a,b;
        cin >> a >> b;
        
        get<0>(range[i])=a;
        get<1>(range[i])=b;
        get<2>(range[i])=i;
    }
 
    sort(range.begin(), range.end(), ordena);
    vector<int> contem(n), contido(n);
 
    int maior = 0;
    for(int i=0; i<n; i++){
        if(get<1>(range[i]) <= maior){
            contido[get<2>(range[i])] = 1;
        }
        maior = max(maior, get<1>(range[i]));
    }
 
    int menor = INF;
    for(int i=n-1; i>=0; i--){
        if(get<1>(range[i]) >= menor){
            contem[get<2>(range[i])] = 1;
        }
        menor = min(menor, get<1>(range[i]));
    }
 
    for(int i: contem){
        cout << i << ' ';
    }
    cout << endl;
    for(int i: contido){
        cout << i << ' ';
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