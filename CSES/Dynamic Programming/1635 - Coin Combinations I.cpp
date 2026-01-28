/*
    Coin Combinations I - 1635
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);

    for(long long i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<long long> dp(x+1, 0);
    dp[0] = 1;

    for(long long i=1; i<=x; i++){
        for(auto coin: coins){
            if(i-coin >=0){
                dp[i] = (dp[i] +dp[i-coin])% MOD;
            }
        }
    }
    cout << dp[x] << endl;
}