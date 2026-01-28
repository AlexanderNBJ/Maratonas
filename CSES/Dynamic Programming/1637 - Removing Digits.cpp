/*
    Removing Digits - 1637
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> dp(n+1, LLONG_MAX);
    dp[0] = 0;

    for(long long i = 1; i<=n; i++){
        long long currentNumber = i;

        while(currentNumber != 0){
            long long aux = currentNumber%10;
            currentNumber /= 10;

            if(aux == 0)
                continue;
            
            dp[i] = min(dp[i], dp[i-aux]+1);
        }
    }

    cout << dp[n] << endl;
}