/*
    Array Description - 1746
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> arr(n);
    for(long long i=0; i<n; i++){
        cin >> arr[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(m+2, 0));

    if(!arr[0]){
        for(long long i=1; i<=m; i++){
            dp[0][i]=1;
        }
    }
    else{
        dp[0][arr[0]] = 1;
    }

    for(long long i=1; i<n; i++){
        if(!arr[i]){
            for(long long j=1; j <= m; j++) {
                long long s = 0;
                s += dp[i-1][j];
                s += dp[i-1][j-1];
                s += dp[i-1][j+1];
                dp[i][j] = (long long)(s % MOD);
            }
        }
        else{
            long long v = arr[i];
            long long s = 0;
            s += dp[i-1][v];
            s += dp[i-1][v-1];
            s += dp[i-1][v+1];
            dp[i][v] = (long long)(s % MOD);
        }
    }

    long long res = 0;
    if(!arr[n-1]){
        for(long long i=1; i<=m; i++){
            res = (res + dp[n-1][i]) % MOD;
        }
    }
    else{
        res = dp[n-1][arr[n-1]];
    }
 
    cout << res << endl;
}