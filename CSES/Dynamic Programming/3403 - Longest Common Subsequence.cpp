/*
    Longest Common Subsequence - 3403
    Alexander Neves Barbosa Júnior
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n, m;
    cin >> n >> m;

    vector<long long> arr1(n), arr2(m);

    for(long long i=0; i<n; i++){
        cin >> arr1[i];
    }

    for(long long i=0; i<m; i++){
        cin >> arr2[i];
    }

      vector<vector<long long>> dp(n+1, vector<long long>(m+1, 0));
 
    for(long long i=1; i<=n; i++){
        for(long long j=1; j<=m; j++){
            if(arr1[i-1] == arr2[j-1]){
                dp[i][j] = dp[i-1][j-1] +1;
            } 
            else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
 
    cout << dp[n][m] << endl;
 
    vector<long long> aux;
    long long i = n, j = m;
 
    while(i>0 && j>0){
        if(arr1[i-1] == arr2[j-1]){
            aux.push_back(arr1[i-1]);
            i--;
            j--;
        } 
        else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        } 
        else {
            j--;
        }
    }
 
    reverse(aux.begin(), aux.end());
 
    for(long long k=0; k<(long long)aux.size(); k++){
        if(k){
            cout << " ";
        }
        cout << aux[k];
    }
}