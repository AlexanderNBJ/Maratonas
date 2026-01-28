/*
    Edit Distance - 1639
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    long long n = a.size();
    long long m = b.size();

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1));

    for(long long j=0; j<=m; j++){
        dp[0][j] = j;
    }
    
    for(long long i=0; i<=n; i++){
        dp[i][0] = i;
    }

    for(long long i=1; i<=n; i++) {
        for(long long j=1; j<=m; j++) {

            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } 
            else {
                dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
    }

    cout << dp[n][m] << endl;
}