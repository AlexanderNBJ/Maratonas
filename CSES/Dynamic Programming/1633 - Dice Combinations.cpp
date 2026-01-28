/*
    Dice Combinations - 1633
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 +7;

int main(){
    long long n;
    cin >> n;

    vector<long long> dp(n+1,0);
    dp[0] = 1;

    for(long long i=1; i<=n; i++){
        for(long long j=1; j<=6; j++){
            long long missingCoin = i-j;
            if(missingCoin >=0){
                dp[i] = (dp[i] + dp[missingCoin]) % MOD;
            }
        }
    }
    cout << dp[n] << endl;
}