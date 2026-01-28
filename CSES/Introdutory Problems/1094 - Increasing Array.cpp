/*
    Increasing Array - 1094
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> arr(n);

    for(long long i=0; i<n; i++){
        long long aux;
        cin >> aux;

        arr[i] = aux;
    }

    long long res = 0;
    long long previousElement = arr[0];

    for(long long i=1; i<n;i++){
        if(arr[i] < previousElement){
            res += previousElement-arr[i];
            arr[i] = previousElement;
        }
        previousElement = arr[i];
    }

    cout << res << endl;
}