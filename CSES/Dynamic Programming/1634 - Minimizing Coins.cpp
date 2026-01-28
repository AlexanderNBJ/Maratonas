/*
    Minimizing Coins - 1634
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> coins(n);

    for(long long i=0; i<n; i++){
        cin >> coins[i];
    }

    vector<long long> dp(x+1, LLONG_MAX);
    dp[0] = 0;

    for(long long i=1; i<=x; i++){
        for(long long coin: coins){
            if(coin > i || dp[i-coin] == LLONG_MAX){
                continue;
            }
            else{
                dp[i] = min(dp[i], dp[i-coin]+1);
            }
        }
    }

    if(dp[x]!= LLONG_MAX)
        cout << dp[x] << endl;
    else
        cout << -1 << endl;

}