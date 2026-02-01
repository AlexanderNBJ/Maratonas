/*
    Collecting Numbers II - 2217
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

ll search(map<ll, ll>& indexes, ll n){
    ll res = 1, currentNumber = 1;

    while(currentNumber != n){
        if(indexes[currentNumber] < indexes[currentNumber+1]){
            currentNumber++;
        }
        else{
            currentNumber++;
            res++;
        }
    }
    return res;
}

void solve() {
    ll n, m;
    cin >> n >> m;

    vll v(n+1), pos(n+1);

    for(int i=1; i<=n; i++){
        cin >> v[i];
        pos[v[i]] = i;
    }

    ll res = 1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1]){
            res++;
        }
    }

    while(m--){
        ll a, b;
        cin >> a >> b;

        set<pll> pairs;

        if(v[a]>1){
            pairs.insert({v[a] - 1, v[a]});
        }
        if(v[a]<n){
            pairs.insert({v[a], v[a] + 1});
        }
        if(v[b]>1){
            pairs.insert({v[b] - 1, v[b]});
        }
        if(v[b]<n){
            pairs.insert({v[b], v[b] + 1});
        }
        
        for(auto p: pairs){
            if (pos[p.first] > pos[p.second]){
                res--;
            }
        }

        swap(v[a], v[b]);
        pos[v[a]] = a;
        pos[v[b]] = b;

        for(auto p: pairs){
            if(pos[p.first] > pos[p.second]){
                res++;
            }
        }

        cout << res << endl;
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
