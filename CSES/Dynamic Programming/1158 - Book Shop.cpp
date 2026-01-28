/*
    Book Shop - 1158
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    long long n, x;
    cin >> n >> x;

    vector<long long> prices(n), pages(n);

    for(long long i=0; i<n; i++){
        cin >> prices[i];
    }
    for(long long i=0; i<n; i++){
        cin >> pages[i];
    }

    vector<long long> dp(x+1,0);
    dp[0]=0;

    for(long long i=0; i<n; i++){
        for(long long j=x; j>=prices[i]; j--){
            dp[j] = max(dp[j-prices[i]]+pages[i], dp[j]);
        }
    }

    cout << dp[x] << endl;
}