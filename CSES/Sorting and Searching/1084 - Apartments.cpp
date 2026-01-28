/*
    Apartments - 1084
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
    ll n, m, k;
    cin >> n >> m >> k;

    vll desiredApartmentSizes(n), apartmentSizes(m);

    forn(i, n){
        cin >> desiredApartmentSizes[i];
    }

    forn(i, m){
        cin >> apartmentSizes[i];
    }

    ll i, j, res;
    res=i=j=0;

    sort(all(apartmentSizes));
    sort(all(desiredApartmentSizes));

    while(i<n && j<m){
        if(apartmentSizes[j]<desiredApartmentSizes[i]-k){
            j++;
        }
        else if(apartmentSizes[j]>desiredApartmentSizes[i]+k){
            i++;
        }
        else{
            res++;
            i++; j++;
        }
    }

    cout << res << endl;
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
