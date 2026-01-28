/*
    Grid Paths I - 1638
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;

int main(){
    long long n;
    cin >> n;

    vector<vector<char>> grid(n, vector<char>(n));

    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            cin >> grid[i][j];
        }
    }
    
    vector<long long> dp(n, 0);
    dp[0] = 1;

    for(long long i=0; i<n; i++){
        for(long long j=0; j<n; j++){
            if(grid[i][j]=='*'){
                dp[j] = 0;
            }
            else{
                long long aux = 0;

                if(j){
                    aux = dp[j-1];
                }
                dp[j] = (dp[j]+aux)%MOD;
            }
        }
    }

    cout << dp[n-1] << endl;
}