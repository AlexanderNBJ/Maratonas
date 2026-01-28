/*
    Counting Towers - 2413
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int main(){
    long long t;
    cin >> t;
    vector<long long> queries(t);
    long long n=0;
 
    for(long long i=0; i<t; i++){
        cin >> queries[i];
        n = max(n, queries[i]);
    }
 
    vector<vector<long long>> dp(n+1, vector<long long>(2,0));
    dp[1][0] = 1;
    dp[1][1] = 1;
 
    for(long long i=2; i<=n; i++){
        dp[i][0] = ((2LL*dp[i-1][0])%MOD +dp[i-1][1])% MOD;
        dp[i][1] = (dp[i-1][0] +(4LL*dp[i-1][1])%MOD )% MOD;
    }
 
    for (long long n: queries) {
        cout << (dp[n][0] +dp[n][1])%MOD << endl;
    }
}