/*
    Two Knights - 1072
*/

#include <bits/stdc++.h>
using namespace std;

long long solve(long long x){
    return (x*x*x*x -9*x*x + 24*x -16)/2;
}

int main(){
    long long k;
    cin >> k;

    for(long long i=1; i<=k; i++){
        cout << solve(i) << endl;
    }
}