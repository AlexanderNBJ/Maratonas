/*
    Coin Combinations II - 1636
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);

    for(int i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<long long> dp(x+1, 0);
    dp[0] = 1;

    for(auto coin: coins){
        for(long long i=1; i<=x; i++){
            if(i-coin >=0){
                dp[i] = (dp[i]+dp[i-coin])%MOD;
            }
        }
    }

    cout << dp[x] << endl;
}